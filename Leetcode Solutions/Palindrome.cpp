#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        int num =x;
        int NumberOfDigits=0;

        while(x>0){
            x = x/10;
            NumberOfDigits++;
        }
        x = num;
        vector<int>Digits(NumberOfDigits);
        vector<int>DummyDigits(NumberOfDigits);

        if(x<0){
            return false;
        }

        for(auto i =Digits.begin();i!=Digits.end();i++){
            *i = x%10;
            x = x/10;
        }

        for(auto j =0; j<NumberOfDigits;j++){
            DummyDigits[j] = Digits[NumberOfDigits-1-j];
        }
        int count =0;
        for(auto k = 0; k<NumberOfDigits; k++){
            if(DummyDigits[k]==Digits[k]){
                count++;
            }
        }
        if(count==NumberOfDigits){
            return true;
        } else{
            return false;
        }

    }
};