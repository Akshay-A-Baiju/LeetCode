class Solution {
public:
    int fun(int x, int y, vector <vector<int>> &triangle, vector <vector<int>> &dp)
    {
        if (x==0 && y==0)
            return triangle[0][0];
        if (x<0 || y<0)
            return 1e9;
        if (dp[x][y]!=-1)
            return dp[x][y];
        int path=1e9;
        if (y<triangle[x-1].size())
            path=min(path,fun(x-1,y,triangle,dp));
        if (y-1>=0)
            path=min(path,fun(x-1,y-1,triangle,dp));
        return dp[x][y]=triangle[x][y]+path;
    }
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int n=triangle.size();
        vector <vector<int>> dp(n, vector <int> (n,-1));
        int ans=1e9;
        for (int i=0;i<n;i++)
            ans=min(ans,fun(n-1,i,triangle,dp));
        return ans;
    }
};