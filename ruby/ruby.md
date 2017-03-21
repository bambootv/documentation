1. 	p = puts = print + "\n"
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

2. Biến
	car_name = "Peugeot": biến cục bộ: từng phương thức, lớp… nhất định.
	$car_name = "Peugeot": biến toàn cục, biến toàn cục có hiệu lực trong toàn bộ code Ruby.
	@sea_name = "Black sea": biến instance, biến này chỉ có hiệu lực trong một đối tượng.
	@@species = "Cat": biến class, mọi đối tượng của một class đều có thể truy xuất biến này.


	p local_variables.include? :$car_name
	p global_variables.include? :$car_name

	self <=> this.

	Biến instance là biến nằm trong một đối tượng cụ thể. Mỗi đối tượng có những biến instance riêng của chúng, biến instance có tên bắt đầu bằng kí tự @.

	Biến class là biến nằm trong một lớp. Những đối tượng được tạo ra từ lớp đó sẽ dùng chung biến class, biến class có tên bắt đầu bằng kí tự @@.

3. 	Đối tượng
	Một đối tượng chứa thuộc tính và phương thức bên trong nó. Thuộc tính là dữ liệu của đối tượng, đây là thành phần tĩnh, phương thức là phần động. Đối tượng có thể được chỉnh sửa hoặc giao tiếp với các đối tượng khác thông qua phương thức.

	Kernel.puts "Ruby language".size

	s = String.new "Hello world"
	puts s

	p 6.object_id

	p 6.even?

	p 6.zero?

	p 6.is_a? Object => Đối tượng 6 có được kế thừa từ đối tượng Object không ?

	Kernel.puts self => main

	p self.class => Object

	p "Jane".methods.size => Kích thước

	puts nil => Rỗng
	
	p nil => nil

	
	per = Person.new "Jane" 
	puts per.get_name
	puts per.send :get_name

	Human.ancestor => Danh sách các lớp cơ sở.

	supe => gọi super trong phương thức show ở lớp con sẽ gọi đến phương thức show ở lớp cha

	class Car
	    attr_reader :name, :price
	    attr_writer :name, :price
	# hoặc attr_accessor :name, :price
	    def to_s
		"#{@name}: #{@price}"
	    end
	end
	c1 = Car.new
	c1.name = "Porsche"
	c1.price = 23500

	def +(other)
	    Circle.new @radius + other.radius
	end
	# Định nghĩa lại phép cộng

	def self.info
    "This is a Circle class"
	end

	Phương thức class được định nghĩa bằng cách thêm từ khóa self vào trước tên phương thức.
	def area
	    "Circle, radius: #{@r}"
	end
	Phương thức area là phương thức instance vì không chứa từ khóa self, vậy tức là các phương thức mà chúng ta đã định nghĩa từ trước tới giờ đều là phương thức instance.

	p Circle.info
	Để gọi phương thức class thì chúng ta gọi từ tên lớp chứ không gọi từ tên đối tượng.

	c = Circle.new 3
	p c.area
	Để gọi phương thức instance thì chúng ta phải tạo một đối tượng rồi gọi từ tên đối tượng đó như trước giờ chúng ta vẫn làm. Ở đoạn code trên chúng ta tạo một đối tượng Circle có tên là c và gọi phương thức instance area của đối tượng đó.

4.	include? Có thuộc hay ko ?

5.	Kiểu
	:name => Symbol

	 Dùng symbol sẽ tiết kiệm được nhiều tài nguyên hơn so với dùng biến thông thường. Tất cả các biến symbol đều là một đối tượng từ lớp Symbol. 		Để định nghĩa một symbol thì chúng ta thêm dấu hai chấm ":" vào trước giá trị, ví dụ :name. Hầu hết các đối tượng trong Ruby đều có phương thức to_sym để chuyển một đối tượng thành một symbol.
	Symbol không thể thay đổi được giá trị. Thường thì symbol được dùng để làm khóa trong bảng băm.


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


9.	String

	msg = "Ruby language"

	puts msg["Ruby"]
	puts msg["Python"]
 
	puts msg[0]
	puts msg[-1] => Kí tự cuối cùng.
	 
	puts msg[0, 3]
	puts msg[0..9]
	puts msg[0, msg.length]


	name = "Hoan" + "Ki"
	name = "Hoan" "Ki"
	name = "Hoan" << "Ki"
 	name = "Hoan".concat("Ki")

	aa == ab
	aa.eql?ab

	aa <==> ab  => trả về -1,0,1

	ruby = "Ruby"
	ruby.upcase
	ruby.downcase
	ruby.capitalize
	ruby.swapcase
	ruby.start_with? "ruby"
	ruby.end_with? "ruby"

	"There are %.5f oranges and %d apples in the basket." % [12, 10]
 
	puts "%10d" % 1
	puts "%10d" % 12
	puts "%10d" % 123

10. Biểu thức:

	
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

14. Module

	Một module là một tập các phương thức, lớp, hằng số, do đó module cũng gần giống như lớp vậy, chỉ khác là module không thể tạo các đối tượng và không thể thừa kế.

	module Forest  
	    class Rock ; end
	    class Tree ; end
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
	Trong lập trình:	Lỗi biên dịch
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
