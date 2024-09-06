#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arraylist.h"

typedef struct Substrings {
    char** substrings;
    int length;
} Substrings;

/*
Splits a string by the specified character
*/
Substrings SplitString(char* str, char sep) {
    char** substrs;
    int splits = 0;
    Arraylist acc = NewArraylist(1);  // arraylist to hold collected characters
    int slen = strlen(str);
    for (int i = 0; i < slen; i++) {
        if (str[i] == sep) {
            // allocate new string array for the new string
            char** newss = (char**)malloc(sizeof(char*) * (splits + 1));
            for (int j = 0; j < splits; j++) {
                newss[j] = substrs[j];  // copy strings from the old array
            }

            // allocate memory for the substring we collected in the new array
            newss[splits] = (char*)malloc(sizeof(char) * acc.len);
            // copy chars from acc to the new array
            for (int k = 0; k < acc.len; k++) {
                newss[splits][k] = *(char*)acc.arr[k];
            }

            // if (splits > 1) free(substrs);
            substrs = newss;
            FreeArraylist(&acc);    // let go of the old acc's memory
            acc = NewArraylist(1);  // create new arraylist for acc
            splits++;
        } else {
            ALAdd(&acc, (void*)&str[i]);
        }
    }

    // check if we have a substring left over
    if (acc.len > 0) {
        char** final;

        // allocate new string array to hold the substrings we already have +
        // the left over one
        final = (char**)malloc(sizeof(char*) * (splits + 1));

        // copy substrings we already have
        for (int i = 0; i < splits; i++) {
            final[i] = (char*)malloc(sizeof(char) * strlen(substrs[i]));
            final[i] = substrs[i];
            // free(substrs[i]);
        }
        free(substrs);  // let go of substrs since we don't need it anymore

        // allocate memory for the left over substring in the new array
        final[splits] = (char*)malloc(sizeof(char) * acc.len);

        // copy chars from acc to the new array
        for (int i = 0; i < acc.len; i++) {
            final[splits][i] = *(char*)acc.arr[i];
        }
        // printf("final[%d] is: %s\n", splits, final[splits]);
        FreeArraylist(&acc);  // let go of acc since we don't need it anymore

        Substrings out = {.substrings = final,
                          .length = splits == 0 ? 1 : splits + 1};
        return out;
    } else {
        Substrings out = {.substrings = substrs,
                          .length = splits == 0 ? 1 : splits};
        return out;
    }
}