#include <iostream>
#include <vector>

/*
 * Selection sort =======================================
 */
void selection_sort(int arr[], int n) {
    if (n == 0) {
        return;
    }

    for (int i = n - 1; i >= 0; i--) {
        //Find largest index
        int index_max = 0;
        for (int j = 0; j <= i; j++) {
            if (arr[j] > arr[index_max]) {
                index_max = j;
            }
        }

        //swap
        int tmp = arr[i];
        arr[i] = arr[index_max];
        arr[index_max] = tmp;
    }
}

/*
 * Merge sort =============================================
 */

void merge(std::vector<int>& v, std::vector<int>& tmp, int lo, int mid, int hi) {
    int i = lo, j = mid + 1;
    int k = 0;
    for (;i <= mid && j <= hi; k++) {
        if (v[i] < v[j]) {
            tmp[k] = v[i];
            i++;
        } else {
            tmp[k] =v[j];
            j++;
        }
    }

    while (i <= mid) {
        tmp[k++] = v[i++];
    }

    while (j <= hi) {
        tmp[k++] = v[j++];
    }

    for (i = lo; i <= hi; i++) {
        v[i] = tmp[i - lo];
    }
}

void _merge_sort(std::vector<int>& v, std::vector<int>& tmp, int lo, int hi) {
    if (lo == hi) {
        return;
    }

    int mid = lo + (hi - lo) / 2;
    _merge_sort(v, tmp, lo, mid);
    _merge_sort(v, tmp, mid + 1, hi);
    merge(v, tmp, lo, mid, hi);
}

void merge_sort(std::vector<int>& v, int lo, int hi) {
    std::vector<int> tmp(v.size(), 0);
    _merge_sort(v, tmp, lo, hi);
}

/*
 * Utility functions ==================================
 */

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void print(const std::vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

/*
 * Main ==============================================
 */

int main() {
    int arr1[] = {1,3,2,5,1};
    selection_sort(arr1, 5);
    print(arr1, 5);

    std::vector<int> v1 = {1,3,2,5,1};
    std::vector<int> v2 = {1,1,1,1,1};
    std::vector<int> v3 = {1};
    std::vector<int> v4 = {15,1};
    std::vector<int> v5 = {1,2,3,4,5};
    std::vector<int> v6 = {5,4,3,2,1};
    merge_sort(v1, 0, 4);
    merge_sort(v2, 0, 4);
    merge_sort(v3, 0, 0);
    merge_sort(v4, 0, 1);
    merge_sort(v5, 0, 4);
    merge_sort(v6, 0, 4);
    print(v1);
    print(v2);
    print(v3);
    print(v4);
    print(v5);
    print(v6);
}
