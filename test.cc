#include <gtest/gtest.h>
#include <algorithm>
#include <random>
#include "sorting.hh"

// Fixture Class used for testing std::vector of int
class SortingInteger : public ::testing::Test
{
    protected:
        void SetUp() override
        {
            // create uniform distribution function
            std::uniform_int_distribution<int> distribution (0, 255);
            std::mt19937 engine;
            auto gen = std::bind(distribution, engine);

            // generate random vector with number between 0 and 255
            std::generate(base.begin(), base.end(), gen);
            base_test = base;

            // sort the reference vector
            std::sort(base.begin(), base.end());
        }

        std::vector<int> base = std::vector<int>(200);
        std::vector<int> base_test;
        Sorting<int> sort;
};

// Fixture Class used for testing std::vector of std::string
class SortingString : public ::testing::Test
{
    protected:
        void SetUp() override
        {
            std::mt19937 engine;

            // create distribution in order to generate number between 0 and 62
            std::uniform_int_distribution<int> distribution (0, 62);
            auto gen = std::bind(distribution, engine);

            // generate 200 random string
            for (auto i = 0; i < 200; i++)
            {
                auto size = gen();
                std::string tmp;

                // generate random string
                for (auto j = 0; j < size; j++)
                    tmp.push_back(string_base[gen()]);

                base.push_back(tmp);
            }
            base_test = base;

            // sort the reference vector
            std::sort(base.begin(), base.end());
        }

        const char string_base[63] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        std::vector<std::string> base = std::vector<std::string>(200);
        std::vector<std::string> base_test;
        Sorting<std::string> sort;
};

// [=== TEST FOR INTEGER ===]

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

TEST_F(SortingInteger, RadixSort)
{
    sort.radix_sort(base_test);
    EXPECT_EQ(base, base_test);
}

// [=== TEST FOR STD::STRING ===]

TEST_F(SortingString, BubleSort)
{
    sort.bubble_sort(base_test);
    EXPECT_EQ(base, base_test);
}

TEST_F(SortingString, BubleSortOpti)
{
    sort.bubble_sort_optimize(base_test);
    EXPECT_EQ(base, base_test);
}

TEST_F(SortingString, InsertionSort)
{
    sort.insertion_sort(base_test);
    EXPECT_EQ(base, base_test);
}

TEST_F(SortingString, MergeSort)
{
    sort.merge_sort(base_test);
    EXPECT_EQ(base, base_test);
}

TEST_F(SortingString, HeapSort)
{
    sort.heap_sort(base_test);
    EXPECT_EQ(base, base_test);
}

TEST_F(SortingString, QuickSort)
{
    sort.quick_sort(base_test);
    EXPECT_EQ(base, base_test);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
