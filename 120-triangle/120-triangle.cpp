class Solution {
public:
    int fun(int i, int j, vector <vector <int>> &triangle, vector <vector <int>> &dp)
    {
        int n=triangle.size();
        if (i==n-1)
            return triangle[i][j];
        if (dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=triangle[i][j]+min(fun(i+1,j,triangle,dp),fun(i+1,j+1,triangle,dp));
    }
    
    int minimumTotal(vector<vector<int>>& triangle)
    {
        // single source, variable ending
        int n=triangle.size();
        vector <vector <int>> dp(n, vector <int> (n,-1));
        return fun(0,0,triangle,dp);
    }
};