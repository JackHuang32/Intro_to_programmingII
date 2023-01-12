#include<iostream>
#include<vector>
#include<stack>
#include<set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        //map letter to string
        vector<vector<int>>arr(26,vector<int>(0));
        vector<string>str;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            set<char>s_letters;
            for(auto ch:s)s_letters.insert(ch);
            s="";
            for(auto ch:s_letters)
            {
                s+=ch;
            }
            str.push_back(s);
            for(auto ch:s)
            {
                arr[ch-'a'].push_back(i);
            }
        }
        int count = 0;
        vector<bool>check_str(n,false);
        vector<bool>check_letter(26,false);
        for(int i=0;i<26;i++)
        {
            //skip checked letter and non exsisted letter
            if(check_letter[i] || arr[i].size()==0)continue;
            check_letter[i] = true;
            stack<int>st;
            st.push(i);
            while(!st.empty())
            {
                int cur_letter = st.top();
                st.pop();
                check_letter[cur_letter] = true;
                for(auto id:arr[cur_letter])
                {
                    if(check_str[id])continue;
                    check_str[id] = true;
                    for(auto ch:str[id])
                    {
                        if(check_letter[ch-'a'])continue;
                        check_letter[ch-'a'] = true;
                        st.push(ch-'a');
                    }
                }
            }
            count++;
        } 
        cout<<count<<endl;
    }
    return 0;
}