#include<iostream>
#include<vector>
using namespace std;
bool around(vector<int>a,vector<int>b,int r)
{
    //cout << "dist:" << (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]) <<endl;
    return ((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]) <= r*r);
}
int DFS(int idx,vector<vector<int>>& coord, vector<bool>&check,int r)
{
    int n = coord.size();
    int found = 0;
    for(int i=0;i<n;i++)
    {
        if(i!=idx && around(coord[i],coord[idx],r))
        {
            //cout<<"found:"<< i <<endl;
            found++;
            if(!check[i])
            {
                
                check[i] = true;
                DFS(i,coord,check,r);
            }
        }
    }
    return found;
} 
int main()
{
    int n,r;
    cin >> n >> r;
    vector<bool>check(n,false);
    vector<vector<int>>coord(n,vector<int>(2,0));
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        coord[i][0] = x;
        coord[i][1] = y;
    }
    int connected = 0;
    int isolated = 0;
    for(int i=0;i<n;i++)
    {
        
        if(!check[i])
        {
            check[i] = true;
            if(DFS(i,coord,check,r) >= 1)
            {
                connected++;
            }
            else
            {
                isolated++;
            }
        }
        
    
    
    /*
        for(auto b:check)
        {
            cout << b << " ";
        }
        cout << endl;
    */
    }
    cout << isolated << " " << connected << endl;
    return 0;
}