/*
Here are an additional 21 tests to check 
the operability of all the functions of my dynamic array.
*/


TEST(VectorTest, PushBack) {
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec[1], 20);
    EXPECT_EQ(vec[2], 30);
}

TEST(VectorTest, PushFront) {
    Vector<int> vec;
    vec.push_front(10);
    vec.push_front(20);
    vec.push_front(30);
    EXPECT_EQ(vec[0], 30);
    EXPECT_EQ(vec[1], 20);
    EXPECT_EQ(vec[2], 10);
}

TEST(VectorTest, PopBack) {
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.pop_back();
    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec[1], 20);
}

TEST(VectorTest, PopFront) {
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.pop_front();
    EXPECT_EQ(vec[0], 20);
    EXPECT_EQ(vec[1], 30);
}

TEST(VectorTest, Insert) {
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.insert(1, 15);
    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec[1], 15);
    EXPECT_EQ(vec[2], 20);
    EXPECT_EQ(vec[3], 30);
}

TEST(VectorTest, Remove) {
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.remove(1);
    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec[1], 30);
}

TEST(VectorTest, Clear) {
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.clear();
    EXPECT_TRUE(vec.empty());
}

TEST(VectorTest, Sort) {
    Vector<int> vec;
    vec.push_back(30);
    vec.push_back(10);
    vec.push_back(20);
    vec.sort();
    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec[1], 20);
    EXPECT_EQ(vec[2], 30);
}

TEST(VectorTest, Reverse) {
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.reverse();
    EXPECT_EQ(vec[0], 30);
    EXPECT_EQ(vec[1], 20);
    EXPECT_EQ(vec[2], 10);
}

TEST(VectorTest, Unique) {
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(20);
    vec.push_back(30);
    vec.unique();
    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec[1], 20);
    EXPECT_EQ(vec[2], 30);
}

TEST(VectorTest, ShrinkToFit) {
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.shrink_to_fit();
    EXPECT_EQ(vec.capacity(), 3);
}

TEST(VectorTest, Reserve) {
    Vector<int> vec;
    vec.reserve(10);
    EXPECT_EQ(vec.capacity(), 10);
}

TEST(VectorTest, Swap) {
    Vector<int> vec1;
    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);
    Vector<int> vec2;
    vec2.push_back(40);
    vec2.push_back(50);
    vec2.push_back(60);
    vec1.swap(vec2);
    EXPECT_EQ(vec1[0], 40);
    EXPECT_EQ(vec1[1], 50);
    EXPECT_EQ(vec1[2], 60);
    EXPECT_EQ(vec2[0], 10);
    EXPECT_EQ(vec2[1], 20);
    EXPECT_EQ(vec2[2], 30);
}

TEST(VectorTest, Assign) {
    Vector<int> vec;
    vec.assign(3, 100);
    EXPECT_EQ(vec[0], 100);
    EXPECT_EQ(vec[1], 100);
    EXPECT_EQ(vec[2], 100);
}

TEST(VectorTest, Erase) {
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    vec.erase(1, 3);
    EXPECT_EQ(vec[0], 10);
    EXPECT_EQ(vec[1], 40);
    EXPECT_EQ(vec[2], 50);
}

TEST(VectorTest, PlusEquals) {
    Vector<int> vec1;
    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);
    Vector<int> vec2;
    vec2.push_back(40);
    vec2.push_back(50);
    vec2.push_back(60);
    vec1 += vec2;
    EXPECT_EQ(vec1[0], 10);
    EXPECT_EQ(vec1[1], 20);
    EXPECT_EQ(vec1[2], 30);
    EXPECT_EQ(vec1[3], 40);
    EXPECT_EQ(vec1[4], 50);
    EXPECT_EQ(vec1[5], 60);
}

TEST(VectorTest, Plus) {
    Vector<int> vec1;
    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);
    Vector<int> vec2;
    vec2.push_back(40);
    vec2.push_back(50);
    vec2.push_back(60);
    Vector<int> vec3 = vec1 + vec2;
    EXPECT_EQ(vec3[0], 10);
    EXPECT_EQ(vec3[1], 20);
    EXPECT_EQ(vec3[2], 30);
    EXPECT_EQ(vec3[3], 40);
    EXPECT_EQ(vec3[4], 50);
    EXPECT_EQ(vec3[5], 60);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

