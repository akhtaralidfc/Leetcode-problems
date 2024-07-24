class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> ans;
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            int power=1,number=0;
            int n=nums[i];
            if(n==0) mp[mapping[n]].push_back(n);
            else{
                while(n>0){
                    int dig=n%10;
                    int md=mapping[dig];
                    number+=md*power;
                    power*=10;
                    n=n/10;
                }
                mp[number].push_back(nums[i]);
            }
        }
        for(auto it:mp){
            for(auto x:it.second){
                ans.push_back(x);
            }
        }
        return ans;
    }
};