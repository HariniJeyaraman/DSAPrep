/*
346. Moving Average from Data Stream
Easy

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Example:

MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/

class MovingAverage {
public:
    /** Initialize your data structure here. */
    list<int> l;
    int window_size;
    double sum;
    MovingAverage(int size) {
        this->window_size=size;
        sum=0.0;
    }
    
    double next(int val) {
        sum+=val;
        if(l.size()==window_size){
            sum-=l.front();
            l.pop_front();
        }
        l.push_back(val);
        return sum/l.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */