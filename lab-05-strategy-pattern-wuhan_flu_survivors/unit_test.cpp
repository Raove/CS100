#include "base.hpp"
#include "container.hpp"
#include "sort.hpp"
#include "gtest/gtest.h"
#include "listcontainer.h"
//#include "listcontainer.cpp"
#include "VectorContainer.h"
//#include "VectorContainer.cpp"
#include "BubbleSort.h"
//#include "BubbleSort.cpp"
#include "SelectionSort.h"
//#include "SelectionSort.cpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(VectorContainerTestSet, SwapTest) {
// Setup the elements under test
    Op* seven = new Op(7);
    VectorContainer* test_container = new VectorContainer();

// Exercise some functionality of hte test elements
    test_container->add_element(seven);

// Assert that the container has at least a single element
// otherwise we are likely to cause a segfault when accessing
    ASSERT_EQ(test_container->size(), 1);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
}

TEST(VectorContainerTestSet2, SwapTest) {
// Setup the elements under test
    Op* seven = new Op(9);
    Op* five = new Op(5);
    VectorContainer* test_container1 = new VectorContainer();

// Exercise some functionality of hte test elements
    test_container1->add_element(seven);
    test_container1->add_element(five);

// Assert that the container has at least a single element
// otherwise we are likely to cause a segfault when accessing
    ASSERT_EQ(test_container1->size(), 2);
    EXPECT_EQ(test_container1->at(0)->evaluate(), 9);
    EXPECT_EQ(test_container1->at(1)->evaluate(), 5);
}

TEST(VectorBubbleSort, Add) {
    Base* T1 = new Op(10);
    Base* T2 = new Op(-1);
    ListContainer test_container2(new BubbleSort());

    Base* Addtest = new Add(T1, T2);
    test_container2.add_element(T1);
    test_container2.add_element(T2);
    test_container2.add_element(Addtest);
    test_container2.sort();
    EXPECT_EQ(-1, test_container2.at(0)->evaluate());
    EXPECT_EQ(9, test_container2.at(1)->evaluate());
    EXPECT_EQ(10, test_container2.at(2)->evaluate());
}

TEST(SortTestSet, SelectionSortTest) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    //ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new SelectionSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}

TEST(ListContainerTestSet, SwapTest) {
// Setup the elements under test
    Op* seven = new Op(7);
    ListContainer* test_container3 = new ListContainer();

// Exercise some functionality of hte test elements
    test_container3->add_element(seven);

// Assert that the container has at least a single element
// otherwise we are likely to cause a segfault when accessing
    ASSERT_EQ(test_container3->size(), 1);
    EXPECT_EQ(test_container3->at(0)->evaluate(), 7);
}

TEST(ListContainerTestSet2, SwapTest) {
// Setup the elements under test
    Op* seven = new Op(7);
    Op* nine = new Op(9);
    ListContainer* test_container4 = new ListContainer();

// Exercise some functionality of hte test elements
    test_container4->add_element(seven);
    test_container4->add_element(nine);

// Assert that the container has at least a single element
// otherwise we are likely to cause a segfault when accessing
    ASSERT_EQ(test_container4->size(), 2);
    EXPECT_EQ(test_container4->at(0)->evaluate(), 7);
    EXPECT_EQ(test_container4->at(1)->evaluate(), 9);
}


