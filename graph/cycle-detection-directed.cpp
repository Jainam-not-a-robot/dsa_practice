#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    vector<vector<int>>graph;
    public:
        Graph(int v){
            this->v=v;
            graph.resize(v);
        }

        void addDirectedEdge(int u,int v){
            graph[u].push_back(v);
        }
        void addUndirectedEdge(int u,int v){
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        void printGraph(){
            for(int i=0;i<v;i++){
                cout << "Node " << i << ": ";
                for (int neighbor : graph[i]) {
                    cout << neighbor << " ";
                }
                cout << "\n";
            }
        }

        void BFSTraversal(){
            queue<int>q;
            q.push(0);
            vector<bool>visited(v,false);
            while(!q.empty()){
                int a=q.front();
                q.pop();
                cout<<a<<' ';
                for(int x:graph[a]){
                    if(!visited[x]){
                        q.push(x);
                        visited[x]=true;
                    }
                }
            }
        }
        void DFSTraversal(int u,vector<bool>&visited){
            cout<<u<<' ';
            visited[u]=true;
            for(int x:graph[u]){
                if(!visited[x])DFSTraversal(x,visited);
            }
        }

        bool detectCycleByDFS(int u,vector<bool>&visited,vector<int>&recPath){
            visited[u]=true;
            for(int x:graph[u]){
                if(!visited[x]){
                    recPath.push_back(u);
                    if(detectCycleByDFS(x,visited,recPath))return true;
                }
                else{
                    for(int y:recPath){
                        if(y==u)return true;
                    }
                }
            }
            recPath.pop();
            return false;
        }
};

int main() {
    // ---------- Test Case 1 ----------
    cout << "Test Case 1:\n";
    Graph g1(4);
    g1.addDirectedEdge(0, 1);
    g1.addDirectedEdge(1, 2);
    g1.addDirectedEdge(2, 3);
    vector<bool> visited1(4, false);
    vector<int> recPath1;
    cout << (g1.detectCycleByDFS(0, visited1, recPath1) ? "Cycle detected\n\n" : "No cycle\n\n");

    // ---------- Test Case 2 ----------
    cout << "Test Case 2:\n";
    Graph g2(4);
    g2.addDirectedEdge(0, 1);
    g2.addDirectedEdge(1, 2);
    g2.addDirectedEdge(2, 0);  // Cycle: 0 -> 1 -> 2 -> 0
    vector<bool> visited2(4, false);
    vector<int> recPath2;
    cout << (g2.detectCycleByDFS(0, visited2, recPath2) ? "Cycle detected\n\n" : "No cycle\n\n");

    // ---------- Test Case 3 ----------
    cout << "Test Case 3:\n";
    Graph g3(5);
    g3.addDirectedEdge(0, 1);
    g3.addDirectedEdge(1, 2);
    g3.addDirectedEdge(2, 3);
    g3.addDirectedEdge(3, 4);
    g3.addDirectedEdge(4, 2);  // Cycle: 2 -> 3 -> 4 -> 2
    vector<bool> visited3(5, false);
    vector<int> recPath3;
    cout << (g3.detectCycleByDFS(0, visited3, recPath3) ? "Cycle detected\n\n" : "No cycle\n\n");

    // ---------- Test Case 4 ----------
    cout << "Test Case 4:\n";
    Graph g4(3);
    g4.addDirectedEdge(0, 1);
    g4.addDirectedEdge(1, 2);
    g4.addDirectedEdge(2, 2);  // Self-loop at node 2 → cycle
    vector<bool> visited4(3, false);
    vector<int> recPath4;
    cout << (g4.detectCycleByDFS(0, visited4, recPath4) ? "Cycle detected\n\n" : "No cycle\n\n");

    // ---------- Test Case 5 ----------
    cout << "Test Case 5:\n";
    Graph g5(6);
    g5.addDirectedEdge(0, 1);
    g5.addDirectedEdge(1, 2);
    g5.addDirectedEdge(2, 3);
    g5.addDirectedEdge(3, 4);
    g5.addDirectedEdge(4, 5);
    vector<bool> visited5(6, false);
    vector<int> recPath5;
    cout << (g5.detectCycleByDFS(0, visited5, recPath5) ? "Cycle detected\n\n" : "No cycle\n\n");

    return 0;
}

