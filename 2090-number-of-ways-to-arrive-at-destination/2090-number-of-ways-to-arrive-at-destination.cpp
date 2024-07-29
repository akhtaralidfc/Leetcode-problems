class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long,long>> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        //coz the cost's range is beyond the capacity of int data type
        vector<long> dist(n,LONG_MAX);
        vector<int> ways(n,0);
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<>> q;
        dist[0]=0;
        ways[0]=1;
        //{dist,node}
        q.push({0,0});

        int modd=(int)(1e9+7);
        while(!q.empty()){
            auto it=q.top();
            q.pop();

            long node=it.second;
            long curdis=it.first;
            for(auto it2: adj[node]){
                long adjnode=it2.first;
                long edjw=it2.second;
                //if the next node is visited 1st time then we'll update the ways of the next visisted node 
                //with same number of ways of cur node 
                if(curdis+edjw<dist[adjnode]){
                    dist[adjnode]=curdis+edjw;
                    q.push({curdis+edjw,adjnode});
                    ways[adjnode]=ways[node];
                }
                //else the node is already been visited by x number of ways, we are supposed to 
                //just add the older number of ways to the current number of ways of the node that it is having right now with itself
                else if(curdis+edjw==dist[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node])%modd;
                }
            }
        }
        return ways[n-1]%modd;
    }
};