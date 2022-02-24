class Solution {
public:
    void reverseString(vector<char>& s)
    {
        vector<char> ss;
        for (int i = s.size()-1 ; i >= 0 ; i--)
            ss.push_back(s[i]);
        s = ss;
    }
};