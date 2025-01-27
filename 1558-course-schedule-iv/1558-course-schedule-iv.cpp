class Solution {
public:
    bool canvisit(int node, int target, vector<int> adj[], int n){
        queue<int> q;
        vector<int> vis(n,0);
        vis[node]=1;
        q.push({node});
        while(!q.empty()){
            int num = q.front();
            q.pop();
            if(num==target) return true;
            for(auto it: adj[num]){
                if(vis[it]==0){
                    if(it==target) return true;
                    q.push(it); vis[it]=1;
                }
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prereq, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(),false);
        if(prereq.size()==0) return ans;
        vector<int> adj[n];
        vector<int> indegree(n,0); 
        for(auto it: prereq){
            adj[it[0]].push_back(it[1]); 
            indegree[it[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++) if(indegree[i]==0) q.push(i);
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            topo.push_back(node);
            q.pop();

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        for(int i=0;i<queries.size();i++){
            int n1=queries[i][0];
            int n2=queries[i][1];
            for(int j=0;j<topo.size();j++){
                if(topo[j]==n1 && canvisit(n1,n2,adj,n) ){
                    ans[i]=true;
                    break;
                }
                if(topo[j]==n2){
                    break;
                }
            }
        }
        return ans;
    }
};