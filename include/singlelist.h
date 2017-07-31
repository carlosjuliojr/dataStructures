#ifndef SINGLELIST_H
#define SINGLELIST_H


template<typename T>
struct Node{
    T data;
    Node* next;


    Node(T a) : data(a), next(nullptr) {}
    T getData(){ return data;}

};


template<typename T>
class SingleList
{
  private:

    Node<T>* iterator;
    int size;
    Node<T>* head;
    Node<T>* tail;

  public:
    /**
    * @brief SingleList
    */
    SingleList()
    {

      this->size=0;
      this->head=nullptr;
      this->tail=nullptr;

    };

    SingleList(Node<T>*);

    /**
    * @brief front
    * @return
    */
    T front()
    {
      T a;

      if(this->size == 0){
        return a;
      }

      return this->head->data;
    }

    /**
    * @brief back
    * @return
    */
    T back()
    {

      T a;

      if(this->size == 0){
        return a;
      }

      return this->tail->data;
    }

    /**
    * @brief begin
    * @return
    */
    Node<T>* begin()
    {
      return this->head;
    }

    /**
    * @brief push_back
    * @param a
    */
    void push_back(T a){

      Node<T>* newNode = new Node<T>(a);

      if(this->size == 0){
        this->head = newNode;
        this->size++;
        this->tail = this->head;

      }else{

        Node<T>* tmp;
        tmp = this->tail;
        tmp->next = newNode;
        tail = newNode;
        this->size++;
      };


    }

    /**
    * @brief push_front
    * @param a
    */
    void push_front(T a)
    {

      Node<T>* newNode = new Node<T>(a);

      if(this->size == 0){
        this->head = newNode;
        this->size++;
        this->tail = this->head;

      }else{

        Node<T>* tmp;
        tmp = this->head;
        head = newNode;
        head->next = tmp;
        this->size++;
      }

    }

    /**
    * @brief empty
    * @return
    */
    bool empty() const
    {
      if(size == 0)
        return true;
      else
        return false;
    };

    /**
    * @brief getSize
    * @return
    */
    int getSize() const{
      return size;
    }

    /**
    * @brief pop_front
    */
    void pop_front(){

      if(this->size == 0){
        return;
      }else if(this->size == 1){

        this->size--;
        delete head;
        this->head= nullptr;
        this->tail= nullptr;


      }else{

        Node<T>* tmp = this->head->next;
        delete head;
        head = tmp;
        this->size--;

      }

    }

    /**
    * @brief pop_front
    */
    void pop_back(){

      if(this->size == 0){
        return;
      }else if(this->size == 1){


        this->size--;
        delete head;


      }else{

        Node<T>* tmp = head;
        while(tmp->next != tail){
          tmp = tmp->next;
        }


        delete tail;
        tail = tmp;
        tail->next =  nullptr;
        this->size--;

      }

    }


    void insert(Node<T>* iterator, int n, T val){

      Node<T>* it = begin();

      while( it != nullptr){

        if(it == iterator){
          break;
        }

        it = it->next;
      }

      if(it != nullptr){

          if(it->next == nullptr){

              for (int var = 0; var < n; ++var) {
              push_back(val);
            }

          }else{
            Node<T>* tmp = it->next;

            for (int var = 0; var < n; ++var) {

              Node<T>* newNode = new Node<T>(val);
              it->next = newNode;
              newNode->next=tmp;
              tmp = it->next;
              this->size++;

            }
        }

      }

    }


    void insert(Node<T>* iterator, T val){

      Node<T>* it = begin();

      while( it != nullptr){

        if(it == iterator){
          break;
        }

        it = it->next;
      }

      if(it != nullptr){

          if(it->next == nullptr){

              push_back(val);

          }else{
            Node<T>* tmp = it->next;


              Node<T>* newNode = new Node<T>(val);
              it->next = newNode;
              newNode->next=tmp;
              tmp = it->next;
              this->size++;

        }

      }

    }





};

#endif // SINGLELIST_H