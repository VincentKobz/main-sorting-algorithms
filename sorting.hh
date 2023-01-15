#pragma once

#include <vector>
#include <iostream>

// Sorting class
template <typename T>
class Sorting
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
        void counting_sort(std::vector<T> &vec, int index);
        void radix_sort(std::vector<T> &vec);
};

// IsInt Struct general template
template <typename T>
struct IsInt
{
    static constexpr bool value = false;
};

// IsInt Struct specialized template
template <>
struct IsInt<int>
{
    static constexpr bool value = true;
};

// max_element template function
template <typename T>
auto my_max_element(T begin, T end)
{
    if (begin == end)
    {
        return *begin;
    }

    auto max = *begin;

    for (; begin <= end; begin++)
    {
        if (*begin > max)
        {
            max = *begin;
        }
    }

    return max;
}

#include "sorting.hxx"
