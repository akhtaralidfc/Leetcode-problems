class Solution {
public:
    int incr(vector<int> &nums){
        int ans=0,cnt=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]) cnt++;
            else{
                ans=max(ans,cnt);
                cnt=1;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
    int decr(vector<int> &nums){
        int ans=0,cnt=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]) cnt++;
            else{
                ans=max(ans,cnt);
                cnt=1;
            }
        }
        ans=max(ans,cnt);
        return ans;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        return max(incr(nums),decr(nums));
    }
};