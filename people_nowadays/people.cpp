#include<iostream>
#include<set>
using namespace std;

int main()
{
    int t;
    cin>>t;
    set<pair<int,string>>record;
    pair<int,string>youngest;
    while(t--)
    {
        string command;
        cin>>command;
        if(command == "born")
        {
            string name;
            int age;
            cin>>name>>age;
            record.insert(make_pair(age,name));
        }
        if(command == "find")
        {
            string name;
            int age;
            cin>>name>>age;
            if(record.find(make_pair(age,name)) != record.end())
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
        if(command == "kill")
        {
            string name;
            int age;
            cin>>name>>age;
            if(record.find(make_pair(age,name)) != record.end())
            {
                auto older = record.upper_bound(make_pair(age,name));
                record.erase(record.find(make_pair(age,name)));
            }
        }
        if(command == "young")
        {
            cout<<record.begin()->second<<" "<<record.begin()->first<<endl;
        }
    }
    return 0;
}