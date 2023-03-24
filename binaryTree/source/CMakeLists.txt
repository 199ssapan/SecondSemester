project (source)

add_executable(source main.c)
include_directories(../binTreeLib)
target_link_libraries(source binTreeLib)