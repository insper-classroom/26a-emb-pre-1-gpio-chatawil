#include <stdio.h>

#define NUM_ELEMENTS 5

static int multiplyNumbers(int x, int y) {
    return x * y;
}

int main(void) {
    int a = 2;
    int b = 5;

    int result = multiplyNumbers(a, b);

    int arr[NUM_ELEMENTS];
    int sum = 0;

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        sum += arr[i];
    }

    (void)result;
    (void)sum;

    return 0;
}