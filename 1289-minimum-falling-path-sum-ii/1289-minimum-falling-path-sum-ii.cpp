class Solution {
public:
    int fun(int i, int j, vector <vector <int>> &matrix, vector <vector<int>> &dp)
    {
        // returns min path sum to reach cell (i,j) from top row
        int n=matrix.size();
        if (j<0 || j>=n)
            return 1e9;
        if (i==0)
            return matrix[i][j];
        if (dp[i][j]!=-1)
            return dp[i][j];
        int add=1e9;
        for (int k=0;k<n;k++)
        {
            if (j!=k)
                add=min(add,fun(i-1,k,matrix,dp));
        }
        return dp[i][j]=matrix[i][j]+add;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid)
    {
        int n=grid.size();
        vector <vector <int>> dp(n, vector <int> (n,-1));
        int ans=1e9;
        for (int i=0;i<n;i++)
            ans=min(ans,fun(n-1,i,grid,dp));
        return ans;
    }
};