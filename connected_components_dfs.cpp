//Count the number of components in a graph
#include <bits/c++config.h>
#include<iostream>
#include<cstdlib>
#include<map>
#include<list>
using namespace std;

class Graph{
    map<int,list<int>> l;
    public : 
    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void dfs_helper(int src, map<int, bool> &visited){
        cout<<src<<" ";
        visited[src]=true;
        for(int val : l[src]){
            if(!visited[val]){
                dfs_helper(val,visited);
            }
        }
    }
    void dfs(){
        map<int, bool> visited;
        for(auto val : l){
            int node = val.first;
            visited[node]=false;
        }
        int count=0;
        for(auto val : l){
            int node = val.first;
            if(!visited[node]){
                cout<<"Component "<<count<<"--->";
                dfs_helper(node,visited);
                count++;
                cout<<endl;
            }
        }
    }

};

int main(){
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(0,4);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(8,8);
    g.dfs();
}