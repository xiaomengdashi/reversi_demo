include_directories(../include)

add_executable(reversi
        main.cpp
        reversi.cpp
        )
target_link_libraries(reversi pthread)


