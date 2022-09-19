#include<stdio.h>
void binary(int a[],unsigned int num,int i)
{
    if(i >= 0)
    {
        int bit = num % 2;
        a[i] = bit;
        binary(a,num/2,i-1);
    }
    return;
}
int main()
{
    float f;
    while(scanf("%f",&f)!=EOF)
    {
        unsigned int temp = *(unsigned int*)&f;
        int a[32];
        binary(a,temp,31);
        for(int i=0;i<32;i++)
            printf("%d",a[i]);
        printf("\n");
    }
    
    return 0;
}