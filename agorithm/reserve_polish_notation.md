Đây là một thuật toán biểu diễn lại công thức toán học giúp máy tính có thể hiểu và thực hiện tính toán đúng như mong muốn.

Lưu ý: Để đơn giản, bài toán đưọc giới hạn lại:
  + Các dấu chỉ gồm mở ngoặc đóng ngoặc
  + Toán tử chỉ gồm cộng trừ nhân chia
  + Toán hạng chỉ gồm các số nguyên từ 0 -> 9.
  Sau khi hiểu rõ thuật toán cơ bản sẽ phát triển sau.

1920: Nhà toán học Jan Lukasiewicz (BaLan) đề xuất biểu thức tiền tố Prefix (ký pháp BaLan)
  -> Loại bỏ hoàn toàn dấu ngoặc (), giảm bớt sự phiền nhiễu của biểu thức toán học.

1950:Nhà khoa học máy tính Charles Hamblin phát minh biểu thức hậu tố Postfix, từ đó dẫn tới Reserve Polish Notation – RPN (ký pháp nghịch đảo BaLan).

Các dạng của biếu thức:
+ Biểu thức trung tố (Infix):
  Toán tử nằm giữa hai toán hạng.
  VD: a + b
  Thông thường con người sử dụng dạng này để biểu diễn công thức toán học.

+ Biểu thức tiền tố (Prefix):
  Thuật toán biểu diễn biểu thức bằng cách đặt các toán tử lên phía trước
  VD: a + b -> + a b

+ Biểu thức hậu tố (Postfix):
  Thuật toán biểu diễn biểu thức bằng cách đặt các toán tử về phía sau
  VD: a + b -> a b +

Sau đây chúng ta sẽ tìm hiểu xem ký pháp BaLan đảo hoạt động như thế nào.
Bạn có thể xem qua ví dụ sau đây:

```
Input:
Infix: 5 + ((1 + 2) * 4) + 3

>>>> (Bước 1)

Postfix: 5 1 2 + 4 * + 3 +

>>>> (Bước 2)

Output:
Result: 20
```

Ký pháp này sẽ sử dụng tới ngăn xếp và hàng đợi.Cụ thể là:

1 queue: lưu giữ biểu thức sau khi chuyển xong

1 stack đệm (xong quá trình chuyển đổi ta sẽ huỷ nó đi) để lưu các toán tử trong quá trình đọc.


#### Bước 1

![](https://user-images.githubusercontent.com/18675907/27953667-d916d9fe-6336-11e7-9d43-7faa70185ff8.jpg)

Note: Khi ta đọc đọc 1 toán tử  (khác “()”, và ta đang chuẩn bị đưa vào stack) thì  sẽ có 2 trường hợp xảy ra: Toán tử chuẩn bị thêm vào sẽ có độ ưu tiên:

+ cao hơn toán tử đầu stack: lúc này ta đơn giản chỉ push toán tử đó vào stack

+ thấp hơn toán tử đầu stack: lúc này ta sẽ lấy lần lượt toán tử từ đầu stack ra (cho đến khi hết stack hoặc gặp “(” ) rồi thêm chúng vào queue, sau đó nhớ push trả lại “(” và push toán tử mới vào.

Không còn kí tự nào nữa ta sẽ lấy hết những toán tử còn lại trong stack ra và cho vào queue, sau đó xoá bỏ stack. Ta sẽ được 1 biểu thức nghịch đảo Ba Lan:   5 1 2 + 4 * + 3 +

#### Bước 2

![](https://user-images.githubusercontent.com/18675907/27980300-52ed710a-63a7-11e7-9f02-6cbaef7157eb.jpg)

Hết dữ liệu trong Queue chứa biểu thức nghịch đảo, ta xoá queue, lấy kết quả cuối cùng có được tự stack ra ngoài (muốn làm gì với nó thì tuỳ yêu cầu tiếp theo) rồi xoá stack đi, kết thúc quá trình tính định trị biểu thức.

```ruby
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

```