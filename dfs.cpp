#include<iostream>
#include<cstdlib>
#include<queue>
#include<cstring>

using namespace std;
int Time;
struct vertices
{
    string color;
    int parent;
    int d;
    int f;
    vector<int> adjList;
};
struct vertices vert[8];

void dfs_visit(int u)
{
Time=Time+1;
    vert[u].d=Time;
    vert[u].color="Gray";
    cout<<u<<" "; 
    for(int val : vert[u].adjList)
    {
        if(vert[val].color=="White")
        {
            vert[val].parent=u;
            dfs_visit(val);
        }
    }
    vert[u].color="Black";
    Time=Time+1;
    vert[u].f=Time;
}

void dfs()
{
    for(int i=7;i>=0;i--)
    {
        vert[i].color="White";
        vert[i].parent=-1;
    }
    Time=0;
    for(int i=7;i>=0;i--)
    {
        if(vert[i].color=="White")
        {
            dfs_visit(i);
        }
    }
}

int main()
{
    vert[0].adjList={1,3};
    vert[1].adjList={0,2};
    vert[2].adjList={1};
    vert[3].adjList={0,4,7};
    vert[4].adjList={3,7,6,5};
    vert[5].adjList={4,6};
    vert[6].adjList={7,4,5};
    vert[7].adjList={3,4,6};
    dfs();
}