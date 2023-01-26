#include <stdio.h>

int main()
{
        int a=10,b=20,c;

        printf("Enter the variable\n");

        c= (++a + a++) - (++a + a);

        printf("adding numbers : %d\n",c);
}
