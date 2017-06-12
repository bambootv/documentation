Help for Git
============


**1. Install on Linux**

`sudo apt-get install git-all`

if error

`sudo apt-get purge runit`

`sudo apt-get purge git-all`

`sudo apt-get purge git`

`sudo apt-get autoremove`

`sudo apt update`

`sudo apt install git`


**2. Delete n last commit**

`git reset HEAD~n`

`git push -f origin master`


**3. User and email**

`git config --global user.name "Your Name"`

`git config --global user.email "youremail@domain.com"`


**4. Remember password**

`use SSH Key`


**5. Show graph**

Graph: `git log --graph --oneline`

Online: `git log --oneline`

**6. Gộp n commit thành 1 commit**

`git rebase -i HEAD~n`

Thay những chữ `pick` cuối cùng bằng `f`

**7. Delete branch**

Local:

`git branch -d <branch_name>`

Remote:

`git push origin --delete <branch_name>`

**8. Khôi phục bằng reflog**

Xem lịch sử `git reflog`

Quay lại sau khi "nhỡ tay": `git reset <id of commit>`

Quay lại sau khi "nhỡ tay": `git reset --hard <id of commit>` (mất code)

**9. Tham số**

	-f: fouce: Đè lên

**10. Log:**

	`git reflog`: Nhật kí thao tác
	`gitk`: View trực quan.

**11. Status:**

	`gst` / `git status`:	Kiểm Tra Trạng Thái Của Tập Tin

**12. Add**

	`git add <file_name>`:	Theo Dõi Các Tập Tin Mới


**13. Ignore**

	`# a comment: dòng này được bỏ qua`

	`# *.a: không theo dõi tập tin có đuôi .a`

	`!lib.a: nhưng theo dõi tập lib.a, mặc dù bạn đang bỏ qua tất cả tập tin .a ở trên
	`

	`/TODO: chỉ bỏ qua tập TODO ở thư mục gốc, chứ không phải ở các thư mục con subdir/TODO`

	`build/: bỏ qua tất cả tập tin trong thư mục build/`

	`doc/*.txt: Bỏ qua doc/notes.txt, không phải doc/server/arch.txt`

	`doc/**/*.txt: bỏ qua tất cả tập .txt trong thư mục doc/`


**14. Diffrent**

	`git diff: Hiển thị thay đổi của những file chưa add.`
	`git diff --staged: Hiển thị thay đổi của những file đã add.`

**15. Rm**

	`git rm filename: Xóa file khỏi stage và xóa khỏi thư mục.`

	`git rm --cached filename: Chỉ xóa file khỏi stage`

	`rm -rf filename: xóa cả file lẫn thư mục`

**16. Commit**

	``git commit --amend``

**17. Remote**

	1. git remote / git remote -v: Hiển thị máy chủ

	res:
	defunkt   git://github.com/defunkt/grit.git
	koke      git://github.com/koke/grit.git
	origin    git@github.com:mojombo/grit.git (Duy nhất cái này có ssh để push lên)

	2. git remote add [shortname] [url]:

	3. git remote show [tên máy chủ trung tâm]

	4. git remote rename [oldName] [newName]


**18. Fetch**

	``git fetch [remote name]: Kéo toàn bộ dữ liệu mà bạn chưa có từ kho máy chủ remote name.``

**19. Push**

	``git push [tên máy chủ] [tên nhánh]``

	``Example: git push origin work1:develop `` :
	work1 của kho local vào nhánh develop của kho truy cập từ xa origin


**20. Tag (lightweight và annotated)**

	1.
	``git tag : Liệt kê tất cả các tag``
	``git tag -l 'v1.4.2.*'``

	2.
	``git tag -a v1.5 -m 'my signed 1.5 tag' (annotated)``
	``git tag -s v1.5 -m 'my signed 1.5 tag' (lightweight)``

	3.
	git show v1.5: Detail of tag.

	4.
	git push origin v1.5
	git push origin --tags



**21. Branch**

	1.git branch testing:
	Tạo ra con trỏ testing

	2. HEAD là tệp trỏ tới điểm đầu của branch đang làm việc.

		2.1: Stage

		2.2: Stash

	3. git checkout testing: Chuyển tới HEAD trỏ tới branch testing.

	4. git checkout -b newbranch: Tạo mới và chuyển sang branch newbranch

	5.
		Cần checkout sang branch khác.
		git branch -d branchname: Xóa branch đã merge
		git branch -D branchname: Xóa branch chưa merge, chấp nhận mất code.

	6. git branch / git branch --merged: Liệt kê


**22. Megre**

	1. git checkout master
	git merge hotfix

	2. Auto merge failed
		<<<<<< [branch][file]
		// content
		=================
		// conten
		[branch][file]>>>>>>>
	Giải quyết:
		B1: Mở IDE
		B2: Tìm "<<<"
		B3: Sửa file
		B4: Sau khi sửa hết, tìm kiếm lại "<<<"
		B5: git add .
		B6: git rebase --continue
				Nếu còn conflic thì fix tiếp
		B7: git push
		B8: Lên github kiểm tra cho chắc :D Ahihi

**23: Rebase**

	Merge bằng rebase:
	git checkout issue3
	git rebase master
	git rebase develop

14. Diff
	Sự khác biệt
	HEAD và stage: git diff --stage
	Nhánh đang làm việc và stage: git diff STAGE
	Nhánh đang làm việc và HEAD: git diff HEAD

14. Nhánh Remote

	Nhánh từ xa (remote) là các tham chiếu tới trạng thái của các nhánh trên kho chứa trung tâm của bạn.
	(remote)/(branch): Nhánh từ xa (remote) là các tham chiếu tới trạng thái của các nhánh trên kho chứa trung tâm của bạn.

15.	Reset about commit
	git reset 4a155e5

16.	Rm
	git rm -f <file_name>

17. Commit vào commit cuối cùng
	` git commit --amend `
	Không chỉnh sửa:  ` git commit --amend --no-edit`

18. Sửa nội dung commit
	` git commit --amend `

19. Xem commit mới nhất trên từng nhánh
	`git branch -v`

20. Xóa commit giữ lại code
	`git reset --soft HEAD~1`

21. Fllow in framgia
	`checkout dev -> pull dev -> checkout newbr -> rebase -> git add . -> rebase --c`
	
22. Rename branch
	`git branch -m old_branch new_branch         # Rename branch locally`
	`git push origin :old_branch                 # Delete the old branch`
	`git push --set-upstream origin new_branch`
