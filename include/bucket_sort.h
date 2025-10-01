#ifndef BUCKET_SORT_H
#define BUCKET_SORT_H

#include <stdio.h>
#include <stdlib.h>
#define BUCKETS 10

typedef struct Node {
    int* values;
    int count;
    int capacity;
} Bucket;


void insert_bucket(Bucket* bucket, int value);

void bucket_sort(int vetor[], int n);

#endif