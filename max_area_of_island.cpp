/*
695. Max Area of Island
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]

Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.

Example 2:

[[0,0,0,0,0,0,0,0]]

Given the above grid, return 0.

Note: The length of each dimension in the given grid does not exceed 50.
*/

class Solution {
public:
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        int count=1;
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
            return 0;
        grid[i][j]=0; //marking this as seen, so that we do not count this cell again
        count+=dfs(grid,i+1,j);
        count+=dfs(grid,i-1,j);
        count+=dfs(grid, i,j+1);
        count+=dfs(grid,i,j-1);
        return count;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                    maxArea=max(maxArea, dfs(grid, i, j));
            }
        }
        return maxArea;
    }
};