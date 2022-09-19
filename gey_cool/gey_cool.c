#include<stdio.h>
long long int arr[2000001];
int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        arr[0] = 0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&arr[i]);
            arr[i]+=arr[i-1];
        }
        long long int ans_l,ans_r,ans = 0;
        while(q--)
        {
            long long int l,r,value;
            scanf("%lld%lld",&l,&r);
            if(l<=r)
            {
                value = arr[r] - arr[l-1];   
            }
            else
            {
                value = arr[n] - arr[l-1] + arr[r];
            }
            if(value > ans)
                {
                    ans = value;
                    ans_l = l;
                    ans_r = r;
                }
        }
        printf("Max_range: (%lld,%lld); Value: %lld\n",ans_l,ans_r,ans);
    }
    
    return 0;
}