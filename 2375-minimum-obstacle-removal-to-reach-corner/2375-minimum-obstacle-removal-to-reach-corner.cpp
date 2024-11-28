class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,1e9));
        queue<pair<int,int>> q;
        q.push({0,0});
        dp[0][0]=0;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x=dx[i]+curr.first;
                int y=dy[i]+curr.second;
                if(x>=0 && y>=0 && x<m && y<n && grid[x][y]+dp[curr.first][curr.second]<dp[x][y]){
                    dp[x][y]=grid[x][y]+dp[curr.first][curr.second];
                    q.push({x, y});
                }
            }
        }
        return dp[m-1][n-1];
    }
};