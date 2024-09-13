#include <stdio.h>

#include "../include/nucl.h"

int main() {
    char str[] =
        "As they say in Russian... 'Whoops, I should've predicted that someone "
        "could escape out of a ventilation shaft using discarded mirrors as "
        "stairs.'";

    Substrings split = SplitString(str, ' ');

    printf("length: %d\n", split.count);

    for (int i = 0; i < split.count; i++)
        printf("string %d: \"%s\"\n", i, split.substrings[i]);

    free(split.substrings);

    char str2[] = "int 0 = 0;\nauto 1 = \"hello\";\nbool 2 = false;";

    split = SplitString(str2, '\n');

    for (int i = 0; i < split.count; i++)
        printf("string %d: \"%s\"\n", i, split.substrings[i]);

    char str3[] = "hello";

    split = SplitString(str3, ' ');

    for (int i = 0; i < split.count; i++)
        printf("string %d: \"%s\"\n", i, split.substrings[i]);
}