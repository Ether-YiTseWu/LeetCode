class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        bool answer = 0;
        vector<int> represent1, represent2;
        
        for (int i = 0 ; i < s.size() ; i++)
            represent1.push_back(s[i]);    
        for (int i = 0 ; i < t.size() ; i++)
            represent2.push_back(t[i]); 
        
        sort(represent1.begin(), represent1.end());
        sort(represent2.begin(), represent2.end());
        
        if (represent1 == represent2)
            answer = 1;
        
        return answer;
    }
};