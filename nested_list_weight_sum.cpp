/*
339. Nested List Weight Sum
Easy

Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:

Input: [[1,1],2,[1,1]]
Output: 10 
Explanation: Four 1's at depth 2, one 2 at depth 1.
Example 2:

Input: [1,[4,[6]]]
Output: 27 
Explanation: One 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27.
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int depth=1;
       int result = helper(nestedList, depth);
        return result;
    }
    
    int helper(vector<NestedInteger>& nestedList, int depth){
        int result=0;
        for(NestedInteger val : nestedList){
            if(val.isInteger()){
                result+=val.getInteger()*depth;
            }
            else{
                result+=helper(val.getList(),depth+1);
            }
        }
        return result;
    }
    
};

/*
Depth-first Traversal [Accepted]
Algorithm

Because the input is nested, it is natural to think about the problem in a recursive way. 
We go through the list of nested integers one by one, keeping track of the current depth d.
If a nested integer is an integer n, we calculate its sum as n\times dn×d. 
If the nested integer is a list, we calculate the sum of this list recursively using the same process but with depth d+1.
*/