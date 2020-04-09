/*
Given numRows, generate the first numRows of Pascal’s triangle.
Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.*/

#include<cstdlib>
#include<iostream>
#include<vector>
std::vector < std::vector<int> > generate(int numRows)
{
    std::vector< std::vector<int> > result;
    if(numRows<=0)
        return result;
    std::vector<int> row;
    row.push_back(1);
    result.push_back(row);
    for(int i=0;i<numRows-1;i++)
    {
        std::vector<int> current_row;
        current_row.push_back(1);
        for(int j=0;j<result[i].size()-1;j++)
        {
            current_row.push_back(result[i][j]+result[i][j+1]);
        }
        current_row.push_back(1); // Since every row starts and ends with 1
        result.push_back(current_row);
    }

    return result;
}

int main()
{
    int n;
    std::cout<<"Enter the number of rows : ";
    std::cin>>n;
    std::cout<<"Pascal's Triangle : \n";
    std::vector<std::vector<int> > result=generate(n);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            std::cout<<result[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
    return 0;
}