// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    static bool cmp(pair <int,int> p1, pair <int,int> p2)
    {
        if (p1.second<p2.second)
            return true;
        return false;
    }
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector <pair<int,int>> interval(n);
        for (int i=0;i<n;i++)
            interval[i]={start[i],end[i]};
        sort(interval.begin(),interval.end(),cmp);
        int ans=0,end_time=0;
        for (int i=0;i<n;i++)
        {
            if (interval[i].first>end_time)
            {
                ans++;
                end_time=interval[i].second;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends