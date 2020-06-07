/*
1029. Two City Scheduling
There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.

 

Example 1:

Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.

*/

//NOTE: Simply sorting using city A ir city B costs and adding first N values of city A cost and last N of city B cost will not work
// The parameter to be used is not the actual cost for city A or B, but how much more we benefit if we choose to go to City A than City B
// So, the "difference" in the costs of city A and B is the right measure to say which city cost to be taken for a person

class Solution {
public:

    //We are doing a custom sort
    // We subtract city B cost and A cost and find how large the difference is. If B - A is very large, then we can say that
    // it is better to choose city A for that entry, since we profit a large cost if B - A is large ( Cost of A is significantly lesser)
    static bool custom_sort(vector<int> val1, vector<int> val2)
   {
       return (val1[1]-val1[0]>val2[1]-val2[0]);
   }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
     int n=costs.size(), result=0;
        sort(costs.begin(), costs.end(), custom_sort);
        //After sorting 1st N/2 values are added from city A cost
        for(int i=0;i<n/2;i++)
            result+=costs[i][0];
        // Since 1st N/2 are already considered, we choose last N/2 from CityB cost (we should not count same person for both city costs)
        for(int i=n/2;i<n;i++)
            result+=costs[i][1];
        return result;
            
    }
};