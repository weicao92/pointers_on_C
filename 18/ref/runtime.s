	.data ; 表示进入数据区
	.even ; 确保变量开始与内存的偶数地址
	.globl	_static_variable ; 变量被声明为全局类型，变量名以一个下划线开始
_static_variable:
	.long	5
	.text ; 进入代码（文本）段

	.globl	_f
_f:	link	a6,#-88 ; 创建堆栈帧，在堆栈中保留了88个字节的空间，用于存储局部变量和其他值；link？
	moveml	#0x3cfc,sp@ ; 0x3cfc表示寄存器d2-d7、a2-a5的值需要被存储；
	; 局部变量的声明和函数原型不会产生汇编代码，初始化才会。
	moveq	#1,d7
	moveq	#2,d6
	moveq	#3,d5
	moveq	#4,d4
	moveq	#5,d3
	moveq	#6,d2
	movl	#7,a6@(-4)
	movl	#8,a6@(-8)
	movl	#9,a6@(-12)
	movl	#10,a6@(-16)
	; 以上：说明最多只能有6个整型值可以被存放在数据寄存器
	; 其他类型的数据会不会、能不能、放在哪个寄存器由编译器或机器决定
	; d0，d1 用于从函数返回值
	movl	#110,a5
	movl	#120,a4
	movl	#130,a3
	movl	#140,a2
	movl	#150,a6@(-20)
	movl	#160,a6@(-24)
	movl	#170,a6@(-28)
	movl	#180,a6@(-32)
	movl	#190,a6@(-36)
	movl	#200,a6@(-40)
	; 以上：说明最多4个
	; a6称为帧指针，指向堆栈帧中内部的一个“引用”位置
	; a7成为堆栈指针，就是sp 
	movl	#1,_a_very_long_name_to_see_how_long_they_can_be

	; 以下：
	movl	a6@(-16),sp@-
	movl	d7,sp@-
	pea	10 ;pea指令简单的把它的操作数压入到堆栈中
	;压栈顺序是相反的。
	jbsr	_func_ret_int ; 跳转子程序：把返回地址压入到堆栈中。
	lea	sp@(12),sp ;把12加到堆栈指针，有效的把参数值从堆栈中弹出。
	; 被调用函数并没有从堆栈中完全清楚他的整个堆栈帧：参数还留在那里等待调用函数清除。
	; 和可变参数列表有关，只有调用者才知道有多少参数。
	movl	d0,d6 ;返回值：d0（中间结果暂存器） d6是i2的存放位置 对应语句 i2 = funcname(p1, p2, p3);
	;这个编译器中，函数返回一个值时把它存放在d0， 调用函数从被调用函数返回之后从d0获取这个值。d0不能用于存放寄存器变量的另一原因～

	jbsr	_func_ret_double
	movl	d0,a6@(-48)
	movl	d1,a6@(-44)
	;double，8个字节，动用2个寄存器了
	pea	a5@
	jbsr	_func_ret_char_ptr
	addqw	#4,sp
	movl	d0,a5
	moveml	a6@(-88),#0x3cfc
	unlk	a6
	rts

	.globl	_func_ret_int
_func_ret_int:
	link	a6,#-8 ;a6的内容被压栈，堆栈指针的当前值被复制到a6；从堆栈指针中-8（空间用于保存局部变量和被保存的寄存器的值）
	moveml	#0x80,sp@ ;0x80 指定寄存器d7
	movl	a6@(16),d7 ;从堆栈复制一个值到d7
	movl	a6@(12),d0 ;把第二个参数复制到d0
	subql	#6,d0 ;-6
	movl	d0,a6@(-4);把差复制到局部变量的预留栈帧
	movl	a6@(8),d0 ; d0: 中间结果暂存器， 所以不能存储寄存器变量： 第一个参数
	addl	a6@(12),d0
	addl	d7,d0
	;函数跋部分
	moveml	a6@(-8),#0x80 ;恢复以前被保存的寄存器值？？？
	unlk	a6 ;unlink: 把a6的值复制给堆栈指针sp，把堆栈中弹出的a6的旧值装入a6，清除堆栈帧中返回地址以上的部分
	rts ;把返回地址从堆栈中弹出到【程序计数器】，实现返回

	.globl	_func_ret_double
_func_ret_double:
	link	a6,#0
	moveml	#0,sp@
	movl	L2000000,d0
	movl	L2000000+4,d1
	unlk	a6
	rts
L2000000:	.long	0x40091eb8,0x51eb851f

	.globl	_func_ret_char_ptr
_func_ret_char_ptr:
	link	a6,#0
	moveml	#0,sp@
	movl	a6@(8),d0
	addql	#1,d0
	unlk	a6
	rts
