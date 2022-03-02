class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        vector<int> answer = digits;
        int carryNum;
        for (int i = digits.size() - 1 ; i >= 0 ; i--)
        {
            carryNum = 0;
            if (answer[i] != 9)
            {
                answer[i] += (1+carryNum);
                return answer;
            }
            else
            {
                answer[i] = 0;
                carryNum = 1;
            }
        }
        if (carryNum)
        {
            answer.push_back(1);
            answer.back() = answer[0];
            answer[0] = 1;
        }
        return answer;
    }
};