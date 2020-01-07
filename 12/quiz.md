# 2.
根据经验，dumb node挺好用的。
可能就是浪费了一个空间吧。

answer： 好用个P，并没有减少特殊情况的处理，浪费空间那是必须的。快学习姆们提供的技巧！

# 4.
好问题。
只能让代码变得繁杂。
或者：
this 变成接口，只接受fwd 运算
rootp 只有fwd和bwd

answer： “声明一个只包含指针的结构”： 通过不完整标签来实现
其他骚操作：
```c
Node *root;
root = malloc( sizeof(Node) - sizeof(ValueType) );
```

# 7.
a没有变化，b省了整个a这么多单词的操作，以此类推