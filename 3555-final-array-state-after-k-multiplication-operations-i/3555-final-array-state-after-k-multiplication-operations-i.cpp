class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
        while(k--){
            int minel= *min_element(nums.begin(),nums.end());
            for(int i=0;i<nums.size();i++){
                if(nums[i]==minel){
                    nums[i]*=mul;
                    break;
                }
            }
        }
        return nums;
    }
};