# main-sorting-algorithms

Implementation in C++ of main sorting algorithms.

## Get started

### Launch test suite

Compile test suite:

```bash
make -B
```

Launch test suite:

```bash
./test
```

### Use the library

```c++
include "headers/sorting.hh"

int main()
{
    std::vector<int> ref = {10, 4, 1, 123, 23, 97, 34, 52, 98, 23, 53};

    Sorting<int> sort;

    sort.buble_sort(ref);
    sort.bubble_sort_optimize(ref);
    sort.insertion_sort(ref);
    sort.selection_sort(ref);
    sort.quick_sort(ref);
    sort.merge_sort(ref);
    sort.heap_sort(ref);
    sort.radix_sort(ref);

    return 0;
}
```

## Sorting algorithms

| Algorithms | Average Case | Best Case | Memory | Comparison sort
|---|---|---|---|---|
| Bubble sort | $O(n^2)$| $O(n)$ | $1$ | $Yes$ |
| Bubble sort optimize | $O(n^2)$| $O(n)$ | $1$ | $Yes$ |
| Insertion sort | $O(n^2)$| $O(n)$ | $1$ | $Yes$ |
| Selection sort | $O(n^2)$| $O(n^2)$ | $1$ | $Yes$ |
| Quicksort | $O(n log(n))$ | $O(n log(n))$ | $O(log(n))$ | $Yes$|
| Merge sort | $O(n log(n))$ | $O(n log(n))$ | $n$ | $Yes$ |
| Heap sort | $O(n log(n))$ | $O(n log(n))$ | $1$ | $Yes$ |
| LSD Radix sort (not in place) | $O(n w)$ | $O(nw)$ | $O(n + w)$ | $No$ |
