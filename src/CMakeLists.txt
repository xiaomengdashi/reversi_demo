include_directories(../include)

add_executable(main
        main.cpp
        reversi.cpp
        Point.cpp Point.h)
target_link_libraries(main pthread)


