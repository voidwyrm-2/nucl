#include <stdio.h>

#include "../include/nucl.h"

int main() {
    char str[] = "hello there friend, how are you doing today?";

    Substrings split = SplitString(str, ' ');

    printf("length: %d\n", split.length);

    for (int i = 0; i < split.length; i++)
        printf("string %d: %s\n", i, split.substrings[i]);
}