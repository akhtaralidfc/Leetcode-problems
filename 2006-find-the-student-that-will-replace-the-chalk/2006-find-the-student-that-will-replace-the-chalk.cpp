class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long sum=0;
        for(auto& it: chalk) sum+=it;
        k=k%sum;
        for(int i=0;i<chalk.size();i++){ 
            if(k-chalk[i] < 0) return i;
            else k-=chalk[i];
        }
        return 0;
    }
};