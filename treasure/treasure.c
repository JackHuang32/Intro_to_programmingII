#include<stdio.h>
long long int crates[1000001];
long long int prefix[1000001];
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    crates[0]=0;
    prefix[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&crates[i]);
        if(crates[i]>0)prefix[i] = crates[i]+prefix[i-1];
        else prefix[i] = prefix[i-1];
    }
    //for(int i=1;i<=n;i++)printf("%d ",prefix[i]);
    //printf("\n");
    while(q--)
    {
        int l,r,m;
        scanf("%d%d%d",&l,&r,&m);
        long long int ans = prefix[l+m-1]-prefix[l-1];
        printf("%lld\n",ans);   
    }
    return 0;
}