/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Input Format

The only argument given is character array A.

Output Format

Return the value of arithmetic expression formed using reverse Polish Notation.

For Example

Input 1:
    A =   ["2", "1", "+", "3", "*"]
Output 1:
    9
Explaination 1:
    starting from backside:
    *: ( )*( )
    3: ()*(3)
    +: ( () + () )*(3)
    1: ( () + (1) )*(3)
    2: ( (2) + (1) )*(3)
    ((2)+(1))*(3) = 9
    
Input 2:
    A = ["4", "13", "5", "/", "+"]
Output 2:
    6
Explaination 2:
    +: ()+()
    /: ()+(() / ())
    5: ()+(() / (5))
    1: ()+((13) / (5))
    4: (4)+((13) / (5))
    (4)+((13) / (5)) = 6
*/
#include<iostream>
#include<cstdlib>
#include<stack>
#include<vector>
#include<cstring>
using namespace std;

int evaluateExpression(vector<string> exp)
{
    stack<int> s;
    for(int i=0;i<exp.size();i++)
    {
        
        if(exp[i]=="-" || exp[i]== "+" || exp[i]=="*" || exp[i]=="/" || exp[i]=="^")
        {
            int op1=s.top();
            s.pop();
            int op2=s.top();
            s.pop();
            if(exp[i]=="-")
                s.push(op1-op2);
            else if(exp[i]=="+")
                s.push(op1+op2);
            else if(exp[i]=="*")
                s.push(op1*op2);
            else if(exp[i]=="/")
            {
                if(op2!=0)
                s.push(op1/op2);
            }
            else if(exp[i]=="^")
                s.push(op1^op2);   
            
        }
        else
            {
                s.push(atoi(exp[i].c_str()));
            }
    }
    return s.top();
}

int main()
{
    vector<string> exp={"2", "1", "+", "3", "*"};
    cout<<evaluateExpression(exp)<<endl;
    return 0;
}