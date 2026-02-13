#include <stdio.h>

#define BITS 8   // Change this for larger numbers

int A = 0;       // Accumulator
int Q;           // Multiplier
int M;           // Multiplicand
int Q_1 = 0;     // Extra bit
int count = BITS;

void arithmeticRightShift() {
    int msbA = (A >> (BITS - 1)) & 1;

    Q_1 = Q & 1;
    Q = (Q >> 1) | ((A & 1) << (BITS - 1));
    A = (A >> 1) | (msbA << (BITS - 1));
}

void boothAlgorithm() {
    while (count > 0) {
        int Q0 = Q & 1;

        if (Q0 == 1 && Q_1 == 0) {
            A = A - M;
        } 
        else if (Q0 == 0 && Q_1 == 1) {
            A = A + M;
        }

        arithmeticRightShift();
        count--;
    }
}

int main() {
    printf("Enter multiplicand: ");
    scanf("%d", &M);

    printf("Enter multiplier: ");
    scanf("%d", &Q);

    boothAlgorithm();

    int result = (A << BITS) | (Q & ((1 << BITS) - 1));

    printf("Product: %d\n", result);

    return 0;
}
