class Solution {
public:
    bool static cmp(string s1,string s2){
        string a=s1.substr(s1.find(' ')+1);
        string b=s2.substr(s2.find(' ')+1);
        return a==b?s1<s2:a<b;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> dig,letter,res;
        for(int i=0;i<logs.size();i++){
            string nextstr=logs[i].substr(logs[i].find(' ')+1);
            if(nextstr[0]>='a' && nextstr[0]<='z'){
                letter.push_back(logs[i]);
            }else{
                dig.push_back(logs[i]);
            }
        }
        sort(letter.begin(),letter.end(),cmp);
        for(auto it: letter) res.push_back(it);
        for(auto it: dig) res.push_back(it);
        return res;
    }
};