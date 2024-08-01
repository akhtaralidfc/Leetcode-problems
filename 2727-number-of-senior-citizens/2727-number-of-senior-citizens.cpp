class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        string age="";
        for(int i=0;i<details.size();i++){
            // age="";
            age=details[i][11];
            age+=details[i][12];
            int cur=age[1]-'0';
            cur=(age[0]-'0')*10+cur;
            if(cur>60) cnt++;
        }
        return cnt;
    }
};