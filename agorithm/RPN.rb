require "byebug"

# type 1: 123
# type 2: User.abc
# type 3: + - * /
class Item
  attr_accessor :value, :type

  def initialize
    @value = ""
  end

  def convert_value
    if (@value[0].ord >= 65 && @value[0].ord <= 90) || (@value[0].ord >= 97 && @value[0].ord <= 112)
      # Association
      return 1
    else
      # Number
      return @value
    end
  end
end

class RPN
  attr_accessor :str, :queue

  def initialize str
    @str = str
    @queue = Queue.new
  end

  def convert
    standardized
    stack = []
    item  = Item.new

    @str.each_char.with_index(0){|char, i|
      if (char == "(")
        # Handling (
        item.value = char
        stack << item
        item = Item.new
      elsif (char == ")")
        # Handling )
        while(stack.last.value != "(") do
          @queue << stack.pop
        end
        stack.pop
      elsif (char == "+" || char == "-" || char == "*" || char == "/" )
        # Handling operator
        if stack.size > 0
          if (classify char) <= (classify stack.last.value)
            st = stack.last
            while st.value != "(" do
              @queue << st
              stack.pop
              if stack.size > 0
                st = stack.last
              else
                break
              end
            end
          end
        end
        item.value = char
        item.type = 3
        stack << item
        item = Item.new
      elsif (char.ord >= 48 && char.ord <= 57)
        # Handling operand
        # Handling number
        item.value += char
        item.type = 1
        if ( (i+1) == @str.length || @str[i+1].ord < 48 || @str[i+1].ord > 57)
          @queue << item
          item = Item.new
        end
      elsif (char.ord == 46 || (char.ord >= 65 && char.ord <= 90) || (char.ord >= 97 && char.ord <= 122))
        # Handling association
        item.value += char
        item.type = 2
        if (@str[i+1].ord != 46) && ((i+1) == @str.length || @str[i+1].ord < 65 || ( @str[i+1].ord > 90 && @str[i+1].ord < 97) || @str[i+1].ord > 122)
          @queue << item
          item = Item.new
        end
      end
    }
    while(stack.size > 0) do
      @queue << stack.pop
    end
  end

  def calculate
    convert
    stack = []

    while(@queue.size > 0) do
      q = @queue.pop
      if q.type == 1 || q.type == 2
        stack << q.convert_value
      elsif q.type == 3
        if q.value == "+"
          stack << stack.delete_at(-2).to_f + stack.delete_at(-1).to_f
        elsif q.value == "-"
          stack << stack.delete_at(-2).to_f - stack.delete_at(-1).to_f
        elsif q.value == "*"
          stack << stack.delete_at(-2).to_f * stack.delete_at(-1).to_f
        elsif q.value == "/"
          stack << stack.delete_at(-2).to_f / stack.delete_at(-1).to_f
        end
      else
        puts "Error in: " + q.value
      end
    end
    return stack.last
  end

  private

  def standardized
    @str.tr!(" ", "")
  end

  def classify c
    if (c == "+" || c == "-")
      1
    elsif (c == "*" || c == "/")
      2
    else
      0
    end
  end
end

s1 = "50 + ((1 + 2) * 4) + 3" #65
s2 = "5/2 + 3*(4/8 - 2)" #Not 5.5 #-2
s3 = "2000 + User.allowance * (150000 + User.score)"
s4 = "10 * 2 + 40 - 10 "

rpn = RPN.new s1
puts "Value of %s is: %d" % [s1, rpn.calculate] #65

rpn = RPN.new s2
puts "Value of %s is: %d" % [s2, rpn.calculate] #-2

rpn = RPN.new s3
puts "Value of %s is: %d" % [s3, rpn.calculate] # 152001

rpn = RPN.new s4
puts "Value of %s is: %d" % [s4, rpn.calculate] # 50
