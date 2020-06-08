/*
You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

    Each word after the identifier will consist only of lowercase letters, or;
    Each word after the identifier will consist only of digits.

We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.

 

Example 1:

Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
*/

//We do not have to sort the digit logs, as mentioned in the problem statement. We need to sort the letter logs, using a custom sort method which 
//compares two letter logs after the identifier (so we need to compare 2 strings after the identifier)
// we achieve this using the custom sort using substring function. 
//After sorting the letter log, we need to append all the sorted letter logs and then the digit logs (order of digit log is the same order appeared in input)

class Solution {
public:
    static bool custom_sort(string s1, string s2)
    {
        int pos1 = s1.find(' ');
        int pos2 = s2.find(' ');
        if(s1.substr(pos1+1)<s2.substr(pos2+1))
            return true;
        else if(s1.substr(pos1+1)>s2.substr(pos2+1))
            return false;
        else //both are equal or tie
            return s1.substr(0, pos1+1)<s2.substr(0,pos2+1);
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digitLog;
        vector<string> letterLog;
        vector<string> result;
        if(logs.size()==0)
            return result;
       for(int i=0;i<logs.size();i++)
       {
           int pos = logs[i].find_first_of(' ');
           if(pos!=string::npos)
           {
               if(isdigit(logs[i][pos+1])!=0)
                   digitLog.push_back(logs[i]);
               else
                   letterLog.push_back(logs[i]);
           }
       }
        sort(letterLog.begin(), letterLog.end(), custom_sort);
        for(string el : letterLog)
            result.push_back(el);
        for(string el : digitLog)
            result.push_back(el);
        return result;
        
    }
};