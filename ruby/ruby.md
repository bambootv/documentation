#### 1.Ruby

1. Introduce
	Ngôn ngữ thông dịch
	Hằng số có thể thay đổi, ruby chỉ đưa ra lời cảnh báo.
	Sigil là các kí tự $ và @ dùng để khai báo phạm vi hoạt động của biến.

#### Note: p puts

	(p || puts) = print + "\n"

	p foo = print foo.inspect
	puts foo = print foo.to_s

	p "ss\nss\n" => ss\nss\n
	puts "ss\nss\n" =>
	ss
	ss

	p "a", "b", ["c", "d"]
	"a"
	"b"
	["c", "d"]

	puts "a", "b", ["c", "d"]
	a
	b
	c
	d

	puts # no arguments
	=> nil #return nil and writes a newline

	>> p
	=> nil # return nil, writes nothing

	puts nil
	p nil
	Phương thức puts sẽ in chuỗi rỗng của đối tượng nil
	Phương thức p lại in chuỗi "nil" ra màn hình.

#### 2.Function

	Hàm chứa ? => return true / false

	light = :on
	if light == :on
	    puts "The light is on"
	else
	    puts "The light is off"
	end
	Dùng symbol thay cho khai báo status = "on" sẽ dễ code hơn

	fdiv => Chia trả về số chấm động.

	Array(1..6)
	p Complex 6
	p Float 12
	p Integer "34"
	p Rational 6
	p String 22

	.split sẽ tách từng kí tự trong string và lưu trong một mảng.

	Các ngôn ngữ khác, từ khóa return để trả về một giá trị của một phương thức
	Ruby: tự động được trả về ngầm bằng giá trị của câu lệnh cuối cùng được thực hiện trong phương thức.

#### 3.Biến
------------------------------
1. Introduce
	Biến là nơi lưu trữ dữ liệu: Tên và kiểu dữ liệu
	Trong ruby, không cần khai báo kiểu dữ liệu -> Ngôn ngữ lập trình động

	```
	car_name = "Peugeot": biến cục bộ: từng phương thức, lớp… nhất định.
	@sea_name = "Black sea": biến instance, biến này chỉ có hiệu lực trong một đối tượng.
	@@species = "Cat": biến class, mọi đối tượng của một class đều có thể truy xuất biến này.
	$car_name = "Peugeot": biến toàn cục, biến toàn cục có hiệu lực trong toàn bộ code Ruby.
	```

	p local_variables.include? :$car_name
	p global_variables.include? :$car_name

	self tham chiếu đến đối tượng hiện tại đang sử dụng
	self (Ruby) <=> con trỏ this (C, Java).

	Biến instance là biến nằm trong một đối tượng cụ thể.
	Mỗi đối tượng có những biến instance riêng của chúng, biến instance có tên bắt đầu bằng kí tự @.

	Biến class là biến nằm trong một lớp.
	Những đối tượng được tạo ra từ lớp đó sẽ dùng chung biến class.
	Biến class có tên bắt đầu bằng kí tự @@.

	Chương trình sau báo lỗi:
		x = 5
		def test
			p x
		end
		test

#### 3. Đối tượng
------------------------------
1. Introduce

	Một đối tượng chứa thuộc tính và phương thức bên trong nó.
	Thuộc tính là dữ liệu của đối tượng, đây là thành phần tĩnh, phương thức là phần động.
	Đối tượng có thể được chỉnh sửa hoặc giao tiếp với các đối tượng khác thông qua phương thức.


#### 3. Methods

Example

	class Car
		attr_reader :name, :price
		attr_writer :name, :price
		# hoặc attr_accessor :name, :price

		def to_s
			"#{@name}: #{@price}"
		end

		def sefl.to_str
			"#{@name}: #{@price}"
		end

		def to_string
			return "#{@name}: #{@price}"
		end
	end
	c1 = Car.new
	c1.name = "Porsche"
	c1.price = 23500

1. Define

	Methods implement the functionality of your program.

	A method definition consists of the def keyword, a method name, the body of the method, return value and the end keyword.
	When called the method will execute the body of the method.

2. Return

	Nếu không return, mặc định trả về câu lệnh cuối cùng.

3. Scope

	Instance method
		```
		def to_s
			"#{@name}: #{@price}"
		end
		```

	Class method
		```
		class Car
			def sefl.to_str
				"#{@name}: #{@price}"
			end
		end
		```
	Để gọi phương thức class thì chúng ta gọi từ tên lớp chứ không gọi từ tên đối tượng.

	Phương thức initialize là phương thức khởi tạo.
	Phương thức này tự động được gọi khi chúng ta khai báo đối tượng.

	Phương thức attr_reader tạo ra phương thức getter
	Phương thức attr_writer tạo các phương thức setter.
	Phương thức attr_accessor sẽ tạo cả getter, setter.

	When Ruby encounters the def keyword, it doesn’t consider it an error if the method already exists: it simply redefines it. This is called overriding.

		```
		>> "43".to_i
		=> 43
		>> class String
		>>   def to_i
		>>     42
		>>   end
		>> end
		=> nil
		>> "43".to_i
		=> 42
		```

4.Arguments

	The default value does not need to appear first, but arguments with defaults must be grouped together

		```
		def to_s (@name, @price = 1)
			"#{@name}: #{@price}"
		end
		```

		```
		def gather_arguments(*arguments)
		  p arguments
		end

		gather_arguments 1, 2, 3 # prints [1, 2, 3]
		```

4.Exception
			```
			def my_method
			  begin
			    # code that may raise an exception
			  rescue
			    # handle exception
			  end
			end
			```

5. Note
		Kernel.puts "Ruby language"
		Kernel.puts "Ruby language".size

		s = String.new "Hello world"
		puts s

		p 6.object_id
		p 6.even?
		p 6.zero?
		p 6.class =>Fixnum
		p 6.is_a? Object => Đối tượng 6 có được kế thừa từ đối tượng Object không ?

		Kernel.puts self => main
		p self.class => Object
		p "Jane".methods.size => Kích thước


#### 3. Kiểu
------------------------------

	:name => Symbol

	Dùng symbol sẽ tiết kiệm được nhiều tài nguyên hơn so với dùng biến thông thường. Tất cả các biến symbol đều là một đối tượng từ lớp Symbol. 		Để định nghĩa một symbol thì chúng ta thêm dấu hai chấm ":" vào trước giá trị, ví dụ :name. Hầu hết các đối tượng trong Ruby đều có phương thức to_sym để chuyển một đối tượng thành một symbol.
	Symbol không thể thay đổi được giá trị. Thường thì symbol được dùng để làm khóa trong bảng băm.

	Một string có kích thước lớn hơn một symbol.
	Symbol giống nhau thì có id giống nhau, string giống nhau thì lại có id khác nhau.
	Ngoài ra Symbol cũng thường được dùng để dánh dấu, chẳng hạn như thay vì khai báo biến number = 1 rồi thực hiện if number == 1... thì ở đây chúng ta dùng symbol sẽ tiết kiệm được bộ nhớ cũng như dễ code hơn.

	Số nguyên Integer:
	Trong toán học: Integer: Z => Vô hạn
	Trong máy tính không có gì là vô hạn
	Integer (Java/C): -2^32 -> 2^32
	Integer (Ruby): Các đối tượng thuộc lớp Fixnum hoặc Bignum.
	Nếu như lớn hơn cho phép, ruby tự động chuyển về Bignum
	Số nguyên quá lớn có thể sử dụng dấu "_", trình thông dịch ruby sẽ bỏ qua và chỉ nhận số.
	VD: 123_422_232 => 123422232



	(1..6)=> Range
	h = { :name => "Jane", :age => 17 } => Mảng băm

6.	Kế thừa

	class Being
		def to_s
			"This is being"
		end

		get_id
			9
		end
	end

	class Living < Being
		def to_s
			"This is living"
		end
	end

7.	Nil là một đối tượng mô tả giá trị “không có”, ý nói một biến không có giá trị gì cả. nil là một đối tượng tĩnh, tức là trong Ruby chỉ có một đối tượng nil duy nhất giống như đối tượng true hay false vậy, nil được tạo ra từ lớp NilClass.

8. 	Mảng

	Mảng và bảng băm lưu dữ liệu theo dạng tập hợp, tức là chúng không lưu từng giá trị cụ thể mà lưu một nhóm các phần tử có giá trị khác nhau.
	Mảng lưu các phần tử theo một thứ tự trong khi bảng băm lưu phần tử theo các cặp khóa-giá trị.

	nums = [1, 2, 3, 4]
 	puts "There are #{nums.size} items in the array"
	nums.each do |num|
	    puts num
	end


	domains = { :de => "Germany", :sk => "Slovakia",
            :us => "United States", :no => "Norway" }
	puts domains.keys
	puts domains.values


	alpha = %w{ a b c d e f g h} # <=> ['a', 'b','c']
	puts alpha.first
	puts alpha.last
	puts alpha.at(3)
	puts alpha.values_at(1..5).
	puts alpha.values_at(1..5)
	puts alpha.values_at(1, 3, 5).


	puts arr1 + arr2
	puts arr1.concat arr2

	alpha.dup trả về mảng mới bằng mảng gốc
	alpha.delete_at(0)

	alpha = alpha.reverse! # Đảo ngược
	.index i: Chỉ số phần tử đầu tiên từ trái qua phải có giá trị bằng i
	.rindex i: Chỉ số phần tử đầu tiên từ phải qua trái có giá trị bằng i

	puts arr.join '-' => chuỗi string có các phần tử ngăn cách nhau bởi kí tự được truyền vào
	puts arr.uniq! =>Phương thức uniq! sẽ loại bỏ các phần tử có giá trị giống nhau.

	alpha.insert 0, 'E', 'F', 'G'
	alpha.push 'H'
	alpha.push 'I', 'J', 'K'
	alpha << 'L' << 'M'
	alpha.unshift 'A', 'B', 'C' # Chèn vào đầu
	alpha.insert(3, 'D')

	alpha.pop
	alpha.shift # Xóa phần tử đầu tiên
	alpha.delete_at(0)
	alpha.delete('d')


	puts "#{arr.sort}"              # Xắp xếp tăng dần
	puts "#{arr.reverse}"		# Xắp xếp giảm dần
	puts "#{arr.shuffle}"		# Trộn

13.	Mảng băm

	hash = Hash.new
	hash[1] = "Jane"
	hash.store(2, "Thomas")

	hash = { "de" => "Germany",
	    "sk" => "Slovakia",
	    "hu" => "Hungary",
	    "us" => "United States",
	    "no" => "Norway"
	}
	puts hash["de"]

	puts hash.has_key? :de
	puts hash.include? :no
	puts hash.key? :me
	puts hash.member? :sk

	puts hash.has_value? "Slovakia"
	puts hash.value? "Germany"

	puts hash.fetch 1  => input: key; return: value

	hash.each { |k, v| puts "Key: #{k}, Value: #{v}" }
	hash.each_key { |key| puts "#{key}" }
	hash.each_value { |val| puts "#{val}" }
	hash.each_pair { |k, v| puts "Key: #{k}, Value: #{v}" }

#### 14. String

Parent: Object


1. str * integer → new_str

	"Ho! " * 3   #=> "Ho! Ho! Ho! "

	"Ho! " * 0   #=> ""

2. Pairing

	name = "Hoan" + "Ki"

	name = "Hoan" "Ki"

	name = "Hoan" << "Ki"

 	name = "Hoan".concat("Ki")

3. Compare

	== 			=== 			eql?

	"aa" == "ab" #=> true

	"aa".eql?"ab" #=> true

	Two strings are equal if they have the same length and content.

	1 == 1.0 #=> true

	1.eql?1.0 #=> false

	"abcdef" <=> "abcde"     #=> 1

	"abcdef" <=> "abcdef"    #=> 0

	"abcdef" <=> "abcdefg"   #=> -1

	"abcdef" <=> "`ABCDEF"    #=> 1

	"abcdef" <=> 1           #=> nil

	msg = "Ruby language"

	puts msg["Ruby"]

	puts msg["Python"]

	puts msg[0]

	puts msg[-1] => Kí tự cuối cùng.

	puts msg[0, 3]

	puts msg[0..9]

	puts msg[0, msg.length]

	ruby = "Ruby"

	ruby.upcase

	ruby.downcase

	ruby.capitalize #=> Viết hoa chữ cái đầu

	ruby.swapcase #=> Hoa <-> thường

	ruby.start_with? "ruby"

	ruby.end_with? "ruby"

	"There are %.5f oranges and %d apples in the basket." % [12, 10]

	puts "%10d" % 1

	puts "%10d" % 12

	puts "%10d" % 123

	Truyền biến vào string #{name}

	p foo = print foo.inspect

	puts foo = print foo.to_s

	p "ss\nss\n" => ss\nss\n

	puts "ss\nss\n" =>
	ss
	ss

#### 15. Biểu thức:


	TÊN					KÍ HIỆU
	Lấy thuộc tính, phương thức		:: .
	Thao tác mảng				[ ] [ ]=
	Lấy lũy thừa				**
	Toán tử phủ định, đảo bit, tăng, giảm	! ~ + -
	Toán tử nhân, chia, chia lấy phần dư	* / %
	Toán tử cộng, trừ			+ -
	Toán tử dịch bit			<< >>
	Toán tử thao tác bit AND		&
	Toán tử thao tác bit OR 		^ |
	Toán tử so sánh hơn kém			> >= < <=
	Toán tử so sánh bằng			<=> == === != =~ !~
	Toán tử logic AND			&&
	Toán tử logic OR			||
	Toán tử tạo phạm vi			.. ... (VD: (i..j) từ i tới j; (i...j) từ i tới j-1)
	Toán tử điều kiện			?: (VD: a = b > c ? b : c)
	Toán tử gán				= += -= *= **= /= %= &= |= ^= <<= >>= ||= &&=
	Phủ định				not
	Toán tử logic OR, AND			or and


11.	Luồng

	if num < 0
	    puts "#{num} is negative"
	elsif
	    num == 0 puts "#{num} is zero"
	elsif num > 0
	   puts "#{num} is positive"
	end


	if num < 0
		puts "#{num} < 0"
	else
		puts "#{num} > 0"
	end

	case domain
	    when "us"
		puts "United States"
	    when "de"
		puts "Germany"
	    when "no"
		puts "Norway"
	    when "hu"
		puts "Hungary"
	    else
		puts "Unknown"
	end

	while i < 10  do
		...
	end
	# từ khóa do là tùy chọn, không có cũng được.


	until hours_left == 0
	    if hours_left == 1
		puts "#{hours_left} hour left"
	    else
		puts " #{hours_left} hours left"
	    end
	    hours_left -= 1
	end
	# thực thi nếu giá trị sau until bằng false

	for i in 0..9 do
	    puts "#{i}"
	end

	planets.each do |iter|
	    puts iter
	end

12.	Tập hợp.
	Tập hợp cũng là một danh sách các phần tử nhưng các phần tử không được phép trùng nhau.

14. Module

	Một module là một tập các phương thức, lớp, hằng số, do đó module cũng gần giống như lớp vậy, chỉ khác là module không thể tạo các đối tượng và không thể thừa kế.

	Thường thì chúng ta sẽ gộp các lớp, phương thức và hằng số có liên quan với nhau vào một module để tránh xung đột tên. Nếu bạn đã từng làm việc với C# và Java thì có thể nói module trong Ruby tương đương với namespace trong C# và package trong Java vậy.

	module Forest
    class Rock ; end
    class Trê ; end
    class Animal ; end
   end

	module Town
		class Pool ; end
		class Cinema ; end
		class Square ; end
		class Animal ; end
	end

	p Forest::Tree.new
	p Forest::Rock.new
	p Town::Cinema.new
	p Forest::Animal.new
	p Town::Animal.new

	include Forest

15. Lỗi
	Trong lập trình:
		Lỗi biên dịch
		Lỗi ngữ nghĩa
		Lỗi exception - lỗi ngoại lệ (Lỗi xảy ra trong quá trình chạy chương trình: run time error)

	age = 17
	begin
	    if age < 18
		raise "Under 18 is not allowed"
	    end
	    puts "Allowed"
	rescue => e
	    puts e
	    p e
	ensure
	    exit 0
	end

16. Quyền truy cập

Quyền truy cập tức là phạm vi truy xuất các thuộc tính và phương thức của mỗi đối tượng. Ruby có 3 loại quyền truy cập là public, protected và private. Trong Ruby, tất cả các thuộc tính đều có quyền truy cập là private và không thể thay đổi được, còn các phương thức thì mặc định có quyền truy cập là public nhưng có thể thay đổi được.

Phương thức protected khác private ở chỗ là chúng có thể truy cập với từ khóa self, giống private ở chỗ là không thể truy cập được ở bên ngoài phần định nghĩa lớp.

#### 17. Range

A Range represents an interval—a set of values with a beginning and an end

Ranges can be constructed using any objects that can be compared using the <=> operator

1. Public Class Methods

		a = Range.new(begin,end,exclude_end=false)

		a = Range.new(1,4) #=> [1, 2, 3, 4]

		If exclude_end=false, result include end

2. Public Instance Methods

		(-1..-5).to_a      #=> []

		(-5..-1).to_a      #=> [-5, -4, -3, -2, -1]

		('a'..'e').to_a    #=> ["a", "b", "c", "d", "e"]

		('a'...'e').to_a   #=> ["a", "b", "c", "d"]

---------------------------------

		(1..5).each do |i|

			puts "#{i}, "

		end

---------------------------------

		(0..2) == (0..2)            #=> true

		(0..2) == Range.new(0,2)    #=> true

		(0..2) == (0...2)           #=> false [0,1,2] # [0,1]

---------------------------------

		case 79

		when 1..50   then   print "low\n"

		when 51..75  then   print "medium\n"

		when 76..100 then   print "high\n"

		end # => high

---------------------------------

		(1..10).begin   #=> 1

		range = [2, 3, 4, 5, 6, 7]

		range.min #2

		range.max #7

		range.include? 3 # true

		range.include? 10 # false

		include?(obj) → true or false

		("a".."z").include?("g")   #=> true

		("a".."z").include?("A")   #=> false

		("a".."z").include?("cc")  #=> false

		last(n) → an_array

		a.last(2) #=> [3, 4]

		a.size => 4


#### 18. Block Proc lambda

1. Block

	+ Tập hợp các câu lệnh thành 1 khối
	+ Được đặt trong dấu {} hoặc do ... end
	+ Phổ biến và dễ dùng hơn lambda và proc.

	  [1,2,3].each { |x|
	    	puts "Number: "
	    	puts x
	    }

	  [1,2,3].each do |x|
	    	puts "Number: "
	    	puts x
	  end

	  Number:
	  1
	  Number:
	  2
	  Number:
	  3
	   => [1, 2, 3]

	Cách truyền trực tiếp.
	Làm thế nào để ruby nhận biết block có sẵn => yield.
	Khi bạn sử dụng yield, mã bên trong khối sẽ được thực hiện.

```
def print_once
  yield
end

print_once { puts "Block is being run" }

#Block is being run
 => nil
```

```
def one_two_three
  yield 1
  yield 2
  yield 3
end

one_two_three { |number| puts number * 10 }
# 10, 20, 30
 => nil
```

```
def do_something_with_block
  yield
end

def do_something_with_block
	return "No block given" unless block_given?
  yield
end
```

2. Proc

  + Block: thay đổi đầu vào thì cần viết lại toàn bộ code.
  Ý tưởng: Đặt tên cho block. khi nào cần thì gọi => Proc

  proc = Proc.new {|x|
    puts "Number: "
    puts x
  }             // p chính là tên của block cần sử dụng

	  [1,2,3].each(&proc)
	  Number:
	  1
	  Number:
	  2
	  Number:
	  3
	   => [1, 2, 3]

	Kí hiệu & để hiểu tham số truyền vào là 1 proc.
	Bản chất chuyển symbol thành một proc object, truyền vào như 1 block.
	Proc chính là 1 object.

  proc.call(1)  # Các câu lệnh trong đối tượng Proc sẽ được thực hiện khi gọi
  Number:
  1
  => nil

  proc.call()

  proc.call

  Number:

   => nil


&proc ? yield
&proc đặt tên + khởi tạo đối tượng -> Chậm hơn yield

3. Lambda

		def proc_method
		    proc = Proc.new { return 1 + 1 }
		    proc.call

		    return 2 + 2
		  end

		  def lambda_method
		    lam = lambda { return 1 + 1 }
		    lam.call

		    return 2 + 2
		  end

		  // call proc and lambda method

		  proc_method #=> 2
		  lambda_method #=> 4


	Proc: ngay sau khi gặp chỉ lệnh return, giá trị sẽ lặp tức trả về;

	Lambda, sau khi nhận chỉ lệnh "return 1 + 1" biểu thức lambda vẫn tiếp tục thực hiện các biểu thức đến cuối cùng nhận được chỉ lệnh "return 2 + 2".




  Có 2 cách khai báo đối tượng proc
  proc = Proc.new { puts "Hello world" }

  another_proc = proc { puts "Hello world" } #<Proc:0x007fd7ba81bbb0@(pry):4>

  Khai báo lambda
  lam = lambda { puts "Hello world" } #<Proc:0x007fd7ba202b20@(pry):5 (lambda)>

	Lambda kiểm tra số lượng tham số đầu vào
	-> trả về một ArgumentError nếu số lượng truyền vào không đúng

	Proc thì không kiểm tra số lượng tham số đầu vào và mặc định tham số đó là nil

