#include<iostream>

void selection_sort(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int partition(int a[],int n, int low, int up){
    int i = low+1;
    int j = up;
    int pivot = a[low];
    int temp;
    while(i<=j){
        while(pivot>a[i]){
            i++;
        }
        while(pivot<a[j]){
            j--;
        }
        if(i<j){
            temp = a[i];
            a[i] = a[j];
            a[j] = a[i];
            i++;
            j--;
        }
        else{
            i++;
        }
    }
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quick_sort(int a[],int n, int low, int up){
    int ploc;
    ploc = partition(a,n,low,up);
    quick_sort(a,n,low,ploc-1);
    quick_sort(a,n,ploc+1,up);
}



int main()
{
    
}