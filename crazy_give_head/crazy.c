#include<stdio.h>
#include<string.h>

int main()
{
    char arr1[2000],arr2[2001];
    int str1,str2;
    int prefix[2001] = {0};
    while(scanf("%s%s",&arr1,&arr2) != EOF)
    {
        int max = 0,temp_ans = 0,head,tail,t;
        str1 = strlen(arr1);
        str2 = strlen(arr2);
        for(int i=0;i<=str1;i++)   //set prefix
        {
            prefix[i] = 0;
        }
        for(int i=0;i<str1;i++)
        {
            int temp = i;
            int flag = 0;
            if(arr1[temp] == arr2[0])             //check if the first alphabet is the same
            {
                    if(str2 == 1)flag = 1;

                    for(int j=1;j<str2;j++)       //check the rest of it
                {
                    if(arr1[temp+j] == arr2[j])
                    {
                        if(j == str2-1)flag = 1;
                        continue;
                    }
                    else  break;

                }

                    if(flag == 1)prefix[temp+1] += 1;
            }

        }
        for(int i=1;i<=str1;i++)
        {
            prefix[i] += prefix[i-1];            //build prefix array
        }
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d%d",&head,&tail);
            if((tail-str2+1)>=head)temp_ans = prefix[tail-str2+1] - prefix[head-1];
            if(temp_ans>=max)max = temp_ans;
        }
       printf("%d\n",max);
    }
    return 0;
}
