Help for Git
============


1. Install on Linux

`sudo apt-get install git-all`

if error

`sudo apt-get purge runit`

`sudo apt-get purge git-all`

`sudo apt-get purge git`

`sudo apt-get autoremove`

`sudo apt update`

`sudo apt install git`


2. Delete n last commit

`git reset HEAD~n`

`git push -f origin master`


3. User and email

`git config --global user.name "Your Name"`

`git config --global user.email "youremail@domain.com"`


4. Remember password

`use SSH Key`


5. Show graph

Graph: `git log --graph --oneline`

Online: `git log --online`

6. Gộp n commit thành 1 commit

`git rebase -i HEAD~n`

Thay những chữ `pick` cuối cùng bằng `f` 

7. Delete branch

Local:
`git branch -d <branch_name>`

Remote:
`git push origin --delete <branch_name>`

8. Khôi phục bằng reflog 

Xem lịch sử `git reflog`
 
Quay lại sau khi "nhỡ tay": `git reset --hard HEAD~ <id of commit>`


Mỗi tập tin trong thư mục làm việc của bạn có thể ở một trong hai trạng thái 

tracked (đã theo dõi)
untrachked. (chưa theo dõi), sau lệnh add sẽ thành tracked.

Tập tin tracked là các tập tin đã có mặt trong ảnh (snapshot) trước; chúng có thể là 
unmodified, (chưa thay đổi)
modified, (đã thay đổi)
staged. (đã tổ chức)

Tập tin untracked là các tập tin còn lại - bất kỳ tập tin nào trong thư mục làm việc của bạn mà không có ở ảnh (lần commit) trước hoặc không ở trong khu vực tổ chức (staging area). 

Ban đầu, khi bạn tạo bản sao của một kho chứa, tất cả tập tin ở trạng thái "đã được theo dõi" (tracked) và "chưa thay đổi" (unmodified) vì bạn vừa mới tải chúng về và chưa thực hiện bất kỳ thay đổi nào.

Khi bạn chỉnh sửa các tập tin, Git coi là chúng đã bị thay đổi so với lần commit trước đó. Bạn stage các tập tin bị thay đổi này và sau đó commit tất cả các thay đổi đã được staged (tổ chức) đó, và quá trình này cứ thế lặp đi lặp lại như được miêu tả trong Hình 2-1.


0. Tham số
	-f: fouce: Đè lên

1.Log:
	git log --graph --oneline: Hiển thị nhật kí trên 1 dòng
	git reflog: Nhật kí thao tác
	gitk: View trực quan.


2.Status:
	git status:	Kiểm Tra Trạng Thái Của Tập Tin


3.Add 
	git add README:	Theo Dõi Các Tập Tin Mới
	

4.ignore
	# a comment - dòng này được bỏ qua
	# không theo dõi tập tin có đuôi .a 
	*.a
	# nhưng theo dõi tập lib.a, mặc dù bạn đang bỏ qua tất cả tập tin .a ở trên
	!lib.a
	# chỉ bỏ qua tập TODO ở thư mục gốc, chứ không phải ở các thư mục con subdir/TODO
	/TODO
	# bỏ qua tất cả tập tin trong thư mục build/
	build/
	# bỏ qua doc/notes.txt, không phải doc/server/arch.txt
	doc/*.txt
	# bỏ qua tất cả tập .txt trong thư mục doc/
	doc/**/*.txt

5. diff

	git diff: Hiển thị thay đổi của những file chưa add.
	git diff --staged: Hiển thị thay đổi của những file đã add.

6. rm
	git rm filename: Xóa file khỏi stage và xóa khỏi thư mục.
	git rm --cached filename: Chỉ xóa file khỏi stage

7. commit
	git commit --amend

8. remote
	1. git remote / git remote -v: Hiển thị máy chủ
	
	res:
	defunkt   git://github.com/defunkt/grit.git
	koke      git://github.com/koke/grit.git
	origin    git@github.com:mojombo/grit.git (Duy nhất cái này có ssh để push lên)

	2. git remote add [shortname] [url]:

	3. git remote show [tên máy chủ trung tâm]

	4. git remote rename [oldName] [newName]



9. fetch

	git fetch [remote name]: Kéo toàn bộ dữ liệu mà bạn chưa có từ kho máy chủ remote name.

10. push

	git push [tên máy chủ] [tên nhánh]

	work1 của kho local vào nhánh develop của kho truy cập từ xa origin
	git push origin work1:develop

11. tag (lightweight và annotated)

	1.
	git tag : Liệt kê tất cả các tag
	git tag -l 'v1.4.2.*'

	2.
	git tag -a v1.5 -m 'my signed 1.5 tag' (annotated)
	git tag -s v1.5 -m 'my signed 1.5 tag' (lightweight)

	3.
	git show v1.5: Detail of tag.

	4.
	git push origin v1.5
	git push origin --tags



12. branch
	1.Define
	Một nhánh trong Git là một con trỏ có khả năng di chuyển được, trỏ đến một trong những commit này.

	2.git branch testing: 
	Tạo ra con trỏ testing

	3. HEAD là tệp trỏ tới điểm đầu của branch đang làm việc.

	3.1: Stage

	3.2: Stash

	4. git checkout testing: Chuyển tới HEAD trỏ tới branch testing.

	5. Ưu điểm của branch git:
	Bởi vì một nhánh trong Git thực tế là một tập tin đơn giản chứa một mã băm SHA-1 có độ dài 40 ký tự của commit mà nó trỏ tới, chính vì thế tạo mới cũng như hủy các nhánh đi rất đơn giản. Tạo mới một nhánh nhanh tương đương với việc ghi 41 bytes vào một tập tin (40 ký tự cộng thêm một dòng mới). Ưu thế hơn sơ với VCS khác rất nhiều.

	6. git checkout -b newbranch: Tạo mới và chuyển sang branch newbranch

	7. 
		Cần checkout sang branch khác.
		git branch -d branchname: Xóa branch đã merge
		git branch -D branchname: Xóa branch chưa merge, chấp nhận mất code.				

	8. git branch / git branch --merged: Liệt kê
	

13. Megre 

	1. git checkout master
	git merge hotfix

	2. Auto merge failed
		<<<<<< [branch][file]
		// content
		=================
		// conten
		[branch][file]>>>>>>>
	Giải quyết: 
		Sửa file
		git add cho từng file
		git status để kiểm tra xem còn file nào chưa giải quyết
		git commit

14: Rebase
	Merge bằng rebase:
	git checkout issue3
	git rebase master

	Đứng ở master, rebase other branch

14. Diff
	Sự khác biệt
	HEAD và stage: git diff --stage
	Nhánh đang làm việc và stage: git diff STAGE
	Nhánh đang làm việc và HEAD: git diff HEAD

14. Nhánh Remote

	Nhánh từ xa (remote) là các tham chiếu tới trạng thái của các nhánh trên kho chứa trung tâm của bạn.	
	(remote)/(branch): Nhánh từ xa (remote) là các tham chiếu tới trạng thái của các nhánh trên kho chứa trung tâm của bạn.
	
15.	Reset about commit
	git reset --hard 4a155e5
