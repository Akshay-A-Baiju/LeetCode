class Solution {
public:
    int maxProduct(vector<string>& words)
    {
        int n=words.size();
        vector <set<char>> freq(n);
        for (int i=0;i<n;i++)
        {
            for (auto &ch: words[i])
                freq[i].insert(ch);
        }
        int ans=0;
        for (int i=0;i<n;i++)
        {
            for (int j=i+1;j<n;j++)
            {
                // check for common elements
                bool isCommon=false;
                for (auto &it: freq[i])
                {
                    if (freq[j].find(it)!=freq[j].end())
                    {
                        isCommon=true;
                        break;
                    }
                }
                if (!isCommon)
                {
                    int len1=words[i].length();
                    int len2=words[j].length();
                    ans=max(ans,len1*len2);
                }
            }
        }
        return ans;
    }
};