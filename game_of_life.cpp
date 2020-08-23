/*
289. Game of Life
Medium

According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

    Any live cell with fewer than two live neighbors dies, as if caused by under-population.
    Any live cell with two or three live neighbors lives on to the next generation.
    Any live cell with more than three live neighbors dies, as if by over-population..
    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:

Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]

Follow up:

    Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
    In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?

*/

//We cannot make the updates to the matrix, as and when we process the matrix. For each cell, we need to find the neighbors value from the original unupdated
//matrix. We can achieve this by creating another copy of the input matrix. But this would require O(m*n) space. So, instead of marking the matrix as
//0 for dead cell and 1 for live cell, we can have a new marking scheme.
// When the cell goes from live -> dead - mark the cell as -1 (indicating that this cell was originally live, now dead)
// When the cell goes from dead -> live - mark the cell as 2 (indicating that the cell was originally dead, now live)
// So, while counting the number of live neighbors for subsequent cells, even after update, we can correctly compute the live neighbors,
// by counting all neighboring cells with value 1 or -1 as originally live
// and all neighboring cells with value 0 or 2 as originally dead
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size();
        int n=board[0].size();
        //vector<vector<int>> copy;
        //copy=board;
        int live=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 live=0;
                if(j+1<n && j>=0 && abs(board[i][j+1])==1)
                    live++;
                if(i+1<m && i+1>=0 && abs(board[i+1][j])==1)
                    live++;
                if(j-1>=0 && j-1<n && abs(board[i][j-1])==1)
                    live++;
                if(i-1>=0 && i-1<m && abs(board[i-1][j])==1)
                    live++;
                if(i-1>=0 && i-1<m && j-1>=0 && j-1<n && abs(board[i-1][j-1])==1)
                    live++;
                if(i-1>=0 && i-1<m && j+1>=0 && j+1<n && abs(board[i-1][j+1])==1)
                    live++;
                if(i+1>=0 && i+1<m && j+1>=0 && j+1<n && abs(board[i+1][j+1])==1)
                    live++;
                if(i+1>=0 && i+1<m && j-1>=0 && j-1<n && abs(board[i+1][j-1])==1)
                    live++;
                if(board[i][j]==1 && (live<2|| live>3))
                    // copy[i][j]=0
                    board[i][j]=-1;
                if(board[i][j]==1 && (live==2||live==3))
                    // copy[i][j]=1
                    board[i][j]=1;
                if(board[i][j]==0 && (live==3))
                    // copy[i][j]=1;
                    board[i][j]=2;
            }
            
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==-1)
                    board[i][j]=0;
                if(board[i][j]==2)
                    board[i][j]=1;
            }
        }
       //board=copy;
        
    }
};