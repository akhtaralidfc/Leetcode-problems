class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int i=0,n=nums.size();
        int j=n-1;
        int start=0,end=n-1;
        vector<int> ans(n,0);
        while(i<n){
            if(nums[i]<pivot) ans[start++]=nums[i];
            if(nums[j]>pivot) ans[end--]=nums[j];
            i++,j--;
        }
        while(start<=end) ans[start++]=pivot;
        return ans;
    }
};