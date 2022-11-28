#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>>prefix(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>prefix[i][j];
                if(i==0 && j==0)continue;
                else
                {
                    if(i==0)
                    {
                        prefix[i][j] = prefix[i][j] + prefix[i][j-1];
                    }
                    else if(j==0)
                    {
                        prefix[i][j] = prefix[i][j] + prefix[i-1][j];
                    }
                    else
                    {
                        prefix[i][j] = prefix[i][j] + prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];

                    }
                }
            }
        }
        int l_x,l_y,r_x,r_y;
        int q;
        cin>>q;
        while(q--)
        {
            cin >>l_x>>l_y>>r_x>>r_y;
            int ans;
            if(l_x==1 && l_y==1)
            {
                ans = prefix[r_x-1][r_y-1]; 
            }
            else if(l_x==1)
            {
                ans = prefix[r_x-1][r_y-1] - prefix[r_x-1][l_y-2];
            }
            else if(l_y==1)
            {
                ans = prefix[r_x-1][r_y-1] - prefix[l_x-2][r_y-1];
            }
            else
            {
                ans = prefix[r_x-1][r_y-1] - prefix[l_x-2][r_y-1] - prefix[r_x-1][l_y-2] + prefix[l_x-2][l_y-2];
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}