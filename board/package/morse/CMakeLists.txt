cmake_minimum_required(VERSION 3.10)

project(morse)

add_executable(morse main.c)
install(TARGETS morse DESTINATION bin)
target_link_libraries(morse PUBLIC
    gpiod
)