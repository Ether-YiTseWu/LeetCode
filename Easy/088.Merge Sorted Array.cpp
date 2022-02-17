class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        vector<int> v;
        for (int i = 0 ; i < m ; i++)
            v.push_back(nums1[i]);
        for (int j = 0 ; j < n ; j++)
            v.push_back(nums2[j]);
        sort(v.begin(), v.end());
        nums1 = v;
    }
};