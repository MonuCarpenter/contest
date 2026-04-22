// #include <bits/stdc++.h> 

// using namespace std;

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     // adjacency list for directed graph
//     // time complexity: O(E)
//     vector<int> adj[n+1];
//     for(int i = 0; i < m; i++)
//     {
//         int u, v;
//         // u —> v
//         cin >> u >> v;
//         adj[u].push_back(v);
//     }
//     return 0;
// }
// /Users/monucarpenter/Documents/Notebooks/DSA.pdf

// connected components in undirected graph 

#include <bits/stdc++.h>

using namespace std; 

class Solution { 
    public: 
    int countComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);

        for(auto &e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // a vector to keep track of visited nodes 
        vector<int> visited(V, 0); 

        // variable to count the number of connected components 
        int components = 0; 

        //Traverse all the nodes in the graph 

        for(int i=0; i<V; i++) { 
            if(visited[i]) continue; 

            components++; 

            //start bfs for this node
            queue<int> q; 
            q.push(i); 
            visited[i] = 1; 

            
        }
        return components 
    }

    int V = 5; 

    //list of unidirected edges. 
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}}; 

    //creating a solution object 
    Solution sol; 

    //printing the number of connected components in the graph 
    cout << sol.countComponents(V, edges) << endl;

    return 0; 
}