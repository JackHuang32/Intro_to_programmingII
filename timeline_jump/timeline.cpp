#include<iostream>
#include<vector>
using namespace std;
struct T_mod { // same as example of T_mod
    long long  operator() (const long long &data1, const long long &val, size_t size) {
        // Increasing a single element by val means the query result should increase val*size.
        return data1 + val * size;
    }
};
struct T_merge { // same as exmplae of T_merge
    long long  operator() (const long long  &data1, const long long &data2) {
        return data1 + data2;
    }
};
struct T_mod_max { // same as example of T_mod
    long long operator() (const long long &data1, const long long &val, size_t size) {
        // Increasing a single element by val means the query result should increase val*size.
        return data1 + val;
    }
};
int max(long a,long b){return (a>b)?a:b;}
struct T_merge_max { // same as exmplae of T_merge
    int operator() (const long long &data1, const long long &data2) {
        return max(data1,data2);
    }
};
int main()
{
    int n;
    cin>>n;
    vector<long long >arr;
    for(int i=0;i<n;i++)
    {
        long long tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    SegmentTree<long long ,T_mod,T_merge>tree(arr);
    SegmentTree<long long ,T_mod_max,T_merge_max>tree_max(arr);
    int q;
    cin>>q;
    while(q--)
    {
        string command;
        cin>>command;
        if(command == "sum")
        {
            int l,r;
            cin>>l>>r;
            cout<<tree.query(l-1,r-1)<<endl;
            
        }
        if(command == "max")
        {
            int l,r;
            cin>>l>>r;
            cout<<tree_max.query(l-1,r-1)<<endl;
        }
        if(command == "modify")
        {
            int l,r,val;
            cin>>l>>r>>val;
            tree.modify(l-1,r-1,val);
            tree_max.modify(l-1,r-1,val);
        }
    }
    return 0;
}