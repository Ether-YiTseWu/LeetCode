class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> answer;
        for(int i = 0 ; i <= n ; i++)
            answer.push_back(ten_to_two(i));
        return answer;
    }
    
    int ten_to_two(int num)
    {
        int answer = 1;
        if (num == 0 || num == 1)
            return num;
        while(num!=1)
        {
            if (num%2==1)
                answer++;
            num /= 2;
        }
        return answer;
    }
};