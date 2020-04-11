//Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
#include<iostream>
#include<cstdlib>
#include<vector>

//Same as generating pascal's triange
//Except we generate pascal's triangle rows only upto k instead of n and return the kth row alone
//instead of returning a 2-D vector

std::vector<int> generate_row(int rowNum)
{
    std::vector<int> result;
    if(rowNum<0)
        return result;
    result.push_back(1);//0th row
    for(int i=0;i<rowNum;i++)
    {
        std::vector<int> temp;
        temp.push_back(1);
        for(int j=0;j<result.size()-1;j++)
        {
            temp.push_back(result[j]+result[j+1]);
        }
        temp.push_back(1);
        result=temp;
    }
    return result;
}

int main()
{
    int row;
    std::cout<<"Enter the row number : ";
    std::cin>>row;
    std::vector<int> result = generate_row(row);
    for(int i : result)
        std::cout<< i <<" ";
    std::cout<<"\n";
    return 0;
}