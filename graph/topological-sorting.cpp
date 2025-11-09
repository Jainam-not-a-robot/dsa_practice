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

        void topological_sorting(int u,vector<bool>&visited,stack<int>&s){
            visited[u]=true;
            for(int x:graph[u]){
                if(!visited[x])topological_sorting(x,visited,s);
            }
            s.push(u);
        }

        vector<int> topo_caller(){
            vector<bool>visited(v,false);
            stack<int>s;
            for(int i=0;i<v;i++){
                if(!visited[i])topological_sorting(i,visited,s);
            }
            
            vector<int>topo_order;
            while(!s.empty()){
                topo_order.push_back(s.top());
                s.pop();
            }
            return topo_order;
        }
};
int main(){

}