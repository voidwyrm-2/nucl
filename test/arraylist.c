#include <stdio.h>
#include <stdlib.h>

#include "../include/nucl.h"

int main() {
    Arraylist arrl = NewArraylist(1);

    // int test
    printf("int test:\n");
    {
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

        printf("cap: %d, length: %d\n", ALCap(&arrl), ALLen(&arrl));
    }

    // string test
    printf("\nstring test:\n");
    {
        char* a = malloc(sizeof(char) * 5);
        a = "hello";

        printf("a: '%s'\n", a);

        ALAdd(&arrl, (void*)&a);

        printf("cap: %d, length: %d\n", ALCap(&arrl), ALLen(&arrl));

        char* b = malloc(sizeof(char) * 5);
        b = "there";

        printf("b: '%s'\n", b);

        ALAdd(&arrl, (void*)&b);

        printf("cap: %d, length: %d\n", ALCap(&arrl), ALLen(&arrl));

        char* b_2 = *(char**)ALRemove(&arrl);

        printf("a, b: '%s', '%s'\n", *(char**)ALRemove(&arrl), b_2);

        printf("cap: %d, length: %d\n", ALCap(&arrl), ALLen(&arrl));
    }

    FreeArraylist(&arrl);

    return 0;
}