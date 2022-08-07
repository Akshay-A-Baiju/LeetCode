class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        int n=nums.size();
        map <int,int> mp;
        for (auto &it: nums)
            mp[it]++;
        vector <int> ans;
        for (auto &pr: mp)
        {
            if (pr.second>n/3)
                ans.push_back(pr.first);
        }
        return ans;
    }
};