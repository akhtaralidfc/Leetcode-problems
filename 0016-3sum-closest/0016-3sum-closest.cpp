class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n-2;i++){
            int l=i+1,r=n-1;
            while(l<r){
                int cursum=nums[i]+nums[l]+nums[r];
                if(abs(target-ans)>abs(target-cursum)) ans=cursum;
                if(cursum==target) break;
                else if(cursum>target) r--;
                else l++;
            }
        }
        return ans;
    }
};