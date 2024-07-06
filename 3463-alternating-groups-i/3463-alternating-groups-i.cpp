class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int cnt=0,n=colors.size();
        for(int i=0;i<colors.size()-2;i++){
            if(colors[i]==colors[i+2] && colors[i]!=colors[i+1]) cnt++;
        }
        if(colors[0]==colors[n-2] && colors[0]!=colors[n-1]) cnt++;
        if(colors[1]==colors[n-1] && colors[0]!=colors[n-1]) cnt++;
        return cnt;
    }
};