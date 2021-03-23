#include <stdio.h>
#include "sub.h"
#include "add.h"

int main(void)
{
    int a = 9, b = 6;
    printf("the sum of a+b:%d", addInt(a, b));
    printf("the sub of a-b:%d", subInt(a, b));
    return 0;
}