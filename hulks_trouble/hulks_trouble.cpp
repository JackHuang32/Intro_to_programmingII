#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<int,int>hash;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin >> tmp;
        if(hash.find(tmp) != hash.end())
        {
            hash[tmp]++;
        }
        else
        {
            hash[tmp] = 1;
        }
    }
    int q;
    cin >> q;
    while(q--)
    {
        int num;
        cin >> num;
        if(hash.find(num) != hash.end())
        {
            cout<<hash.find(num)->second<<endl;
        }
        else
        {
            cout<<"0"<<endl;
        }
    }

    return 0;
}