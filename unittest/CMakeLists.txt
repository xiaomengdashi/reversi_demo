include_directories(../include)
add_executable(unittest
        unittest.cpp
        ../src/reversi.cpp
        )

target_link_libraries(unittest gtest gtest_main pthread)

