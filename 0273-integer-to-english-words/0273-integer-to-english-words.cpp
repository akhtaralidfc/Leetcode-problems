class Solution {
public:
    string numberToWords(int num) {
        vector<int> numbers = {
            1000000000, 1000000, 1000, 100, 90, 80, 70, 60, 50, 40, 30, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
        };
        vector<string> words={
            "Billion","Million","Thousand","Hundred","Ninety","Eighty","Seventy","Sixty","Fifty","Forty","Thirty","Twenty","Nineteen","Eighteen","Seventeen","Sixteen","Fifteen","Fourteen","Thirteen","Twelve","Eleven","Ten","Nine","Eight","Seven","Six","Five","Four","Three","Two","One"
        };
        string res;
        for(int i=0;i<31;i++){
            if(num>=numbers[i]){
                if(num>=100) res+=numberToWords(num/numbers[i])+" "+words[i]+" ";
                else res += words[i] + " ";
                num%=numbers[i];
                if(num==0) break;
            }
        }
        if(res.empty()) return "Zero";
        else return res.substr(0,res.size()-1);
    }
};