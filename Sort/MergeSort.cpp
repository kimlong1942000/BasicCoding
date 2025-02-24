#include <iostream>  
using namespace std;  

// Hàm hợp nhất hai mảng  
void merge(int arr[], int left, int mid, int right) {  
    int i, j, k;  
    int n1 = mid - left + 1; // Số phần tử trong mảng con trái  
    int n2 = right - mid; // Số phần tử trong mảng con phải  

    // Tạo mảng tạm cho hai phần  
    int *L = new int[n1];  
    int *R = new int[n2];  

    // Sao chép dữ liệu vào mảng tạm  
    for (i = 0; i < n1; i++)  
        L[i] = arr[left + i];  
    for (j = 0; j < n2; j++)  
        R[j] = arr[mid + 1 + j];  

    // Hợp nhất hai mảng  
    i = 0; // Chỉ số cho mảng bên trái  
    j = 0; // Chỉ số cho mảng bên phải  
    k = left; // Chỉ số cho mảng đang được hợp nhất  
    while (i < n1 && j < n2) {  
        if (L[i] <= R[j]) {  
            arr[k] = L[i];  
            i++;  
        } else {  
            arr[k] = R[j];  
            j++;  
        }  
        k++;  
    }  

    // Sao chép phần còn lại của mảng bên trái  
    while (i < n1) {  
        arr[k] = L[i];  
        i++;  
        k++;  
    }  

    // Sao chép phần còn lại của mảng bên phải  
    while (j < n2) {  
        arr[k] = R[j];  
        j++;  
        k++;  
    }  

    delete[] L; // Giải phóng bộ nhớ  
    delete[] R; // Giải phóng bộ nhớ  
}  

// Hàm sắp xếp hòa trộn  
void mergeSort(int arr[], int left, int right) {  
    if (left < right) {  
        int mid = left + (right - left) / 2; // Tìm chỉ số giữa  

        mergeSort(arr, left, mid); // Sắp xếp nửa bên trái  
        mergeSort(arr, mid + 1, right); // Sắp xếp nửa bên phải  
        merge(arr, left, mid, right); // Hợp nhất hai nửa đã sắp xếp  
    }  
}  

// Hàm in mảng  
void printArray(int arr[], int n) {  
    for (int i = 0; i < n; i++)  
        cout << arr[i] << " "; // In từng phần tử  
    cout << endl;  
}  

int main() {  
    int arr[] = {38, 27, 43, 3, 9, 82, 10};  
    int n = sizeof(arr) / sizeof(arr[0]); // Tính số phần tử trong mảng  
    mergeSort(arr, 0, n - 1); // Gọi hàm sắp xếp hòa trộn  
    printArray(arr, n); // In mảng đã sắp xếp  
    return 0;  
}