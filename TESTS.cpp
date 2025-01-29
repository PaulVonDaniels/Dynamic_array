/*
Here are an additional 21 tests to check 
the operability of all the functions of my dynamic array.
*/


signed int main(void) 
{
    Vector<short> vector;

    vector.push_back(10); vector.push_back(20); vector.push_front(5); vector.push_front(1);
    std::cout << "Test 1: ";
    vector.print();

    vector.pop_back();
    vector.pop_front();
    cout << "Test 2: ";
    vector.print();

    vector[0] = 15;
    cout << "Test 3: ";
    vector.print();

    vector.insert(1, 12);
    cout << "Test 4: ";
    vector.print();

    vector.remove(1);
    cout << "Test 5: ";
    vector.print();

    vector.clear();
    cout << "Test 6: ";
    vector.print();

    vector.push_back(3);
    vector.push_back(1);
    vector.push_back(4);
    vector.fill(100);
    cout << "Test 7: ";
    vector.print();

    cout << "Test 8: " << vector.contains(100)?"is true":"is false"<<endl;
    cout << "Test 8: " << vector.contains(200)?"is true":"is false"<<endl;

    vector.replace(100, 50);
    cout << "Test 9: ";
    vector.print();

    std::cout << "Test 10: " << vector.at(1) << endl;
    __try 
    {
        cout << "Test 10: " << vector.at(10) << endl;
    } 
    __catch (const VectorIndexError& __e) {
        cout << "Test 10: " << __e.what() << endl;
    }

    short* data_ptr = vector.data();
    cout << "Test 11: " << data_ptr[0] << " " << data_ptr[1] << " " << data_ptr[2] << endl;

    vector.push_back(30); vector.push_back(20); vector.push_back(10);
    vector.sort();
    cout << "Test 12: ";
    vector.print();

    vector.reverse();
    cout << "Test 13: ";
    vector.print();

    vector.push_back(50); vector.push_back(50);
    vector.unique();
    cout << "Test 14: ";
    vector.print();

    vector.shrink_to_fit();
    cout << "Test 15: " << vector.capacity() << endl;

    vector.reserve(10);
    cout << "Test 16: " << vector.capacity() << endl;

    Vector<int> vec2;
    vec2.assign(3, 100);
    cout << "Test 17: ";
    vec2.print();

    vec.swap(vec2);
    cout << "Test 18 (vec): ";
    vec.print();
    cout << "Test 18 (vec2): ";
    vec2.print();

    vec2.erase(1, 3);
    cout << "Test 19: ";
    vec2.print();

    Vector<int> vec3;
    vec3.push_back(7); vec3.push_back(8);
    vec2 += vec3;
    cout << "Test 20: ";
    vec2.print();

    Vector<int> vec4 = vec2 + vec3;
    cout << "Test 21: ";
    vec4.print();

    return 0;
}
