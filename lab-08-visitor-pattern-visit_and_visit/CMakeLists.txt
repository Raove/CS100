CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

SET(DEBUG_FLAG "-g")

add_definitions(${DEBUG_FLAG})

SET(CPPS
        binary_iterator.cpp
        preorder_iterator.cpp
        unary_iterator.cpp
        )

ADD_EXECUTABLE(test
        ${CPPS}
    unit_test.cpp
)

ADD_EXECUTABLE(main
        ${CPPS}
        main.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
