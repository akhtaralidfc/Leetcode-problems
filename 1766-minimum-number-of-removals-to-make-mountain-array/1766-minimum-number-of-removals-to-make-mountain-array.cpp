class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> leftdp(nums.size(),1),rightdp(nums.size(),1);
        //leftlis
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    leftdp[i]=max(leftdp[i],leftdp[j]+1);
                }
            }
        }
        //rightlis
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=nums.size()-1;j>i;j--){
                if(nums[i]>nums[j]){
                    rightdp[i]=max(rightdp[i],rightdp[j]+1);
                }
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(leftdp[i]!=1 && rightdp[i]!=1){
                ans=max(ans,leftdp[i]+rightdp[i]);
            }
        }
        return nums.size()-ans+1;
    }
};