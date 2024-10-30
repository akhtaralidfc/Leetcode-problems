class Solution {
public:

    int minInsertions(string s) {
        int pastopen=0,openneeded=0,closeneeded=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') pastopen++;
            else{
                if(i<s.size()-1 && s[i+1]==')'){
                    if(pastopen>0) pastopen--; //"())"
                    else openneeded++; //"))"
                    i++;
                }
                else{
                    if(pastopen>0){
                        //"(),()("
                        pastopen--;
                        closeneeded++;
                    }
                    else{
                        //")("
                        openneeded++;
                        closeneeded++;
                    }
                }
            }
        }
        return 2*pastopen+openneeded+closeneeded;
		}
};