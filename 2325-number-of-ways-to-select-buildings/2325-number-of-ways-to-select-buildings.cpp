class Solution {
public:
    long long numberOfWays(string s) {
        int n=s.size();
        long long tzero=0,tone=0,curzero=0,curone=0;
        for(int i=0;i<n;i++) {
            if(s[i]=='0') tzero++;
            else tone++;
        }
        long long res=0;
        for(int i=0;i<n;i++) {
            if(s[i]=='0') {
                res+=(curone*(tone-curone));
                curzero++;
            } else {
                res+=(curzero*(tzero-curzero));
                curone++;
            }
        }
        return res;
    }
};