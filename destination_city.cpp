/*
You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.

It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

 

Example 1:

Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo" 
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".

Example 2:

Input: paths = [["B","C"],["D","B"],["C","A"]]
Output: "A"
Explanation: All possible trips are: 
"D" -> "B" -> "C" -> "A". 
"B" -> "C" -> "A". 
"C" -> "A". 
"A". 
Clearly the destination city is "A".

Example 3:

Input: paths = [["A","Z"]]
Output: "Z"
*/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        //Key is to make sure that you find the city that never appears in the left.
        //So store all the cities that appear in the left(0th index of sublist) in a set
        //Iterate over the all the cities in index 1 of sublist and check if that city is present in the set
        // if present, that city already has an outgoing path to another city and cannot be the destination city
        // else if the city is not present in the entire set, it is the destination
        unordered_set<string> cities;
        for(auto &val : paths)
        {
            cities.insert(val[0]);
        }
        for(auto &val : paths)
        {
            if(cities.find(val[1])==cities.end())
                return val[1];
        }
        return "";
    }
};