#include <stdio.h>

/*
 看点： 无论定义了啥，三个家伙还是都引进声明。
 可选的办法是把三个家伙也纳入#if宏

 answer傻了吧，考量的是一种特殊情况：
OPTION_LONG和OPTION_DETAILED都tm定义了怎么办

不要用elif！
多定一个ok量，判别要不要调用default！！！
*/
int print_ledger_long(int i);
int print_ledger_detailed(int i);
int print_ledger_default(int i);

void
print_ledger(int i){
    #if defined(OPTION_LONG)
        print_ledger_long(i);
    #elif defined(OPTION_DETAILED)
        print_ledger_detailed(i);
    #else
    print_ledger_default(i);
}

int 
main()
{

}