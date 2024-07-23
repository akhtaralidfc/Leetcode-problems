class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto it: m){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),[&](pair<int,int>& a,pair<int,int>& b){
            if(a.second<b.second) return true;
            else if(a.second==b.second) return a.first>b.first;
            return false; 
        });
        vector<int> ans;
        for(auto it: v){
            for(int i=0;i<it.second;i++)
                ans.push_back(it.first);
        }
        return ans;

    }
};