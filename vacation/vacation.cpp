#include<iostream>
#include<vector>
int max(int a,int b){return (a>b)?a:b;}
int max(int a,int b,int c)
{
    return max(a,max(b,c));
}
int main()
{
    int row;
    std::cin>>row;
    std::vector<std::vector<int>>arr(row,std::vector<int>(3,0));
    //std::cout<<"here\n";
    for(auto &n:arr)
    {
        for(auto &num:n)
        {
            
            
            int tmp;
            std::cin>>tmp;
            num = tmp;
            
        }
    }
    for(int i=1;i<row;i++)
    {
        for(int j=0;j<3;j++)
        {
            arr[i][j] += max(arr[i-1][(j+1)%3],arr[i-1][(j+2)%3]);
        }
    }
    std::cout<<max(arr[row-1][0],arr[row-1][1],arr[row-1][2])<<std::endl;
    return 0;
}