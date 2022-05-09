class Solution {
public:
    void generate(string &digits, int i, int n, string &s, vector <vector<char>> &vec, vector <string> &res)
    {
        if (i==n)
        {
            res.push_back(s);
            return;
        }
        int d=digits[i]-'2';
        for (auto &it: vec[d])
        {
            s.push_back(it);
            generate(digits,i+1,n,s,vec,res);
            s.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits)
    {
        int n=digits.length();
        vector <vector<char>> vec(8);
        vec[0]={'a','b','c'};
        vec[1]={'d','e','f'};
        vec[2]={'g','h','i'};
        vec[3]={'j','k','l'};
        vec[4]={'m','n','o'};
        vec[5]={'p','q','r','s'};
        vec[6]={'t','u','v'};
        vec[7]={'w','x','y','z'};
        vector <string> res;
        if (n==0)
            return res;
        string s;
        generate(digits,0,n,s,vec,res);
        return res;
    }
};