# Data Structures

## Linear Data Structures

Sequential data structures where elements are arranged in a linear order.

- Array: Static and dynamic arrays for storing elements in contiguous memory locations.
- Linked List: Node-based structure where elements point to the next element in sequence.
- Stack: Last-In-First-Out (LIFO) data structure supporting push and pop operations.
- Queue: First-In-First-Out (FIFO) data structure supporting enqueue and dequeue operations.

## Tree Data Structures

Hierarchical data structures with nodes connected by edges.

- Binary Tree: Tree structure where each node has at most two children.
- Binary Search Tree: Binary tree with ordered property: left subtree < root < right subtree.
- AVL Tree: Self-balancing binary search tree with height difference constraint.
- Red-Black Tree: Self-balancing binary search tree with color-based balancing rules.
- B-Tree: Multi-way tree optimized for systems with large block sizes.
- Segment Tree: Binary tree for efficient range queries and updates.
- Fenwick Tree: Tree structure for efficient prefix sum calculations.
- Trie: Prefix tree for efficient string operations and searches.

## Heap Data Structures

Tree-based structures maintaining heap property for priority operations.

- Binary Heap: Complete binary tree with heap property (min-heap or max-heap).
- Binomial Heap: Collection of binomial trees supporting efficient merge operations.
- Fibonacci Heap: Advanced heap with amortized constant time decrease-key operation.

## Hash Table Data Structures

Structures using hash functions for fast key-value operations.

- Open Addressing: Hash table resolving collisions by probing alternative positions.
- Separate Chaining: Hash table using linked lists to handle collisions.
- Unordered Map: Hash-based associative container for key-value pairs.
- Unordered Set: Hash-based container for unique elements.

## Graph Data Structures

Structures representing relationships between vertices through edges.

- Adjacency List: Graph representation using lists of neighboring vertices.
- Adjacency Matrix: Graph representation using 2D matrix of edge weights.
- Edge List: Graph representation as a list of all edges.

## Specialized Data Structures

- Disjoint Set: Structure for tracking disjoint sets with union and find operations.
- Suffix Array: Sorted array of all suffixes of a string for pattern matching.
- Bloom Filter: Probabilistic data structure for membership testing.
- Skip List: Probabilistic data structure with multiple levels for fast search.

## Concurrent Data Structures

Thread-safe structures for multi-threaded environments.

- Concurrent Queue: Thread-safe queue supporting concurrent enqueue/dequeue operations.
- Concurrent Hash Map: Thread-safe hash table for concurrent access.
- Persistent Structures: Immutable data structures preserving previous versions.

## Adapters

Interface adapters providing specific functionality over base structures.

- Stack Adapter: Stack interface implemented using underlying containers.
- Queue Adapter: Queue interface implemented using underlying containers.
- Priority Queue Adapter: Priority queue interface with heap-based implementation.