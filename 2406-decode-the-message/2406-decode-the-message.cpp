class Solution {
public:
    string decodeMessage(string key, string message) {
        char ch='a';
        unordered_map<char,char> m;
        for(auto it: key){
            if(it==' ') continue;
            if(m.find(it)==m.end()){
                m[it]=ch;
                ch++;
            }
        }
        string res="";
        for(auto it: message){
            if(it==' ') res+=' ';
            else res+=m[it];
        }
        return res;
    }
};