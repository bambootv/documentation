Mỗi tập tin trong thư mục làm việc của bạn có thể ở một trong hai trạng thái

tracked (đã theo dõi)
untrachked. (chưa theo dõi), sau lệnh add sẽ thành tracked.

Tập tin tracked là các tập tin đã có mặt trong ảnh (snapshot) trước; chúng có thể là
unmodified, (chưa thay đổi)
modified, (đã thay đổi)
staged. (đã tổ chức)

Tập tin untracked là các tập tin còn lại - bất kỳ tập tin nào trong thư mục làm việc của bạn mà không có ở ảnh (lần commit) trước hoặc không ở trong khu vực tổ chức (staging area).

Ban đầu, khi bạn tạo bản sao của một kho chứa, tất cả tập tin ở trạng thái "đã được theo dõi" (tracked) và "chưa thay đổi" (unmodified) vì bạn vừa mới tải chúng về và chưa thực hiện bất kỳ thay đổi nào.

Khi bạn chỉnh sửa các tập tin, Git coi là chúng đã bị thay đổi so với lần commit trước đó. Bạn stage các tập tin bị thay đổi này và sau đó commit tất cả các thay đổi đã được staged (tổ chức) đó, và quá trình này cứ thế lặp đi lặp lại.

**Branch&&
1.Define
  Một nhánh trong Git là một con trỏ có khả năng di chuyển được, trỏ đến một trong những commit này.

2. Ưu điểm của branch git:
  Bởi vì một nhánh trong Git thực tế là một tập tin đơn giản chứa một mã băm SHA-1 có độ dài 40 ký tự của commit mà nó trỏ tới, chính vì thế tạo mới cũng như hủy các nhánh đi rất đơn giản. Tạo mới một nhánh nhanh tương đương với việc ghi 41 bytes vào một tập tin (40 ký tự cộng thêm một dòng mới). Ưu thế hơn sơ với VCS khác rất nhiều.
