#include<gtest/gtest.h>
#include"../../include/doublylist.h"


TEST(test1, test_push_front)
{

  DoublyList<int>* myList = new DoublyList<int>;

  myList->push_front(4);


  myList->push_front(3);



  ASSERT_EQ(myList->front(),3);
  ASSERT_EQ(myList->back(),4);

  myList->push_front(2);


  ASSERT_EQ(myList->front(),2);
  ASSERT_EQ(myList->back(),4);

  myList->push_front(1);


  ASSERT_EQ(myList->front(),1);
  ASSERT_EQ(myList->back(),4);

  delete myList;

}


TEST(test2, test_empty)
{

  DoublyList<int>* myList = new DoublyList<int>;


  ASSERT_TRUE(myList->empty());

  myList->push_front(4);

  ASSERT_FALSE(myList->empty());


  delete myList;
}

TEST(test3, test_push_back)
{

  DoublyList<int>* myList = new DoublyList<int>;

  myList->push_back(4);


  myList->push_back(3);



  ASSERT_EQ(myList->front(),4);
  ASSERT_EQ(myList->back(),3);

  myList->push_back(2);


  ASSERT_EQ(myList->front(),4);
  ASSERT_EQ(myList->back(),2);

  myList->push_back(1);


  ASSERT_EQ(myList->front(),4);
  ASSERT_EQ(myList->back(),1);


  delete myList;
}


TEST(test4, test_back)
{

  DoublyList<int>* myList = new DoublyList<int>;

  myList->push_back(4);


  myList->push_back(3);

  ASSERT_EQ(myList->back(),3);

  myList->push_back(2);

  ASSERT_EQ(myList->back(),2);

  myList->push_back(1);

  ASSERT_EQ(myList->back(),1);


  delete myList;
}


TEST(test5, test_front)
{

  DoublyList<int>* myList = new DoublyList<int>;

  myList->push_back(4);


  myList->push_back(3);

  ASSERT_EQ(myList->front(),4);

  myList->push_front(2);

  ASSERT_EQ(myList->front(),2);

  myList->push_front(1);

  ASSERT_EQ(myList->front(),1);


  delete myList;
}


TEST(test5, test_pop_front)
{

  DoublyList<int>* myList = new DoublyList<int>;

  myList->push_back(4);


  myList->push_back(3);


  myList->pop_front();
  ASSERT_EQ(myList->front(),3);


  myList->push_back(4);


  myList->push_back(3);


  myList->pop_front();


  ASSERT_EQ(myList->front(),4);

  myList->pop_front();
  myList->pop_front();

  ASSERT_TRUE(myList->empty());


  delete myList;
}





