/*
1245. Tree Diameter
Medium

Given an undirected tree, return its diameter: the number of edges in a longest path in that tree.

The tree is given as an array of edges where edges[i] = [u, v] is a bidirectional edge between nodes u and v.  Each node has labels in the set {0, 1, ..., edges.length}.

 

Example 1:



Input: edges = [[0,1],[0,2]]
Output: 2
Explanation: 
A longest path of the tree is the path 1 - 0 - 2.
Example 2:



Input: edges = [[0,1],[1,2],[2,3],[1,4],[4,5]]
Output: 4
Explanation: 
A longest path of the tree is the path 3 - 2 - 1 - 4 - 5.
 

Constraints:

0 <= edges.length < 10^4
edges[i][0] != edges[i][1]
0 <= edges[i][j] <= edges.length
The given edges form an undirected tree.
*/

class Solution {
public:
    void dfs(int node, unordered_map<int, vector<int>> &adj, int depth, int &max_depth, int &m_node, vector<bool> &visited){
        if(visited[node]) return;
        if(depth>max_depth){
            max_depth = depth;
            m_node = node;
        }
        visited[node]=true;
        for(int i=0;i<adj[node].size();i++){
            dfs(adj[node][i], adj, depth+1, max_depth, m_node, visited);
        }
    }
    
    int treeDiameter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int m_node=edges[0][0];
        int max_depth=0;
        vector<bool> visited(adj.size(),false);
        dfs(edges[0][0],adj,0,max_depth,m_node,visited);
        for(int i=0;i<visited.size();i++)
            visited[i]=false;
        dfs(m_node,adj,0,max_depth,m_node,visited);
        return max_depth;
    }
};