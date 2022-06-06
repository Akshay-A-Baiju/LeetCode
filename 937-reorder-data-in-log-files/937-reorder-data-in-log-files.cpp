class Solution {
public:
    static bool cmp(string s1, string s2)
    {
        int pos1=0,pos2=0;
        while (s1[pos1]!=' ') pos1++;
        while (s2[pos2]!=' ') pos2++;
        string id1=s1.substr(0,pos1);
        string id2=s2.substr(0,pos2);
        s1.erase(0,pos1);
        s2.erase(0,pos2);
        if (s1<s2)
            return true;
        if (s1==s2 && id1<id2)
            return true;
        return false;
    }
    
    vector<string> reorderLogFiles(vector<string>& A)
    {
        vector <string> letter,digit;
        for (auto &s: A)
        {
            if (s[s.length()-1]>='a' && s[s.length()-1]<='z')
                letter.push_back(s);
            else
                digit.push_back(s);
        }
        sort(letter.begin(),letter.end(),cmp);
        vector <string> res;
        for (auto &it: letter)
            res.push_back(it);
        for (auto &it: digit)
            res.push_back(it);
        return res;
    }
};