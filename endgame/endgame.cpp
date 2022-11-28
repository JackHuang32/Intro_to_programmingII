#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef struct list_
{
    /* data */
    int x;
    int y;
    int dis;
    list_(int x_,int y_,int z_)
    {
        /* data */
        x = x_;
        y = y_;
        dis = z_;
    };
    
}list;
char map[1000][1000];
int n,m;
queue<list>check_list;
void show()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
}

int BFS(int start_x,int start_y,int enemy,int step)
{
    list start(start_x,start_y,step);
    check_list.push(start);
    
    while(!check_list.empty())
    {
        
        //cout<<"---------------------"<<endl;
        //show();
        list cur = check_list.front();
        //cout<<"x:"<<cur.x<<" y:"<<cur.y<<endl;
        check_list.pop();
        int x = cur.x,y = cur.y;
        int next_x,next_y,next_dis;
        for(int i=1;i<=4;i++)
        {
            switch(i)
            {
                case 1:
                    next_x = x;
                    next_y = y+1;
                    next_dis = cur.dis+1;
                    break;
                case 2:
                    next_x = x+1;
                    next_y = y;
                    next_dis = cur.dis+1;
                    break;
                case 3:
                    next_x = x-1;
                    next_y = y;
                    next_dis = cur.dis+1;
                    break;
                case 4:
                    next_x = x;
                    next_y = y-1;
                    next_dis = cur.dis+1;
                    break;
                default:
                    break;
            }
            if(next_x<0 || next_x>=n || next_y < 0 || next_y >= m)
            {
                continue;
            }
            else if(map[next_x][next_y] == '0' || map[next_x][next_y] == 'C')
            {
                continue;
            }
            else if(map[next_x][next_y] == '.')
            {
                check_list.push(list(next_x,next_y,next_dis));
            }
            else if(map[next_x][next_y] == 'T')
            {
                check_list.push(list(next_x,next_y,next_dis));
                enemy--;
                //cout<<"enemy:"<<enemy<<endl;
                if(enemy==0)
                {
                    return cur.dis+1;
                }            
            }    
            map[next_x][next_y] = '0';
        
        }
        
        map[cur.x][cur.y] = '0';
    }
    return -1;
}

int main()
{
    int init_x,init_y,enemy=0;
    cin >> n >> m;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char tmp;
            cin >> tmp;
            map[i][j] = tmp;
            if(map[i][j] == 'I')
            {
                init_x = i;
                init_y = j;
            }
            if(map[i][j] == 'T')
            {
                enemy++;
            }
        }
    }
    
    int step = BFS(init_x,init_y,enemy,0);
    cout<<step<<endl;
    return 0;
}