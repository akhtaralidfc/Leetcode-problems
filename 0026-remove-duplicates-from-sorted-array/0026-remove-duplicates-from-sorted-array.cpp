class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // int i=0,j=0,n=nums.size();
        // if(n==1) return 1;
        // while(j<n){
        //   while(j<n-1 && nums[j]==nums[j+1]) j++;
        //   nums[i]=nums[j];
        //   i++,j++;
        // }
        // return i;


        int i=0,j=0,n=nums.size();
        while(i<n && j<n){
            while(j<n-1 && nums[j]==nums[j+1]) j++;
            nums[i]=nums[j];
            i++,j++;
        }
        return i;
    }
};