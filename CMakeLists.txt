cmake_minimum_required(VERSION 3.28)
project(exzzz C)

set(CMAKE_C_STANDARD 23)

# Первая программа (Обычное бинарное дерево и сортировки)
add_executable(exzzz
        Trees/BinaryTree.c
        Sortings/Shell.c
        Sortings/QuickSort.c
        Sortings/HeapSort.c
        Sortings/Assertion.c
        Sortings/Linear.c
)

# Вторая программа (Дерево выражений)
add_executable(expression_tree_prog
        Trees/ExpressionTree.c
)
