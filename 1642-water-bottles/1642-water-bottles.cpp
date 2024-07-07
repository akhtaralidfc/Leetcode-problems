class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int b=numBottles,a=numExchange;
        int ans=numBottles;
        while(b>=a){
            int rem=b%a;
            int cur=b/a;
            int totalrembot=cur+rem;
            b=totalrembot;
            ans+=cur;
        }
        return ans;
    }
};