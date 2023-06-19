#include<iostream>
#include<list>
#include<vector>


class HashTable{
    int capacity;
    std::list<int>*table;

    int HashFunction(int key){
        int i = (2*key +3)%capacity;
        return i;
    }

    public:

    HashTable(int capacity){
        this->capacity = capacity;
        table = new std::list<int>[capacity];
    }

    void Insert(int key){
        int index = HashFunction(key);
        table[index].push_back(key);
    }

    void Delete(int key){
        int index = HashFunction(key);

        for(auto i = table[index].begin();i!=table[index].end();++i){
            if(*i==key){
                table[index].erase(i);
                break;
            }
        }

    }

    void DisplayHashtable(){
        for(int i =0; i<capacity;i++){
            std::cout<<i<<": ";
            for(auto j = table[i].begin();j!=table[i].end();++j){
                std::cout<<*j<<", ";
            }
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
    hashTable.DisplayHashtable();

    // Delete a key from the hash table
    hashTable.Delete(15);

    // Display the hash table again
    std::cout << "\nAfter deleting key 15: \n";
    hashTable.DisplayHashtable();

    return 0;
}