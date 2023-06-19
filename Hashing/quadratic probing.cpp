#include<iostream>
#include<vector>
#include<list>

class HashTable{

    std::vector<int>table;
    int capacity;
    std::vector<bool>occupied;

    int HashFunction(int key){
        return (key*2+3)%capacity; //index return 
    }


    public:

    void Insert(int key){
        int index  = HashFunction(key);
        int i =0;

        while(occupied[index]==true){
            i++;
            index = (index +i*i)%capacity;
            if(i==capacity){
                std::cout<<"hash table is full: "<<key<<std::endl;
                return;
            }
        }
        occupied[index]=true;
        table[index] = key;
    }

    void Delete(int key){
        int index = HashFunction(key);
        int i=0;
        while(occupied[index]==true && table[index]!=key){
            i++;
            index = (index + i*i)%capacity;
            if(i==capacity){
                std::cout<<"element not found"<<key<<std::endl;
                return;
            }

        }
        if(occupied[index]==true){
            table[index]=-1;
            occupied[index]=false;
        }
    }

    HashTable(int capacity){
        this->capacity = capacity;
        occupied = std::vector<bool>(capacity,false);
        table = std::vector<int>(capacity,-1);
    }

    void Display(){
        for(int i=0;i<capacity;i++){
            std::cout<<i<<":"<<table[i];
            std::cout<<std::endl;
        }
    }

};

int main(){
    HashTable hashTable(10); // Create a hash table with 10 buckets

    // Insert some keys into the hash table
    for(int i = 0; i < 20; i++) {
        hashTable.Insert(i);
    }

    // Display the hash table
    hashTable.Display();

    // Delete a key from the hash table
    hashTable.Delete(15);

    // Display the hash table again
    std::cout << "\nAfter deleting key 15: \n";
    hashTable.Display();

    return 0;
}

/*

Index:    0   1   2   3   4   5   6   7   8   9

table:   [5] [ ] [7] [1] [ ] [4] [6] [3] [2] [ ]

occupied:[T] [F] [T] [T] [F] [T] [T] [T] [T] [F]


*/