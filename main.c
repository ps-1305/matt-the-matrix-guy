#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INP_MAT(arr,n, file) for(int i=0; i<n; i++){for(int j=0; j<n; j++){fscanf(file, "%d", &arr[i][j]);}}
#define PRINT_MAT(arr,n, file) for(int i=0; i<n; i++){for(int j=0; j<n; j++){fprintf(file, "%d ", arr[i][j]);}fprintf(file, "\n");}
#define PRINT_FLOAT_MAT(arr,n, file) for(int i=0; i<n; i++){for(int j=0; j<n; j++){fprintf(file, "%.2f ", arr[i][j]);}fprintf(file, "\n");}
#define FOR(i,n) for(int i=0; i<n; i++)
#define FOR_SE(i,start,end) for(int i=start; i<end;i++)
#define true 1
#define false 0

/*
$ arguments = integer matrix , dimension of the matrix
$ returns = integer 
? function = calculates the determinant of a matrix using recursion
*/
int calcDeterminant(int mat[][20], int dim){
    // base case
    if(dim == 1) {
        return mat[0][0];
    }
 
    else{
        // initialisation of determinan
        int det =  0;
        FOR(i, dim){
            // calculate minor matrix excluding the current row and i-th column
            int minor[20][20];
            int minor_size = dim - 1;
            FOR_SE(j,1,dim){
            int k = 0;
            FOR(l,dim){
                if(l != i){
                minor[j - 1][k] = mat[j][l];  // Only exclude i-th column
                k++;
                }
            }
            }
            // apply recursion with sign based on co-factor position
            det += pow(-1, i) * mat[0][i] * calcDeterminant(minor, minor_size);
        }
        return det;
    }
}

/*
$ arguments = integer matrix, dimension of the matrix, indices i and j
$ returns = integer
? function = calculates the minor of a specific location
*/
int calcMinor(int mat[][20],int dim, int i,int j){
    // if dim == 2 then direct formula
    if(dim == 2){
        if(i == j){
            return i-1>=0 ? mat[i-1][j-1] : mat[i+1][j+1];
        }
        else if(i != j){
            return mat[j][i];
        }
    }
    // else we use submatrices and determinant
    else{
        int sub_mat[20][20], ni = 0, nj = 0;
        FOR(p,dim){
            FOR(q, dim){
                if(p!=i && q!=j){    
                    sub_mat[ni][nj] = mat[p][q];
                    nj++;
                }
            }
            nj = 0;
            if(p != i){
                ni++;
            }
        }
        return calcDeterminant(sub_mat, dim-1);
    }
    return 0;
}

/*
$ arguments = integer matrix, dimension of the matrix, file pointer, filename string
$ returns = 1 - success, 0 - not success, -1 - singular
? function = finds and prints the adjoint to the console
*/
int calcAdjoint(int mat[][20], int dim, FILE* file, char filename[50]){
    if(file != NULL && calcDeterminant(mat,dim)!=0){
        // adjoint matrix initialisation
        int adjoint[20][20];
        // using minor for adjoint in a for loop
        FOR(i, dim){
            FOR(j, dim){
                adjoint[j][i] = pow(-1, i+j) * calcMinor(mat, dim, i, j);
            }
        }
        // printing to the file
        PRINT_MAT(adjoint, dim, file);
        printf("\033[32;4m>>%s", filename);
        printf("\033[m\n");
        fclose(file);
        for(int i=0; i<dim; i++){
                for(int j=0; j<dim; j++){
                    printf("\033[33m%d ", mat[i][j]);
                }
                printf("\033[0m\n");
            }
        
        return 1;
    }
    // singularty case
    else if(calcDeterminant(mat, dim) == 0){
        return -1;
    }
    return 0;
}

/*
$ arguments = integer matrix, dimension of the matrix, file pointer, filename string
$ returns = 1 - success, 0 - not success
? function = finds and prints the determinant to the console
*/
int findInverse(int mat[][20], int dim, FILE* file, char filename[50]){
    // taking float for division later
    float det = (float) calcDeterminant(mat, dim);
    // only non-singular matrices allowed
    if(det != 0){
        float inverse[20][20];
        FOR(i, dim){
            FOR(j, dim){
                inverse[j][i] = ((float)pow(-1, i+j) * (float)calcMinor(mat, dim, i, j))/det;
            }
        }
        // output to file
        PRINT_FLOAT_MAT(inverse, dim, file);
        printf("\033[32;4m>>%s", filename);
        printf("\033[m\n");
        fclose(file);
        for(int i=0; i<dim; i++){
            for(int j=0; j<dim; j++){
                printf("\033[33m%d ", mat[i][j]);
            }
            printf("\033[0m\n");
        }
        return 1;
    }
    return 0;
}

/*
$ arguments = integer var
$ returns = void
? function = solves linear equation
*/
void linearEquations(int var){
    // 2 variable case
    if(var == 2){
        // this is for storing constants - a,b,c,d,e,f
        int cons[6];
        // this is for storing the variables
        char vars[2];
        // this is for storing the signs 
        char signs[4];

        // input of the equation
        scanf("%d %c %c %d %c %c %d", &cons[0],&vars[0],&signs[0],&cons[1], &vars[1], &signs[1], &cons[2]);
        scanf("%d %c %c %d %c %c %d", &cons[3],&vars[0],&signs[2],&cons[4], &vars[1], &signs[3], &cons[5]);
        
        // checking for minus sign
        if((int)signs[0] == 45){
            cons[1] *= -1;
        }
        if((int)signs[2] == 45){
            cons[4] *= -1;
        }

        // solving through cramer's rule
        int D[2][20], Dx[2][20], Dy[2][20];
        D[0][0] = cons[0]; // a1
        D[0][1] = cons[1]; // b1
        D[1][0] = cons[3]; // a2
        D[1][1] = cons[4]; // b2

        if(calcDeterminant(D, 2) != 0){
            Dx[0][0] = cons[2];
            Dx[0][1] = cons[1];
            Dx[1][0] = cons[5];
            Dx[1][1] = cons[4];
            Dy[0][0] = cons[0];
            Dy[0][1] = cons[2];
            Dy[1][0] = cons[3];
            Dy[1][1] = cons[5];
            float x = (float)calcDeterminant(Dx,2)/(float)calcDeterminant(D,2);
            float y = (float)calcDeterminant(Dy,2)/(float)calcDeterminant(D,2);
            printf("%c = %.2f and %c = %.2f", vars[0],x,vars[1], y);
            getchar();
            getchar();
        }
        else{
            printf("No solution possible.");
            getchar();
            getchar();
        }
    }
    // 3 variable case
    else{
        // this is for storing constants - a,b,c,d,e,f,g,h,i,j,k,l
        int cons[12];
        // this is for storing the variables
        char vars[3];
        // this is for storing the signs 
        char signs[9];

        // input of the equation
        scanf("%d %c %c %d %c %c %d %c %c %d", &cons[0],&vars[0],&signs[0],&cons[1],&vars[1],&signs[1],&cons[2],&vars[2],&signs[2],&cons[3]);
        scanf("%d %c %c %d %c %c %d %c %c %d", &cons[4],&vars[0],&signs[3],&cons[5],&vars[1],&signs[4],&cons[6],&vars[2],&signs[5],&cons[7]);
        scanf("%d %c %c %d %c %c %d %c %c %d", &cons[8],&vars[0],&signs[6],&cons[9],&vars[1],&signs[7],&cons[10],&vars[2],&signs[8],&cons[11]);
        
        // checking for minus sign
        if((int)signs[0] == 45){
            cons[1] *= -1;
        }
        if((int)signs[1] == 45){
            cons[2] *= -1;
        }
        if((int)signs[3] == 45){
            cons[5] *= -1;
        }
        if((int)signs[4] == 45){
            cons[6] *= -1;
        }
        if((int)signs[6] == 45){
            cons[9] *= -1;
        }
        if((int)signs[7] == 45){
            cons[10] *= -1;
        }

        // solving through cramer's rule
        int D[3][20], Dx[3][20], Dy[3][20], Dz[3][20];
        D[0][0] = cons[0]; // a1
        D[0][1] = cons[1]; // b1
        D[0][2] = cons[2]; // c1
        D[1][0] = cons[4]; // a2
        D[1][1] = cons[5]; // b2
        D[1][2] = cons[6]; // c2
        D[2][0] = cons[8]; // a3
        D[2][1] = cons[9]; // b3
        D[2][2] = cons[10];  //c3 

        if(calcDeterminant(D, 3) != 0){
            Dx[0][0] = cons[3]; // d1
            Dx[0][1] = cons[1]; // b1
            Dx[0][2] = cons[2]; // c1
            Dx[1][0] = cons[7]; // d2
            Dx[1][1] = cons[5]; // b2
            Dx[1][2] = cons[6]; // c2
            Dx[2][0] = cons[11]; // d3
            Dx[2][1] = cons[9]; // b3
            Dx[2][2] = cons[10];  //c3

            Dy[0][0] = cons[0]; // a1
            Dy[0][1] = cons[3]; // d1
            Dy[0][2] = cons[2]; // c1
            Dy[1][0] = cons[4]; // a2
            Dy[1][1] = cons[7]; // d2
            Dy[1][2] = cons[6]; // c2
            Dy[2][0] = cons[8]; // a3
            Dy[2][1] = cons[11]; // d3
            Dy[2][2] = cons[10];  //c3

            Dz[0][0] = cons[0]; // a1
            Dz[0][1] = cons[1]; // b1
            Dz[0][2] = cons[3]; // d1
            Dz[1][0] = cons[4]; // a2
            Dz[1][1] = cons[5]; // b2
            Dz[1][2] = cons[7]; // d2
            Dz[2][0] = cons[8]; // a3
            Dz[2][1] = cons[9]; // b3
            Dz[2][2] = cons[11];  //d3

            float x = (float)calcDeterminant(Dx,3)/(float)calcDeterminant(D,3);
            float y = (float)calcDeterminant(Dy,3)/(float)calcDeterminant(D,3);
            float z = (float)calcDeterminant(Dz,3)/(float)calcDeterminant(D,3);

            printf("%c = %.2f and %c = %.2f and %c = %.2f", vars[0], x, vars[1], y, vars[2], z);
            getchar();
            getchar();
        }
        else{
            printf("No solution possible.");
            getchar();
            getchar();
        }
    }
}

int main(void){
    // * intro

    printf("\033[32m   __  ___     __  __    __  __                    __      _                      \n  /  |/  /__ _/ /_/ /_  / /_/ /  ___   __ _  ___ _/ /_____(_)_ __  ___ ___ ____ __\n / /|_/ / _ `/ __/ __/ / __/ _ \\/ -_) /  ' \\/ _ `/ __/ __/ /\\ \\ / / _ `/ // / // /\n/_/  /_/\\_,_/\\__/\\__/  \\__/_//_/\\__/ /_/_/_/\\_,_/\\__/_/ /_//_\\_\\  \\_, /\\_,_/\\_, / \n                                                                 /___/     /___/  \n");
    getchar();
    system("clear");

    // * input filename for in and out

    // greeting
    printf("\033[4;32mFILE MENU\n\n");

    printf(">>sample_file.txt");
    printf("\033[m\n");
    printf("\033[33m<dimension-of-the-matrix>\n");
    printf("<matrix-row-1>\n");
    printf("<matrix-row-2>\n");
    printf(".\n");
    printf(".\n");
    printf(".\n");
    printf("<matrix-row-n>");
    printf("\033[0\n\n");

    // filenames and extension supported
    char in[50], out[50], extension[4] = ".txt"; 
    // input file
    printf("\033[0mFilename to take input from: ");
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

    if(fin == NULL && fout == NULL){
        printf("\033[31mFile(s) not found, Enter again\n");
    }

    // taking in the dimension of matrix from the file
    int dimension;
    fscanf(fin, "%d", &dimension);

    // initialisation of our matrix
    int mat[20][20];

    // reading from file for n dimensions
    if(dimension <= 20 ? true : false){
        INP_MAT(mat, dimension, fin); 
    }
    else{
        printf("Invalid value detected, opinion rejected.");
        system("clear");
        exit(-1);
    }

    fclose(fin);
    fclose(fout);

    system("clear");

    // * choice menu

    while(1){
        system("clear");

        FILE* fout = fopen(out, "w");
        
        printf("\033[32;4mDETERMINANT RELATED:");
        printf("\033[0m 1.Determinant | 2.Minor | 3.Cofactor | 4.Adjoint | 5.Inverse\n");
        printf("\033[32;4mEIGEN OPS:");
        printf("\033[32;4mLINEAR EQNS:");
        printf("\033[0m 6.Solver\t");
        printf("\033[31m*for 2 or 3 variables\n");
        printf("\033[32;4mMISC:");
        printf("\033[0m 0.Exit | 10.Print Matrix\n");
        // printf("\033[0m0.Exit\n1.Inverse\n2.Adjoint\n3.Minor\n4.Cofactor\n5.Eigenvalues\n6.Eigenvectors\n7.Diagnolisation\n8.Determinant\n9.Print\n");
        printf("\033[32mChoice: ");
        int choice;
        scanf("%d", &choice);
        
        // 0. Exit 
        if(choice == 0){
            system("clear");
            break;
        }

        // 1. Determinant
        if(choice == 1){
            system("clear");
            printf("\033[32;4mDeterminant\n");
            printf("\033[0mDeterminant of the given matrix is:%d\n", calcDeterminant(mat,dimension));
            getchar();
            getchar();
        }

        // 2. Minor
        if(choice == 2){
            system("clear");
            printf("\033[32;4mMinor\n");
            // input of indices
            int i,j;
            printf("\033[0mIndices:\n");
            printf("i = ");
            scanf("%d", &i);
            printf("j = ");
            scanf("%d", &j);
            // function call if base case is cleared
            if(i <= dimension && j <= dimension){
                printf("Minor of i=%d and j=%d is: %d\n",i,j,calcMinor(mat,dimension, i-1, j-1));
                getchar();
                getchar();
            }
            else{
                printf("Index out of bound.");
                getchar();
            }
        }

        // 3. Cofactor
        if(choice == 3){
            system("clear");
            printf("\033[32;4mCofactor\n");
            // input of indices
            int i,j;
            printf("\033[0mIndices:\n");
            printf("i = ");
            scanf("%d", &i);
            printf("j = ");
            scanf("%d", &j);
            // function call if base case is cleared
            if(i <= dimension && j <= dimension){
                printf("Cofactor of i=%d and j=%d is: %d\n",i,j,(int)(pow(-1,i+j)*calcMinor(mat,dimension,i-1,j-1)));
                getchar();
            }
            else{
                printf("Index out of bound.");
                getchar();
            }
            getchar();
        }

        // 4. Adjoint
        if(choice == 4){
            system("clear");
            printf("\033[32;4mAdjoint");
            printf("\033[m\n");
            if(calcAdjoint(mat, dimension, fout, out) > 0 ? true : false){
                getchar();
                getchar();
            }
            else{
                printf("Singular matrix.");
                getchar();
                getchar();
            }  
        } 

        // 5. Inverse
        if(choice == 5){
            system("clear");
            printf("\033[32;4mInverse\n");
            if(findInverse(mat, dimension, fout, out)){
                getchar();
                getchar();
            }
            else{
                printf("Something went wrong.");
            }
        }

        // 8. Linear equations
        if(choice == 6){
            system("clear");
            printf("\033[32;4mLinear equations in 2 or 3 variables");
            printf("\033[0m\n");
            int variables;
            printf("Number of variables: ");
            scanf("%d", &variables);
            if(variables >= 2 && variables <= 3){
                linearEquations(variables);
            }
            else{
                printf("Please enter a valid number.");
            }
        }

        // 10. Print matrix
        if(choice == 10){
            system("clear");
            printf("\033[32;4m>>%s", in);
            printf("\033[0m\n");
            for(int i=0; i<dimension; i++){
                for(int j=0; j<dimension; j++){
                    printf("\033[33m%d ", mat[i][j]);
                }
                printf("\033[0m\n");
            }
            getchar();
            getchar();
        }
    }
}
