class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int n=nums.size();
        vector <int> bits(31,0);
        for (auto &it: nums)
        {
            for (int i=0;i<31;i++)
            {
                if (it&(1LL<<i))
                    bits[i]++;
            }
        }
        int ans=0;
        for (int i=0;i<31;i++)
        {
            if (bits[i]>n/2)
                ans+=(1LL<<i);
        }
        return ans;        
    }
};