class Solution {
public:
     string countOfAtoms(string formula) {
       vector<pair<string,int>> v;
        map<string,int> mp;
        int s=formula.size();
        int len=-1;
        for(int i=0;i<formula.length();i++)
        {
            if(isupper(formula[i]))
            {
                pair<string,int> temp;
                string t=string(1,formula[i]);
                while(i<s-1 && islower(formula[i+1]))
                {
                    t+=formula[i+1];
                    i++;
                }
                temp.first=t;
                temp.second=1;
                v.push_back(temp);
                len++;
                
            }
            else if(formula[i]=='(' || formula[i]==')')
            {
                pair<string,int>temp;
                temp.first=formula[i];
                temp.second=1;
                v.push_back(temp);
                len++;
            }
            else if(isdigit(formula[i]))
            {
                string p=string(1,formula[i]);
                while(i<s-1 && isdigit(formula[i+1]))
                {
                    p+=formula[i+1];
                    i++;
                }
                if(v[len].first==")")
                {
                    int x=len;
                    
                    while(true)
                    {
                        if(v[x].first=="(" && v[x].second==1)
                        {
                            
                            v[x].second*=stoi(p);
                            break;
                        }
                        v[x].second*=stoi(p);
                        x--;
                    }
                    
                }
                else
                {
                    v[len].second*=stoi(p);
                }
                
            }
        }
        for(int i=0;i<=len;i++)
        {
            if(v[i].first!="(" && v[i].first!=")"){
            
            mp[v[i].first]+=v[i].second;
            }
        }
        string ans="";
        for(auto i:mp)
        {
            ans+=i.first;
            if(i.second!=1){
            ans+=to_string(i.second);}
        }
        return ans;
    }
};