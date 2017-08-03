#ifndef STACK_H
#define STACK_H


template<typename T>
struct Node{

    T data;
    Node* next;

    Node(T a) : data(a), next(nullptr) {}
    T getData() const{ return data;}

};


template<typename T>
class Stack
{

  private:

    int size;
    Node<T>* top;



  public:
    /**
     * @brief Stack
     */
    Stack(): size(0), top(nullptr) {}

    bool empty(){
//      return (this->size == 0 ) ? true : false;

      if(this->size == 0 ){
        return true;
      }else
        return false;
    }

    /**
     * @brief push
     * @param node
     */
    void push(T node){

      Node<T>* newNode = new Node<T>(node);

      if(this->size == 0){

        this->top = newNode;

      }else{

        Node<T>* tmp ;
        tmp = this->top;
        this->top = newNode;
        this->top->next = tmp;

      }
      this->size++;
    }

    /**
     * @brief pop
     */
    void  pop(){

      if(this->size == 0){

        return;

      }else if(this->size == 1){

        delete this->top;
        this->size--;

      }else{
        Node<T>* tmp ;
        tmp = this->top->next;
        delete this->top;
        this->top = tmp;
        this->size--;

      }
    }

    /**
     * @brief top
     * @return
     */
    Node<T>* top_stack() const {
      return this->top;
    }

    int getSize() const
    {
    return this->size;
    }
};

#endif // STACK_H


