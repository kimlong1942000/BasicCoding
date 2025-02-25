#include <iostream>  
#include <vector>  
#include <optional> // Để sử dụng std::optional  

using namespace std;  

class Stack {  
    private:  
        std::vector<int> elements;  // sử dụng vector thay cho Array
    
    public:  
        void push(int value) {  
            elements.push_back(value);  
        }  
    
        void pop() {  
            if (isEmpty()) {  
                std::cout << "Stack rong - khong co phan tu nao de xoa" << std::endl;  
                return;  
            }  
            elements.pop_back();  
        }  
    
        bool isEmpty() const {  
            return elements.empty();  
        }  
    
        std::optional<int> peek() {  
            if (isEmpty()) {  
                return std::nullopt; // Không có giá trị  
            }  
            return elements.back(); // Trả về phần tử trên cùng  
        }  
    };  

int main() {  
    Stack stack;  

    // Kiểm tra giá trị trên cùng khi stack rỗng  
    auto topElement = stack.peek();  
    if (!topElement) {  
        std::cout << "Stack is empty, cannot peek." << std::endl; // Thông báo khi stack rỗng  
    }  

    // Thêm một số phần tử vào stack  
    stack.push(19);  
    stack.push(4);  
    stack.push(2000);  

    // Kiểm tra giá trị trên cùng sau khi thêm phần tử  
    topElement = stack.peek();  
    if (topElement) {  
        std::cout << "Phần tử trên cùng là: " << *topElement << std::endl; // Xuất ra phần tử trên cùng  
    }  

    // Xóa phần tử trên cùng  
    stack.pop();  

    // Kiểm tra lại giá trị trên cùng  
    topElement = stack.peek();  
    if (topElement) {  
        std::cout << "Phần tử trên cùng sau khi pop là: " << *topElement << std::endl; // Xuất ra phần tử trên cùng  
    }  

    // Xóa hết để kiểm tra lại  
    stack.pop();   
    stack.pop(); // Bây giờ stack rỗng  
    topElement = stack.peek();  
    if (!topElement) {  
        std::cout << "Stack is empty, cannot peek." << std::endl; // Thông báo khi stack rỗng  
    }  

    return 0;
}