#include <gtest/gtest.h>
#include <algorithm>
#include <random>
#include "sorting.hh"

class SortingInteger : public ::testing::Test
{
    protected:
        void SetUp() override
        {
            std::uniform_int_distribution<int> distribution (0, 99);
            std::mt19937 engine;
            auto gen = std::bind(distribution, engine);
            std::generate(base.begin(), base.end(), gen);
            base_test = base;
            std::sort(base.begin(), base.end());
        }

        std::vector<int> base = std::vector<int>(200);
        std::vector<int> base_test;
        sorting<int> sort;
};

TEST_F(SortingInteger, BubleSort)
{
    sort.bubble_sort(base_test);
    EXPECT_EQ(base, base_test);
}

TEST_F(SortingInteger, BubleSortOpti)
{
    sort.bubble_sort_optimize(base_test);
    EXPECT_EQ(base, base_test);
}

TEST_F(SortingInteger, InsertionSort)
{
    sort.insertion_sort(base_test);
    EXPECT_EQ(base, base_test);
}

TEST_F(SortingInteger, MergeSort)
{
    sort.merge_sort(base_test);
    EXPECT_EQ(base, base_test);
}

TEST_F(SortingInteger, HeapSort)
{
    sort.heap_sort(base_test);
    EXPECT_EQ(base, base_test);
}

TEST_F(SortingInteger, QuickSort)
{
    sort.quick_sort(base_test);
    EXPECT_EQ(base, base_test);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
