#include<iostream>
#define M 1000000007
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        string S;
        cin>>x>>S;
        long long  cur_len = S.length()%M;
        if(cur_len == 1)
        {
            cout<<"1"<<endl;
            continue;
        }
        for(int i=0;i<x;i++)
        {
            long long  right_len = (cur_len-i-1+M)%M;
            int repeat = S[i]-'0';
            long long addition = (right_len%M*(repeat)%M)%M;
            cur_len = ((i+1)%M + addition%M)%M;
            if(S.length() <= x && repeat >= 2)
            {
                auto tmp = S.substr(i+1);
                for(int j=0;j<repeat-1;j++)
                {
                    S += tmp;
                }
            }
            
        }
        cout << cur_len%M <<endl;

    }
    return 0;
}