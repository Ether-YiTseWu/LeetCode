class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) 
    {
        int count = 0;
        long long sum = 0;
        sort(nums.begin(), nums.end());
        
        if (nums[0] != 1)
        {
            if (k < nums[0])
            {
                count = k;
                sum += (long)(1+count)*(long)(count)/2;
                return sum;
            }
            sum += (long)nums[0]*(long)(nums[0]-1)/2;
            count += nums[0]-1;
        }

        for (int i = 0 ; i < nums.size()-1; i++)
        {
            if (nums[i] == nums[i+1] || nums[i+1] - nums[i] == 1)
                continue;
            if (count+nums[i+1]-nums[i]-1 <= k)
            {
                count += nums[i+1]-nums[i]-1;
                sum += (long)(nums[i]+nums[i+1])*(long)(nums[i+1]-nums[i]-1)/2;
            }
            else
            {
                int add = nums[i];
                while(++add)
                {
                    count++;
                    sum += (long)add;
                    if (count == k)
                        return sum;
                }
            }
            if (count == k)
                return sum;
        }
        sum += (long)(nums.back()+1+(nums.back()+1+(k-count)-1))*(long)(k-count)/2;
        return sum;
    }
};