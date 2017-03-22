1. Empty Blank

`>> "".blank?
=> true`

`>> "      ".empty?
=> false

>> "      ".blank?
=> true

>> nil.blank?
=> true`

2. Controller

`rails generate controller Say home help about`

3. Demo class

`class User
  attr_accessor :name, :email

  def initialize (attributes = {})
    @name = attributes[:name]
    @email = attributes[:email]
  end

  def formated_email
    "#{@name} <#{@email}>"
  end
end`

`def formated_email
    "#{@name} <#{@email}>"
  end`

`ex = User.new(name: "A",email: "hoan@gmail.com")`
