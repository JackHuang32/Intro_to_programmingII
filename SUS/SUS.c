#include<stdio.h>
#include<math.h>
int pre[100];
int post[100];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&pre[i]);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&post[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pre[i]==post[j])
                {
                    if(j!=0 && pre[i+1]==post[j-1])
                    {
                        ans++;
                    }

                }
            }
        }
        printf("%d\n",(int)pow(2,ans));
    }
    return 0;   
}