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
   printf("add : %d\n",addresult);
   
   subresult = sub(23,5);
   printf("sub : %d\n",subresult);
   
   mulresult = mul(23,5);
   printf("sub : %d\n",mulresult);
}

