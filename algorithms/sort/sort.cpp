#include <iostream>
#include <vector>

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

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

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
 * Quick sort =============================================
 */
int partition(int arr[], int l, int r) {
    int pivot_index = r; //Choose last element as pivot
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] <= arr[pivot_index]) {
            i++; //Increase boundary for left partition by one
            swap(arr[i], arr[j]); //Put element at j into the left partition
        }
    }
    swap(arr[i+1], arr[pivot_index]); //Swap pivot element with first element in right partition
    return i + 1;
}

void quicksort(int arr[], int l, int r) {
    if (l < r) { //Need to check like this because we will be calling quicksort with l..p-1 and p+1..r
        int p = partition(arr, l, r);
        quicksort(arr, l, p - 1);
        quicksort(arr, p + 1, r);
    }
}

/*
 * Main ==============================================
 */

int main() {
    std::cout << "=============================Selection sort=================================\n";
    int arr1[] = {1,3,2,5,1};
    selection_sort(arr1, 5);
    print(arr1, 5);

    std::cout << "=============================Merge sort=================================\n";
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

    std::cout << "=============================Quick sort=================================\n";
    int a1[] = {1,3,2,5,1};
    int a2[] = {1,1,1,1,1};
    int a3[] = {1};
    int a4[] = {15,1};
    int a5[] = {1,2,3,4,5};
    int a6[] = {5,4,3,2,1};
    quicksort(a1, 0, 4);
    quicksort(a2, 0, 4);
    quicksort(a3, 0, 0);
    quicksort(a4, 0, 1);
    quicksort(a5, 0, 4);
    quicksort(a6, 0, 4);
    print(a1, 5);
    print(a2, 5);
    print(a3, 1);
    print(a4, 2);
    print(a5, 5);
    print(a6, 5);
}
