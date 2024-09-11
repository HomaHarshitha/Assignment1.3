#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include "matfun.h"

// Global variables to store coordinates
static double A[2], B[2], C[2], D[2];

void calculate_points() {
    double **A_mat = createMat(2,1);
    double **D_mat = createMat(2,1);
    double **B_mat, **C_mat;

    // Coordinates of A(-2, 1) and D(1, 2)
    A_mat[0][0] = -2; A_mat[1][0] = 1;
    D_mat[0][0] = 1; D_mat[1][0] = 2;

    // Assume coordinates for C(4, b)
    C_mat = createMat(2,1);
    C_mat[0][0] = 4; C_mat[1][0] = 1; // Assume an initial guess for b (b=1)

    // Solve for B using the formula B = A + C - D
    B_mat = Matadd(A_mat, Matsub(C_mat, D_mat, 2, 1), 2, 1);

    // Store coordinates in global variables
    A[0] = A_mat[0][0]; A[1] = A_mat[1][0];
    B[0] = B_mat[0][0]; B[1] = B_mat[1][0];
    C[0] = C_mat[0][0]; C[1] = C_mat[1][0];
    D[0] = D_mat[0][0]; D[1] = D_mat[1][0];

    // Free memory
    free(A_mat); free(B_mat); free(C_mat); free(D_mat);
}

void get_coordinates(double *a, double *b, double *c, double *d) {
    a[0] = A[0]; a[1] = A[1];
    b[0] = B[0]; b[1] = B[1];
    c[0] = C[0]; c[1] = C[1];
    d[0] = D[0]; d[1] = D[1];
}

