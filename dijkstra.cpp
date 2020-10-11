#include <bits/stdc++.h>
using namespace std;

// #define n 7;
#define inf 1000000
struct node{
    int val;
    unordered_map<int, vector<pair<int, int> >> adj;
};

int n; //number of vertices
int e; //edges

node* create_node(int val){
    node* dummy = new node();
    dummy->val = val;
    return dummy;
}

void add_edge(node* u, node* v, int w, node* g){
    g->adj[u->val].push_back(make_pair(v->val,w));
    g->adj[v->val].push_back(make_pair(u->val,w));
}

int find_min(int dist[], bool visited[]){
    int minv = INT32_MAX, minInd=0;
    for(int i=0;i<n;i++){
        if(dist[i]<minv && visited[i]==false){
            minv = dist[i];
            minInd = i;
        }
    }   
    return minInd;
}   

void dij(int src, int dist[], bool visited[], node* g){
    for(int i=0;i<n;i++) visited[i] = false;
    for(int i=1;i<n;i++) dist[i]= inf;
    dist[src] = 0;
    for(int i=0;i<n;i++){
        // int u=i;
        int u = find_min(dist, visited);
        cout<<"u is : "<<u<<endl;
        visited[u] = true;
        for(auto el : g->adj[u]){
            if(visited[el.first] == false && (dist[u] + el.second < dist[el.first])){
                dist[el.first] = dist[u] + el.second;
            }
        }
    }
    cout<<"dist : \n";
    for(int i=0;i<n;i++) cout<<dist[i]<<" ";

}


int main(){
    n=7;
    e=8;
    node* g = new node();
    add_edge(create_node(0), create_node(1), 100, g);
    add_edge(create_node(1), create_node(2), 60, g);
    add_edge(create_node(0), create_node(2), 800, g);
    add_edge(create_node(2), create_node(3), 700, g);
    add_edge(create_node(1), create_node(4), 200, g);
    add_edge(create_node(4), create_node(5), 500, g);
    add_edge(create_node(4), create_node(6), 100,g);
    add_edge(create_node(6), create_node(5), 50, g);

    for(auto val : g->adj){
        cout<<"u : "<<val.first<<" : ";
        for(auto el : val.second){
            cout<<"v : "<<el.first << " w : "<<el.second<<" ";
        }
        cout<<endl;
    }    
    int dist[n];
    bool visited[n];
    dij(0, dist, visited, g);
    cout<<endl;

}