#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main()
{
    int n,m;
    cin >>n>>m;
    vector<vector<int>>arr(n,vector<int>(m,0));
    int min = (int)INFINITY;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int tmp;
            cin>>tmp;
            if(tmp < min)
            {
                min = tmp;
            }
            arr[i][j] = tmp;
        }
    }   
    cout<<min<<endl;
    return 0;
}