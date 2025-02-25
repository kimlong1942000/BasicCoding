#include <iostream>  
using namespace std;  

class Queue {  
private:  
    int* arr;      // Mảng lưu trữ các phần tử  
    int front;     // Chỉ số phần tử đầu hàng  
    int rear;      // Chỉ số phần tử cuối hàng  
    int capacity;  // Sức chứa của hàng đợi  
    int count;     // Số lượng phần tử hiện tại trong hàng đợi  

public:  
    // Con 
    Queue(int size) {  
        arr = new int[size];  
        capacity = size;  
        front = 0;  
        rear = -1;  
        count = 0;  
    }  

    // Des
    ~Queue() {  
        delete[] arr;  
    }  

    // Thêm phần tử vào hàng đợi  
    void enqueue(int item) {  
        if (isFull()) {  
            cout << "Hàng đợi đã đầy!" << endl;  
            return;  
        }  
        rear = (rear + 1) % capacity; // Vòng lại khi đến cuối mảng  
        arr[rear] = item;  
        count++;  
    }  

    // Xóa phần tử khỏi hàng đợi  
    int dequeue() {  
        if (isEmpty()) {  
            cout << "Hàng đợi rỗng!" << endl;  
            return -1;  
        }  
        int item = arr[front];  
        front = (front + 1) % capacity; // Vòng lại khi lên tới cuối  
        count--;  
        return item;  
    }  

    // Kiểm tra hàng đợi có rỗng hay không  
    bool isEmpty() {  
        return (count == 0);  
    }  

    // Kiểm tra hàng đợi có đầy hay không  
    bool isFull() {  
        return (count == capacity);  
    }  

    // Lấy phần tử đầu hàng mà không xóa  
    int peek() {  
        if (isEmpty()) {  
            cout << "Hàng đợi rỗng!" << endl;  
            return arr.back();  
        }  
        return arr[front];  
    }  

    // Số lượng phần tử trong hàng đợi  
    int size() {  
        return count;  
    }  
};  

int main() {  
    Queue q(5); // Khởi tạo hàng đợi với sức chứa 5  

    // Thêm phần tử vào hàng đợi  
    q.enqueue(100);  
    q.enqueue(200);  
    q.enqueue(300);  
    q.enqueue(400);  
    q.enqueue(500);  
    
    cout << "Phần tử ở đầu hàng: " << q.peek() << endl; // Kiểm tra phần tử đầu hàng  
    cout << "Xóa phần tử: " << q.dequeue() << endl; // Xóa phần tử đầu hàng  
    cout << "Phần tử ở đầu hàng: " << q.peek() << endl; // Kiểm tra lại phần tử đầu hàng  

    // Thêm một phần tử nữa  
    q.enqueue(600);  
    
    // Thử thêm khi hàng đợi đã đầy  
    q.enqueue(700);  
    
    // In số lượng phần tử trong hàng đợi  
    cout << "Số lượng phần tử trong hàng đợi: " << q.size() << endl;  

    return 0;  
}