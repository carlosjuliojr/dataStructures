#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#include<iostream>


template< typename T>
struct Node {

    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T a) : data(a), next(nullptr), prev(nullptr) {}
    T getData() const{ return data;}


};


template <typename T>
class DoublyList
{
  private:

    int size;
    Node<T>* head;
    Node<T>* tail;




  public:

    /**
     * @brief DoublyList
     */
    DoublyList() {

      this->size = 0;
      this->head= nullptr;
      this->tail = nullptr;

    }

    /**
     * @brief begin
     * @return
     */
    Node<T>* begin() const
    {
      return this->head;
    }

    /**
     * @brief end
     * @return
     */
    Node<T>* end() const
    {
      return this->tail;
    }

    /**
     * @brief empty
     * @return
     */
    bool empty()const
    {
      return  (this->size == 0) ? true : false;
    }

    /**
      * @brief fron
      * @return
      */
    T front() const
    {
      return this->head->data;
    }

    /**
      * @brief back
      * @return
      */
    T back() const
    {
      return this->tail->data;
    }
    /**
     * @brief push_front
     * @param a
     */
    const void push_front(const T& a)
    {

      Node<T>* newNode = new Node<T>(a);


      if(this->size == 0){

        this->tail = newNode;

      }else{

        Node<T>* tmp = this->head;
        tmp->prev = newNode;
        newNode->next = tmp;

      }

      this->head = newNode;
      this->size++;
    }

    /**
     * @brief push_back
     * @param a
     */
    void push_back(const T &a){

      Node<T>* newNode = new Node<T>(a);


      if(this->size == 0){

        this->head = newNode;

      }else{

        Node<T>* tmp = this->tail;
        tmp->next = newNode;
        newNode->prev = tmp;

      }

      this->tail = newNode;
      this->size++;
    }
    /**
     * @brief print
     */
    void print(){

      Node<T>* it = this->begin();
      while(it != nullptr){

        std::cout<< it->data << " => ";
        it= it->next;
      }

    }


    int getSize() const {

     return this->size;
    }

    /**
      * @brief pop_front
      */
     void pop_front(){


       if(this->size ==1){


         delete this->head;
         this->head= nullptr;
         this->tail= nullptr;

         this->size--;
       }else if (this->size > 1){

         Node<T>* tmp = this->head->next;
         delete this->head;
         this->head = tmp;
         this->head->prev=nullptr;
         this->size--;

       }else
         return;

    }

};







#endif // DOUBLYLIST_H
