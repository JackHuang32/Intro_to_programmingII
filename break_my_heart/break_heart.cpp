#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<int>S;
    int q;
    cin >> q;
    while(q--)
    {
        string command;
        cin >> command;
        int min;
        if(command == "print")
        {
            if(S.size() == 0)
            {
                continue;
            }
            else
            {
                int tmp = -1;
                for(int i=0;i<S.size();i++)
                {
                    tmp = *S.upper_bound(tmp);
                    cout << tmp << " ";
                }
                cout<<endl;
            }
        }
        if(command == "insert")
        {
            int num;
            cin >> num;
            S.insert(num);
        }
        if(command == "range_erase")
        {
            int l,r;
            cin >> l >> r;
            auto left = S.lower_bound(l);
            auto right = S.upper_bound(r);
            S.erase(left,right);
        }
        if(command == "min")
        {
            if(S.size() == 0)
            {
                continue;
            }
            else
            {
                auto min = S.upper_bound(-1);
                cout << *min << endl;
            }
            
        }
        if(command == "sum")
        {
            long long int sum=0;
            for(auto i=S.begin();i!= S.end();i++)
            {
                sum += *i;
            }
            cout << sum <<endl;
        }
    }
    return 0;
}