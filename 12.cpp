#include <iostream>
#include <stdexcept>
#include <memory>

using namespace std;
template <typename T>
struct ILinkedList {
    virtual void push_back(const T& data) = 0;
    virtual void push_front(const T& data) = 0;
    virtual void pop_back() = 0;
    virtual void pop_front() = 0;
    virtual T front() const = 0;
    virtual T back() const = 0;
    virtual size_t size() const = 0;
    virtual bool empty() const = 0;
    virtual ~ILinkedList() {}
};
template <typename T>
struct Node {
    T data;
    unique_ptr<Node<T>> next;
    Node(const T& data) : data(data), next(nullptr) {}
};
template <typename T>
class LList : public ILinkedList<T> {
private:
    unique_ptr<Node<T>> head;
    Node<T>* tail;
    size_t list_size;

public:
    LList() : head(nullptr), tail(nullptr), list_size(0) {}
    LList(const LList<T>& other) : list_size(other.list_size) {
        if (other.head) {
            head = make_unique<Node<T>>(other.head->data);
            Node<T>* current = head.get();
            Node<T>* otherCurrent = other.head->next.get();

            while (otherCurrent) {
                current->next = make_unique<Node<T>>(otherCurrent->data);
                current = current->next.get();
                otherCurrent = otherCurrent->next.get();
            }
            tail = current;
        }
        else {
            tail = nullptr;
        }
    }

    void push_back(const T& data) override {
        auto new_node = make_unique<Node<T>>(data);
        if (empty()) {
            head = move(new_node);
            tail = head.get();
        }
        else {
            tail->next = move(new_node);
            tail = tail->next.get();
        }
        list_size++;
    }

    void push_front(const T& data) override {
        auto new_node = make_unique<Node<T>>(data);
        if (empty()) {
            head = move(new_node);
            tail = head.get();
        }
        else {
            new_node->next = move(head);
            head = move(new_node);
        }
        list_size++;
    }

    void pop_back() override {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        if (head.get() == tail) {
            head.reset();
            tail = nullptr;
        }
        else {
            Node<T>* current = head.get();
            while (current->next.get() != tail) {
                current = current->next.get();
            }
            current->next.reset();
            tail = current;
        }
        list_size--;
    }

    void pop_front() override {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        head = move(head->next);
        if (head == nullptr) {
            tail = nullptr;
        }
        list_size--;
    }

    T front() const override {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }

        return head->data;
    }

    T back() const override {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        return tail->data;
    }

    size_t size() const override {
        return list_size;
    }

    bool empty() const override {
        return list_size == 0;
    }
    void pop() {
        pop_front();
    }
};
template <typename T>
class Queue : public LList<T> {
public:
    Queue() : LList<T>() {}
    Queue(const Queue<T>& other) : LList<T>(other) {}

    void push(const T& data) {
        LList<T>::push_back(data);
    }

    void pop() {
        LList<T>::pop_front();
    }

    T front() const {
        return LList<T>::front();
    }

    T back() const {
        return LList<T>::back();
    }
};
int main() {
    Queue<char> qe; 
    qe.push('a');
    qe.push('b');
    qe.push('c');

    std::cout << qe.size() << std::endl; 

    auto q = qe;

    while (!qe.empty()) {
        std::cout << qe.front() << '\t' << qe.back() << std::endl;
        qe.pop();
    }
    std::cout << qe.size() << '\t' << q.size() << '\t'
        << q.front() << '\t' << q.back() << std::endl;

    return 0;
}
