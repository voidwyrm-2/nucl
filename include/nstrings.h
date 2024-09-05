#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arraylist.h"

typedef struct Substrings {
    char** substrings;
    int length;
} Substrings;

Substrings SplitString(char* str, char sep) {
    char** substrs;
    int splits = 0;
    // int total_size = 0;
    Arraylist acc = NewArraylist(1);
    int slen = strlen(str);
    for (int i = 0; i < slen; i++) {
        if (str[i] == sep) {
            char** newss = (char**)malloc(sizeof(char*) * (splits + 1));
            for (int j = 0; j < splits; j++) {
                newss[j] = substrs[j];
            }

            newss[splits] = (char*)malloc(sizeof(char) * acc.len);
            for (int k = 0; k < acc.len; k++) {
                newss[splits][k] = *(char*)acc.arr[k];
            }

            // if (splits > 1) free(substrs);
            substrs = newss;
            acc = NewArraylist(1);
            splits++;
        } else {
            ALAdd(&acc, (void*)&str[i]);
        }
    }

    if (acc.len > 0) {
        char** final;

        final = (char**)malloc(sizeof(char*) * (splits + 1));

        for (int i = 0; i < splits; i++) {
            final[i] = (char*)malloc(sizeof(char) * strlen(substrs[i]));
            final[i] = substrs[i];
            // free(substrs[i]);
        }
        free(substrs);

        final[splits] = (char*)malloc(sizeof(char) * acc.len);

        for (int i = 0; i < acc.len; i++) {
            // printf("loop, %d\n", i);
            //  printf("acc.arr: '%c', final: %p\n", *(char*)acc.arr[i],
            //         final[splits]);
            final[splits][i] = *(char*)acc.arr[i];
        }
        // printf("final[%d] is: %s\n", splits, final[splits]);
        free(acc.arr);

        Substrings out = {.substrings = final,
                          .length = splits == 0 ? 1 : splits + 1};
        return out;
    } else {
        Substrings out = {.substrings = substrs,
                          .length = splits == 0 ? 1 : splits};
        return out;
    }
}