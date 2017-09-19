Linux terminal:

```
select version();

mysql --user=root --password=root
Ex: mysql -u root -proot -e "create database fg"
mysql -u root -proot fg

show databases;

use <database_name>

select database();

show tables;

show columns from <table_name>;

Rails:
	rake db:drop
	rails db:create
	rails db:migrate
	rails db:reset
```

1. Select
	+ select: Used to select data from database.
	The data returned is stored in a result table.
	The data returned is stored in a result table, called the result-set.

	+ distinct: used to return only distinct (diffrent) values.
	```
	select distinct country from customers;
	select count (distinct country) from customers;
	```

	+ where:
	```
	select * from User where Class = "1";
	select * from Customers where Country="Germany" and City="Berlin"
	```

	+ not
	```
	select * from Customers
	where not Country="Germany" and not city="Berlin";
	```

	+ order
	```
	select * from Customers
	order by CustomersID DESC, CustomerName ASC
	DESC: Giam (Default)
	ASC: Tang
	```

	+ insert into
	```
	insert into Customers (ContactName, Address)
	values ("Hoan", "Ha Noi")
	```

1. Don’t begin with an L . To do this, type:
	mysql> SELECT album_name FROM album WHERE album_name NOT LIKE "L%";

2. Names end in “es” or start with “The,” but not both. You’d need to type:
	mysql> SELECT artist_name FROM artist WHERE
		-> artist_name LIKE "The%" XOR
		-> artist_name LIKE "%es";

3. Order by
	SELECT * FROM artist ORDER BY artist_name;

4.
	SELECT time, track_name FROM track
		-> WHERE time < 3.6
		-> ORDER BY time DESC, track_name ASC;

5.
	SELECT track_name FROM track WHERE track_name < 'b';

6.
	SELECT time, track_name FROM track ORDER BY CAST(time AS CHAR);

7.
	SELECT track_name FROM track LIMIT 10;

8.
	SELECT album_name, track_name FROM album INNER JOIN track
		-> USING (artist_id, album_id) LIMIT 15;

9.
	mysql> SELECT SUM(time) FROM
		-> album INNER JOIN track USING (artist_id, album_id)
		-> WHERE album.artist_id = 1 AND album.album_id = 7;

10.
	SELECT MAX(artist_id) FROM artist;

11.
	INSERT INTO artist
		VALUES((SELECT 1+MAX(artist_id) FROM artist), "Barry Adamson");

12.
	DELETE FROM played WHERE played < "2006-08-15";

13.
	UPDATE artist SET artist_name = UPPER(artist_name);
	update artist set artist_name = UPPER(artist_name);

14.	INNER JOIN tạo một bảng kết quả mới bằng việc kết hợp các giá trị cột của hai bảng (bang1 và bang2) dựa trên join-predicate. Truy vấn này so sánh mỗi hàng trong bang1 với mỗi hàng trong bang2 để tìm ra các cặp hàng mà thỏa mãn join-predicate. Khi join-predicate được thỏa mãn, các giá trị cột của mỗi cặp hàng được kết nối A và B được kết hợp vào trong một hàng kết quả.

	SELECT  ID, TEN, SOTIEN, NGAY
	     FROM SINHVIEN
	     INNER JOIN MUONSACH
	     ON SINHVIEN.ID = MUONSACH.SINHVIEN_ID;
15.
	CREATE DATABASE IF NOT EXISTS lucy;

16:
	CREATE DATABASE IF NOT EXISTS lucy;


	CREATE TABLE shuffle (
		-> artist_id SMALLINT(5) NOT NULL DEFAULT 0,
		-> album_id SMALLINT(4) NOT NULL DEFAULT 0,
		-> track_id SMALLINT(3) NOT NULL DEFAULT 0,
		-> sequence_id SMALLINT(3) AUTO_INCREMENT NOT NULL,
		-> PRIMARY KEY (sequence_id));



17:

	mysql>
	CREATE TABLE artist (
		artist_id SMALLINT(5) NOT NULL DEFAULT 0,
		artist_name CHAR(128) DEFAULT NULL,
		PRIMARY KEY (artist_id)
		);



19.
	SELECT artist_name FROM
	artist INNER JOIN album USING (artist_id)
	ORDER BY artist_name;

20. 	Xắp xếp kết quả:
	SELECT MaSV, TenSV, NamSinh
		FROM SINHVIEN
		ORDER BY MaSV ASC, NamSinh DESC

21.	Kết hợp nhiều kết quả của hai lệnh select.
	SELECT cot1 [, cot2 ]
	FROM bang1 [, bang2 ]
	[WHERE dieu_kien]

	UNION ALL

	SELECT cot1 [, cot2 ]
	FROM bang1 [, bang2 ]
	[WHERE dieu_kien]

22.	Liên kết 2 bảng trong csdl

23.	Rails: belong to, have many => Chuyện gì xảy ra.
	Include trong SQL


