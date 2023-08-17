#include <stdio.h>
#include "add.h"
#include "sub.h"
#include "mul.h"

int addresult;
int subresult;
int mulresult;

int main(int a, int b)
{
        addresult = add(5,9);
        printf("adding : %d\n", addresult);

        subresult = sub(5,9);
        printf("subtract : %d\n", subresult);

        mulresult = mul(5,9);
        printf("multiplication : %d\n", mulresult);
}
