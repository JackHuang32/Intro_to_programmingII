#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    multiset<string>S;
    vector<string>arr;
    int n;
    cin>>n;
    string max = "0";
    string min = "0";
    while(n--)
    {
        string command;
        cin>>command;
        //cout<<"command:"<<command<<endl;
        if(command == "insert")
        {
            string tmp;
            cin>>tmp;
            S.insert(tmp);
            arr.push_back(tmp);
            if(arr.size() == 1)
            {
                max = tmp;
                min = tmp;
            }
            else
            {
                if(max.length() <= tmp.length())
                {
                    if(max.length() != tmp.length())
                    {
                        max = tmp;
                    }
                    else if(max < tmp)
                    {
                        max = tmp;
                    }
                }
                if(min.length() >= tmp.length())
                {
                    if(min.length() != tmp.length())
                    {
                        min = tmp;
                    }
                    else if(min > tmp)
                    {
                        min = tmp;
                    }
                }
            }
        }
        else if(command == "min")
        {
            if(S.size()==0)continue;
            //auto min = S.upper_bound("0");
            cout<<min<<endl;
        }
        else if(command == "max")
        {
            if(S.size()==0)continue;
            cout<<max<<endl;
        }
        else if(command == "find")
        {
            //cout<<"find"<<endl;
            
            int idx;
            cin>>idx;
            if(idx > arr.size())continue;
            cout<<arr[idx-1]<<endl;
            //cout<<"find"<<endl;
        }
        else if(command == "amount")
        {
            string num;
            cin>>num;
            cout<<S.count(num)<<endl;
        }
    }
    return 0;
}