class Solution {
public:
    bool solve(long long mid,vector<int>& nums,int k){
        int cnt=1;
        long long pre=nums[0];
        for(int i=1;i<nums.size();i++){
            if((nums[i]-pre)>=mid){
               cnt++;
               pre=nums[i];    
            }
        }
        return cnt>=k;
    }
    int maximumTastiness(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        long long l=0,h=nums[nums.size()-1]-nums[0];
        long long ans=0;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(solve(mid,nums,k)){
                ans=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return ans;
    }
};