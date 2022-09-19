#include<stdio.h>
#include<string.h>
char sample[1001],total[1001];
int prefix[1001];
int main()
{
    while(scanf("%s%s",total,sample)!=EOF)
    {
        int total_len = strlen(total),sample_len = strlen(sample);
        if(sample_len>total_len)
        {
            printf("0\n");
            continue;
        }
        for(int i=strlen(total)-1;i>=0;i--)total[i+1] = total[i];
        for(int i=strlen(sample)-1;i>=0;i--)sample[i+1] = sample[i];
        prefix[0]=0;
        for(int i=1;i<=strlen(total);i++)
        {
           int flag = 0;
           for(int j=1;j<=sample_len;j++)
           {
               if(sample[j]==total[i+j-1])
               {
                   if(j==sample_len)
                   {
                       flag=1;
                       //printf("pos:%d ",i);
                   }
                   continue;
               }
               else
               {
                   break;
               }
           }
           if(flag)prefix[i]=1;
           else prefix[i]=0;
           prefix[i]+=prefix[i-1];
        }
        //printf("\n");
        int q;
        scanf("%d",&q);
        int max = 0;
        while(q--)
        {
            int start,end;
            scanf("%d%d",&start,&end);
            int cur_ans = prefix[end-sample_len+1]-prefix[start-1];
            if(max<cur_ans)max = cur_ans;
        }
        printf("%d\n",max);

    }
    return 0;
}