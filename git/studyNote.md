# git 上传克隆流程

## 1 git clone到本地

```
# 查看本地是否配置公私密钥
$ ls -al ~/.ssh

# 如果表示本地没有密钥，或者.ssh目录下没有id_rsa和id_rsa.pub文件，则输入下面命令生成密钥
$ ssh-keygen -t rsa -C "your_email@email.com"

# 再将公钥输入到github里，参考其他博客

# 进行ssh测试
$ ssh -T git@github.com

# 如果报错Connection timed out，可能因为github.com那边无法将github.com自动转换为ssh.github.com,需添加config文件(如下)
Host github.com
User git
Hostname ssh.github.com
PreferredAuthentications publickey
IdentityFile ~/.ssh/id_rsa
Port 443

# git clone ssh仓库地址
```

![image-20240119133056223](https://raw.githubusercontent.com/mulin33/ImageHost/main/blogImg/image-20240119133056223.png)

## 2 git上传到本地仓库

![Lightbox](https://raw.githubusercontent.com/mulin33/ImageHost/main/blogImg/gitindex.png)

```
## 以下上传步骤前提是ssh已经配置好
# 查看当前仓库状态（显示待提交信息）
git status

# 将本地文件添加到缓存区(.表示所有文件)
git add 文件夹/.

# 将缓存区文件提交到本地仓库
git commit -m "注释"

# 先把远程仓库拉到本地仓库，查看本地仓库远程仓库提交内容是否矛盾，为了确保两种情况:
#1.A和B完成内容不同，更新B提交的内容到本地仓库
#2.A和B完成内容相同，commit就会冲突，然后会报错提示你保留哪部分
git pull origin main

# 把本地仓库内容推到远程仓库
git push origin main
```



