# CSAPP

阅读CSAPP的笔记。

### CONTENT
- [0. 读前准备](#0-读前准备)
- [1. 计算机系统漫游](#1-计算机系统漫游)
- [2. 信息的表示和处理](#2-信息的表示和处理)
- [4. linked_list链表](#4-linked_list链表)
- [5. dp](#5-dp)
- [6. binary_search二分查找](#6-binary_search二分查找)
- [7. 离线算法](#7-离线算法)
- [8. heap堆](#8-heap堆)
- [9. backtracking回溯](#9-backtracking回溯)
- [10. trivial](#10-trivial)

### 0. 读前准备

其实在此之前（读前之前）已经接触到了Linux相关的命令行操作了（如使用GitBash来从本地将更新的代码`push`到远端；或者用picgo把本地图片上传到远端，再用`pull`指令拉到本地文件夹）。
之后看到网上说vim是编辑器之神（这里网上包括知乎、csdn、南大的ICS课程的课前准备），便去详细了解了一下vim的使用，并对其进行了外观的配置，变得更加好看了。
说一下我对vim的感受：无gui的按钮操作，全部都是键盘按键完成（当然这是在关闭鼠标操作设置的前提下，不过我发现即使开启了鼠标的操作功能，在root下开启vim会使用最最最原始的配置），
而且这个编辑器既然是存在于Linux系统中的，于是可以编写各种代码如python、cpp，并随时保存和在命令行中（编译和）运行，实际上与windows系统中的pycharm或者vscode功能是差不多的。

总结来看，我对vim目前的用途也就仅仅限于：找到根目录，`cd`到`/mnt`中，去`/d`盘编辑我的本地代码（实际上和用pycharm的效果是一样的）。最大的好处是：可以同时编辑py文件和cpp文件（虽然和vscode是一样的）。
但是配置完成后真的很酷啊！效果图如下（第二张是设置了JetBrains Mono字体的）：
![my_vim_after_setting.png](imgs%2Fmy_vim_after_setting.png)
![my_vim_after_setting2.png](imgs%2Fmy_vim_after_setting2.png)

这里附上我配置vim参考的链接教程：`https://blog.csdn.net/qq_42417071/article/details/139027077` 。

对vim的配置主要是对vimrc的内容进行修改，第一步是先对其复制得到一个拷贝，粘贴到~下，重命名为.vimrc，每次访问的命令就是：`ink@gale:~$ vim .vimrc`。我把配置文件内容都放在了这个repo的vimrc文件夹[我的 Vim 配置](vimrc/myconfig.vim)中，可以用来参考。
（尽量实现了类似于vscode编辑代码时的自动功能，但仍有一些不完善的地方，..也懒得改了主要是我自己不太会写shell脚本，需要靠互联网和gpt和deepseek三者辅助修改，比较麻烦吧）

此外，在vim中下载了tmux的包，这样可以在一个窗口中建立多个pane，如在左侧写py代码，在右侧随时执行这个文件，实现和pycharm类似的功能（我的配置中设置了`\1`作为热键在完成操作：
保存当前代码文件`:w`->向右侧pane中发送指令`python3 %`->将光标移到右侧pane中（这样方便输入测试数据））

### 🚀1. 计算机系统漫游

### 🚀2. 信息的表示和处理

8位=1字节

内存由一大块字节数组组成，每个字节都由一个唯一的数字来标识，这个数字就是它的地址。

✔️**二进制、十进制、十六进制的转换**：
1. bin<->hex
二进制转十六：从后往前分割4位，逐个转换；

十六转二进制：逐位转换

当x=2^n时，二进制为1后面跟n个0，当n=i+4j时，对应十六进制：0x(2^i)(0*j)
2048=2^11, 11=3+4*2, 0x800
2. dec<->hex
十进制转十六：不断做除法取余数，最后用stack反转结果

十六转十进制：从地位到高位乘16的对应次方

✔️**寻址和字节顺序**：
每个字节都有一个编号数字来标识，叫做其地址。那么一个字节是8位，对应到十六进制中就是两个数字（或者a到f中的字母）。
理解起来就是：对于一个十六进制数字，每一个数字=1个字节，需要一个字节的空间去存。

对于一个int类型的变量x（假设是32位的），假设十六进制值位0x01234567，那么它的内存地址是需要4个字节的，每个字节保存俩个数字。
同时对于跨越多个字节的对象，这个对象的地址是所使用的所有字节中最小的地址。假设x变量的地址为0x100（说明四个字节地址最小的为0x100）

在保存时采用一块连续的内存地址，有两种方式：`最低有效字节在前面（小端法）`和`最高有效字节在前面（大端法）`，
则对于连续字节地址：0x100,0x101,0x102,0x103，采用大端法为：01,23,45,67，小端法为:67,45,23,01。

但是在表示字符串的时候，无论是大端法的机器还是小端法的机器，输出的结果都是按照字符串的前后顺序，因为字符串的末尾是null。

对于代码的编译，不同系统上的指令编码是不同的，因此二进制代码很少能在不同机器之间移植。


✔️**位级运算**：
与& 或| 异或^ 取反~

一个常见用法是实现**掩码运算**，例如位级运算`x&0xFF`生成一个由x的最低有效字节组成的值，比如： 
`0x2342A4EF & 0xFF = 0xEF`。而掩码`~0`将生成一个全为1的掩码。

利用是：要取出x的最高三字节：`x&0xFFFFFF00`
要取出x的最低一字节：`x&0xFF`

bitset(x,y):把y是1的位置在x中设为1 --> `(x | y)`
bitclean(x,y):把y是1的位置在x中设为0 --> `(x & ~y)`

实现异或：`x ^ y == bis(bic(x,y), bic(y,x)) --> x ^ y == (x & ~y) | (~x & y)`

注意位级运算与逻辑运算的差别，&&如果左侧为假直接返回0而不判断右侧，||如果左侧为真直接返回1而不判断右侧，`x==y <-> !(x^y)`

✔️**位移运算**：
