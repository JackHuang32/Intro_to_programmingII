#include<stdio.h>
#include<stdlib.h>
#define mod 1000000007 
long long int a[2000001];
long long int game_record[2000001][2];
int cmp(const void* a,const void*b)
{
    const int(* pa)[2] = a;
    const int(* pb)[2] = b;
    if((*pa)[0]==(*pb)[0])return (*pa)[1]-(*pb)[1];
    else
    {
        return (*pa)[0]-(*pb)[0];
    }
}
long long int fpw(long long int times)
{
    if(times==0)return 1;
    else
    {   
        long long int tmp = fpw(times/2);
        if(times%2==0)
        {
            return (tmp%mod*tmp%mod)%mod;
        }
        else
        {
            return (2*tmp%mod*tmp%mod)%mod;
        }
    }
}
int BS(int l,int r,int val)
{
    if(l>r)return -1;
    else if(l==r)return l;
    else
    {
        int mid = (l+r)/2;
        if(game_record[mid][0]>=val)
        {
            return BS(l,mid,val);
        }
        else if(game_record[mid][0]<val)
        {
            return BS(mid+1,r,val);
        }
        
    }
}
int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d(/`A`)/ ~I__I",&a[i]);
            if(a[i]%2==1)
            {
                game_record[i][0] = 0;
                game_record[i][1] = i;
            }
            else
            {
                game_record[i][0] = fpw(a[i]/2);
                game_record[i][1] = i;
            }
        }
        qsort(game_record,n,2*sizeof(long long int),cmp);
        /*
        for(int i=0;i<n;i++)printf("%d ",game_record[i][0]);
        printf("\n");
        for(int i=0;i<n;i++)printf("%d ",game_record[i][1]);
        printf("\n");
        */
        while(q--)
        {
            int num;
            scanf("%d",&num);
            int idx = BS(0,n-1,num);
            //printf("idx: %d\n",idx);
            if(idx>=0&&game_record[idx][0]==num)
            {
                printf("%lld\n",game_record[idx][1]+1);
            }
            else
            {
                printf("Go Down Chicken 404\n");
            }
        }
        
    }
    
    return 0;
}