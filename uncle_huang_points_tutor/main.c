#include<stdio.h>

long long int x,y,m,ans;
long long int fpw(long long int x,long long int y)
{
    long long res;
    if(y == 0)return 1;

        res = fpw(x,y/2);
        if(y%2 == 0)
        {
            return (res*res)%m;
        }
        if(y%2 == 1)
        {
            return ((res*res)%m*x)%m;
        }
}
int main()
{

    scanf("%lld%lld%lld",&x,&y,&m);
    ans = fpw(x%m,y);
    if(m == 1)ans = 0;
    printf("%lld\n",ans);
    return 0;
}
