#include <stdio.h>

#include "../include/nucl.h"

int main() {
    Arraylist arrl = NewArraylist(1);

    printf("cap: %d, length: %d\n", ALCap(&arrl), ALLen(&arrl));

    int a = 20;

    printf("a: %d\n", a);

    ALAdd(&arrl, (void*)&a);

    printf("cap: %d, length: %d\n", ALCap(&arrl), ALLen(&arrl));

    int b = 22;

    printf("b: %d\n", b);

    ALAdd(&arrl, (void*)&b);

    printf("cap: %d, length: %d\n", ALCap(&arrl), ALLen(&arrl));

    int b_2 = *(int*)ALRemove(&arrl);

    printf("a + b: %d\n", *(int*)ALRemove(&arrl) + b_2);

    printf("cap: %d, length: %d\n", ALCap(&arrl), ALLen(&arrl));

    return 0;
}