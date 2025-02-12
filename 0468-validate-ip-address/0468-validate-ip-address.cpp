class Solution {
public:
    string validIPAddress(string queryIP) {
        bool isdot;     
        int count=0; 
        for(auto x: queryIP){
            cout<<count<<" ";
            if(x=='.'){
                isdot=true;
                if(count>4) return "Neither";
                count = 0;
            }
            if(x==':'){
                isdot =false;
                //if(count>4) return "Neither";
                break;
            }
            count++;
        }
        if(isdot)
        {
            int count=0;
            string st="";
            for(int i=0;i<queryIP.length();i++)
            {
                if(queryIP[i]=='.')
                {
                    if(st.length()==0) return "Neither";
                    int s=stoi(st);
                    if(s<0 || s>255) return "Neither";
                    //FOR HANDLING "00.0.000.0" CASE 
                    string str = to_string(s);
                    if(st!=str) return "Neither";
                    st="";
                    count++;
                }
                else if(queryIP[i]>='0' && queryIP[i]<='9') st += queryIP[i];
                else return "Neither";
            }
            if(st.length()==0) return "Neither";
            int s=stoi(st);
            if(s<0 || s>255) return "Neither";
            string str=to_string(s);
            if(st!=str) return "Neither";
            return count==3 ? "IPv4": "Neither";
        }
        else{
            int length = 0;
            count=0;
            for(int i=0;i<queryIP.length();i++)
            {
                if(queryIP[i]==':'){
                    if(length==0 || length>4) return "Neither";
                    length=0;
                    count++;
                }
                else if(queryIP[i]>=48 && queryIP[i]<=57) length++;
                else if(queryIP[i]>=97 && queryIP[i]<=102) length++;
                else if(queryIP[i]>=65 && queryIP[i]<=70) length++;
                else return "Neither";
            }
            if(length==0 || length>4) return "Neither";
            return count==7 ? "IPv6" : "Neither";
        }
        return "Neither";
    }
};