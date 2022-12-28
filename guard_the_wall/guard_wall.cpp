#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector<int>wall(n+2,0);
        vector<pair<int,int>>guards(q);
        for(int i=0;i<q;i++)
        {
            int left,right;
            cin>>left>>right;
            wall[left]++;
            wall[right+1]--;
            guards[i] = make_pair(left,right);
        }
        int total = 0;
        for(int i=1;i<=n;i++)
        {
            wall[i]+=wall[i-1];
            if(wall[i]>0)
            {
                total++;
            }
        }
        /*cout<<"wall:";
        for(auto num:wall)cout<<num<<"  ";
        cout<<endl;*/
        int min = 10000000;
        for(int g=0;g<q;g++)
        {
            auto guard = guards[g];
            int lost_guard = 0;
            vector<int>prefix(n+1,0);
            vector<int>tmp = wall;
            for(int i=guard.first;i<=guard.second;i++)
            {
                tmp[i]--;
                if(tmp[i]==0)lost_guard++;
            }
            for(int i=1;i<=n;i++)
            {
                if(tmp[i]==1)prefix[i] = prefix[i-1]+tmp[i];
                else
                {
                    prefix[i] = prefix[i-1];
                }
            }
            for(int i=0;i<q;i++)
            {
                if(i!=g)
                {
                    if(min > prefix[guards[i].second]-prefix[guards[i].first-1]+lost_guard)
                    {
                        min = prefix[guards[i].second]-prefix[guards[i].first-1]+lost_guard;
                    }
                }
                //cout<<"min: "<<min<<endl;
            }
            /*cout<<"prefix: ";
            for(auto p:prefix)cout<<p<<" ";
            cout<<endl;*/
            
        }  
        cout<<total-min<<endl;
    }
    return 0;
}