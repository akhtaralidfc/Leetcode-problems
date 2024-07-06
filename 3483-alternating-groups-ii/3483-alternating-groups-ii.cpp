class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int last=colors[0],ans=0,cnt=1;
        for(int i=1;i<n;i++){
            if(colors[i]!=last) cnt++;
            else cnt=1;
            if(cnt>=k) ans++;
            last=colors[i];
        }
        for(int i=0;i<k-1;i++){
            if(colors[i]!=last) cnt++;
            else cnt=0;
            if(cnt>=k) ans++;
            last=colors[i];
        }
        return ans;
    }
};