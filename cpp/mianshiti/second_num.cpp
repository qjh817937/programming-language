#include <stdio.h>

int secondNum(int array[], int count) {
    int max=array[0];
    int second=0x7fffffff;
    for(int i =1; i < count; i++) {
        if (max<array[i])  {
            second=max;
            max=array[i];
        }
        else if(max>array[i]) {
            if(second<array[i]) {
                second=array[i];
            }
        } 

    }
    return second;
}

int main(int argc, char** args) {
    int arr[] = {1, 2, 3, 4};
    printf("second=%d\n", secondNum(arr, 4));
    int arr1[] = {1, 2, 3, 3, 4, 3, 4};
    printf("second=%d\n", secondNum(arr1, 7));
    return 0;
}
