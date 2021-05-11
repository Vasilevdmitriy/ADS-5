// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <cassert>

template<typename T>
class TPQueue {
  struct ITEM{
   T data;
   ITEM * next;
  };
public:
  TPQueue(): head(nullptr), tail(nullptr){};
  TPQueue(const T&);
  TPQueue(const TPQueue&);
  ~TPQueue();
  void push(const T&);
  T pop();
private:
  TPQueue::ITEM* create(const T&);
  ITEM *head;
  ITEM *tail;
};

template<typename T>
TPQueue<T>::TPQueue(const T& data){
  head = create(data);
  tail = head;
}

template<typename T>
TPQueue<T>::~TPQueue(){
  while(head)
    pop();
}

template<typename T>
typename TPQueue<T>::ITEM* TPQueue<T>::create(const T& data){
  
  ITEM *item = new ITEM;
  item->data = data;
  item->next = nullptr;
  return item;
}



template<typename T>
void TPQueue<T>::push(const T & data) {
      ITEM * temp = create(data);
      while(tail->next != nullptr) {
        if (temp->data.prior < data.prior) {
             if(tail && head){
              ITEM *temp = create(data);
              temp->next = head;
               head = temp;
              } else {
                head = create(data);
                tail = head;
              }
        } else {
          if(tail && head){
           tail->next = create(data);
            tail = tail -> next;
            } else {
            head = create(data);
           tail = head;
            }
        
        }
       } 
}

template<typename T>
T TPQueue<T>::pop(){
  if(head){
    ITEM *temp = head->next;
    T data = head->data;
    delete head;
    head = temp;
    return data;
  } 
}

struct SYM {
  char ch;
  int  prior;
};

#endif // INCLUDE_TPQUEUE_H_
