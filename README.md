# CSAPP

阅读CSAPP的笔记。

<!-- TOC -->
* [CSAPP](#csapp)
    * [🚀0. 读前准备](#0-读前准备)
    * [🚀1. 计算机系统漫游](#1-计算机系统漫游)
    * [🚀2. 信息的表示和处理](#2-信息的表示和处理)
      * [2.1 信息存储](#21-信息存储)
      * [2.2 整数表示](#22-整数表示)
      * [2.3 整数运算](#23-整数运算)
        * [2.3.1 无符号加法](#231-无符号加法)
        * [2.3.2 补码加法](#232-补码加法)
<!-- TOC -->

### 🚀0. 读前准备

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

#### 2.1 信息存储

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
|操作|值|
|:--:|:--:|
|x|`[01100011] [10010101]`|
|x << 4|`[00110000] [01010000]`| 
|x >> 4(逻辑右移)|`[00000110] [00001001]`|
|x << 4(算术右移)|`[00000110] [11111001]`|

注：在Java中，x>>>4才是逻辑右移。算术右移会根据正负补齐高位，逻辑右移只会补0.

优先级：移位运算优先级比加减法要低。


#### 2.2 整数表示

✔️**整形数据类型**：
C数据类型在32位和64位的整数取值范围只有long和unsigned ling有区别：32为`2**32-1`；64为`2**64-1`.

✔️**无符号数的编码(正整数)**：
对于一个有$w$位的整数数据类型，可以把位向量写成$\overrightarrow{x}$，且每一位的取值为0或1。那么可以给出无符号数的编码定义：

对向量$\overrightarrow{x}=[x_{w-1},x_{w-2},\cdots,x_0]$:

$$B2U_w(\overrightarrow{x}) \doteq \sum_{i=0}^{w-1} x_i2^i$$

其中$B2U_w$为Binary to Unsigned的缩写，长度为w。

与此同时，无符号数编码具有唯一性，即函数$B2U_w$是一个双射。

那么当向量表示为$[11...1]$时最大值为$2^w-1$，表示为$[00...0]$时最小值为$0$.

✔️**补码的编码(负整数)**：
对于负数值的表示，常常使用补码（two's-complement）形式表示，将字的最高有效位解释为负权（negative weight）。给出补码定义：

对向量$\overrightarrow{x}=[x_{w-1},x_{w-2},\cdots,x_0]$:

$$B2T_w(\overrightarrow{x}) \doteq -x_{w-1}2^{w-1}+\sum_{i=0}^{w-2} x_i2^i$$

其中$B2T_w$为Binary to Two's-complement的缩写，长度为w。

$B2T_w([0101])=5$

$B2T_w([1011])=-5$

与此同时，补码编码具有唯一性，即函数$B2T_w$是一个双射。

那么当向量表示为$[011...1]$时最大值为$2^{w-1}-1$，表示为$[100...0]$时最小值为$-2^{w-1}$.

对于字长w=8，给出表示整数的最值：

$UMax_w = 2^w-1=255=0xFF$

$TMax_w = 2^{w-1}-1=127=0x7F$

$TMin_w = -2^{w-1}=-128=0x80$

$-1=[11111111]=0xFF$

$0=[00000000]=0x00$

**TIPS**：
1. $(1):|TMin|=|TMax|+1$，$(2):UMax=2TMax+1$.且在有符号表示中，-1为全为1的串。
2. 对于32位的机器，由8个十六进制数字组成的，且开始的那个数字（最高的第8位）是8-f之间的任何值，都是一个负数。但是0x8048337是一个整数（补高位0）。

补充：
还有两种标准的表示方式和：
**反码（Ones' Complement）** $$B2O_w(\overrightarrow{x}) \doteq -x_{w-1}(2^{w-1}-1)+\sum_{i=0}^{w-2}x_i2^i$$

**原码（Sign-Magnitude）** $$B2S_w(\overrightarrow{x}) \doteq (-1)^{x_{w-1}} \cdot (\sum_i=0^{w-2}x_i2^i)$$

✔️**有符号数和无符号数之间的转换**：
1. 补码转为无符号数：

$$
T2U_w=
\begin{cases}
x,\ x\geq0\\
x+2^w,\ x<0\\
\end{cases}
$$

其中满足$TMin_w \leq x \leq TMax_w$

2. 无符号数转为补码：

$$
U2T_w=
\begin{cases}
x,\ x \leq TMax_w\\
x-2^w,\ x > TMax_w\\
\end{cases}
$$

其中满足$0 \leq x \leq UMax_w$

3. C语言中有符号数与无符号数的表示

遵循一个最基本的原则：给定一个数字，其二进制的底层表示是固定不变的，而最终这个数字表示的含义要根据自己赋予其的数据类型去解释。
比如对于2^31（2147483648），其十六进制表示为0x80000000，如果是int类型（4字节，有符号数），那么最高位（第32位）为1，说明这是一个负数（最高位是8-f的都是负数），
根据$T2U_w$的公式得知其表示的数字实际上为-2147483648；如果是unsigned类型（4字节，无符号数，可以写成2147483648u/U），那么最高位解释为正权值，
因此表示为正的2147483648。然而，尽管在两种表示方式下数值是不同的，其二进制表示形式是一致的，只是对二进制的解释方式的差别导致的数值的大小差别。

在对数值进行比较时，如果两个数分别为有符号和无符号，那么会将有符号隐式地转为无符号进行比较，即有如下布尔值：

2147483647 > -2147483647-1 --> 均为有符号 --> true

2147483647u > -2147483647-1 --> 将右侧的有符号转为无符号（+2147483648） --> false

✔️**扩展一个数字的位表示**：

1. 无符号数的零扩展

直接在最高位补0即可。

2. 有符号数的符号扩展

保持与当前最高位一致，向前补齐，是1补1，是0补0.

**TIP：** 对于有符号数，可以把高位的1都删去，直到这一连续的1串只剩下1个1的时候，数值是相等的，比如：
-5=[1011]=[11011]=[111011]

✔️**截断数字**：

1. 截断无符号数

$令\overrightarrow{x}是一个w位的向量，而\overrightarrow{x'}是将其截断为k位的结果。令x=B2U_w(\overrightarrow{x}),
x'=B2U_k(\overrightarrow{x'})。则有x'=x \mod 2^k。$

2. 截断有符号数

$令\overrightarrow{x}是一个w位的向量，而\overrightarrow{x'}是将其截断为k位的结果。令x=B2U_w(\overrightarrow{x}),
x'=B2T_k(\overrightarrow{x'})。则有x'=U2T_k(x\mod2^k)。$

#### 2.3 整数运算

##### 2.3.1 无符号加法

原理1：

无符号数加法：

对满足 $0 \leq x,y < 2^w$ 的 $x$ 和 $y$ 有：

$$
x +_w^{u} y=
\begin{cases}
x+y,\ x+y<2^w\ (正常)\\
x+y-2^w,\ 2^w \leq x+y < 2^{w+1}\ (溢出)\\
\end{cases}
$$

检测无符号整数加法是否发生了溢出：如果和s<x(or s<y)，则发生了溢出。

原理2：

无符号数求反：

对满足 $0 \leq x,y < 2^w$ 的 $x$ ，其w位的无符号逆元$-_w^{u}x$由下式给出：

$$
-_w^{u}x =
\begin{cases}
x,\ x=0\\
2^{w}-x,\ x>0\\
\end{cases}
$$

对十六进制数字先变为dec，然后计算逆元，再变为16进制

##### 2.3.2 补码加法

原理：

补码加法：

对满足 $-2^{w-1} \leq x,y \leq 2^{w-1}-1$ 的 $x$ 和 $y$ 有：

$$
x +_w^{t} y=
\begin{cases}
x+y-2^w,\ 2^{w-1} \leq x+y \ (正溢出)\\
x+y,\ -2^{w-1} \leq x+y < 2^{w-1} \ (正常)\\
x+y+2^w,\ x+y < -2^{w-1}\ (负溢出)\\
\end{cases}
$$

(考虑负溢出为什么必定是加 $2^w$ :因为从w+1位截断到w时，首位的1后面的第二位必定是0，否则这个数字就大于w位的最小负值了，见上面的TIP)

$$

$∀ u, v \in G; u < v \equiv u.fin < v.fin$