#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool around(vector<int>first,vector<int>second,int r)
{
    return (pow(first[0]-second[0],2)+pow(first[1]-second[1],2)) <= pow(r,2);
}
void DFS(vector<vector<int>>&map,vector<bool>&check,int r,int pos,int& size)
{
    int n = map.size();
    for(int i=0;i<n;i++)
    {
        if(!check[i] && around(map[i],map[pos],r))
        {
            check[i] = true;
            size++;
            DFS(map,check,r,i,size);
        }
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,r,k;
        cin>>n>>r>>k;
        vector<vector<int>>map(n,vector<int>(2,0));
        vector<bool>check(n,false);
        for(int i=0;i<n;i++)
        {
            cin >> map[i][0] >> map[i][1];
        }
        int above = 0;
        int connected = 0;
        for(int i=0;i<n;i++)
        {
            if(!check[i])
            {
                check[i] = true;
                int num = 0;
                DFS(map,check,r,i,num);
                if(num+1 >= k)
                {
                    above++;
                }
                connected++;
            }
        }
        cout << connected-above <<" "<<above<<endl; 
    }
    return 0;
}