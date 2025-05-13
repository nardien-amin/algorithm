// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

void reverse(int* arr, int size) {
    int l = 0, r = size - 1;
    while (l < r) {
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    }
}

void merge(int* nums, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = nums[left + i];
    for (int j = 0; j < n2; j++) R[j] = nums[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) nums[k++] = L[i++];
        else nums[k++] = R[j++];
    }

    while (i < n1) nums[k++] = L[i++];
    while (j < n2) nums[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int* nums, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

void wiggleSort(int* nums, int numsSize) {
    // Step 1: Sort the array
    mergeSort(nums, 0, numsSize - 1);

    // Step 2: Split and reverse halves
    int half = (numsSize + 1) / 2;
    int* small = (int*)malloc(half * sizeof(int));
    int* large = (int*)malloc((numsSize - half) * sizeof(int));

    for (int i = 0; i < half; i++) small[i] = nums[i];
    for (int i = 0; i < numsSize - half; i++) large[i] = nums[half + i];

    reverse(small, half);
    reverse(large, numsSize - half);

    // Step 3: Fill in wiggle pattern
    int i = 0, s = 0, l = 0;
    while (i < numsSize) {
        if (i % 2 == 0) {
            nums[i++] = small[s++];
        } else {
            nums[i++] = large[l++];
        }
    }

    free(small);
    free(large);
}

// Test
int main() {
    int nums[] = {1, 5, 1, 1, 6, 4};
    int size = sizeof(nums) / sizeof(nums[0]);

    wiggleSort(nums, size);

    printf("Wiggle Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
