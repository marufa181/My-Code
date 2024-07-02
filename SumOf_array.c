#include <stdio.h>


int calc_sum(int arr[], int left, int right) {
    
    if (left == right) {
        return arr[left];
    }

    
    int mid = left + (right - left) / 2;

    int left_sum = calc_sum(arr, left, mid);
    int right_sum = calc_sum(arr, mid + 1, right);

    
    return left_sum + right_sum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int total_sum = calc_sum(arr, 0, n - 1);

    printf("Sum of the array is: %d\n", total_sum);

    return 0;
}
