#include<stdio.h>
int Jos(int n,int m)
{
    if(n==1)return 1;
    else
    {
        return ((Jos(n-1,m)+m-1))%n+1;
    } 
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        printf("%d\n",Jos(n,m));
    }
    return 0;
}