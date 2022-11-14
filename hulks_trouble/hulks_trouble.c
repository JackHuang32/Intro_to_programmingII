#include<stdio.h>
#include<stdlib.h>
int arr[100001];
int cmp(const void* a,const void* b)
{
    int* aa = (int*)a;
    int* bb = (int*)b;
    return *aa-*bb;
}
int BS_lower(int tar,int n)
{
    int l = 0;
    int r = n-1;
    while(l < r)
    {
        int mid = (l+r)/2;
        if(arr[mid] < tar)
        {
            l = mid+1;
        }
        else
        {
            r = mid;  
        }
    }
    return l;
}
int BS_upper(int tar,int n)
{
    int l = 0;
    int r = n;
    while(l < r)
    {
        int mid = (l+r)/2;
        if(arr[mid] <= tar)
        {
            l = mid+1;
        }
        else
        {
            r = mid;
        }
    }
    return r;
}
int main()
{
    int n;
    
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int q;
    scanf("%d",&q);
    
    qsort(arr,n,sizeof(int),cmp);
    
    while(q--)
    {
        int num;
        scanf("%d",&num);
        int l = BS_lower(num,n);
        if(arr[l] == num)
        {
            int r = BS_upper(num,n);
            printf("%d\n",r-l);
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}
