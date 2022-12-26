#include<iostream>
#include<vector>
using namespace std;
long long Count(int day,vector<int>&arr)
{
    //cout<<"count:"<<day<<endl;
    int n = arr.size();
    long long int total = 0;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]-count < 0)break;
        if(i%day == day-1)
        {
            total+=arr[i]-count;
            count++;
        }
        else
        {
            total+=arr[i]-count;
        }
    }
    //cout<<"total:"<<total<<endl;
    return total;
}
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n,target;
        cin>>n>>target;
        vector<int>arr(n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        if(sum < target)
        {
            cout<<"-1"<<endl;
            continue;
        }
        else
        {
            int left=1;
            int right=n;
            while(left < right)
            {
                int mid = (left+right)/2;
                if(Count(mid,arr) >= target)
                {
                    right = mid;
                }
                else
                {
                    left = mid+1;
                }
            }
            cout<<left<<endl;
        }
    }
    return 0;
}