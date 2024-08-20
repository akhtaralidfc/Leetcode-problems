class Solution {
public:
    int find(vector<int> &prices, int i,int k,bool buy,vector<vector<int>> &v,int kk)
    {
        if(i>=prices.size()||k<=0) return 0;
        if(v[i][buy]!=-1) return v[i][buy];
        
        if(buy)  //if we are buying then next time we will sell else next time we will buy
        {        //-prices[i], because bought stock of prices[i], expend money
            
           return v[i][buy]=max(-prices[i]+find(prices,i+k,k,!buy,v,kk),find(prices,i+1,k,buy,v,kk)); 
        }
        else    //it's time to sell , now decrease k, we have done 1 transaction
        {       //+prices[i], because we now gain (i.e) sell our stock at rate of prices[i]
           return v[i][buy]=max( prices[i]+find(prices,i+1,k-1,!buy,v,kk),find(prices,i+1,k,buy,v,kk)); 
        }
    }
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size(); 
        // vector<vector<int>> v(n,vector<int> (2,-1));
        // //passing here buy=1 because we will first buy then sell
        // //we can do atmost k=1 transaction
        // return find(prices,0,1,1,v);
        int i=0,j=1;
        int mini=prices[0];
        int ans=0;
        for(int j=1;j<n;j++){
            mini=min(mini,prices[i]);
            ans=max(ans,prices[j]-mini);
            // mini=min(mini,prices[i]);
            i++;
        }
        return ans;
    }
};