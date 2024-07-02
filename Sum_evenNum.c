#include <stdio.h>


int calc_sum_even(int arr[], int left, int right) {
    
    if (left == right) {
        return (arr[left] % 2 == 0) ? arr[left] : 0;
    }

    int mid = left + (right - left) / 2;

    
    int left_sum = calc_sum_even(arr, left, mid);
    int right_sum = calc_sum_even(arr, mid + 1, right);

    
    return left_sum + right_sum;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int total_sum_even = calc_sum_even(arr, 0, n - 1);

    printf("Sum of the even numbers in the array is: %d\n", total_sum_even);

    return 0;
}
