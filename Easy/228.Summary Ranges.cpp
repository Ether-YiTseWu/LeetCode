class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> answer;
        string s;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            int initial = nums[i], j = i;
            while (j+1 < nums.size() && nums[j+1] == nums[j] + 1)
            {
                cout << nums[j] << " " << nums[j+1] << endl;
                j++;
            }
            if (j == i)
                s = to_string(initial);
            else
                s = to_string(initial) + "->" + to_string(nums[j]);
            answer.push_back(s);
            i = j;
        }
        return answer;
    }
};