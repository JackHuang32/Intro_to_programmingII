#include<iostream>
#include<map>
#include<utility>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<pair<char,int>,int>Second;
    map<int,int>first;
    int second_num=0;
    int first_num=0;
    while(n--)
    {
        int vow_num = 0;
        char last_vow = '0';
        string word;
        cin>>word;
        reverse(word.begin(),word.end());
        for(auto chr:word)
        {
            if(chr == 'a'||chr=='e'||chr=='i'||chr=='o'||chr=='u')
            {
                vow_num++;
                if(vow_num==1)
                {
                    last_vow = chr;
                }
            }
        }
        if(vow_num==0)continue;
        else
        {
            if(Second.find(make_pair(last_vow,vow_num))!=Second.end())
            {
                int num = ++Second[make_pair(last_vow,vow_num)];
                if(num%2==0)
                {
                    second_num++;
                }
            }
            else
            {
                Second[make_pair(last_vow,vow_num)]=1;
            }
            if(first.find(vow_num)!=first.end())
            {
                first[vow_num]++;
                if(first[vow_num]%2==0)
                {
                    first_num++;
                }
            }
            else
            {
                first[vow_num]=1;
            }
        }
       
    }
    if(second_num >= first_num/2)
    {
        cout<<first_num/2<<endl;
    }
    else
    {
        cout<<second_num<<endl;
    }
    return 0;
}