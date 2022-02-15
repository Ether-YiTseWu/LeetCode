class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        if (nums.size() == 1)
            return nums[0];
        sort(nums.begin(), nums.end());
        // Two Two Comparasion
        int i;
        for (i = 1 ; i < nums.size() ; i+=2)
        {
            if (nums[i-1] != nums[i])
                return nums[i-1];
        }
        // if single number at the last
        return nums[i-1];
    }
};