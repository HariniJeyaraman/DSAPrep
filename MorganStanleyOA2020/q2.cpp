/*
*Question 2 in Morgan Stanley Online Assessment test on AMCAT Aspiring Minds platform

*The delivery section of the e-commerce company EasyShop warehouse has a heirachical architecture. The main delivery unit
*is at the top of the heirarchy. Each delivery unit can have zero or more then zero delivery units attached. There are total 
*of N delivery units present in the warehouse. Each delivery unit is identified with ID from 1 to N. The delivery units deliver
*the products in batches. Out of these N delivery units, only R delivery units have a batch of products ready for pickup. 
*The company uses automated self-driving vehicles for pickups. The vehicle can start from any delivery unit and and can take
*any path to the next unit, but it cannot traverse the same path again.

*Write an algorithm to help the vehicle pick up the maximum number of batches of products.

*INPUT :
*1st line consists of 2 space separated integers - num and batchNum - representing the number of delivery units (N) and the number 
*of batches of products (R), respectively
*The second line consists of R space-separated integers, representing the delivery units containing the product batches
*The next N-1 lines consist of space-separated integers - idx and idy - representing the pair of units connected by a path

*OUTPUT :
*Print an integer representing the maximum number of batches that the vehicle can collect.

*CONSTRAINTS :
*1 <= batchNum <= 10^5
*1 <= idx,idy <= num
*/
#include<iostream>
#include<cstdlib>
#include<unordered_map>
#include<vector>
using namespace std;

struct node{
    int val;
    unordered_map<int,vector<int>> adj;
};

void add_edge(node* g, node* x, node* y){
    g->adj[x->val].push_back(y->val);
    g->adj[y->val].push_back(x->val);
}

node* create_node(int x){
    node* newnode = new node();
    newnode->val=x;
    return newnode;
}

unordered_map<int, bool> visited;
int result=INT8_MIN;
void dfs_visit(int source, node* graph, string s, int num_nodes, int c, unordered_map<int,int> nodes_to_cover){
    if(visited[source]==false){
        visited[source]=true;
        s+=to_string(source);
        num_nodes++;
        if(nodes_to_cover.find(source)!=nodes_to_cover.end())
            c++;
        //leaf node
       if(graph->adj[source].size()==1){
           result=max(result,c);
           cout<<"num nodes is : "<<num_nodes<<"\n";
           cout<<s<<"\n";
           cout<<"batch local : "<<c<<"\n";
       }
        
        // cout<<source<<" ";
        for(auto el : graph->adj[source]){
                if(visited[el]==false){
                    dfs_visit(el, graph, s, num_nodes, c, nodes_to_cover);
                }
        }
    }
}

void dfs(node* graph, unordered_map<int,int> nodes_to_cover){
    for(auto val : graph->adj){
        if(visited[val.first]==false){
            cout<<"Entered\n";
            dfs_visit(val.first, graph, "", 0, 0, nodes_to_cover);
            cout<<"\n";
        }
    }
}

int main(){
    int n,r;
    node* graph = new node();
    cin>>n>>r;
    unordered_map<int,int> nodes_to_cover(r);
    int val;
    for(int i=0;i<r;i++){
        cin>>val;
        nodes_to_cover[val]=i;
    }
        int x,y;
    for(int i=0;i<n-1;i++){
        cin>>x>>y;
        node* n1 = create_node(x);
        node* n2 = create_node(y);
        add_edge(graph, n1, n2);
    }
    //printing adj list
    for(auto el : graph->adj){
        cout<<el.first<<" : ";
        for(int val : el.second){
            cout<<val<<" ";
        }
        cout<<"\n";
    }
    for(auto el : visited)
        el.second=false;

    dfs(graph, nodes_to_cover);
    //Final output
    cout<<"Max batches covered is : "<<result<<endl;
}
