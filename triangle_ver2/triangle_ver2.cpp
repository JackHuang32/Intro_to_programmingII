#include<iostream>
#include<vector>
using namespace std;
int ceil(float n)
{
    return n-(int)n == 0 ? n : n+1; 
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        //cout<<ceil(1)<<endl;
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        vector<int>comb(2*D+1,0);
        vector<int>prefix(2*D+1,0);
        for(int i=A;i<=B;i++)
        {
            comb[i+B]++;
            comb[i+C+1]--;
        }
        for(int i=A+B;i<=B+C+1;i++)
        {
            comb[i]+=comb[i-1];
        }
        for(int i=A;i<=1.5*D;i++)
        {
            prefix[i] = prefix[i-1]+comb[i];
        }
        long long int ans=0;
        for(int i=C;i<=D;i++)
        {
            ans += prefix[ceil(1.5*i)-1]-prefix[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}