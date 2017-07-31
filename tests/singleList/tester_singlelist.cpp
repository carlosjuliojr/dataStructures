#include<gtest/gtest.h>
#include"../../include/singlelist.h"


TEST(test1, test_pust_front)
{

   SingleList<int>* myList = new SingleList<int>;

      myList->push_front(1);


      ASSERT_EQ(myList->front(),1);

      myList->push_front(10);
      ASSERT_EQ(myList->front(),10);
      myList->push_front(10);
      myList->push_front(0);


      ASSERT_EQ(myList->front(),0);

delete myList;
}

TEST(test2, test_back)
{

   SingleList<int>* myList = new SingleList<int>;


      std::cout<<myList->back();

      myList->push_back(1);
      myList->push_back(11);
      myList->push_back(10);


      ASSERT_EQ(myList->back(),10);

      delete myList;

}

TEST(test3, test_push_back)
{

   SingleList<int>* myList = new SingleList<int>;

      myList->push_back(2);
      myList->push_back(4);
      myList->push_back(6);


      Node<int>* tmp = myList->begin();
      int i = 2;
      while(tmp != nullptr){

          ASSERT_EQ(tmp->data,i);
          tmp = tmp->next;
          i+=2;

      }



      delete myList;

}

TEST(test4, test_push_front)
{

   SingleList<int>* myList = new SingleList<int>;

      myList->push_front(2);
      myList->push_front(4);
      myList->push_front(6);


      Node<int>* tmp = myList->begin();
      int i = 6;
      while(tmp != nullptr){

          ASSERT_EQ(tmp->data,i);
          tmp = tmp->next;
          i-=2;

      }
      delete myList;

}

TEST(test5, test_empty)
{

   SingleList<int>* myList = new SingleList<int>;


      ASSERT_TRUE(myList->empty());

      myList->push_front(2);
      myList->push_front(2);

      ASSERT_FALSE(myList->empty());

      myList->pop_front();

       ASSERT_FALSE(myList->empty());

       delete myList;

}

TEST(test6, test_pop_front)
{

   SingleList<int>* myList = new SingleList<int>;

      myList->push_front(2);
      myList->push_front(3);


      // 3 => 2 => null
      myList->pop_front();

      ASSERT_EQ(myList->front(), 2);
      // 2 => null
      myList->pop_front();
        // null therefore the list is empty
       ASSERT_TRUE(myList->empty());

delete myList;

}

TEST(test7, test_pop_back)
{

   SingleList<int>* myList = new SingleList<int>;

      myList->push_front(2);
      myList->push_front(3);
      myList->push_front(4);
      myList->push_front(5);


      // 5 => 4 => 3 => 2 => null
      myList->pop_back();

      myList->pop_back();


      ASSERT_EQ(myList->back(), 4);
      // 5 => 4 => null
      myList->pop_back();
      ASSERT_EQ(myList->back(), 5);

      myList->pop_back();
     ASSERT_TRUE(myList->empty());




delete myList;

}


TEST(test8, test_insert)
{

   SingleList<int>* myList = new SingleList<int>;

      myList->push_front(4);
      myList->push_front(3);


      // 3 => 4 => null
      myList->insert(myList->begin(),3,-1);


      // 3  => -1 => -1 => -1 => 4 => null
      myList->pop_back();

      std::cout << myList->back()<<"yohana";

      // 3 => => -1 => -1 => -1 => null
      ASSERT_EQ(myList->back(),-1);


       std::cout << myList->back()<<"yohana2";
      myList->pop_back();

       std::cout << myList->back()<<"yohana2";
       // 3 => => -1 => -1 => null
       ASSERT_EQ(myList->back(),-1);





delete myList;

}


