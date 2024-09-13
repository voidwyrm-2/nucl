#pragma once

#include <stdlib.h>

typedef struct Result {
    void* res;
    char* err;
} Result;

Result NewResult(void* r, char* e) {
    Result result = {.res = r, .err = e};
    return result;
}

Result NewErrResult(char* e) {
    return NewResult(NULL, e);
}

Result NewSuccessResult(void* r) {
    return NewResult(r, NULL);
}