class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even=0,odd=0,res=1,n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]%2) odd++;
            else even++;
            if(nums[i]%2 != nums[i+1]%2) res++;
        }
        if(nums[n-1]%2) odd++;
        else even++;
        return max({res,odd,even});
    }
};