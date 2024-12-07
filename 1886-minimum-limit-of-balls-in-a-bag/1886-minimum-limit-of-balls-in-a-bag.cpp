class Solution {
public:
    int minimumSize(vector<int>& nums, int k) {
        int left=1,right=1e9;
        while(left<right){
            int mid=left+(right-left)/2;
            int cnt=0;
            for(auto it: nums) cnt+=(it-1)/mid;
            if(cnt>k) left=mid+1;
            else right=mid;
        }
        return left;
    }
};