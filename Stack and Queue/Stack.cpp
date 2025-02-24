#include <iostream>  
using namespace std;  

class Stack {  
private:  
    int* arr;      // Mảng lưu trữ các phần tử  
    int top;       // Chỉ số phần tử đỉnh  
    int capacity;  // Sức chứa của ngăn xếp  

public:  
    // Con  
    Stack(int size) {  
        arr = new int[size];  
        capacity = size;  
        top = -1; // Đỉnh ngăn xếp rỗng  
    }  

    // Des
    ~Stack() {  
        delete[] arr;  
    }  

    // Thêm phần tử vào ngăn xếp  
    void push(int item) {  
        if (isFull()) {  
            cout << "Ngăn xếp đã đầy!" << endl;  
            return;  
        }  
        arr[++top] = item; // Tăng chỉ số đỉnh và thêm phần tử  
    }  

    // Xóa phần tử khỏi ngăn xếp  
    int pop() {  
        if (isEmpty()) {  
            cout << "Ngăn xếp rỗng!" << endl;  
            return -1;  
        }  
        return arr[top--]; // Trả về phần tử đỉnh và giảm chỉ số đỉnh  
    }  

    // Kiểm tra ngăn xếp có rỗng hay không  
    bool isEmpty() {  
        return (top == -1);  
    }  

    // Kiểm tra ngăn xếp có đầy hay không  
    bool isFull() {  
        return (top == capacity - 1);  
    }  

    // Lấy phần tử đỉnh mà không xóa  
    int peek() {  
        if (isEmpty()) {  
            cout << "Ngăn xếp rỗng!" << endl;  
            return -1;  
        }  
        return arr[top];  
    }  

    // Số lượng phần tử trong ngăn xếp  
    int size() {  
        return top + 1;  
    }  
};  

int main() {  
    Stack s(5); // Khởi tạo ngăn xếp với sức chứa 5  

    // Thêm phần tử vào ngăn xếp  
    s.push(10);  
    s.push(20);  
    s.push(30);  
    s.push(40);  
    s.push(50);  
    
    cout << "Phần tử đỉnh: " << s.peek() << endl; // Kiểm tra phần tử đỉnh  
    cout << "Xóa phần tử: " << s.pop() << endl; // Xóa phần tử đỉnh  
    cout << "Phần tử đỉnh sau khi xóa: " << s.peek() << endl; // Kiểm tra lại phần tử đỉnh  

    // Thử thêm khi ngăn xếp đã đầy  
    s.push(60); // Thêm phần tử 60, nhưng ngăn xếp đã đầy  

    // In số lượng phần tử trong ngăn xếp  
    cout << "Số lượng phần tử trong ngăn xếp: " << s.size() << endl;  

    return 0;  
}