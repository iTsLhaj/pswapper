cmake_minimum_required(VERSION 3.28)
project(push_swap2 C)

set(CMAKE_C_STANDARD 11)
set(LIBS
        ${PROJECT_SOURCE_DIR}/lib/libft.a
        ${PROJECT_SOURCE_DIR}/lib/libftprintf.a
)

include_directories(include)

add_executable(push_swap2 src/main.c
        src/moves/swap.c
        src/moves/push.c
        src/moves/rotate.c
        src/moves/reverse_rotate.c
        include/stack.h
        src/stack/ascii/ps_ascii_utils.c
        src/stack/ascii/ps_ascii_nbox.c
        src/stack/ps_stack_append.c
        src/stack/ps_stack_last.c
        src/parser/ps_parser.c
        src/stack/ps_stack_free.c
        src/parser/ps_parser_utils.c)
target_link_libraries(push_swap2 ${LIBS})