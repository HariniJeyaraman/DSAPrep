/*
1086. High Five
Easy

Given a list of scores of different students, return the average score of each student's top five scores in the order of each student's id.

Each entry items[i] has items[i][0] the student's id, and items[i][1] the student's score.  The average score is calculated using integer division.

 

Example 1:

Input: [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
Output: [[1,87],[2,88]]
Explanation: 
The average of the student with id = 1 is 87.
The average of the student with id = 2 is 88.6. But with integer division their average converts to 88.
 

Note:

1 <= items.length <= 1000
items[i].length == 2
The IDs of the students is between 1 to 1000
The score of the students is between 1 to 100
For each student, there are at least 5 scores
*/

//Using Priority Queue
class Solution {
public:
    static bool custom_sort(vector<int> &A, vector<int> &B){
    return A[0]<B[0];    
    }
    
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        priority_queue<int> marks;
        vector<vector<int>> result;
        sort(items.begin(), items.end());
        int student=items[0][0],sum=0;
        for(int i=0;i<items.size();i++){
           
            if(items[i][0]==student){
                marks.push(items[i][1]);
                // student = items[i][0];
            }
            if(items[i][0]!=student || i==items.size()-1){
                for(int k=0;k<5;k++){
                    sum+=marks.top();
                    marks.pop();
                }
                vector<int> temp={items[i-1][0], sum/5};
                result.push_back(temp);
                temp.clear();
                marks = priority_queue <int>();
                marks.push(items[i][1]);
                student = items[i][0];
                sum=0;
            }
        }
        return result;
    }
};

//Constant Space
class Solution {
public:
    static bool custom_sort(vector<int> &A, vector<int> &B){
    if(A[0]!=B[0])
        return A[0]<B[0];
    return A[1]>B[1];
    } 
    
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        sort(items.begin(), items.end(), custom_sort);
        vector<vector<int>> result;
        int student=items[0][0],c=0,sum=0;
        for(int i=0;i<items.size();i++){
            if(items[i][0]==student){
                if(c<5){
                   sum+=items[i][1];
                    c++; 
                }   
            }
            if(items[i][0]!=student || i==items.size()-1){
            if(c==5){
                    vector<int> temp={student, sum/5};
                    result.push_back(temp);
                    c=0;
                sum=0;
                }
            student=items[i][0];
                sum+=items[i][1];
                c++;
            }
        }
        return result;
    }
};