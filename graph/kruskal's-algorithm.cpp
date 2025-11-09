    #include <bits/stdc++.h>
    using namespace std;

class Graph {
    int V;
    vector<vector<pair<int,int>>> adj; // <neighbor, weight>

public:
    Graph(int v) {
        V = v;
        adj.resize(v);
    }

    void addDirectedEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
    }

    void addUndirectedEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << ": ";
            for (auto [neighbor, wt] : adj[i]) {
                cout << "(" << neighbor << ", " << wt << ") ";
            }
            cout << "\n";
        }
    }

    // BFS (ignores weights, just traversal)
    void BFSTraversal() {
        vector<bool> visited(V, false);
        queue<int> q;

        for (int start = 0; start < V; start++) {
            if (!visited[start]) {
                q.push(start);
                visited[start] = true;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    cout << node << " ";

                    for (auto [neighbor, wt] : adj[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }
            }
        }
        cout << "\n";
    }

    // DFS
    void DFSUtil(int node, vector<bool> &visited) {
        visited[node] = true;
        cout << node << " ";
        for (auto [neighbor, wt] : adj[node]) {
            if (!visited[neighbor]) DFSUtil(neighbor, visited);
        }
    }

    void DFSTraversal() {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) DFSUtil(i, visited);
        }
        cout << "\n";
    }
};


    class DisjointSet {
    private:
        vector<int> parent;
        vector<int> rank;  // or size, depending on approach

    public:
        // Constructor
        DisjointSet(int n) {
            parent.resize(n + 1);
            rank.resize(n + 1, 0);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
            // initialize parent and rank/size here
        }

        // Find ultimate parent (with path compression)
        int findUPar(int node) {
            // your logic here
            if(node!=parent[node]){
                parent[node] = findUPar(parent[node]);
            }
            return parent[node];
        }

        // Union by rank
        void unionByRank(int u, int v) {
            int pu=findUPar(u);
            int pv=findUPar(v);
            if(pu!=pv){
                if(rank[pu]<rank[pv]){
                    parent[pu]=pv;
                }
                else if(rank[pv]<rank[pu]){
                    parent[pv]=pu;
                }
                else{
                    parent[pv]=pu;
                    rank[pu]++;
                }
            }
            return;
            // your logic here
        }

        // Check if two nodes belong to the same component
        bool isConnected(int u, int v) {
            if(findUPar(u)==findUPar(v))return true;
            else return false;
        }
    };


    class Kruskal_algo{

        public:
        
        int spanningTree(int V,vector<vector<pair<int,int>>>&graph){//graph has a pair, first is node connected and second is weight
            vector<pair<int,pair<int,int>>>edges;//weight node1 node2

            for(int i=0;i<V;i++){
                for(auto x:graph[i]){
                    edges.push_back({x.second,{i,x.first}});
                }
            }//here, edges get completed
            sort(edges.begin(),edges.end());
            int totalWeight=0;
            DisjointSet ds(V);
            for(auto it:edges){
                int weight=it.first;
                int node1=it.second.first;
                int node2=it.second.second;

                if(ds.findUPar(node1)!=ds.findUPar(node2)){
                    ds.unionByRank(node1,node2);
                    totalWeight+=weight;
                }
            }
            return totalWeight;
        }
    };
        // int main() {
        //     int n = 7; // example size
        //     DisjointSet ds(n);

        //     // Example usage
        //     // ds.unionBySize(1, 2);
        //     ds.unionByRank(3, 4);
            
        //     if (ds.isConnected(1, 3)) {
        //         cout << "Connected\n";
        //     } else {
        //         cout << "Not connected\n";
        //     }

        //     return 0;
        // }
