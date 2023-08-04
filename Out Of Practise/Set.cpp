#include<iostream>
#include<set>

int main()
{

    std::set<int>SetOfNumbers = {10,230,1,420};
 
    for(auto i = SetOfNumbers.begin();i!=SetOfNumbers.end();++i){
        std::cout<<*i<<std::endl;
    }

    std::set<std::pair<int,int>>PairOfNumbers;
    PairOfNumbers.insert({1,2});
    

}