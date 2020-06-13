#include<iostream>
#include<cstdlib>
#include<queue>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;
int Time;
struct vertices
{
    int vertNo;
    string color;
    int parent;
    int d;
    int f;
    vector<int> adjList;
};
stack<int> s;
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
    s.push(u);
}

void dfs()
{
    for(int i=1;i<=5;i++)
    {
        vert[i].color="White";
        vert[i].parent=-1;
    }
    Time=0;
    for(int i=1;i<=5;i++)
    {
        if(vert[i].color=="White")
        {
            dfs_visit(i);
        }
    }
}

int main()
{
    vert[1].adjList={2,3};
    vert[1].vertNo=1;
    vert[2].adjList={3,4};
    vert[2].vertNo=2;
    vert[3].adjList={4,5};
    vert[3].vertNo=3;
    vert[4].adjList={};
    vert[4].vertNo=4;
    vert[5].adjList={};
    vert[5].vertNo=5;
    dfs();
    cout<<"After topological sort : \n";
    // sort(vert, vert+5, custom_sort);
    for(int i=1;i<=5;i++)
        cout<<vert[i].f<<" ";
    cout<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    
}