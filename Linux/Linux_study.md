# Linux_study

## 1 简介

目前**电脑端**操作系统：

* Windows
* Linux
* macOS

**手机端**操作系统

* Android
* IOS（苹果）
* HarmonyOS

**Linux发行版**

* 内核（**免费开源**）提供了Linux系统主要功能，如硬件调度管理的能力

* 内核无法被用户直接使用，需要配合使用应用程序才能被用户使用
* 在内核之上，封装系统级**应用程序**，组合在一起称为**Linux发行版**（如：ubuntu,centOS等）

**FinnalShell**软件

* 操作Linux系统中间跨越VMware窗口，会导致交互不太方便
* 我们只需要使用命令行无需使用图形化，所以通过命令行远程连接使用即可

**Linux目录**

* Linux没有盘符这一概念(如Windows的C盘，D盘等，每个盘符形成一个树)
* 只有一个根目录/，所有文件都在它下面(只有一个树)
* Windows路径：`D:\data\hello.txt`（其中`D:`表示D盘，`\`表示层级关系）
* Linux路径：`/usr/hello.txt`（其中`开头的/`表示根目录，`后面的/`表示层级关系）

**Linux路径**

绝对路径和相对路径省略

特殊路径符：

* `.`表示当前目录，`cd ./Desktop`=`cd Desktop`
* `..`表示上一级目录，回到上一目录`cd ..`，回到上两级目录`cd ../..`
* `~`表示用户的home目录，`cd ~`

## 2 命令

格式：`command [-options] [parameter]`

home目录：每一个用户在Linux的专属目录，其路径是`/home/用户名`

根目录查看:other locations->Computer

管道符`|`：将管道符左边命令的结果，作为右边命令的输入

反引号`：被`包围的内容，会作为命令被执行，而非普通字符(如下:echo `pwd`会执行pwd命令)

重定向符`>`：将左侧命令的结果，覆盖写入到符号右侧指定的文件中

重定向符`>>`：将左侧命令的结果，追加写入到符号右侧指定的文件中

1. **ls** -alh [路径]
2. **pwd**
3. **cd** [路径/无参数表示切换到home下]
4. **mkdir** [-p] Linux路径
5. **touch** Linux路径
6. **cat**/**more** Linux路径
7. **cp** [-r用于文件夹]  from路径  to路径
8. **mv**  from路径  to路径
9. **rm**  [-r 文件夹删除  -f 强制删除,用于root用户]  参数1  参数2  ......(支持通配符*)
10. **which**  要查找的命令(如cat等)
11. **find**  起始路径  -name  "文件名"   or    **find**  起始路径  -size  +/-n[k/M/G]（如+1G 表示找到超过1G的文件）
12. **grep**  [-n匹配行号]  "关键字" 文件路径
13. **wc**  [-c字节数 -m字符数 -l行数 -w单词数]  文件路径(可通过管道符输入)
14. **echo**

## 3 进阶

### 3.1 vi编辑器

vi/vim（visual interface），是Linux中最经典的文本编辑器，vim是vi的加强版

1. 命令模式（Command mode）——所敲的按键编辑器为命令，不能自由进行文本编辑
2. 输入模式（insert mode）——可以对文件内容进行自由编辑
3. 底线命令模式（last line mode）——以`:`开始，用于文件的保存、退出(:set nu 显示行号)

<img src="https://raw.githubusercontent.com/mulin33/ImageHost/main/blogImg/1.png" alt="1" style="zoom:80%;" />

### 3.2 Linux用户和权限

**root 用户（超级管理员）**

* 无论是Windows、MacOS、Linux均采用多用户的管理模式进行权限管理
* 在Linux系统中，拥有最大权限的账户名为：root（超级管理员）
* root用户拥有最大的系统操作权限，而普通用户在许多地方受限（一般在HOME目录内不受限，在HOME以外只有只读和执行，无修改权限）

**su(switch user)**

su  [-]  [用户名]

* `-`符号可选，表示在切换用户后加载环境变量，建议带上
* **exit**退回上一个用户

 **sudo  其他命令**

* 加上sudo，可为这一条命令临时赋予root授权
* 但并不是所有用户，都有权力使用sudo，需要为普通用户配置**sudo认证**

**sudo认证**

* 切换到root用户，通过vim编辑器打开:/etc/sudoers
* `用户名[mu] ALL=(ALL)    NOPASSWD:ALL`给用户[mu]添加root权限，且不需要密码
* `root    ALL=(ALL:ALL) ALL`给所有用户添加root权限，但需要密码

### 3.3 用户和用户组

原因：Linux可以对用户和用户组权限进行控制

**用户组命令**

* 需要root权限
* **groupadd  用户组名**——创建用户组
* **groupdel   用户组名**——删除用户组

**用户命令**

* 需要root权限
* **uesradd [-g -d -m] 用户名**——创建用户（-g 指定用户组,默认同名用户组 ，-d指定用户home路径,默认/home/用户名 ，-m选项同时创建家目录，否则su该新用户时会报错不能找到文件）
* **userdel [-r] 用户名**——删除用户（-r删除用户HOME目录）
* **id [用户名]**——查看用户组（不提供用户名查看自身）
* **usermod -aG  用户组  用户名**——将指定用户加入指定用户组

**其他相关**

* **getent passwd**——查看当前系统中有哪些用户，显示信息——用户名：密码(x)：用户ID：组ID：描述信息(无用)：HOEM目录：执行终端(默认bash)
* **getent group**——查看当前系统有哪些组，显示信息——组名称：组认真(x)：组ID

### 3.4 文件权限

使用ls -l命令后，第一列表示文件权限，第二列表示所属用户，第三列表示所属用户组

![image-20231228213804890](https://raw.githubusercontent.com/mulin33/ImageHost/main/blogImg/image-20231228213804890.png)

<img src="https://raw.githubusercontent.com/mulin33/ImageHost/main/blogImg/1.jpg" alt="1"  />

**chmod命令**

* 只有文件、文件夹的所属用户或root用户可以修改
* `chmod [-R]  权限  文件或文件夹`——修改文件权限（-R对文件夹内的全部内容应用同样的操作）
* **rwx**：r表示4，w表示2，x表示1，所以修改权限可以表示为`chmod 777 test.txt`即将test.txt权限都打开
