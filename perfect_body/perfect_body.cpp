#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p,k;
        cin>>n>>p>>k;
        vector<int>arr(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        for(int i=1;i<=n;i++)
        {
            if(i <= k-1)
            {
                arr[i] += arr[i-1];
            }
            else
            {
                arr[i] += arr[i-k];
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(p >= arr[i])
            {
                ans = i;
            }
            
        }
        cout<<ans<<endl;
    }
    return 0;
}