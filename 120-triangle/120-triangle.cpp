class Solution {
public:    
    int minimumTotal(vector<vector<int>>& triangle)
    {
        // single source, variable ending
        int n=triangle.size();
        vector <vector <int>> dp(n, vector <int> (n,0));
        for (int i=n-1;i>=0;i--)
        {
            for (int j=i;j>=0;j--)
            {
                if (i==n-1)
                    dp[i][j]=triangle[i][j];
                else
                    dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};