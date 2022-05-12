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
        return dp[i][j]=matrix[i][j]+min({fun(i-1,j,matrix,dp),fun(i-1,j-1,matrix,dp),fun(i-1,j+1,matrix,dp)});
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n=matrix.size();
        vector <vector <int>> dp(n, vector <int> (n,-1));
        int ans=1e9;
        for (int i=0;i<n;i++)
            ans=min(ans,fun(n-1,i,matrix,dp));
        return ans;
    }
};