include_directories(../include)

add_executable(main
        main.cpp
        reversi.cpp
        )
target_link_libraries(main pthread)


