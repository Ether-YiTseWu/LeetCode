class Solution {
public:
    int mySqrt(int x) 
    {
        if (x == 1 || x == 2 || x == 3)
            return 1;
        // Must use long
        long val;
        for (int i = 2 ; i <= x/2+1 ; i++)
        {
            val = (i-1)*(i-1);
            if(val <= x && (val+2*i-1) > x)
                return (i-1);
        }
        return 0;
    }
};