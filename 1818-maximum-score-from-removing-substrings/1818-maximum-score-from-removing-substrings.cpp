class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if(x<y){
            swap(x,y);
            for(char& c:s){
                if(c=='a') c='b';
                else if(c=='b') c='a';
            }
        }
        int points=0;
        stack<char> st;
        for (char c : s){
            if(!st.empty() && st.top()=='a' && c=='b'){
                st.pop();
                points+=x;
            }else{
                st.push(c);
            }
        }
        string rem;
        while(!st.empty()){
            rem+=st.top();
            st.pop();
        }
        reverse(rem.begin(),rem.end());
        for(char c:rem){
            if(!st.empty() && st.top()=='b' && c=='a'){
                st.pop();
                points+=y;
            }else{
                st.push(c);
            }
        }
        return points;
    }
};