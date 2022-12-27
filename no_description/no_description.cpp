#include<iostream>
#include<vector>
#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
using namespace std;
typedef long long  Long;
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n,k;
        cin>>n>>k;
        vector<vector<Long>>dp(k+1,vector<Long>(n+1,0));
        vector<Long>arr(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
            arr[i]+=arr[i-1];
            dp[1][i] = arr[i];
        }
        
        for(int i=2;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int l=j-1;l>=1;l--)
                {
                    cout<<"i:"<<i<<" j:"<<j<<" l:"<<l<<endl;
                    if(l!=j-1)dp[i][j] = min(max(dp[i-1][l],arr[j]-arr[l]),dp[i][j]);
                    else
                    {
                        dp[i][j] = max(dp[i-1][l],arr[j]-arr[l]);
                    }
                    cout<<dp[i][j]<<endl;
                    //cout<<"done"<<endl;
                }
            }
        }
        cout<<dp[k][n]<<endl;
    }
    return 0;
}