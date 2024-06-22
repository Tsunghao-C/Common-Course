# 42 Common Core Porject - Push_swap

## Objective

1. Create a program that can list all necessary operations to sort an array of numbers stored in a stack (Stack_A) with an empty stack (Stack_B).
2. Need to come up with an algorithm to find out the least steps to complete the sorting.

## Key concept

1. What is stack? How is it different to the counterpart "Queue"?
2. What are the algorithms used to solve a sorting problem.
3. Basic understanding of data structure: array, linked-list, binary tree (optional).
4. Linked list (or Btree) management

## Note

### Data structure
1. In this project, I used linked list as my primary data structure. It iseasy and straight forward to manipulate the operands on linked list.
2. Although I wanted to try with btree at the beginning, it was too complicated for me to translate the push, swap, and rotation operands in btree structure. The benefit of using btree is that when you initiate a data structure with BST (Binary Search Tree), it is already partial sorted (the left childis always smaller than current node while the right child is always bigger than current node).
3. I only used a simple linked list structure. Each node contains content, next node, and previous node. During the evaluation, I learned from peer that you actually create another struct call t_stack that contains the "profile" of each linked list. It could make the codes more concisely and structured, especially when calculating the least cost steps.

```
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
    struct s_list   *prev;
}   t_list;

typedef struct s_stack
{
    t_list          **bgn_list;
    t_list          *last;
    int             list_size;
}   t_stack;
```
### Algorithm

1. Selecting the algorithm is also part of major topic in this project. However, since the project is push_swap sort, the methods you can choose is limited. I followed the following article and used thesame mehtod (machine turk) to do the sorting.
2. The idea is:
    1. If the stack length is <= 5, create a tiny sort function to solve it.
    2. otherwise, first push the top 2 numbers to stack_b
    3. then, continue to push elements from a to b in a decending order "in a most efficient way" until there is only 3 elements left in the stack_a.
    4. use tiny sort to deal with 3 elements, that could be done without pushing to other stack.
    5. Push every thing back from b to a, also in a most efficient way for each push.
    6. Lastly, rotate a until the smallest number is at the beginning. 
3. This method could sort 100 random numbers within 700 steps in all cases, and for 500 numbers with 5500 steps in "Most" cases. Only in certain worst cases the steps will exceed 5500 steps.

### Different Sorting Methods (from chatgpt)

| Sorting Method                      | Mechanism                                                                                                                                                | Pros                                                                                                 | Cons                                                                                                                | Estimated Steps for 500 Elements                                                      |   |
|-------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------|---|
| Merge Sort                          | Divide the stack into two halves, recursively sort each half, and merge the sorted halves.                                                               | Efficient with O(n log n) time complexity. Can handle large datasets well.                           | Requires additional space for auxiliary stacks. Implementation can be complex.                                      | Best Case: O(n log n) ≈ 4500 steps, Worst Case: O(n log n) ≈ 4500 steps               |   |
| Insertion Sort                      | Use an auxiliary stack to keep the elements in sorted order by inserting elements from the original stack into the auxiliary stack in the correct order. | Simple to implement. Only requires O(1) additional space.                                            | Inefficient with O(n^2) time complexity for large datasets.                                                         | Best Case: O(n) ≈ 500 steps, Worst Case: O(n^2) ≈ 125,000 steps                       |   |
| Selection Sort                      | Repeatedly find the minimum element from the unsorted part of the stack and move it to a sorted auxiliary stack.                                         | Simple to understand and implement.                                                                  | Inefficient with O(n^2) time complexity. Requires additional space for the auxiliary stack.                         | Best Case: O(n^2) ≈ 125,000 steps, Worst Case: O(n^2) ≈ 125,000 steps                 |   |
| Bubble Sort                         | Repeatedly swap adjacent elements if they are in the wrong order, using a temporary stack to hold elements during swaps.                                 | Simple to implement.                                                                                 | Very inefficient with O(n^2) time complexity. Requires additional space for temporary stack.                        | Best Case: O(n) ≈ 500 steps, Worst Case: O(n^2) ≈ 125,000 steps                       |   |
| Quick Sort                          | Choose a pivot, partition the stack into elements less than and greater than the pivot, and recursively sort the partitions.                             | Efficient with average-case O(n log n) time complexity. Can be implemented in place.                 | Worst-case time complexity is O(n^2). Requires careful implementation to handle stack-based partitioning.           | Best Case: O(n log n) ≈ 4500 steps, Worst Case: O(n^2) ≈ 125,000 steps                |   |
| Heap Sort                           | Use a heap data structure to sort the stack, where the stack is transformed into a heap, and elements are extracted in sorted order.                     | Efficient with O(n log n) time complexity.                                                           | Requires additional space for the heap. Implementation is more complex compared to simpler sorting algorithms.      | Best Case: O(n log n) ≈ 4500 steps, Worst Case: O(n log n) ≈ 4500 steps               |   |
| Radix Sort                          | Sort the stack by processing individual digits or bits, using auxiliary stacks or queues to group elements.                                              | Efficient with O(nk) time complexity for certain data types (e.g., integers).                        | Limited to sorting specific data types (e.g., integers). Requires additional space for auxiliary structures.        | Best Case: O(nk) ≈ 1000 steps (for k = 2), Worst Case: O(nk) ≈ 1500 steps (for k = 3) |   |
| Recursive Sort with Temporary Stack | Use a temporary stack to hold elements while recursively sorting the original stack, inserting elements back in sorted order.                            | Simple to implement. Works well for small stacks.                                                    | Inefficient with O(n^2) time complexity for large datasets. Requires additional space for the temporary stack.      | Best Case: O(n^2) ≈ 125,000 steps, Worst Case: O(n^2) ≈ 125,000 steps                 |   |
| Shell Sort                          | Sort elements at a specific interval (gap), reducing the gap size over time, and performing insertion sort for each gap size.                            | More efficient than insertion sort and bubble sort with O(n log n) complexity in some gap sequences. | Performance depends heavily on the gap sequence. Not as efficient as merge, quick, or heap sort for large datasets. | Best Case: O(n log n) ≈ 2500 steps, Worst Case: O(n^1.5) ≈ 12,500 steps               |   |

