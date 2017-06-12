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

