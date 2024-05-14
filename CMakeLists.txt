cmake_minimum_required(VERSION 3.28)
project(push_swap2 C)

set(CMAKE_C_STANDARD 11)

# Source files
set(SRC_FILES
        src/stack/ps_stack_append.c
        src/stack/ps_stack_last.c
        src/stack/ps_stack_free.c
        src/stack/ps_stack_length.c
        src/stack/ps_stack_is_sorted.c
        src/moves/swap.c
        src/moves/push.c
        src/moves/rotate.c
        src/moves/reverse_rotate.c
        src/parser/ps_parser.c
        src/parser/ps_parser_utils.c
        src/sorting/utils/ps_stack_biggest.c
        src/sorting/utils/ps_stack_smallest.c
        src/sorting/utils/ps_stack_indexer.c
        src/sorting/utils/ps_stack_leviosa.c
        src/sorting/ps_stack_sort_three.c
        src/sorting/ps_stack_sort_five.c
        src/sorting/ps_sort_chunks.c
        src/sorting/utils/ps_stack_to_array.c
        src/sorting/utils/ps_shift_back.c
)

# Executable
add_executable(push_swap2 ${SRC_FILES} src/main.c)

# Include directories
target_include_directories(push_swap2 PRIVATE include/)

# Compiler flags
target_compile_options(push_swap2 PRIVATE -Wall -Wextra -Werror)

# Link libraries
target_link_libraries(push_swap2 PRIVATE ${CMAKE_SOURCE_DIR}/lib/libft/libft.a)
target_link_libraries(push_swap2 PRIVATE ${CMAKE_SOURCE_DIR}/lib/ft_printf/libftprintf.a)