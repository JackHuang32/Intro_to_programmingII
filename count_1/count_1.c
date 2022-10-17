#include<stdio.h>
int count(int num)
{
    int sum = 0;
    while(num>0)
    {
        if(num%10==1)
        {
            sum++;
        }
        num/=10;
    }
    return sum;
}
int main()
{
    int arr[1000002];
    for (int i=1;i<=1000000;i++)
    {
        arr[i] = arr[i-1]+count(i);
    }
    int t;
    scanf("%d",&t);
    int max = 0;
    while(t--)
    {
        int left, right;
        scanf("%d%d",&left,&right);
        printf("%d\n",arr[right]-arr[left-1]);
    }
    return 0;
}