/*
    - Run this file with cmod test.c
    - This will run the file and build test.o.
*/

import std;
import io;
import hello_world_library;
import array;

int main(){
    hello_world();
    array_int arr = array_int_alloc(10);
    for (int i = 0; i < 10; i++){
        array_int_set(arr,i,i);
    }
    for (int i = 0; i < 10; i++){
        printf("%d ",array_int_get(arr,i));
    }
    printf("\n");
    array_int_destroy(arr);
    return 0;
}