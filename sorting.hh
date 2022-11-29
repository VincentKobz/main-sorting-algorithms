#pragma once

#include <vector>
#include <iostream>

template <typename T>
class sorting
{
    public:
        void bubble_sort(std::vector<T> &vec);
        void bubble_sort_optimize(std::vector<T> &vec);
        void insertion_sort(std::vector<T> &vec);
        void selection_sort(std::vector<T> &vec);
        void merge(std::vector<T> &vec, int left, int mid, int right);
        void merge_recur(std::vector<T> &vec, int left, int right);
        void merge_sort(std::vector<T> &vec);
        void heap_sort(std::vector<T> &vec);
        void sift_up(std::vector<T> &heap, size_t pad, size_t end);
        void heapify(std::vector<T> &vec, size_t nb);
        void quick_sort_recur(std::vector<T> &vec, int left, int right);
        auto partition(std::vector<T> &vec, int left, int right);
        void quick_sort(std::vector<T> &vec);
};

#include "sorting.hxx"

