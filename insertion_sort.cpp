#include<iostream>

void insertion_sort(int a[], int n){
    for(int i=0;i<n;i++){
        int k = a[i];
        int j;
        for(j=i-1;j>=0 && k<a[j];j--){
            a[j+1] = a[j];
        }
        a[j+1]=k;
        
    }
}

void display(int array[],int n){
    for(int i=0;i<n;i++){
        std::cout<<array[i]<<",";
    }
}

int main(){
    int array[] = {10,9,8,7,6,5,3,2,1};
    int n = sizeof(array)/sizeof(array[0]);
    insertion_sort(array,n);
    display(array,n);
    return 0;
}
