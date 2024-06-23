class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans=0,n=nums.size();
        multiset<int> m;
        int i=0,j=0;
        while(j<n){
            m.insert(nums[j]);
            while(*(m.rbegin())-*(m.begin())>limit){
                m.erase(m.find(nums[i++]));
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};