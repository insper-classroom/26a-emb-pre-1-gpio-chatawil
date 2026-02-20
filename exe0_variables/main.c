#include "stdio.h"

enum { A_LIMIT = 5 };
static int a = 0; // var global
static int b = 0; // var global

static void foo(void) {
    a = a + 1; // acessa variavel global
}

void main(void) {
    while (1) {
        foo();
        
        if (a > A_LIMIT) {
            b = 1;
        }
    }
}
