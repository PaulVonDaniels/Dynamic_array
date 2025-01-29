/*
Here are an additional 21 tests to check 
the operability of all the functions of my dynamic array.
*/

#include <gtest/gtest.h>
#include "vector.h"  // Подключите ваш файл с классом Vector

// Тест для конструктора по умолчанию
TEST(VectorTest, DefaultConstructor) {
    Vector<int> vec;
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.capacity(), 8);
    EXPECT_TRUE(vec.empty());
}

// Тест для push_back и push_front
TEST(VectorTest, PushBackAndPushFront) {
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_front(5);
    vec.push_front(1);

    EXPECT_EQ(vec.size(), 4);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 5);
    EXPECT_EQ(vec[2], 10);
    EXPECT_EQ(vec[3], 20);
}

// Тест для pop_back и pop_front
TEST(VectorTest, PopBackAndPopFront) {
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_front(5);
    vec.push_front(1);

    vec.pop_back();
    vec.pop_front();

    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], 5);
    EXPECT_EQ(vec[1], 10);
}

// Тест для оператора []
TEST(VectorTest, OperatorBrackets) {
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);

    vec[1] = 15;
    EXPECT_EQ(vec[1], 15);

    EXPECT_THROW(vec[2], VectorIndexError);  // Проверка на выход за границы
}

// Тест для insert и remove
TEST(VectorTest, InsertAndRemove) {
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);

    vec.insert(1, 15);
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[1], 15);

    vec.remove(1);
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[1], 20);
}

// Тест для clear
TEST(VectorTest, Clear) {
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);

    vec.clear();
    EXPECT_EQ(vec.size(), 0);
    EXPECT_TRUE(vec.empty());
}

// Тест для sort и reverse
TEST(VectorTest, SortAndReverse) {
    Vector<int> vec;
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(2);

    vec.sort();
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 1);
    EXPECT_EQ(vec[2], 2);
    EXPECT_EQ(vec[3], 3);
    EXPECT_EQ(vec[4], 4);

    vec.reverse();
    EXPECT_EQ(vec[0], 4);
    EXPECT_EQ(vec[1], 3);
    EXPECT_EQ(vec[2], 2);
    EXPECT_EQ(vec[3], 1);
    EXPECT_EQ(vec[4], 1);
}

// Тест для unique
TEST(VectorTest, Unique) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(3);

    vec.unique();
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}

// Тест для shrink_to_fit и reserve
TEST(VectorTest, ShrinkToFitAndReserve) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    vec.shrink_to_fit();
    EXPECT_EQ(vec.capacity(), 3);

    vec.reserve(10);
    EXPECT_EQ(vec.capacity(), 10);
}

// Тест для assign
TEST(VectorTest, Assign) {
    Vector<int> vec;
    vec.assign(5, 100);

    EXPECT_EQ(vec.size(), 5);
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(vec[i], 100);
    }
}

// Тест для swap
TEST(VectorTest, Swap) {
    Vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);

    Vector<int> vec2;
    vec2.push_back(3);
    vec2.push_back(4);

    vec1.swap(vec2);

    EXPECT_EQ(vec1.size(), 2);
    EXPECT_EQ(vec1[0], 3);
    EXPECT_EQ(vec1[1], 4);

    EXPECT_EQ(vec2.size(), 2);
    EXPECT_EQ(vec2[0], 1);
    EXPECT_EQ(vec2[1], 2);
}

// Тест для erase
TEST(VectorTest, Erase) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    vec.erase(1, 3);
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 4);
}

// Тест для оператора += и +
TEST(VectorTest, OperatorPlusAndPlusEqual) {
    Vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);

    Vector<int> vec2;
    vec2.push_back(3);
    vec2.push_back(4);

    vec1 += vec2;
    EXPECT_EQ(vec1.size(), 4);
    EXPECT_EQ(vec1[0], 1);
    EXPECT_EQ(vec1[1], 2);
    EXPECT_EQ(vec1[2], 3);
    EXPECT_EQ(vec1[3], 4);

    Vector<int> vec3 = vec1 + vec2;
    EXPECT_EQ(vec3.size(), 6);
    EXPECT_EQ(vec3[0], 1);
    EXPECT_EQ(vec3[1], 2);
    EXPECT_EQ(vec3[2], 3);
    EXPECT_EQ(vec3[3], 4);
    EXPECT_EQ(vec3[4], 3);
    EXPECT_EQ(vec3[5], 4);
}

// Тест для at
TEST(VectorTest, At) {
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);

    EXPECT_EQ(vec.at(0), 10);
    EXPECT_EQ(vec.at(1), 20);
    EXPECT_THROW(vec.at(2), VectorIndexError);  // Проверка на выход за границы
}

// Тест для fill
TEST(VectorTest, Fill) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    vec.fill(100);
    for (int i = 0; i < vec.size(); ++i) {
        EXPECT_EQ(vec[i], 100);
    }
}

// Тест для contains
TEST(VectorTest, Contains) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    EXPECT_TRUE(vec.contains(2));
    EXPECT_FALSE(vec.contains(4));
}

// Тест для replace
TEST(VectorTest, Replace) {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(3);

    vec.replace(2, 100);
    EXPECT_EQ(vec[1], 100);
    EXPECT_EQ(vec[2], 100);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
