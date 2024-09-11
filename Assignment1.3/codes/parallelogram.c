#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matfun.h"

int main() {
    // Define points A, B, C, D
    double **A = createMat(2,1);
    double **D = createMat(2,1);
    double **B, **C;

    // Coordinates of A(-2, 1) and D(1, 2)
    A[0][0] = -2; A[1][0] = 1;
    D[0][0] = 1; D[1][0] = 2;

    // Assume coordinates for C(4, b)
    C = createMat(2,1);
    C[0][0] = 4; C[1][0] = 1; // Assume an initial guess for b (b=1)

    // Solve for B using the formula B = A + C - D
    B = Matadd(A, Matsub(C, D, 2, 1), 2, 1);
    // Free memory
    free(A); free(B); free(C); free(D);

    return 0;
}

