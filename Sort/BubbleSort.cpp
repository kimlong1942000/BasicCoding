#include <iostream>  
using namespace std;  

// Hàm sắp xếp bọt  
void bubbleSort(int arr[], int n) {  
    for (int i = 0; i < n - 1; i++) { // Vòng lặp qua từng phần tử  
        for (int j = 0; j < n - i - 1; j++) { // Vòng lặp để so sánh các phần tử ngay cạnh nhau  
            if (arr[j] > arr[j + 1]) {  
                swap(arr[j], arr[j + 1]); // Hoán đổi nếu phần tử hiện tại lớn hơn phần tử kế tiếp  
            }  
        }  
    }  
}  

// Hàm in mảng  
void printArray(int arr[], int n) {  
    for (int i = 0; i < n; i++)  
        cout << arr[i] << " "; // In từng phần tử  
    cout << endl;  
}  

int main() {  
    int arr[] = {64, 34, 25, 12, 22, 11, 90};  
    int n = sizeof(arr) / sizeof(arr[0]); // Tính số phần tử trong mảng  
    bubbleSort(arr, n); // Gọi hàm sắp xếp  
    printArray(arr, n); // In mảng đã sắp xếp  
    return 0;  
}