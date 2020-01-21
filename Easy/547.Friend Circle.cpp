class Solution 
{
public:
    int findCircleNum(vector<vector<int>>& M) 
    {
        int row = M.size();
        int column= M[0].size();
        
        if(row == 0 || column== 0) return 0;
        int res = 0;
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<column; j++)
            {
                // Find the top left corner number(the first people of this friend circle) is 1
                if(M[i][j] == 1)
                {
                    res++;
                    dfs(M, i, j);
                }
            }
        }
        return res;
    }
    
    // DFS Alogorithm, let the value of people already be visited equal minus one
    void dfs(vector<vector<int>>& grid, int i, int j)
    {
        // Use stack to implement DFS Alogorithm
        stack<int> st;
        st.push(i);
        grid[i][j] = -1;
        grid[j][i] = -1;
        while(!st.empty())
        {
            int curr = st.top();
            st.pop();
            
            for(int k=0; k<grid[curr].size(); k++)
            {
                if(grid[curr][k] == 1)
                {
                    grid[curr][k] = -1;
                    grid[k][curr] = -1;
                    st.push(k);
                }
            }
        }
    }
};
