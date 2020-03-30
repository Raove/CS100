CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

#SET(SOURCE listcontainer.cpp VectorContainer.cpp SelectionSort.cpp BubbleSort.cpp)

ADD_EXECUTABLE(test
        VectorContainer.cpp
        SelectionSort.cpp
        BubbleSort.cpp
        listcontainer.cpp
        unit_test.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
