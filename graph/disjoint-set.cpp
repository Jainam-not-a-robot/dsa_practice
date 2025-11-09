    #include <bits/stdc++.h>
    using namespace std;

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
                return findUPar(parent[node]);
            }
            return node;
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

    int main() {
        int n = 7; // example size
        DisjointSet ds(n);

        // Example usage
        // ds.unionBySize(1, 2);
        ds.unionByRank(3, 4);
        
        if (ds.isConnected(1, 3)) {
            cout << "Connected\n";
        } else {
            cout << "Not connected\n";
        }

        return 0;
    }
