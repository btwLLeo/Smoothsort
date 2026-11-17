#include <gtest/gtest.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "heapsort.hpp"

TEST(SortTest, HandlesNull){
    int *a = nullptr;
    heapsort(a, 0);
    ASSERT_EQ(a, nullptr);
}

TEST(SortTest, HandlesSingleElement){
    int a[1] = {rand() % 100}, b[1] = {a[0]};
    heapsort(a, 1);
    ASSERT_EQ(a[0], b[0]);
}

TEST(SortTest, AgainstOracle){
    for(int n = 0; n < 200; ++n){
        int *a, *b;
        a = new int[n]; b = new int[n];
        
        for(int i = 0; i < n; ++i)
            a[i] = b[i] = rand() % 100;
        
            std::sort(b, b + n);
        heapsort(a, n);
        
        bool same = std::equal(a, a + n, b);
        delete[] a;
        delete[] b;

        ASSERT_TRUE(same) << "failed for n = " << n;
    }
}

int main(int argc, char **argv){
    std::srand(std::time(nullptr));
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}