#include <iostream>  
using namespace std;  

class Stack {  
private:  
    vector<int> arr;  // thay vector cho arrray

public:  
    // Constructor  
    Stack() = default; // Sử dụng mặc định constructor  

    // Destructor - không cần thiết, vector tự động giải phóng bộ nhớ  

    // Thêm phần tử vào ngăn xếp  
    void push(int x) {  
        arr.push_back(x); // Thêm phần tử vào cuối vector  
    }  

    // Xóa phần tử khỏi ngăn xếp  
    int pop() {  
        if (isEmpty()) {  
            cout << "Ngăn xếp rỗng!" << endl;  
            return -1;  
        }  
        return arr.back();
    }  

    // Kiểm tra ngăn xếp có rỗng hay không  
    bool isEmpty() {  
        return arr.empty();  
    }  

    // Lấy phần tử đỉnh mà không xóa  
    int peek() {  
        if (arr.empty()) {  
            std::cout << "Stack is empty" << std::endl;  
            return -1; // Trả về -1 nếu stack rỗng  
        }  
        return arr.back(); // Trả về phần tử trên cùng  
    }  

    // Số lượng phần tử trong ngăn xếp  
    int size() {  
        return arr.size();  
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