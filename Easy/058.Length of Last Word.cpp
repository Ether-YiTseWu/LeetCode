class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        vector<int> wordLength;
        string cmpr = " ";
        int count = 0;
        // Get every word length
        for (int i = 0 ; i < s.length() ; i++)
        {
            if (s[i] != cmpr[0])
                count++;
            else
            {
                if (count != 0)
                    wordLength.push_back(count);
                count = 0; 
            }
        }
        // Check the last word length
        if (count != 0)
            wordLength.push_back(count);
        // return the last ele in wordLength
        return wordLength.back();
    }
};