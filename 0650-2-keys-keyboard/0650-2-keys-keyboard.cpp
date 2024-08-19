class Solution {
public:
    int solve(int steps,int value,int copy,int n,vector<vector<int>> &dp){
        if(steps>n || value>n) return 1e9;
        if(value==n) return steps;
        if(dp[steps][value]!=-1) return dp[steps][value];
        int paste=solve(steps+1,value+copy,copy,n,dp);
        int copyyy=solve(steps+2,2*value,value,n,dp);
        return dp[steps][value]=min(copyyy,paste);
    }
    int minSteps(int n) {
        if(n==1) return 0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,1,1,n,dp);
    }
};