class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if(nums.size() == 1)
            return 1;
        
        // Get repeating numbers showing time
        int count = 0;
        for (int i = 1 ; i < nums.size() ; i++)
            if (nums[i]==nums[i-1])
                count ++;
        count = nums.size()-count;

        // Deal with new nums
        int newNum = nums[0], index = 0;
        for (int i = 0 ; i < count; i++)
        {
            nums[i] = newNum;
            // Decide the next newNum
            for (int j = index+1 ; j < nums.size() ; j++)
            {
                if (newNum != nums[j])
                {
                    newNum = nums[j];
                    index = j;
                    break;
                }
            }
        }
        return count;
    }
};