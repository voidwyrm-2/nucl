#include <stdio.h>

#include "../include/nucl.h"

int main() {
    char str[] =
        "As they say in Russian... 'Whoops, I should've predicted that someone "
        "could escape out of a ventilation shaft using discarded mirrors as "
        "stairs.'";

    Substrings split = SplitString(str, ' ');

    printf("length: %d\n", split.length);

    for (int i = 0; i < split.length; i++)
        printf("string %d: \"%s\"\n", i, split.substrings[i]);
}