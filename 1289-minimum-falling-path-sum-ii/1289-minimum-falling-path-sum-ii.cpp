class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid)
    {
        int n=grid.size();
        vector <vector <int>> dp(n, vector <int> (n,0));
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (i==0)
                    dp[i][j]=grid[i][j];
                else
                {
                    int add=1e9;
                    for (int k=0;k<n;k++)
                    {
                        if (k!=j)
                            add=min(add,dp[i-1][k]);
                    }
                    dp[i][j]=grid[i][j]+add;
                }
            }
        }
        int ans=1e9;
        for (int i=0;i<n;i++)
            ans=min(ans,dp[n-1][i]);
        return ans;        
    }
};