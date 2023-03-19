project(source)

add_executable(source main.c)
include_directories(../GOFLib)
target_link_libraries(source GOFLib ncurses)