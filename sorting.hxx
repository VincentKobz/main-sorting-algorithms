#pragma once
#include "sorting.hh"
#include <cmath>

template<typename T>
void sorting<T>::bubble_sort(std::vector<T> &vec)
{
    auto len = vec.size();
    bool detect = true;

    while (detect)
    {
        detect = false;
        for (size_t i = 0; i < len - 1; i++)
        {
            if (vec[i] > vec[i + 1])
            {
                std::swap(vec[i + 1], vec[i]);
                detect = true;
            }
        }
    }
}

template<typename T>
void sorting<T>::bubble_sort_optimize(std::vector<T> &vec)
{
    auto len = vec.size();
    bool detect = true;

    while (detect)
    {
        detect = false;
        for (size_t i = 0; i < len - 1; i++)
        {
            if (vec[i] > vec[i + 1])
            {
                std::swap(vec[i + 1], vec[i]);
                detect = true;
            }
        }
        len -= 1;
    }
}

template<typename T>
void sorting<T>::insertion_sort(std::vector<T> &vec)
{
    size_t j = 1;
    while (j < vec.size())
    {
        size_t i = j;

        while (i > 0 && vec[i - 1] > vec[i])
        {
            std::swap(vec[i - 1], vec[i]);
            i -= 1;
        }
        j += 1;
    }
}

template <typename T>
void sorting<T>::selection_sort(std::vector<T> &vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        auto min = i;

        for (size_t j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[min])
                min = j;
        }

        if (min != i)
        {
            std::swap(vec[i], vec[min]);
        }
    }
}

template <typename T>
void sorting<T>::merge(std::vector<T> &vec, int left, int mid, int right)
{
    auto len_1 = mid - left + 1;
    auto len_2 = right - mid;

    T p1[len_1];
    T p2[len_1];

    for (auto i = 0; i < len_1; i++)
        p1[i] = vec[left + i];

    for (auto i = 0; i < len_2; i++)
        p2[i] = vec[mid + i + 1];

    auto index_p1 = 0, index_p2 = 0, index = left;
    while (index_p1 < len_1 && index_p2 < len_2)
    {
        if (p1[index_p1] < p2[index_p2])
        {
            vec[index++] = p1[index_p1++];
        }
        else
        {
            vec[index++] = p2[index_p2++];
        }
    }

    for (auto i = index_p1; i < len_1; i++)
        vec[index++] = p1[i];

    for (auto i = index_p2; i < len_2; i++)
        vec[index++] = p2[i];
}

template <typename T>
void sorting<T>::merge_recur(std::vector<T> &vec, int left, int right)
{
    if (left >= right)
        return;

    auto mid = left + (right - left) / 2;

    merge_recur(vec, left, mid);
    merge_recur(vec, mid + 1, right);
    merge(vec, left, mid, right);
}

template <typename T>
void sorting<T>::merge_sort(std::vector<T> &vec)
{
    merge_recur(vec, 0, vec.size() - 1);
}

template <typename T>
void sorting<T>::heapify(std::vector<T> &vec, size_t nb)
{
    auto counter = 1;

    while (nb > counter)
    {
        sift_up(vec, 0, counter);
        counter++;
    }
}

template <typename T>
void sorting<T>::sift_up(std::vector<T> &heap, size_t pad, size_t end)
{
    auto child = end;

    while (child > pad)
    {
        size_t parent = std::floor((child - 1) / 2);

        if (heap[parent] < heap[child])
        {
            std::swap(heap[parent], heap[child]);
        }
        else
        {
            return;
        }

        child = parent;
    }
}

// O(n log(n))
template <typename T>
void sorting<T>::heap_sort(std::vector<T> &vec)
{
    auto len = vec.size() - 1;

    heapify(vec, len);

    while (len > 0)
    {
        std::swap(vec[len], vec[0]);
        heapify(vec, len);
        len--;
    }
}

template <typename T>
void sorting<T>::quick_sort_recur(std::vector<T> &vec, int left, int right)
{
    if (left >= right)
        return;

    auto pivot = partition(vec, left, right);

    quick_sort_recur(vec, left, pivot);
    quick_sort_recur(vec, pivot + 1, right);
}

template <typename T>
auto sorting<T>::partition(std::vector<T> &vec, int left, int right)
{
    T pivot = vec[std::floor((right + left) / 2)];
    auto p_left = left - 1;
    auto p_right =  right + 1;

    for (;;)
    {
        while (vec[++p_left] < pivot)
            ;

        while (vec[--p_right] > pivot)
            ;

        if (p_left >= p_right)
            return p_right;

        std::swap(vec[p_left], vec[p_right]);
    }
}

template <typename T>
void sorting<T>::quick_sort(std::vector<T> &vec)
{
    quick_sort_recur(vec, 0, vec.size() - 1);
}
