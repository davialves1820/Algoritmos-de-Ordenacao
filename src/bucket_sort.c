#include "bucket_sort.h"

void insert_bucket(Bucket *bucket, int value) {
    if (bucket->count == bucket->capacity) {
        bucket->capacity *= 2;
        bucket->values = realloc(bucket->values, bucket->capacity * sizeof(int));
    }
    bucket->values[bucket->count++] = value;
}

void bucket_sort(int arr[], int n) {
    Bucket buckets[BUCKETS];

    // Inicializar buckets
    for (int i = 0; i < BUCKETS; i++) {
        buckets[i].count = 0;
        buckets[i].capacity = 5;
        buckets[i].values = malloc(buckets[i].capacity * sizeof(int));
    }

    // Encontrar valor máximo
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Distribuir elementos nos buckets
    for (int i = 0; i < n; i++) {
        int index = (BUCKETS * arr[i]) / (max + 1); // escala para bucket
        insert_bucket(&buckets[index], arr[i]);
    }

    // Ordenar cada bucket usando quick_sort
    int idx = 0;
    for (int i = 0; i < BUCKETS; i++) {
        if (buckets[i].count > 0) {
            quick_sort(buckets[i].values, 0, buckets[i].count - 1);
            for (int j = 0; j < buckets[i].count; j++) {
                arr[idx++] = buckets[i].values[j];
            }
        }
        free(buckets[i].values);
    }
}