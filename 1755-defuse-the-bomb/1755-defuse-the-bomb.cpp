class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> pre(n,0),suff(n,0);
        if(k==0) return pre;
        else if(k<0){
            k=abs(k);
            int sum=0;
            for(int i=0;i<k;i++){
                sum+=code[i];
            }
            for(int i=k;i<=(2*n);i++){
                pre[(i%n)]=sum;
                sum-=code[(i-k+n)%n];
                sum+=code[i%n];
            }
            return pre;
        }
        else{
            int sum=0,cnt=0;
            for(int i=n-1;i>=(n-k);i--){
                sum+=code[i];
            }
            for(int i=(n-k-1);cnt<(2*n);i--){
                if(i<0) i=n-1;
                suff[i]=sum;
                sum-=code[(i+k)%n];
                sum+=code[i];
                cnt++;
            }
            return suff;
        }
        return code;
    }
};