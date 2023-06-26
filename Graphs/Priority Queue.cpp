#include<iostream>
#include<queue>
#include<vector>


int main(){

    std::priority_queue<int,std::vector<int>,std::greater<int>>Q;
    for(auto i =0;i<10;i++){
        Q.push(i);
    }

    int val;
    for(auto i =0;i<10;i++){
        val = Q.top();
        Q.pop();
        std::cout<<val;
    }

}