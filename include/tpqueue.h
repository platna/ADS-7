// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept>

template<typename T>
class TPQueue {
 private:
    struct Node {
        T data;
        Node* next;
    };
    Node* begin;
    Node* end;

 public:
    TPQueue() : begin(nullptr), end(nullptr) {}

    void push(const T& data) {
      Node* new_mode = new Node{data, nullptr};
      if (!begin || begin->data.prior < data.prior) {
        new_mode->next = begin;
        begin = new_mode;
      } else {
        Node* current = begin;
        while (current->next &&  current->next->data.prior >= data.prior) {
          current = current->next;
        }
        new_mode->next = current->next;
        current->next = new_mode;
      }
      if (!end) {
        end = begin;
      }
    }
    T pop() {
      if (!begin) {
        throw std::out_of_range("Queue empty");
      }
      T data = begin->data;
      Node* temp = begin;
      begin = begin->next;
      delete temp;
      if (!begin) {
        end = nullptr;
      }
      return data;
    }
    bool is_empty() {
      return !begin;
    }
};

struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
