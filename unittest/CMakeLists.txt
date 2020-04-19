include_directories(../include)
add_executable(unittest
        ../src/reversi.cpp
        unittest_can_play.cpp
        unittest_reverse.cpp)

target_link_libraries(unittest gtest gtest_main pthread)

