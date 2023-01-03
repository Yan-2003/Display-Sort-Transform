#include <stdio.h>


void display(int (* array)[4], int col , int row );
void sort(int (* array)[4], int col , int row );
void transform(int (* array)[4], int col , int row );

int main(){
    int col = 6;
    int row = 4;
    int arr2D[5][4] = 
    {
        {31,18,22,-16},
        {102,67,38,42},
        {5,9,6,8},
        {35,6,22,-7},
        {-54,27,309,66}
    };

    printf("\nInitialize Data: \n\n");
    display(arr2D, col-1,row);
    printf("\nSorted Data: \n\n");
    sort(arr2D,col-1,row);
    printf("\nTransformed Data: \n\n");
    transform(arr2D,col,row);
    return 0;
    
}
void display(int (* array)[4], int col , int row ){
    
    for(int i = 0; i < col; i++){
        if(i == col-1 && col > 5){ 
            printf("\n");
        }
        for(int j = 0; j < row; j++){
             printf("|%8d\t|", array[i][j]);
        }
        printf("\n");
    }
}
void sort(int (* array)[4], int col , int row ){
    int temp; 
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            for(int k = 0; k < row-1; k++){
                if(array[i][k] > array[i][k+1]){
                    temp = array[i][k+1];
                    array[i][k+1] = array[i][k];
                    array[i][k] = temp;
                }
            }
        }
    }
    display(array,col,row);
}
void transform(int array[6][4], int col , int row ){
    int count = 0;
    for(int i = 0; i < row; i++){

        array[col-1][count] = 0;

        for(int j = 0; j < col-1; j++){
            array[j][i] -= array[j][i]+array[j][i];
            array[col-1][count] += array[j][i];
        }
        count++;
    }
    display(array,col,row);
}