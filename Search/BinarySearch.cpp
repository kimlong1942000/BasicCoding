#include <iostream>  
using namespace std;  

// Hàm tìm kiếm nhị phân  
int binarySearch(int arr[], int left, int right, int key) {  
    while (left <= right) {  
        int mid = left + (right - left) / 2; // Tính chỉ số giữa  

        // Kiểm tra phần tử giữa  
        if (arr[mid] == key) {  
            return mid; // Trả về chỉ số nếu tìm thấy  
        }  

        // Nếu key lớn hơn phần tử giữa, chỉ thị tìm kiếm nửa bên phải  
        if (arr[mid] < key) {  
            left = mid + 1;  
        } else { // Nếu key nhỏ hơn phần tử giữa, chỉ thị tìm kiếm nửa bên trái  
            right = mid - 1;  
        }  
    }  
    return -1; // Trả về -1 nếu không tìm thấy  
}  

int main() {  
    int arr[] = {2, 3, 4, 5, 8}; // Mảng đã được sắp xếp  
    int n = sizeof(arr) / sizeof(arr[0]); // Tính số phần tử trong mảng  
    int key = 4; // Giá trị cần tìm  
    int result = binarySearch(arr, 0, n - 1, key); // Gọi hàm tìm kiếm  

    if (result != -1) {  
        cout << "Phần tử " << key << " được tìm thấy tại chỉ số: " << result << endl;  
    } else {  
        cout << "Phần tử " << key << " không được tìm thấy." << endl;  
    }  

    return 0;  
}