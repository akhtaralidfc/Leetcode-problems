class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=26;
        vector<vector<long long>> dist(n,vector<long long>(n,LLONG_MAX));
        for(int i=0;i<n;i++) dist[i][i]=0;
        for(int i=0;i<original.size();i++){
            dist[original[i]-'a'][changed[i]-'a']=min(dist[original[i]-'a'][changed[i]-'a'],(long long)cost[i]);
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]<LLONG_MAX && dist[k][j]<LLONG_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        long long totalcost=0;
        for(int i=0;i<source.size();i++){
            if(source[i] != target[i]){
                int src=source[i] - 'a';
                int tgt=target[i] - 'a';
                if(dist[src][tgt]==LLONG_MAX) return -1;
                totalcost+=dist[src][tgt];
            }
        }
        return totalcost<LLONG_MAX?totalcost:-1;
    }
};