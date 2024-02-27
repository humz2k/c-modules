import std;

typedef struct array_int{
    int* raw;
    int len;
} array_int;

array_int array_int_alloc(int len){
    array_int out;
    out.raw = (int*)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++){
        out.raw[i] = 0;
    }
    out.len = len;
    return out;
}

int array_int_get(array_int arr, int idx){
    return arr.raw[idx];
}

int array_int_set(array_int arr, int idx, int val){
    arr.raw[idx] = val;
    return val;
}

void array_int_destroy(array_int arr){
    free(arr.raw);
}
