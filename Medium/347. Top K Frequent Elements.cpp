class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        if (nums.size() == 1)
            return nums;
        
        vector<int> times, answers, answer;
        sort(nums.begin(), nums.end());
        nums.push_back(0); // Avoid times and answers are empty
        int count = 1;
        for (int i = 0 ; i < nums.size()-1 ; i++)
        {
            if (nums[i] == nums[i+1])
                count += 1;
            else
            {
                times.push_back(count);
                answers.push_back(nums[i]);
                count = 1;
            }
        }
        
        // Bubble Sort, sort answers with the times order
        for (int i = 0 ; i < times.size() ; i++)
        {
            for (int j = i+1 ; j < times.size() ; j++)
            {
                if (times[i] < times[j])
                {
                    int tempA = times[i], tempB = answers[i];
                    times[i] = times[j];
                    times[j] = tempA;
                    answers[i] = answers[j];
                    answers[j] = tempB;
                }
            }
        }
        
        for (int i = 0 ; i < k ; i++)
            answer.push_back(answers[i]);
        
        return answer;
    }
};