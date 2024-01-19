#include<iostream>
/* idea of transpose of sparse matrix is that we need to make changes to its
 representation matrix such that it becomes a transpose of the orignal matrix! */

void transpose_sparse(int A[][3], int B[][3]){
    B[0][0] = A[0][1];
    B[0][1] = A[0][0];
    B[0][2] = A[0][2];

    int row_b = 1;
    int number_non_zero_entries = A[0][2];

    for(auto )

}


void display_matrix(int B[][3]){
    for(auto i=0;i<4;i++){
        for(auto j=0;j<3;j++){
            std::cout<<B[i][j]<<",";
        }
        std::cout<<std::endl;
    }
}

int main(){
    int A[][3] = {
        {4,3,3},
        {1,1,5},
        {1,2,4},
        {3,1,1}
    };

    int B[][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    transpose_sparse(A,B);
    display_matrix(B);
}