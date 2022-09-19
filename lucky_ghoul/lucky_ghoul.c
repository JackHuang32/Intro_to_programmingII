#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int arr[2000001];
int BS(int num,int l,int r)
{
    if(l>r)return -1;
    else
    {
        int mid = (l+r)/2;
        if(arr[mid]>num)
        {
            return BS(num,l,mid-1);
        }
        else if(arr[mid]<num)
        {
            return BS(num,mid+1,r);
        }
        return mid;
    }
}
int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
        }
        while(q--)
        {
            int want_to_find;
            scanf("%d",&want_to_find);
            int pos = BS(want_to_find,1,n);
            if(pos>0)printf("%d\n",pos);
            else
            {
                printf("Break your bridge!\n");
            }
        }
    }
    return 0;
}