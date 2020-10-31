# Algorithm Library
Based on https://cp-algorithms.com/

# Articles

## Algebra
  - **Fundamentals**
    - Binary Exponentiation
    - Euclidean algorithm for computing the greatest common divisor
    - Extended Euclidean Algorithm
    - Linear Diophantine Equations
    - Fibonacci Numbers
  - **Prime numbers**
    - Sieve of Eratosthenes
    - Sieve of Eratosthenes with Linear Complexity
    - Primality tests
    - Integer factorization
  - **Number-theoretic functions**
    - Euler's totient function
    - Number of divisors / sum of divisors
  - **Modular arithmetic**
    - Modular Inverse
    - Linear Congruence Equation
    - Chinese Remainder Theorem
    - Factorial modulo p
    - Discrete Log
    - Primitive Root
    - Discrete Root
    - Montgomery Multiplication
  - **Number systems**
    - Balanced Ternary
    - Gray code
  - **Miscellaneous**
    - Enumerating submasks of a bitmask
    - Arbitrary-Precision Arithmetic
    - Fast Fourier Transform
    - Operations on polynomials and series

## Data Structures
  - **Fundamentals**
    - Minimum Stack / Minimum Queue
    - Sparse Table
  - **Trees**
    - Disjoint Set Union
    - Fenwick Tree
    - Sqrt Decomposition
    - Segment Tree
    - Treap
    - Sqrt Tree
    - Randomized Heap
  - **Advanced**
    - Deleting from a data structure in O(T(n) log n)

## Dynamic Programming
  - **DP optimizations**
    - Divide and Conquer DP
  - **Tasks**
    - Dynamic Programming on Broken Profiles. Problem "Parquet"
    - Finding the largest zero submatrix

## String Processing
  - **Fundamentals**
    - String Hashing
    - Rabin-Karp for String Matching
    - Prefix function - Knuth-Morris-Pratt
    - Z-function
    - Suffix Array
    - Aho-Corasick algorithm
  - **Advanced**
    - Suffix Tree
    - Suffix Automaton
    - Lyndon factorization
  - **Tasks**
    - Expression parsing
    - Manacher's Algorithm - Finding all sub-palindromes in O(N)
    - Finding repetitions

## Linear Algebra
  - **Matrices**
    - Gauss & System of Linear Equations
    - Gauss & Determinant
    - Kraut & Determinant
    - Rank of a matrix

## Combinatorics
  - **Fundamentals**
    - Finding Power of Factorial Divisor
    - Binomials Coefficients
    - Catalan Numbers
  - **Techniques**
    - The Inclusion-Exclusion Principle
    - Burnside's lemma / Pólya enumeration theorem
    - Stars and bars
    - Generating all K-combinations
  - **Tasks**
    - Placing Bishops on a Chessboard
    - Balanced bracket sequences
    - Counting labeled graphs

## Numerical Methods
  - **Search**
    - Ternary Search
    - Newton's method for finding roots
  - **Integration**
    - Integration by Simpson's formula

## Geometry
  - **Elementary operations**
    - Basic Geometry
    - Fidning the equation of a line for a segment
    - Intersection Point of Lines
    - Check if two segments intersect
    - Intersections of Segments
    - Circle-Line Intersection
    - Circle-Circle Intersection
    - Common tangents to two circles
    - Length of the union of segments
  - **Polygons**
    - Oriented area of a triangle
    - Area of simple polygon
    - Check if points belong to the convex polygon in O(log n)
    - Minkowski sum of convex polygons
    - Pick's Theorem - area of lattice polygons
    - Lattice points of non-lattice polygon
  - **Convex hull**
    - Convex hull construction using Graham's Scan
    - Convex hull trick and Li Chao tree
  - **Sweep-line**
    - Search for a pair of intersecting segments
    - Point location in O(log n)
  - **Miscellaneous**
    - Finding the nearest pair of points
    - Delaunay triangulation and Voronoi diagram
    - Vertical decomposition

## Graphs
  - **Graph traversal**
    - Breadth First Search
    - Depth First Search
  - **Connected components, bridges, articulations points**
    - Finding Connected Conponents
    - Finding Bridge in O(n + m)
    - Finding Bridges Online
    - Finding Articulation Points in O(n + m)
    - Strongly Connected Components and Condensation Graph
    - Strong Orientation
  - **Single-source shortest paths**
    - Dijkstra - finding shortest paths from given vertex
    - Dijkstra on sparse graphs
    - Bellman-Ford - finding shortest paths with negative weights
    - 0-1 BFS
    - D'Esopo-Pape algorithm
  - **All-pairs shortest paths**
    - Floyd-Warshall - finding all shortest paths
    - Number of paths of fixed length / Shortest paths of fixed length
  - **Spanning trees**
    - Minimum Spanning Tree - Prim's Algorithm
    - Minimum Spanning Tree - Kruskal
    - Minimum Spanning Tree - Kruskal with Disjoint Set Union
    - Second best Minimum Spanning Tree - Using Kruskal and Lowest Common Ancestor
    - Kirchhoff Theorem
    - Prüfer code
  - **Cycles**
    - Checking a graph for acyclicity and finding a cycle in O(m)
    - Finding a Negative Cycle in the Graph
    - Eulerian Path
  - **Lowest common ancestor**
    - Lowest Common Ancestor
    - Lowest Common Ancestor - Binary Lifting
    - Lowest Common Ancestor - Farach-Colton and Bender algorithm
    - Solve RMQ by finding LCA
    - Lowest Common Ancestor - Tarjan's off-line algorithm
  - **Flows and related problems**
    - Maximum flow - Ford-Fulkerson and Edmonds-Karp
    - Maximum flow - Push-relabel algorithm
    - Maximum flow - Push-relabel algorithm improved
    - Maximum flow - Dinic's algorithm
    - Maximum flow - MPM algorithm
    - Flows with demands
    - Minimum-cost flow
    - Assignment problem. Solution using min-cost-flow in O(n^5)
  - **Matchings and related problems**
    - Bipartite Graph Check
  - **Miscellaneous**
    - Topological Sorting
    - Edge connectivity - Vertex connectivity
    - Tree painting
    - 2-SAT
    - Heavy-light-decomposition

## Miscellaneous
  - **Sequences**
    - RMQ task (Range Minimum Query - the smallest element in an interval)
    - Longest increasing subsequence
    - Search the subsegment with the maximum/minimum sum
    - K-th order statistic in O(n)
  - **Game Theory**
    - Games on arbitrary graphs
    - Sprague-Grundy theorem. Nim.
  - **Schedules**
    - Scheduling jobs on one machine
    - Scheduling jobs on two machines
    - Optimal schedule of jobs given their deadlines and durations
  - **Miscellaneous**
    - Josephus problem
    - 15 Puzzle Game: Existence Of The Solution
    - The Stern-Brocot Tree and Farey Sequences
