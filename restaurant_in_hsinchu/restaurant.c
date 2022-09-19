#include<stdio.h>
#define mod 1000000007
long long int F[2][2] = {1,1,1,0};
long long int mat[2][2] = {1,1,1,0};
void product(long long int *,long long int *);
void fpw(long long int t)
{
    if(t == 1)return;
    fpw(t/2);
    if(t%2 == 0)
    {
        product(&mat[0][0],&mat[0][0]);
    }
    else
    {
        product(&mat[0][0],&mat[0][0]);
        product(&F[0][0],&mat[0][0]);
    }
}
void product(long long int  *mat1,long long int *mat2) //[mat1] * [mat2]
{
    long long int temp[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            temp[i][j] = 0;
            for(int k=0;k<2;k++)
            {
                temp[i][j] += mat1[i*2+k]*mat2[j+k*2]%mod;
            }
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            mat2[2*i+j] = temp[i][j];
        }
    }
}
int main()
{
    long long int num,ans;
    while(scanf("%lld",&num) != EOF)
    {
        if(num == 1)
        {
            printf("1\n");
            continue;
        }
         if(num == 2)
        {
            printf("1\n");
            continue;
        }
        else
        {
            fpw(num - 2);
            ans = mat[0][0]%mod + mat[0][1]%mod;
            ans = ans%mod;
            printf("%lld\n",ans);
            mat[0][0] = 1;
            mat[0][1] = 1;
            mat[1][0] = 1;
            mat[1][1] = 0;

        }

    }
    return 0;
}
