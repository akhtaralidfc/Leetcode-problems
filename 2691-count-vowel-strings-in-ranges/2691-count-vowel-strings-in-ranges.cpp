class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');
        vector<int> nums(words.size());
        for(int i=0;i<words.size();i++){
            int start=0,end=words[i].size()-1;
            if(vowels.count(words[i][0])>0 && vowels.count(words[i][end])>0) nums[i]=1;
            else nums[i]=0;
        }
        for(int i=1;i<nums.size();i++) nums[i]=nums[i]+nums[i-1];
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int start=queries[i][0],end=queries[i][1];
            if(start==0) ans[i]=nums[end];
            else ans[i]=nums[end]-nums[start-1];
        }
        return ans;
    }
};