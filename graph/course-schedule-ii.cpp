class Solution {
public:
    bool dfs(int u,vector<vector<int>>&graph,vector<bool>&visited,vector<bool>&recPath){
        visited[u]=true;
        recPath[u]=true;
        for(int &x:graph[u]){
            if(!visited[x]){
                if(dfs(x,graph,visited,recPath))return true;
            }
            else{
                if(recPath[x])return true;
            }
        }
        recPath[u]=false;
        return false;
    }
    void toposort(int u,vector<bool>&vis,vector<vector<int>>&graph,stack<int>&s){
        vis[u]=true;
        for(int x:graph[u]){
            if(!vis[x])toposort(x,vis,graph,s);
        }
        s.push(u);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<bool>visited(numCourses,false);
        vector<bool>recPath(numCourses,false);
        bool cond=false;
        for(auto &it:prerequisites){
            graph[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,graph,visited,recPath)){
                    vector<int>nullvec;
                    return nullvec;
                };
            }
        }
        vector<int>ans;
        vector<bool>vis(numCourses,false);
        stack<int>s;
        for(int i=0;i<numCourses;i++){

            if(!vis[i])toposort(i,vis,graph,s);
            
            
        }
        while(!s.empty()){
                ans.push_back(s.top());
                s.pop();
            }
        return ans;
    }
};