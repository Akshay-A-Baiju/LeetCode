// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int fun(int i, int j, string &s, string &t, vector <vector <int>> &dp)
    {
        if (i<0)
            return j+1;
        if (j<0)
            return i+1;
        if (dp[i][j]!=-1)
            return dp[i][j];
        int ans;
        if (s[i]==t[j])
            ans=fun(i-1,j-1,s,t,dp);
        else
        {
            int insertChar=1+fun(i,j-1,s,t,dp);
            int removeChar=1+fun(i-1,j,s,t,dp);
            int replaceChar=1+fun(i-1,j-1,s,t,dp);
            ans=min({insertChar,removeChar,replaceChar});
        }
        return dp[i][j]=ans;
    }
    int editDistance(string s, string t)
    {
        int n=s.length(),m=t.length();
        vector <vector<int>> dp(n, vector <int> (m,-1));
        return fun(n-1,m-1,s,t,dp);
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends