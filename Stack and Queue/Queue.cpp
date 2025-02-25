#include <iostream>  
#include <vector>  
#include <optional> // Để sử dụng std::optional  

class Queue {  
private:  
    std::vector<int> elements;  

public:  
    void enqueue(int value) {  
        elements.push_back(value); // Thêm phần tử vào cuối hàng đợi  
    }  

    void dequeue() {  
        if (isEmpty()) {  
            std::cout << "Queue is empty, cannot dequeue." << std::endl;  
            return;  
        }  
        elements.erase(elements.begin()); // Xóa phần tử đầu tiên  
    }  

    bool isEmpty() const {  
        return elements.empty(); // Kiểm tra xem hàng đợi có rỗng không  
    }  

    std::optional<int> peek() {  
        if (isEmpty()) {  
            return std::nullopt; // Không có giá trị  
        }  
        return elements.front(); // Trả về phần tử đầu tiên  
    }  
};  

int main() {  
    Queue queue;  

    // Kiểm tra giá trị đầu tiên khi hàng đợi rỗng  
    auto frontElement = queue.peek();  
    if (!frontElement) {  
        std::cout << "Queue rong - khong co gi dau" << std::endl; // Thông báo khi hàng đợi rỗng  
    }  

    // Thêm một số phần tử vào hàng đợi  
    queue.enqueue(19);  
    queue.enqueue(4);  
    queue.enqueue(2000);  

    // Kiểm tra giá trị đầu tiên sau khi thêm phần tử  
    frontElement = queue.peek();  
    if (frontElement) {  
        std::cout << "Phần tử đầu tiên là: " << *frontElement << std::endl; // Xuất ra phần tử đầu tiên  
    }  

    // Xóa phần tử đầu tiên  
    queue.dequeue();  

    // Kiểm tra lại giá trị đầu tiên  
    frontElement = queue.peek();  
    if (frontElement) {  
        std::cout << "Phần tử đầu tiên sau khi dequeue là: " << *frontElement << std::endl; // Xuất ra phần tử đầu tiên  
    }  

    // Xóa hết để kiểm tra lại  
    queue.dequeue();   
    queue.dequeue(); // Bây giờ hàng đợi rỗng  
    frontElement = queue.peek();  
    if (!frontElement) {  
        std::cout << "Queue is empty, cannot peek." << std::endl; // Thông báo khi hàng đợi rỗng  
    }  

    return 0;  
}