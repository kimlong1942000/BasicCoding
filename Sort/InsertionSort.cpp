#include <iostream>  
using namespace std;  

// Hàm sắp xếp chèn  
void insertionSort(int arr[], int n) {  
    for (int i = 1; i < n; i++) {  
        int key = arr[i]; // Lấy giá trị của phần tử hiện tại  
        int j = i - 1; // Bắt đầu từ phần tử trước đó  

        // Di chuyển các phần tử lớn hơn key về phía phải  
        while (j >= 0 && arr[j] > key) {  
            arr[j + 1] = arr[j]; // Di chuyển phần tử  
            j--; // Giảm chỉ số j  
        }  
        arr[j + 1] = key; // Chèn key vào vị trí đúng  
    }  
}  

// Hàm in mảng  
void printArray(int arr[], int n) {  
    for (int i = 0; i < n; i++)  
        cout << arr[i] << " "; // In từng phần tử  
    cout << endl;  
}  

int main() {  
    int arr[] = {12, 11, 13, 5, 6};  
    int n = sizeof(arr) / sizeof(arr[0]); // Tính số phần tử trong mảng  
    insertionSort(arr, n); // Gọi hàm sắp xếp  
    printArray(arr, n); // In mảng đã sắp xếp  
    return 0;  
}