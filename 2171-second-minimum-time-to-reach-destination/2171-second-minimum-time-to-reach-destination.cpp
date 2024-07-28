class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> adj[n+1];
        for(auto it: edges){
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }
        // for(auto it: edges){
        //     adj[it[0]].push_back(it[1]);
        //     adj[it[1]].push_back(it[0]);
        // }
        vector<priority_queue<int>> dis(n+1);
        for(int i=0;i<n;i++) dis[i].push(1e9);
        dis[0].pop();
        dis[0].push(0);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
        q.push({0,0});
        while(!q.empty()){
            int dist=q.top().first;
            int node=q.top().second;
            q.pop();

            int k=dist/change;
            if(k%2==1){
                dist+=(change-dist%change);
            }

            for(auto it: adj[node]){
                int adjdis=dist+time;
                if(dis[it].top()==1e9){
                    dis[it].pop();
                    dis[it].push(adjdis);
                    q.push({adjdis,it});
                }
                else if(dis[it].size()<2 && dis[it].top()!=adjdis){
                    dis[it].push(adjdis);
                    q.push({adjdis,it});
                }
                else{
                    if(dis[it].top()>adjdis){
                        dis[it].pop();
                        dis[it].push(adjdis);
                        q.push({adjdis,it});
                    }
                }
            }
        }
        return dis[n-1].top();
    }
};