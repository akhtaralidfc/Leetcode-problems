class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0,j=0,n=nums.size();
        int ans=0,one=0;
        while(j<n){
            if(nums[j]==0){
                ans=max(ans,one);
                one=0;
            }
            else{
                one++;
            }
            j++;
        }
        ans=max(ans,one);
        return ans;
    }
};