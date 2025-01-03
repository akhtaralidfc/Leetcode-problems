class Solution {
public:
    void solve(set<vector<int>>& set,vector<int> nums,int ind){
        if(ind==nums.size()){
            set.insert(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            solve(set,nums,ind+1);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> set;
        // sort(nums.begin(),nums.end());
        solve(set,nums,0);
        vector<vector<int>> res(set.begin(),set.end());
        return res;
    }
};