class Solution {
public:
    int bfs(int start, unordered_map<int, unordered_set<int>>& hashEdges, vector<bool> visited) {
        queue<int> q;
        q.push(start);
        visited[start]=true;
        int level=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                int node=q.front();
                q.pop();
                for(auto it: hashEdges[node]) {
                    if(visited[it]) continue;
                    q.push(it);
                    visited[it]=true;
                }
            }
            level++;
        }
        return level;
    }
    int checkConnectedBfs(int start, unordered_map<int, unordered_set<int>>& hashEdges, vector<bool>& vis) {
        vector<int> members;
        vector<bool> viscopy=vis;
        queue<int> q;
        q.push(start);
        members.push_back(start);
        vis[start]=true;
        int level=0;
        while(!q.empty()){
            int n=q.size();
            vector<int> collections;
            for(int i=0;i<n;i++){
                int node = q.front();
                q.pop();
                for(auto it: hashEdges[node]){
                    if(vis[it]) continue;
                    collections.push_back(it);
                    vis[it]=true;
                }
            }
            int m=collections.size();
            for(int i=0;i<m;i++){
                for(int j=0;j<i;j++){
                    if (hashEdges[collections[i]].count(collections[j])) return -1;
                }
            }
            for(int i=0;i<m;i++){
                q.push(collections[i]);
                members.push_back(collections[i]);
            }
            level++;
        }
        for(auto it: members){
            level=max(level,bfs(it,hashEdges,viscopy));
        }
        return level;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> hashEdges;
        for(auto it: edges){
            hashEdges[it[0]-1].insert(it[1]-1);
            hashEdges[it[1]-1].insert(it[0]-1);
        }
        vector<bool> vis(n,false);
        int maxRes=0;
        for(int node=0;node<n;node++){
            if(vis[node]) continue;
            int result=checkConnectedBfs(node,hashEdges,vis);
            if(result==-1) return -1;
            maxRes+=result;
        }
        return maxRes;
    }
};