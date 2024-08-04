class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for(int i=0;i<n;i++) q.push({nums[i],i+1});
        int ans=0,mod=1e9+7;
        for(int i=1;i<=right;i++){
            auto p=q.top();
            q.pop();
            if(i>=left) ans=(ans+p.first)%mod;
            if(p.second<n){
                p.first += nums[p.second++];
                q.push(p);
            }
        }
        return ans;
    }
};