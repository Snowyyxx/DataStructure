#include<iostream>

void bs(int arr[], int length){
    int count=0;
    for(auto i =0;i<length-1;i++){
        for(auto j=0;j<length-i-1;j++){
            if(arr[j]>arr[j+1]){
                std::swap(arr[j],arr[j+1]);
                count++;
            }
        }
        if(count==0){
            break;
        }
    }

}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int length = sizeof(arr) / sizeof(arr[0]);
    bs(arr, length);

    // Print the sorted array to check if it's correctly sorted
    for(int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
