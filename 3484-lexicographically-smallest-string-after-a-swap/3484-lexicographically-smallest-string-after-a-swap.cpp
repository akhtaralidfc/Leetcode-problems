class Solution {
public:
    string getSmallestString(string s) {
        int n=s.length();
        for(int i=0;i<n-1;i++){
            int first=s[i]-'0';
            int second=s[i+1]-'0';
            if((first>second) && ((first%2==0 && second%2==0) || (first%2==1 && second%2==1))) {
                swap(s[i],s[i+1]);
                break;
            }
        }
        return s;
    }
};