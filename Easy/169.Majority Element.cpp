class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        if (nums.size()==1)
            return nums[0];
        sort(nums.begin(), nums.end());
        int max = -1, showTimes = 1, answer = 0;
        // Main Algorithm
        for (int i = 1 ; i < nums.size() ; i++)
        {
            // Check repeating time
            if (nums[i-1] == nums[i])
            {
                showTimes++;
                if (showTimes > max)
                    max = showTimes, answer = nums[i-1];
            }
            else
                showTimes = 1;
        }
        return answer;
    }
};