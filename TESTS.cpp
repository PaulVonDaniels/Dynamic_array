int main() 
{
    Vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_front(5);
    vec.push_front(1);
    cout << "Test 1: ";
    vec.print();

    vec.pop_back();
    vec.pop_front();
    cout << "Test 2: ";
    vec.print();

    vec[0] = 15;
    cout << "Test 3: ";
    vec.print();

    vec.insert(1, 12);
    cout << "Test 4: ";
    vec.print();

    vec.remove(1);
    cout << "Test 5: ";
    vec.print();

    vec.clear();
    cout << "Test 6: ";
    vec.print();

    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(4);
    vec.fill(100);
    cout << "Test 7: ";
    vec.print();

    cout << "Test 8: " << (vec.contains(100) ? "true" : "false") << endl;
    cout << "Test 8: " << (vec.contains(200) ? "true" : "false") << endl;

    vec.replace(100, 50);
    cout << "Test 9: ";
    vec.print();

    cout << "Test 10: " << vec.at(1) << endl;
    try {
        cout << "Test 10: " << vec.at(10) << endl;
    } catch (const VectorIndexError& e) {
        cout << "Test 10: " << e.what() << endl;
    }

    int* data_ptr = vec.data();
    cout << "Test 11: " << data_ptr[0] << " " << data_ptr[1] << " " << data_ptr[2] << endl;

    vec.push_back(30);
    vec.push_back(20);
    vec.push_back(10);
    vec.sort();
    cout << "Test 12: ";
    vec.print();

    vec.reverse();
    cout << "Test 13: ";
    vec.print();

    vec.push_back(50);
    vec.push_back(50);
    vec.unique();
    cout << "Test 14: ";
    vec.print();

    vec.shrink_to_fit();
    cout << "Test 15: " << vec.capacity() << endl;

    vec.reserve(10);
    cout << "Test 16: " << vec.capacity() << endl;

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
    vec3.push_back(7);
    vec3.push_back(8);
    vec2 += vec3;
    cout << "Test 20: ";
    vec2.print();

    Vector<int> vec4 = vec2 + vec3;
    cout << "Test 21: ";
    vec4.print();

    return 0;
}