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

### 2.1 符号

格式：`command [-options] [parameter]`

home目录：每一个用户在Linux的专属目录，其路径是`/home/用户名`

根目录查看:other locations->Computer   

管道符`|`：将管道符左边命令的结果，作为右边命令的输入

反引号`：被`包围的内容，会作为命令被执行，而非普通字符(如下:echo `pwd`会执行pwd命令)

重定向符`>`：将左侧命令的结果，覆盖写入到符号右侧指定的文件中

重定向符`>>`：将左侧命令的结果，追加写入到符号右侧指定的文件中

飘号：不是单引号，被飘号包围的内容会作为命令执行，如`pwd`

### 2.2 命令

1. **ls** -alh [路径]
2. **pwd**
3. **cd** [路径/无参数表示切换到home下]
4. **mkdir** [-p 表示一次性创建多个不存在的目录] Linux路径 
5. **tree**  目录（查看目录结构，需要安装）  
6. **touch** Linux路径 （创建文件）
7. **cp** [-r用于文件夹]  from路径  to路径
8. **rm**  [-r 文件夹删除  -f 强制删除,用于root用户]  参数1  参数2  ......(支持通配符*)
9. **mv**  from路径  to路径   （可以移动或者**重命名**文件）
10. **man/help**  [命令]     （manual/help查看命令使用手册）
11. **reboot**    (重启Linux电脑)
12. 
13. **which**  要查找的命令(如cat等)
14. **find**  起始路径  -name  "文件名"   or    **find**  起始路径  -size  +/-n[k/M/G]（如+1G 表示找到超过1G的文件）
15. **grep**  [-n匹配行号]  "关键字" 文件路径  （使用案例参照 [端口](###4.4 端口)）
16. **wc**  [-c字节数 -m字符数 -l行数 -w单词数]  文件路径(可通过管道符输入)
17. **echo** "输出内容"   （用法：`echo "文字" >> 文件路径` 可实现把文字附加到文件里面）
18. **tail**  [-f 持续跟踪文件 -num 查看尾部多少行]  filename   (`tail -f filename` 可用于查看动态日志)

### 2.3 快捷键

ctrl+c：强制终止

ctrl+d：账户退出，退出特定程序(如python)专属页面

ctrl+a：跳到命令开头

ctrl+e：跳到命令结尾

ctrl+键盘左键：向左跳一个单词

ctrl+键盘右键：向右跳一个单词

ctrl+l(或clear命令)：清屏

## 3 进阶

**Linux下编辑器**：**vim**命令行编辑；**gedit**类似windows记事本编辑

### 3.1 vim编辑器

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

**chown命令**

* 只有root用户可以执行
* `chown [-R] [用户]:[用户组] 需修改文件或文件夹`——修改文件、文件夹的所属用户和用户组

## 4 实用

### 4.1 程序安装和软链接

操作系统安装软件包主要有两种：

* 安装包自行安装(Windows系统:exe文件、msi文件；Mac系统：dmg文件、pkg文件)
* 应用商店（windows系统：Microsoft Store；Mac系统：AppStore）

| Linux发行版本 | 应用商店名称 | 安装包后缀 |
| ------------- | ------------ | ---------- |
| CentOS        | yum          | .rpm       |
| Ubuntu        | apt          | .deb       |

------

```
# 对于Linux常见命令安装
# Ubuntu下载软件方法，需要root权限
apt [-y] [install | remove | search] 软件名称

# ubunut用命令行运行deb安装包
sudo dpkg -i xxxx.deb
# 卸载软件包
sudo dpkg -r xxxx
```



**软链接**

`ln -s 参数1(被链接的文件or文件夹)  参数2(链接目的地)`——作用等同快捷方式(-s symbolic link符号链接)

例：`ln -s /etc/apt ~/apt`会把根目录的apt文件在home目录以apt命名显示

### 4.2 IP地址和主机名

**IP地址**

每一台联网电脑都会有一个地址，用于和其他计算机进行通讯

* IP地址主要有2个版本，v4和v6版本（v6很少用）
* IPv4地址格式：`a.b.c.d`其中abcd表示0~255数字
* **ifconfig**可以查看IP地址

![image-20231229214147521](https://raw.githubusercontent.com/mulin33/ImageHost/main/blogImg/image-20231229214147521.png)

**特殊IP**

* **127.0.0.1**：用于指代本机，lo(loopback interface)本地回环接口
* **0.0.0.0** ： ①可用于指代本机；②在端口绑定中用来确定绑定关系；③在一些IP地址限制中，表示所有IP，表示允许任意IP访问

**主机**

每一台电脑除了对外联络地址(IP地址以外)，也可以有另外一个名字——主机名

* `hostname`——查询主机名
* `hostnamectl set-hostname 主机名`——修改主机名

**域名和DNS**

IP并不方便人类的记忆和书写，与网络上的数字型 IP 地址相对应的字符型地址，就是**域名**

**DNS：**当访问“www.fuyeor.com”时，首先由 **DNS（Domain Name System, DNS）**域名系统解析为 IP 地址，随后再访问 IP

**域名解析**

* 先看本机的记录（私人地址本）
  * windows：C:\Windows\System32\drivers\etc\hosts
  * Linux：/etc/hosts

* 再联网去DNS服务器(如114.114.114.114,8.8.8.8等)询问

### 4.3 网络相关命令

**ping**

`ping [-c num 检查的次数] ip或主机名`——检查特定的网络服务器是否是可联通状态

**wget**

`wget [-b 后台下载，日志写入到工作目录的wget-log文件] url`——非交互式的文件下载器，可以在命令行下载网络文件(如果要查看动态日志，可使用`tail -f wget-log`)

**curl**

`curl [-O 选项用于下载文件，保存文件] url` 用于下载文件、获取信息(类似浏览器，输入网址获得html源码)

例：`curl cip.cc`获得公网IP属地

### 4.4 端口

**端口**

计算机和外部交互的出入口，分为物理端口和虚拟端口

* 物理端口：USB、HDMI、DP等
* 虚拟端口：操作系统和外部交互的出入口(IP只能确定计算机，通过端口才能锁定要交互的程序)

![端口图释](https://raw.githubusercontent.com/mulin33/ImageHost/main/blogImg/image-20231230203832215.png)

**端口划分**

Linux支持65535（2^16）个端口

* 公认端口：1-1023，用于系统内置或知名软件绑定使用（如SSH服务22端口，HTTPS服务443端口）
* 注册端口：1024-49151（48*2^10），用于松散绑定使用（用户自定义）
* 动态端口：49152-65535，用于临时使用，多用于出口（比如A计算机接收计算机B返回的信息，临时开一个端口）

**端口命令**

* `nmap IP`（network mapper）查看指定IP的对外暴露端口(例：`namp 127.0.0.1`查看本机端口)
* `netstat -anp`显示端口使用情况（在需要查看具体端口时，可仿照 `netstat -anp | grep 22`）

### 4.5 进程

进程指程序在操作系统内运行后被注册为系统内的一个进程，并拥有独立的进程ID（进程号）

* `ps -ef` process status 查看进程信息，使用`ps -ef | grep 关键字`  筛选信息

![Linux ps命令解释](https://raw.githubusercontent.com/mulin33/ImageHost/main/blogImg/image-20231230213819622.png)

* kill [-9 强制关闭] 关闭指定进程号的进程 

### 4.6 环境变量



### 4.7 上传下载压缩工具



## 5 编程

###  5.1 gcc和gdb

**gcc：**gcc和g++是c/c++的linux系统集成的编译器，源文件的后缀应为 .C/.cpp/.c++/.cc等（实际使用中，gcc编译C,g++编译C++）

**gdb：**是 GNU 开发的一个Unix/Linux下强大的程序调试工具

```
# 下面命令同时安装编译器和调试器(gcc/g++/gdb)
sudo apt install build-essential gdb

# 检查是否安装成功
gcc --version
g++ --version
gdb --version
```

### 5.2 cmake



```
sudo apt install cmake
```

作用：cmake生成可执行程序，也能生成动态库和静态库（库文件是为了第三方引用，使用库而不使用源代码：为了维护和保密）

### VScode

![image-20240103151532471](https://raw.githubusercontent.com/mulin33/ImageHost/main/blogImg/image-20240103151532471.png)

## 6 把Linux(Ubuntu安装到移动硬盘)

设备：Lenovo XiaoXinPro 14ITL 2021、移动硬盘(1T)、U盘



<img src="https://raw.githubusercontent.com/mulin33/ImageHost/main/blogImg/image-20240116214749803.png" alt="image-20240116214749803" style="zoom:67%;" />

