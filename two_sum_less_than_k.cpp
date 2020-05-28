/*
Two sum less than k
(Similar to Movies on Flight asked by Amazon in Online Assessment Test)
 Given an array of integers and an integer x, return the maximum s such that there exists i<j with A[i]+A[j]=s and s<k
 If no i,j exist satisfying the equation, return -1
 */

 #include<vector>
 #include<cstdlib>
 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;

 //brute force approach
 int twoSumLessThank(vector<int> a, int k)
 {
     int maxSum=INT_MIN;
     for(int i=0;i<a.size();i++)
     {
         for(int j=i+1;j<a.size();j++)
         {
             int currSum=a[i]+a[j];
             if(currSum<k && currSum>maxSum)
             {
                 maxSum=currSum;
             }
         }
     }
     return maxSum==INT_MIN?-1:maxSum;
 }

 //O(log n)
 int twoSumLessThank(vector<int> a, int k)
 {
     int left=0;
     int maxSum=INT_MIN;
     int currSum;
     int right=a.size()-1;
     while(left<right)
     {
        currSum=a[left]+a[right];
        if(currSum<k && currSum>maxSum)
            maxSum=currSum;
        else if(currSum>=k)
            right--;
        else
            left++;
     }
     return maxSum==INT_MIN?-1:maxSum;
 }
