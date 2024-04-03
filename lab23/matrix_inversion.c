#include<stdio.h>
#include<math.h>

#define MAX_SIZE 25

float determinant(float [][MAX_SIZE], int);
void cofactor(float [][MAX_SIZE], int);
void transpose(float [][MAX_SIZE], float [][MAX_SIZE], int);
void findValues(float [][MAX_SIZE], int);

int main() {
    float matrix[MAX_SIZE][MAX_SIZE], n;
    int i, j;

    printf("Enter the order of the Matrix: ");
    scanf("%f", &n);

    printf("Enter the elements of a matrix: \n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    if ((int)n != n || n != 3) {
        printf("Invalid matrix size. This code currently supports only 3x3 matrices.\n");
        return 1;
    }

    cofactor(matrix, n);

    return 0;
}

float determinant(float matrix[][MAX_SIZE], int n) {
    float det = 0;
    float submatrix[MAX_SIZE][MAX_SIZE];

    if (n == 1) {
        return matrix[0][0];
    }
    else if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    else {
        for (int c = 0; c < n; c++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == c)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, c) * matrix[0][c] * determinant(submatrix, n - 1));
        }
    }
    return det;
}

void cofactor(float matrix[][MAX_SIZE], int n) {
    float temp[MAX_SIZE][MAX_SIZE], fac[MAX_SIZE][MAX_SIZE];
    for (int q = 0; q < n; q++) {
        for (int p = 0; p < n; p++) {
            int i = 0, j = 0;
            for (int row = 0; row < n; row++) {
                for (int col = 0; col < n; col++) {
                    if (row != q && col != p) {
                        temp[i][j++] = matrix[row][col];
                        if (j == n - 1) {
                            j = 0;
                            i++;
                        }
                    }
                }
            }
            fac[q][p] = pow(-1, q + p) * determinant(temp, n - 1);
        }
    }
    transpose(matrix, fac, n);
}

void transpose(float matrix[][MAX_SIZE], float cofactor[][MAX_SIZE], int n) {
    float inverse[MAX_SIZE][MAX_SIZE];
    float det = determinant(matrix, n);
    if (det == 0) {
        printf("Since the determinant is zero (0), the inverse is not possible.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse[i][j] = cofactor[j][i] / det;
        }
    }
    printf("The inverse of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f\t", inverse[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    findValues(inverse, n);
}

void findValues(float matrix[][MAX_SIZE], int n) {
    if (n != 3) {
        printf("Cannot find values of x, y, and z. Matrix size must be 3x3.\n");
        return;
    }

    float b[3][1] = {0}; 
    float x[3][1] = {0}; 

   
    printf("Enter the constants of the equations (b1 b2 b3):\n");
    for (int i = 0; i < 3; i++) {
        scanf("%f", &b[i][0]);
    }

   
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < 3; k++) {
                x[i][j] += matrix[i][k] * b[k][j];
            }
        }
    }

 
    printf("The values of x, y, and z in matrix form:\n");
    for (int i = 0; i < 3; i++) {
        printf("%f\n", x[i][0]);
    }
}
