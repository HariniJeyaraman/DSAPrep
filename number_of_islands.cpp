/*
200. Number of Islands
Medium

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/
class Solution {
public:
    // int result;
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)
            return 0;
        int result=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1')
                    result+=helper(i,j, grid);
            }
        }
        return result;
    }
    
    int helper(int i, int j, vector<vector<char>>& grid){
        if(i<0 || j<0 || i>grid.size()-1 || j>grid[i].size()-1)
            return 0;
        // if(grid[i+1][j]=='0' || grid[i][j+1]=='0' || grid[i][j-1]=='0' || grid[i-1][j]=='0'){
        if(grid[i][j]=='0'){
            // result++;
            return 0;
        }
           
        grid[i][j]='0';
        helper(i+1,j,grid);
        helper(i,j+1, grid);
        helper(i,j-1, grid);
        helper(i-1,j,grid);
        return 1;
    }