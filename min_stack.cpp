/*
155. Min Stack
Easy

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

*/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    stack<int> ms;
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
       if(ms.empty() || x<=ms.top())
           ms.push(x);
    }
    
    void pop() {
        int val = s.top();
        if(val == ms.top())
            ms.pop();
        s.pop();    
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
       return ms.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */