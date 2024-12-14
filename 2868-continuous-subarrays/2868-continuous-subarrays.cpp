class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        long long cnt=0;
        map<int,int> m;
        for(int l=0, r=0; r<n; r++){
            m[nums[r]]++;
            while(l<r && prev(m.end())->first-m.begin()->first>2){
                int f=--m[nums[l]];
                if (f==0) m.erase(nums[l]);
                l++;
            }
            cnt+=r-l+1;
        }
        return cnt;
    }
};