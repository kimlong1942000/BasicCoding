#include <iostream>  
using namespace std;  

// Hàm tìm kiếm tuyến tính  
int linearSearch(int arr[], int n, int key) {  
    for (int i = 0; i < n; i++) {  
        if (arr[i] == key) { // Kiểm tra từng phần tử  
            return i; // Trả về chỉ số nếu tìm thấy  
        }  
    }  
    return -1; // Trả về -1 nếu không tìm thấy  
}  

int main() {  
    int arr[] = {5, 3, 8, 4, 2};  
    int n = sizeof(arr) / sizeof(arr[0]); // Tính số phần tử trong mảng  
    int key = 4; // Giá trị cần tìm  
    int result = linearSearch(arr, n, key); // Gọi hàm tìm kiếm  

    if (result != -1) {  
        cout << "Phần tử " << key << " được tìm thấy tại chỉ số: " << result << endl;  
    } else {  
        cout << "Phần tử " << key << " không được tìm thấy." << endl;  
    }  

    return 0;  
}