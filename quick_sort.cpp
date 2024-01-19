#include<iostream>
int partition(int a[],int low,int up);
void quick_sort(int a[],int low,int up){
    int ploc;
    if(low>up){
        return;
    }
    ploc = partition(a,low,up);
    quick_sort(a,low,ploc-1);
    quick_sort(a,ploc+1,up);
}

int partition(int a[],int low,int up){
    int i,j,pivot;
    pivot= a[low];
    i=low+1;
    j=up;
    while(i<=j){
        while(a[i]<pivot){
            i++;
        }
        while(a[j]>pivot){
            j--;
        }
        if(i<j){
            std::swap(a[i],a[j]);
            i++;
            j--;
        }
        else{
            i++;
        }
    }
    a[low] = a[j];
    a[j] = pivot;
    return j;

}

void display(int array[],int n){
    for(int i=0;i<n;i++){
        std::cout<<array[i]<<",";
    }
}
int main(){
    int array[] = {10,9,8,7,6,5,3,2,1};
    int n = sizeof(array)/sizeof(array[0]);
    quick_sort(array, 0, n-1);  // Sort the array
    display(array,n);
    return 0;
}
