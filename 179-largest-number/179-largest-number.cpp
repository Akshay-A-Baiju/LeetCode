class Solution {
public:
    static bool cmp(string s1, string s2)
    {
        return (s1+s2>s2+s1);
    }
    string largestNumber(vector<int>& nums)
    {
        int n=nums.size();
        vector <string> v(n);
        for (int i=0;i<n;i++)
            v[i]=to_string(nums[i]);
        sort(v.begin(),v.end(),cmp);
        string res;
        for (auto &s: v)
        {
            for (auto &ch: s)
                res.push_back(ch);
        }
        // remove leading zeros
        int i=0;
        while (i<res.length() && res[i]=='0') i++;
        res=res.substr(i);
        if (res.length()==0)
            res="0";
        return res;        
    }
};