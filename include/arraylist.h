#pragma once

#include <stdlib.h>

typedef struct Arraylist {
    void** arr;
    int cap;
    int len;
} Arraylist;

Arraylist NewArraylist(int size) {
    void** a = (void**)malloc(sizeof(int) * size);
    Arraylist al = {.arr = a, .cap = size, .len = 0};
    return al;
}

void* ALRemove(Arraylist* al) {
    if (al->len > 0 && al->cap > 0) {
        al->len--;
        void* v = al->arr[al->len];
        al->arr[al->len] = 0;
        return v;
    }
    return 0;
};

void ALAdd(Arraylist* al, void* value) {
    if (al->len + 1 >= al->cap) {
        al->cap++;
        void** newArr = (void**)malloc(sizeof(int) * al->cap);
        for (int i = 0; i < al->cap - 1; i++) {
            newArr[i] = al->arr[i];
        }
        free(al->arr);
        al->arr = newArr;
    }
    al->arr[al->len] = value;
    al->len++;
}

int ALLen(Arraylist* al) { return al->len; }

int ALCap(Arraylist* al) { return al->cap; }