#include<stdio.h>
int abs(int a){return (a>0)?a:-a;}
int min(int a,int b){return (a<b)?a:b;}
int main()
{
    int n;
    int arr[100001];
    int dp[100001];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    { 
        scanf("%d",&arr[i]);
    }
    dp[0] = 0;
    for(int i=1;i<n;i++)
    {
        if(i==1)
        {
            dp[i] = abs(arr[i]-arr[0]);
        }
        else
        {
            dp[i] = min(dp[i-1]+abs(arr[i]-arr[i-1]),dp[i-2]+abs(arr[i]-arr[i-2]));
        }
    }
    printf("%d\n",dp[n-1]);
    return 0;
}