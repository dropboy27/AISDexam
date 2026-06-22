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
add_executable(expression_tree_prog Trees/ExpressionTree.c)

# АВЛ-дерево
add_executable(avl_tree_prog Trees/AVLTree.c)

# Красно-черное дерево
add_executable(redblack_tree_prog Trees/RedBlackTree.c)

# Песочница / обучение
add_executable(learning learning.c)

# === РАЗДЕЛ ГРАФОВ (Каждый файл — отдельный запускаемый таргет) ===

# Матрица смежности
add_executable(graph_matrix Graphs/MatrixSm.c)

# Списки смежности
add_executable(graph_ssmez Graphs/SSmez.c)

# Алгоритм Прима
add_executable(graph_prim Graphs/Prim.c)

# Твой алгоритм Краскала!
add_executable(graph_kruskal Graphs/Kraskal.c)
add_executable(graph_dijkstra Graphs/Dijkstra.c)
add_executable(graph_floyd Graphs/Floyd.c)
