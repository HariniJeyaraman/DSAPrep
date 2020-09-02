/*
716. Max Stack
Easy

Design a max stack that supports push, pop, top, peekMax and popMax.

push(x) -- Push element x onto stack.
pop() -- Remove the element on top of the stack and return it.
top() -- Get the element on the top.
peekMax() -- Retrieve the maximum element in the stack.
popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
Example 1:
MaxStack stack = new MaxStack();
stack.push(5); 
stack.push(1);
stack.push(5);
stack.top(); -> 5
stack.popMax(); -> 5
stack.top(); -> 1
stack.peekMax(); -> 5
stack.pop(); -> 1
stack.top(); -> 5
Note:
-1e7 <= x <= 1e7
Number of operations won't exceed 10000.
The last four operations won't be called when stack is empty.
*/

class MaxStack {
public:
    /** initialize your data structure here. */
    vector<int> stack;
    MaxStack() {
        
    }
    
    void push(int x) {
        stack.push_back(x);
    }
    
    int pop() {
        int val = stack[stack.size()-1];
        stack.pop_back();
        return val;
    }
    
    int top() {
        return stack[stack.size()-1];
    }
    
    int peekMax() {
        return *max_element(stack.begin(), stack.end());
    }
    
    int popMax() {
        // int maxind = max_element(stack.begin(),stack.end()) - stack.begin();
        int maxind=-1;
        int val = *max_element(stack.begin(), stack.end());
        for(int i=stack.size()-1;i>=0;i--){
            if(stack[i]==val)
            {
                maxind=i;
                break;
            }
        }
        stack.erase(stack.begin()+maxind);
        return val;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */