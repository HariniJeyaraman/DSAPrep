/*
1185. Day of the Week
Easy

Given a date, return the corresponding day of the week for that date.

The input is given as three integers representing the day, month and year respectively.

Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.

 

Example 1:

Input: day = 31, month = 8, year = 2019
Output: "Saturday"
Example 2:

Input: day = 18, month = 7, year = 1999
Output: "Sunday"
Example 3:

Input: day = 15, month = 8, year = 1993
Output: "Sunday"
 

Constraints:

The given dates are valid dates between the years 1971 and 2100.
*/

class Solution {
public:
    bool isLeapYear(int year){
    if(year%4!=0) return false;
        else if(year%100!=0) return true;
        else if(year%400!=0) return false;
        else return true; //2000 is leap year, 2100 not
    }
    
    string dayOfTheWeek(int day, int month, int year) {
        string days[7] = {"Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        int monthDays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        //1971-1-1 is a Friday
        int total_days=0;
        total_days = (year-1971)*365;
        for(int i=1971;i<year;i++)
            if(isLeapYear(i)) total_days++;
        for(int i=0;i<month-1;i++){
            total_days+=monthDays[i];
        }
        if(isLeapYear(year) && month>2) total_days++;
        total_days+=day-1;
        return days[(total_days+5)%7];
        
    }
};