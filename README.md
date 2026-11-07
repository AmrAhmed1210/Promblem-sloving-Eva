# Problem Solving Course Solutions

Clean C++17 solutions for the 13-week Problem Solving course.
The code is organized week by week, following the course plan, so every topic taught in class has its own folder.

Each source file is self-contained: it holds one problem, its solution, and a `main` that prints sample results.
The sources contain no comments; this document explains what each file does.

## Quick start

Run everything:

```
./scripts/run_all.sh
```

Run one week only:

```
./scripts/run_all.sh week_03
```

Compile a single file by hand:

```
g++ -std=c++17 src/week_02_graph_traversal_and_dijkstra/dijkstra.cpp -o dijkstra
./dijkstra
```

Build with CMake (also works in Visual Studio through File > Open > Folder):

```
cmake -S . -B build
cmake --build build
./build/week_02_dijkstra
```

Each executable is named `week_NN_<file name>`.

## Course map

| Week | Outcome | Topic | Folder |
|---|---|---|---|
| Week 1 | LO1 | Recursion Review and Graph Fundamentals | `src/week_01_recursion_and_graph_fundamentals` |
| Week 2 | LO1 | Graph Traversal and Dijkstra | `src/week_02_graph_traversal_and_dijkstra` |
| Week 3 | LO2 | Backtracking and Complete Search | `src/week_03_backtracking_and_complete_search` |
| Week 4 | LO2 | Divide and Conquer, Binary Search and Merge Sort | `src/week_04_divide_and_conquer` |
| Week 5 | LO3 | Dynamic Programming Fundamentals | `src/week_05_dynamic_programming_basics` |
| Week 6 | LO3 | Rod Cutting and 0/1 Knapsack | `src/week_06_rod_cutting_and_knapsack` |
| Week 7 | LO3 | Greedy Algorithms | `src/week_07_greedy_algorithms` |
| Week 8 | LO4 | Binary Exponentiation and Euclidean Algorithms | `src/week_08_math_algorithms` |
| Week 9 | LO4 | Vectors, Complex Numbers and Lines | `src/week_09_vectors_complex_numbers_and_lines` |
| Week 10 | LO4 | Circles | `src/week_10_circles` |
| Week 11 | LO5 | LCP, Rabin-Karp and KMP | `src/week_11_string_algorithms` |
| Week 12 | REV | Comprehensive revision | Reuse the folders above: Day 1 weeks 1-2, Day 2 weeks 5-6, Day 3 weeks 9-10, Day 4 week 11, Day 5 weeks 7-8 |
| Week 13 | Final | Final assessment | No code |

## Project layout

```
ProblemSolving/
  CMakeLists.txt
  README.md
  scripts/
    run_all.sh
  src/
    week_01_recursion_and_graph_fundamentals/
    week_02_graph_traversal_and_dijkstra/
    week_03_backtracking_and_complete_search/
    week_04_divide_and_conquer/
    week_05_dynamic_programming_basics/
    week_06_rod_cutting_and_knapsack/
    week_07_greedy_algorithms/
    week_08_math_algorithms/
    week_09_vectors_complex_numbers_and_lines/
    week_10_circles/
    week_11_string_algorithms/
```

## Weekly contents

### Week 1 (LO1): Recursion Review and Graph Fundamentals

Covers: Vector review, recursive thinking and base cases, graph terminology, adjacency matrix, adjacency list, edge list.

| File | Problem | Time |
|---|---|---|
| `vector_basics.cpp` | Maximum, prefix sums and reversal of a vector | O(n) |
| `sum_of_digits.cpp` | Sum the digits of a number recursively | O(log n) |
| `reverse_string.cpp` | Reverse a string recursively | O(n) |
| `palindrome_check.cpp` | Check whether a string is a palindrome recursively | O(n) |
| `adjacency_list.cpp` | Build an adjacency list, directed or undirected | O(V + E) |
| `adjacency_matrix.cpp` | Build an adjacency matrix, directed or undirected | O(V^2 + E) |
| `edge_list.cpp` | Build a weighted edge list | O(E) |
| `find_center_of_star_graph.cpp` | LeetCode 1791: find the center of a star graph | O(1) |
| `find_town_judge.cpp` | LeetCode 997: find the town judge using in-degree and out-degree | O(n + E) |

### Week 2 (LO1): Graph Traversal and Dijkstra

Covers: DFS, BFS, visited nodes, queue-based traversal, distance relaxation, priority-based node selection.

| File | Problem | Time |
|---|---|---|
| `dfs.cpp` | Recursive depth first traversal | O(V + E) |
| `bfs.cpp` | Queue-based breadth first traversal | O(V + E) |
| `path_exists_in_graph.cpp` | LeetCode 1971: is there a path between two nodes | O(V + E) |
| `min_score_of_path.cpp` | LeetCode 2492: minimum edge weight in the component of city 1 | O(V + E) |
| `cycle_detection.cpp` | Detect a cycle in an undirected graph | O(V + E) |
| `tree_diameter.cpp` | Diameter of a tree given as a parent array | O(n) |
| `dijkstra.cpp` | Single-source shortest paths with a min-heap | O((V + E) log V) |

### Week 3 (LO2): Backtracking and Complete Search

Covers: Search space, decision tree, choose-explore-undo, base cases, pruning invalid choices.

| File | Problem | Time |
|---|---|---|
| `subsets.cpp` | Generate all subsets (include or exclude each element) | O(n * 2^n) |
| `permutations.cpp` | Generate all permutations using a used-array | O(n * n!) |
| `combination_sum.cpp` | LeetCode 39: combinations that reach a target, with pruning | Exponential, pruned |
| `n_queens.cpp` | Count and print N-Queens solutions with column and diagonal pruning | Exponential, pruned |

### Week 4 (LO2): Divide and Conquer, Binary Search and Merge Sort

Covers: Divide-solve-combine, sorted data requirement, interval reduction, merging sorted halves.

| File | Problem | Time |
|---|---|---|
| `maximum_divide_and_conquer.cpp` | Find the maximum by splitting the array in halves | O(n) |
| `binary_search.cpp` | Binary search, recursive and iterative | O(log n) |
| `search_insert_position.cpp` | LeetCode 35: index of a target or where it would be inserted | O(log n) |
| `merge_sort.cpp` | Merge sort | O(n log n) |
| `majority_element.cpp` | LeetCode 169: majority element with Boyer-Moore voting | O(n) |

### Week 5 (LO3): Dynamic Programming Fundamentals

Covers: Repeated subproblems, state, base cases, transitions, memoization versus tabulation.

| File | Problem | Time |
|---|---|---|
| `factorial.cpp` | Factorial with memoization and with tabulation | O(n) |
| `fibonacci.cpp` | Fibonacci with memoization and with tabulation | O(n) |

### Week 6 (LO3): Rod Cutting and 0/1 Knapsack

Covers: Defining subproblems, building the recurrence, include-or-exclude decisions, DP tables.

| File | Problem | Time |
|---|---|---|
| `rod_cutting.cpp` | Maximum revenue from cutting a rod, bottom-up | O(n^2) |
| `knapsack_01.cpp` | 0/1 knapsack with memoization | O(n * W) |
| `longest_common_subsequence.cpp` | Longest common subsequence of two strings | O(n * m) |

### Week 7 (LO3): Greedy Algorithms

Covers: Local optimal choice, greedy versus dynamic programming, sorting before selecting.

| File | Problem | Time |
|---|---|---|
| `fractional_knapsack.cpp` | Fractional knapsack sorted by value-to-weight ratio | O(n log n) |
| `activity_selection.cpp` | Select the maximum number of non-overlapping tasks by finish time | O(n log n) |
| `coin_change.cpp` | Greedy coin change for canonical coin systems | O(n log n + amount) |

### Week 8 (LO4): Binary Exponentiation and Euclidean Algorithms

Covers: Repeated squaring, GCD by repeated remainders, LCM, Bezout coefficients, modular inverse.

| File | Problem | Time |
|---|---|---|
| `binary_exponentiation.cpp` | Fast power with negative exponent support | O(log n) |
| `gcd.cpp` | Euclidean GCD, recursive and iterative | O(log min(a, b)) |
| `lcm.cpp` | LCM from GCD without overflow | O(log min(a, b)) |
| `extended_euclidean.cpp` | Extended Euclid coefficients and modular inverse | O(log min(a, b)) |
| `sieve_of_eratosthenes.cpp` | All primes up to n | O(n log log n) |
| `reverse_bits.cpp` | LeetCode 190: reverse the bits of a 32-bit integer | O(1) |

### Week 9 (LO4): Vectors, Complex Numbers and Lines

Covers: Dot product, cross product, complex arithmetic, line equation, intersection, point checks.

| File | Problem | Time |
|---|---|---|
| `dot_cross_product.cpp` | Dot product, 2D cross product and 3D cross product | O(1) |
| `complex_numbers.cpp` | Add, subtract, multiply and divide complex numbers | O(1) |
| `line_equation.cpp` | Equation of the line through two points, including vertical and horizontal lines | O(1) |
| `lines_intersection.cpp` | Intersection of two lines: crossing, parallel or identical | O(1) |
| `point_on_line_slope_form.cpp` | Is a point above, below or on y = mx + c | O(1) |
| `point_on_line_cross_product.cpp` | Position of a point relative to a line through two points using the cross product | O(1) |

### Week 10 (LO4): Circles

Covers: Circle equation, point position, line-circle cases, circle-circle cases.

| File | Problem | Time |
|---|---|---|
| `circle_equation.cpp` | Equation of a circle from center and radius | O(1) |
| `point_position_relative_to_circle.cpp` | Is a point inside, on or outside a circle | O(1) |
| `line_circle_intersection.cpp` | No intersection, tangent or two intersection points | O(1) |
| `circle_circle_intersection.cpp` | Separate, nested, tangent, intersecting or coincident circles | O(1) |

### Week 11 (LO5): LCP, Rabin-Karp and KMP

Covers: Prefix comparison, rolling hash, collision check, LPS preprocessing, matching without rechecking.

| File | Problem | Time |
|---|---|---|
| `longest_common_prefix.cpp` | LeetCode 14: brute force and sorting approaches | O(n * m) |
| `find_first_occurrence.cpp` | LeetCode 28: naive substring search | O(n * m) |
| `rabin_karp.cpp` | Rolling-hash substring search (algorithm in rabin_karp.hpp) | O(n + m) average |
| `repeated_string_match.cpp` | LeetCode 686: repeat a string until another becomes a substring | O(n + m) average |
| `kmp.cpp` | KMP search returning every match index | O(n + m) |

## Conventions

- C++17, standard library only.
- One problem per file, with a `main` that shows sample input and output.
- Functions take inputs by `const` reference when they do not modify them.
- Floating-point comparisons use an epsilon instead of `==`.
- Names describe intent: `findJudge`, `minScore`, `rabinKarp`.

## Suggested way to study

1. Read the week's table and open the first file.
2. Run it, then change the sample input in `main` and predict the output before running again.
3. Rewrite the solution from scratch without looking, then compare.
4. For recursive and DP files, trace the calls on paper for a small input.
