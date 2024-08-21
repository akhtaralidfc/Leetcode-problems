class Solution {
public:
    int f(int i,int last,vector<int>& prices,vector<vector<int>> &dp){
        int n =prices.size();
        if(i==n) return 0;
        if(dp[i][last]!=-1) return dp[i][last];
        int p1=f(i+1,i,prices,dp)+prices[i];
        int p2=INT_MAX;
        if(i<=last+last+1 && last!=n){
            p2=f(i+1,last,prices,dp);
        }
        return  dp[i][last]=min(p1,p2);
    }
    int minimumCoins(vector<int>& prices) {
        int n =prices.size();
        vector<vector<int>> dp(n+1,vector(n+1,-1));
        return f(0,n,prices,dp);
    }
};