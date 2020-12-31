/*
Minimum number of dice throws required to reach the destination 36 starting from the source.
Find the shortest path also
*/

#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
#include<map>
#include<list>
using namespace std;

template<typename T>
class Graph{
    map<T,list<T>> l;
    public : 
        void addEdge(int x, int y){
            l[x].push_back(y);
        }

        int bfs(T src, T dest){
            map<T, int> dist;
            map<T, T> parent;
            queue<T> q;

            //All other nodes will have inf distance from source
            for(auto node_pair : l){
                T node = node_pair.first;
                dist[node] = INT8_MAX;
            }
            q.push(src);
            dist[src] = 0;
            parent[src] = src;

            while(!q.empty()){
                T node = q.front();
                q.pop();
                for(auto val : l[node]){
                    //if node is not visited
                    if(dist[val] == INT8_MAX){
                        q.push(val);
                        //mark the node as visited
                        dist[val] = dist[node] + 1;
                        parent[val] = node;
                    }
                }
            }
            //Print the path src to dest node
            int temp = dest;
            while(temp!=src){
                cout<<temp<<"<----";
                temp = parent[temp];
            }
            cout<<src<<endl;
            return dist[dest];
        }
};





int main(){
    //Input
    int board[50]={0};

    //Snakes //Ladders
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;

    //Add edges to the Graph
    Graph<int> g;
    for(int i=0;i<=36;i++){
        for(int dice=1;dice<=6;dice++){
            int j = i+dice;
            j += board[j];
            if(j<=36){
                g.addEdge(i,j);
            }
        }
    }
    //considering node 36
    g.addEdge(36,36);
   cout<<"Min throws of dice : "<< g.bfs(0,36)<<endl;

}