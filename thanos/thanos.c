#include<stdio.h>
#define mod 1000000007
long long int mat[3][3]={1,2,1,1,0,0,0,1,0};
long long int T[3][3]={1,2,1,1,0,0,0,1,0};
void product(long long int  a[3][3],long long int  b[3][3])
{
    long long int tmp[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            long long int aij=0;
            for(int k=0;k<3;k++)
            {
                aij+=a[i][k]*b[k][j]%mod;
            }
            tmp[i][j] = aij%mod;
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            a[i][j] = tmp[i][j];
            //printf("%lld ",tmp[i][j]);
        }
    }
    
    return;
}
void fpw(long long int times)
{
    if(times<=1)return;
    else
    {
        fpw(times/2);
        product(T,T);
        if(times%2==1)product(T,mat);

    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int idx;
        scanf("%lld",&idx);
        if(idx==1)
        {
            printf("1\n");
        }
        else if(idx==2)
        {
            printf("12\n");
        }
        else if(idx==3)
        {
            printf("13\n");
        }
        else
        {
            long long int product_times = idx-3;
            fpw(product_times);
            long long int ans = T[0][0]*13%mod+T[0][1]*12%mod+T[0][2]%mod;
            ans = ans%mod;
            printf("%lld\n",ans);
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    T[i][j] = mat[i][j];
                }
            }
        }
    }
    return 0;
}