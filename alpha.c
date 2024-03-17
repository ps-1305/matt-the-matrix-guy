#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define INP_MAT(arr,n, file) for(int i=0; i<n; i++){for(int j=0; j<n; j++){fscanf(file, "%d", &arr[i][j]);}}
#define PRINT_MAT(arr,n, file) for(int i=0; i<n; i++){for(int j=0; j<n; j++){fprintf(file, "%d ", arr[i][j]);}fprintf(file, "\n");}

int main(void){
    /*
    $ 2x2 3x3
    [] 1. inverse
    [] 2. adjoint
    [] 3. minor of specific location
    [] 4. cofactor of specific location
    [] 5. eigenvalues of a matrix
    [] 6. eigenvectors of a matrix 
    [] 7. diagnolisation of a matrix
    [] 8. determinant of a matrix

    $ for non square
    [] 1. product of two matrices 
    [] 2. addition
    
    $ others and misc
    [] 1. solving linear equations 
    [] 2. optimisation problems

    $ another thing (last but not the least)
    [*] 1. file handling in c 
    [-] 2. matrixScript
    */
    
    // * input filename for in and out
    
    // filenames and extension supported
    char in[50], out[50], extension[4] = ".txt"; 
    
    // input file
    printf("Filename to take input from: ");
    fgets(in, 50, stdin);
    in[strcspn(in, "\n")] = '\0';
    if(strstr(in, ".txt") == 0){
        strcat(in, extension);
    }

    // output file
    printf("Filename to give output to: ");
    fgets(out, 50, stdin);
    out[strcspn(out, "\n")] = '\0';
    if(strstr(out, ".txt") == 0){
        strcat(out, extension);
    }

    // input and output file pointers
    FILE* fin = fopen(in, "r");
    FILE* fout = fopen(out, "w");

    if(fin != NULL && fout != NULL){
        // taking in the dimension of matrix from the file
        int dimension;
        fscanf(in, "%d", &dimension);

        // initialisation of our matrix
        int mat[dimension][dimension];

        // reading from file for 2 and 3 dimensions
        switch(dimension)
        {
            case 2: INP_MAT(mat, 2, in); break;
            case 3: INP_MAT(mat, 3, in); break;
            default: printf("Invalid value detected, opinion rejected.")
        }
    }
    
    // printf("\033[47;32mSuccessful!");
    // * choice menu
    while(1){
        printf("0.Exit\n1.Inverse\n2.Adjoint\n3.Minor\n4.Cofactor\n5.Eigenvalues\n6.Eigenvectors\n7.Diagnolisation\n8.Determinant\n");
        printf("\033[32mChoice: ");
        int choice;
        scanf("%d", &choice);
        printf("\033[0m%d",choice);
        
        // 0. Exit 
        if(choice == 0){
            break;
        }

        // 1. Inverse 

        // 2. Adjoint

        // 3. Minor
        if(choice == 3){
            
        }

        // 4. Cofactor 

        // 5. Eigenvalues

        // 6. Eigenvectors 

        // 7. Diagonalisation

        // 8. Determinant
        if(choice == 8){
            return 0;
        }
    }
}
