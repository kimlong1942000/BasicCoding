#include <iostream>  
using namespace std;  

// Hàm sắp xếp chọn  
void selectionSort(int arr[], int n) {  
    for (int i = 0; i < n - 1; i++) {  
        int minIndex = i; // Giả sử phần tử đầu tiên là nhỏ nhất  
        for (int j = i + 1; j < n; j++) {  
            // Tìm phần tử nhỏ nhất trong phần còn lại của mảng  
            if (arr[j] < arr[minIndex]) {  
                minIndex = j; // Cập nhật chỉ số phần tử nhỏ nhất  
            }  
        }  
        // Hoán đổi phần tử nhỏ nhất với phần tử ở vị trí i  
        swap(arr[i], arr[minIndex]);  
    }  
}  

// Hàm in mảng  
void printArray(int arr[], int n) {  
    for (int i = 0; i < n; i++)  
        cout << arr[i] << " "; // In từng phần tử  
    cout << endl;  
}  

int main() {  
    int arr[] = {64, 25, 12, 22, 11};  
    int n = sizeof(arr) / sizeof(arr[0]); // Tính số phần tử trong mảng  
    selectionSort(arr, n); // Gọi hàm sắp xếp  
    printArray(arr, n); // In mảng đã sắp xếp  
    return 0;  
}