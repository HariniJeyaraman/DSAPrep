/*
22. Generate Parentheses
Medium

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n==0)
            return result;
        helper("",n, n, n, result);
        return result;
            
    }
    void helper(string s, int left, int right, int n, vector<string>& result){
        // if(left==0 && right==0)
        //     return ;
        if(s.length()==2*n){
            result.push_back(s);
            return;
        }
        if(left>0){
            helper(s+"(", left-1, right, n, result);
        }
        if(left<right && right>0){
            helper(s+")", left, right-1, n, result);
        }
    }
};