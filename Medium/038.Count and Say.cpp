class Solution 
{
public:
    string countAndSay(int n) 
    {
        vector<string> ans;
        ans.push_back("1");
        ans.push_back("11");
        for(int i = 2 ; i < n ; i++)
        {
            string nextAns = "", preAns = ans.back();
            int count = 0, numberCount = 1;
            while (count + 1 < preAns.size())
            {
                bool flag = false;
                if (preAns[count] == preAns[count+1])
                    numberCount += 1;
                else
                {
                    nextAns += to_string(numberCount);
                    nextAns += preAns[count];
                    numberCount = 1;
                    flag = true;
                }
                count += 1;
                if (count == preAns.size()-1)
                {
                    if (flag)
                    {
                        nextAns += "1";
                        nextAns += preAns[count];
                        break;
                    }
                    nextAns += to_string(numberCount);
                    nextAns += preAns[count-1];
                    numberCount = 0;
                    break;
                }
            }
            ans.push_back(nextAns);
        }

        return ans[n-1];
    }
};