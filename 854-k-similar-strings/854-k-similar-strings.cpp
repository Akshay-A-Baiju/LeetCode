class Solution {
public:
    map <pair<string,string>,int> dp;

    int fun(string s1, string s2)
    {
        // cerr<<s1<<" "<<s2<<endl;
        int n=s1.length();
        if (s1==s2)
            return 0;
        if (dp.find({s1,s2})!=dp.end())
            return dp[{s1,s2}];
        if (s1[0]==s2[0])
        {
            s1=s1.substr(1);
            s2=s2.substr(1);
            return dp[{s1,s2}]=fun(s1,s2);
        }
        int ans=n*n;
        for (int j=1;j<s1.length();j++)
        {
            if (s1[j]==s2[0])
            {
                swap(s1[0],s1[j]);
                string str1=s1.substr(1);
                string str2=s2.substr(1);
                ans=min(ans,1+fun(str1,str2));
                swap(s1[0],s1[j]);
            }
        }
        return dp[{s1,s2}]=ans;
    }
    int kSimilarity(string s1, string s2)
    {
        int n=s1.length();
        return fun(s1,s2);       
    }
};