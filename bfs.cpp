#include<iostream>
#include<cstdlib>
#include<queue>
#include<cstring>

using namespace std;

struct vertices
{
    string color;
    int dist;
    int parent;
    vector<int> adjList;
    
};
int n;
vector<int> prev;
struct vertices vert[8];

//Finding shortest path between source and destination
void bfs(int src, int dest)
{
    for(int i=0;i<=7;i++)
    {
        if(i!=src)
        {
            vert[i].color="White";
            vert[i].dist=9999;
            vert[i].parent=-1;
            cout<<"Parent of "<<i<<" is : "<<vert[i].parent<<endl;
        }
    }
vert[src].color="Gray";
vert[src].dist=0;
vert[src].parent=-1;
queue<int> q;
q.push(src);
// prev.push_back(src);
while(!q.empty())
{
    int u = q.front();
    q.pop();
    for(int vertex : vert[u].adjList)
    {
        if(vert[vertex].color=="White")
        {
            vert[vertex].color="Gray";
            vert[vertex].dist= vert[u].dist+1;
            vert[vertex].parent = u;
            // prev.push_back(u);//for the path
            q.push(vertex);
            // if(vertex==dest)
            // break;
        }
    }
    vert[u].color="Black";
    
}
cout<<"Parent of 7 is : "<<vert[7].parent<<endl;
    
}

int print(int src, int dest)
{
    if(dest==src)
        return src;
    cout<<vert[dest].parent<<" ";
    print(src,vert[dest].parent); 
}

int main()
{
    // int n;
    int source = 1;
    
    vert[0].adjList={1,3};
    vert[1].adjList={0,2};
    vert[2].adjList={1};
    vert[3].adjList={0,4,7};
    vert[4].adjList={3,7,6,5};
    vert[5].adjList={4,6};
    vert[6].adjList={7,4,5};
    vert[7].adjList={3,4,6};
    bfs(0,7);
    print(0,7);
    
}


/*
    1 ---- 0      7 ---- 6
    |      |      |      |
    2      3 ---- 4 ---- 5

*/