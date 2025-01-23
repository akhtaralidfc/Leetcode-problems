class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int baby=0,n=grid.size(),m=grid[0].size();
        vector<int> rvec(n,0),cvec(m,0);
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(grid[i][j]==1) rvec[i]++,cvec[j]++;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(grid[i][j]==1 && (rvec[i]>1 || cvec[j]>1)) baby++;
        return baby;
    }
};