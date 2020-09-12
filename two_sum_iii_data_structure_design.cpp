/*
170. Two Sum III - Data structure design
Easy

Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Example 1:

add(1); add(3); add(5);
find(4) -> true
find(7) -> false
Example 2:

add(3); add(1); add(2);
find(3) -> true
find(6) -> false
*/

//Bad implementation
class TwoSum {
public:
    /** Initialize your data structure here. */
    vector<int> nums;
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        nums.push_back(number);
        // sort(nums.begin, nums.end())
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        sort(nums.begin(), nums.end());
        int l=0,r=nums.size()-1;
        while(l<r){
            if(nums[l]+nums[r]==value)
                return true;
            else if(nums[l]+nums[r]<value)
                l++;
            else
                r--;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */

 //Using Map
 class TwoSum {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int> m;
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        m[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        
        for(auto &val : m){
            // cout<<val.first;
            if(m.count(value-val.first))
            {
               if ( (val.first!=value-val.first && m[val.first]>=1) || ((val.first==value-val.first) && m[val.first]>=2) )
                return true ;
            }
                
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
