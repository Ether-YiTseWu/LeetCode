class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int count = 0, k;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            if (nums[i] == val)
            {   
                nums[i] = 101;
                count ++;
            }
        }
        sort(nums.begin(), nums.end());
        k = nums.size() - count;
        return k;
    }
};