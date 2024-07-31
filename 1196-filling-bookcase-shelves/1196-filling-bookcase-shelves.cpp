class Solution {
public:
    // int helper(vector<vector<int>> &books, int idx, int remainingShelfWidth, int height, int shelfWidth, vector<vector<int>> &dp){
    //     if(idx >= books.size()) return height;
    //     if(dp[idx][remainingShelfWidth] != -1) return dp[idx][remainingShelfWidth];
    //     int currBookWidth  = books[idx][0];
    //     int currBookHeight = books[idx][1]; 
    //     int opt1 = height + helper(books, idx + 1, shelfWidth - currBookWidth, currBookHeight, shelfWidth, dp);
    //     int opt2 = INT_MAX;
    //     if(remainingShelfWidth >= currBookWidth){
    //         opt2 = helper(books, idx + 1, remainingShelfWidth - currBookWidth, max(height, currBookHeight), shelfWidth, dp);
    //     }
    //     return dp[idx][remainingShelfWidth] = min(opt1, opt2);
    // }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        // int n=books.size();
        // vector<vector<int>> dp(n,vector<int>(shelfWidth+1,-1));
        // return helper(books,0,shelfWidth,0,shelfWidth,dp);
        books.insert(books.begin(),{0,0});
        vector<int> dp(books.size(),INT_MAX);
        dp[0] = 0;
        int width, height, j;
        for(int i=1;i<books.size();i++){
            width = books[i][0];
            height = books[i][1];
            j = i-1;
            while (j>=0 && width<=shelfWidth){
                dp[i] = min(dp[i], dp[j]+height);
                width += books[j][0];
                height = max(height, books[j][1]);
                j--;
            }
        }
        return dp.back();
    }
};