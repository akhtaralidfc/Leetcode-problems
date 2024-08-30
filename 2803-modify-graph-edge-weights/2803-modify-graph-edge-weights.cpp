class Solution {
public:
    void dijktra(const vector<vector<pair<int, int>>>& adj, vector<vector<int>>& edges, vector<vector<int>>& dist, int source, int diff, int run) {
        int n=adj.size();
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<>> q;
        q.push({0,source});
        dist[source][run]=0;

        while(!q.empty()){
            auto [curdis,curnode]=q.top();
            q.pop();

            if(curdis>dist[curnode][run]) continue;

            for(auto& it: adj[curnode]){
                int nextnode=it.first,edgeIndex=it.second;
                int weight=edges[edgeIndex][2];
                // cout<<nextnode<<":"<<weight<<"\n";

                if(weight==-1) weight=1; 

                if(run==1 && edges[edgeIndex][2]==-1){
                    int newWeight=diff+dist[nextnode][0]-dist[curnode][1];
                    if(newWeight>weight){
                        edges[edgeIndex][2]=weight=newWeight;
                    }
                }

                if(dist[nextnode][run]>dist[curnode][run]+weight) {
                    dist[nextnode][run]=dist[curnode][run]+weight;
                    q.push({dist[nextnode][run], nextnode});
                }
            }
        }
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int nodeA=edges[i][0];
            int nodeB=edges[i][1];
            adj[nodeA].push_back({nodeB,i});
            adj[nodeB].push_back({nodeA,i});
        }
        vector<vector<int>> dist(n,vector<int>(2,INT_MAX));
        dist[source][0]=dist[source][1] = 0;
        dijktra(adj,edges,dist,source,0,0);

        int diff=target-dist[destination][0];
        if(diff<0) return {}; 
        dijktra(adj,edges,dist,source,diff,1);
        if(dist[destination][1]<target) return {}; 
        for(auto& it: edges){
            if(it[2]==-1) it[2]=1;
        }
        return edges;
    }
};