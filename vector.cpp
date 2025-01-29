#include <iostream>
#include <cstdio>
#include <locale.h>
#include <exception>
#include <cstring>
#include <string>
#include <cstdint>
#include <cstdlib>
#include <algorithm>
using std::fixed;
using std::ios;
using std::cout;
using std::cin;
using std::endl;
using std::string;

class VectorIndexError : public std::exception
{
protected:
    std::string msg;
public:
    VectorIndexError(const std::string& error) noexcept;
    virtual ~VectorIndexError() noexcept;
    virtual const char* what() const noexcept override { return msg.c_str(); }
};

VectorIndexError::VectorIndexError(const std::string& error) noexcept : msg(error) { }

VectorIndexError::~VectorIndexError() = default;

template <class T>
class Vector
{
    T* arr = {nullptr};
    int64_t length{0}, __capacity{8};

    void resize() {
        __capacity *= 2;
        T* new_arr = new T[__capacity];

        for (size_t i {}; i < length; ++i) 
        {
            new_arr[i] = arr[i];
        }

        delete[] arr;
        arr = new_arr;
    }

public:
    Vector();

    ~Vector();

    void push_back(T number);

    void push_front(T number);

    void pop_back();

    void pop_front();

    T& operator[](int index);

    void insert(int index, T value);

    void remove(int index);

    void clear();

    bool empty();

    int64_t size();

    int64_t capacity();

    void sort();

    int64_t find(T value);

    void reverse();

    void unique();

    void shrink_to_fit();

    void reserve(int64_t new_capacity);

    void swap(Vector<T>& other);
    
    void assign(int64_t count, T value);

    void erase(int64_t start, int64_t end);

    void print() const;

    Vector(const Vector<T>& other);

    Vector(Vector<T>&& other) noexcept;

    Vector<T>& operator=(Vector<T>& other);

    Vector<T>& operator+=(Vector<T>& other);

    Vector<T>& operator+(Vector<T>& other);

    T* data() { return arr; }
    const T* data() const { return arr; }

    T& at(int64_t index) {
        if (index >= length || index < 0) 
        {
            throw VectorIndexError("Invalid element index.");
        }
        return arr[index];
    }

    const T& at(int64_t index) const {
        if (index >= length || index < 0) 
        {
            throw VectorIndexError("Invalid element index.");
        }
        return arr[index];
    }

    void fill(T value) {
        for (int64_t i = 0; i < length; ++i) 
        {
            arr[i] = value;
        }
    }

    bool contains(T value) const {
        for (int64_t i = 0; i < length; ++i) 
        {
            if (arr[i] == value) 
            {
                return true;
            }
        }
        return false;
    }

    void replace(T old_value, T new_value) {
        for (int64_t i = 0; i < length; ++i) 
        {
            if (arr[i] == old_value) 
            {
                arr[i] = new_value;
            }
        }
    }
};

template <class T>
Vector<T>::Vector() { arr = new T[__capacity]; }

template <class T>
Vector<T>::~Vector() 
{ if (arr != nullptr) delete[] arr; }

template <class T>
void Vector<T>::push_back(T number) 
{
    if (length >= __capacity) 
    {
        resize();
    }
    arr[length] = number;
    length++;
}

template <class T>
void Vector<T>::push_front(T number) {
    if (length >= __capacity) 
    {
        resize();
    }
    for (int64_t i = length - 1; i >= 0; --i) 
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = number;
    length++;
}

template <class T>
void Vector<T>::pop_back() 
{
    if (length > 0) {
        length--;
    }
}

template <class T>
void Vector<T>::pop_front() 
{
    if (length > 0) {
        for (int64_t i {}; i < length - 1; ++i) 
        {
            arr[i] = arr[i + 1];
        }
        --length;
    }
}

template <class T>
T& Vector<T>::operator[](int index) 
{
    if (index >= length || index < 0) 
    {
        throw VectorIndexError("Invalid element index.");
    }
    return arr[index];
}

template <class T>
void Vector<T>::insert(int index, T value) 
{
    if (index >= length || index < 0) 
    {
        throw VectorIndexError("Invalid element index.");
    }
    if (length >= __capacity) 
    {
        resize();
    }
    for (int64_t i = length; i > index; --i) 
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    length++;
}

template <class T>
void Vector<T>::remove(int index) {
    if (index >= length || index < 0) 
    {
        throw VectorIndexError("Invalid element index.");
    }
    for (int64_t i = index; i < length - 1; ++i) 
    {
        arr[i] = arr[i + 1];
    }
    length--;
}

template <class T>
void Vector<T>::clear() 
{
    if (arr != nullptr) 
    {
        delete[] arr;
        arr = nullptr;
        length = 0;
        __capacity = 8;
    }
}

template <class T>
bool Vector<T>::empty() 
{
    return length == 0;
}

template <class T>
int64_t Vector<T>::size() 
{
    return length;
}

template <class T>
int64_t Vector<T>::capacity() 
{
    return __capacity;
}

template <class T>
void Vector<T>::sort() 
{
    std::sort(arr, arr + length);
}

template <class T>
int64_t Vector<T>::find(T value) 
{
    for (int64_t i {}; i < length; ++i) 
        if (arr[i] == value) 
            return i;
    return -1;
}

template <class T>
void Vector<T>::reverse() 
{
    for (int64_t i {}; i < length / 2; ++i) 
    {
        std::swap(arr[i], arr[length - i - 1]);
    }
}

template <class T>
void Vector<T>::unique() 
{
    if (length == 0) return;

    int64_t new_length = 1;
    for (int64_t i = 1; i < length; ++i) 
    {
        if (arr[i] != arr[new_length - 1]) 
        {
            arr[new_length++] = arr[i];
        }
    }
    length = new_length;
}

template <class T>
void Vector<T>::shrink_to_fit() 
{
    if (length < __capacity) 
    {
        __capacity = length;
        T* new_arr = new T[__capacity];
        for (int64_t i {}; i < length; ++i) 
        {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
    }
}

template <class T>
void Vector<T>::reserve(int64_t new_capacity) 
{
    if (new_capacity > __capacity) 
    {
        __capacity = new_capacity;
        T* new_arr = new T[__capacity];
        for (int64_t i {}; i < length; ++i) 
        {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
    }
}

template <class T>
void Vector<T>::swap(Vector<T>& other)
{
    std::swap(arr, other.arr);
    std::swap(length, other.length);
    std::swap(__capacity, other.__capacity);
}

template <class T>
void Vector<T>::assign(int64_t count, T value) 
{
    clear();
    reserve(count);
    for (int64_t i {}; i < count; ++i) 
    {
        push_back(value);
    }
}

template <class T>
void Vector<T>::erase(int64_t start, int64_t end)
{
    if (start < 0 || end > length || start > end) 
    {
        throw VectorIndexError("Invalid range.");
    }
    for (int64_t i = start; i < end; ++i) 
    {
        remove(start);
    }
}

template <class T>
void Vector<T>::print() const 
{
    for (int64_t i {}; i < length; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <class T>
Vector<T>::Vector(const Vector<T>& other) : length(other.length), __capacity(other.__capacity) 
{
    this->arr = new T[other.__capacity];
    for (int64_t i {}; i < other.length; ++i) 
    {
        arr[i] = other.arr[i];
    }
}

template <class T>
Vector<T>::Vector(Vector<T>&& other) noexcept : length(other.length), __capacity(other.__capacity) 
{
    arr = other.arr;
    other.arr = nullptr;
}

template <class T>
Vector<T>& Vector<T>::operator=(Vector<T>& other) 
{
    if (this != &other) 
    {
        delete[] arr;
        this->length = other.length;
        this->__capacity = other.__capacity;
        arr = new T[__capacity];
        for (int64_t i {}; i < length; ++i) 
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <class T>
Vector<T>& Vector<T>::operator+=(Vector<T>& other) 
{
    if (length + other.length >= this->__capacity) 
    {
        __capacity = length + other.length;
        T* new_arr = new T[__capacity];
        for (int64_t i {}; i < length; ++i) 
        {
            new_arr[i] = arr[i];
        }
        for (int64_t i = length; i < length + other.length; ++i) 
        {
            new_arr[i] = other.arr[i - length];
        }
        delete[] arr;
        arr = new_arr;
        length += other.length;
    } 
    else 
    {
        for (int64_t i = length; i < length + other.length; ++i) 
        {
            arr[i] = other.arr[i - length];
        }
        length += other.length;
    }
    return *this;
}

template <class T>
Vector<T>& Vector<T>::operator+(Vector<T>& other) 
{
    Vector<T>* res = new Vector();
    res->__capacity = length + other.length;
    res->arr = new T[res->__capacity];
    for (int64_t i {}; i < length; ++i) 
    {
        res->arr[i] = arr[i];
    }
    for (int64_t i = length; i < length + other.length; ++i) 
    {
        res->arr[i] = other.arr[i - length];
    }
    res->length = length + other.length;
    return *res;
}

signed int main() 
{
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_front(5);
    vec.push_front(1);

    cout << "After push_back and push_front: ";
    vec.print();

    vec.pop_back();
    vec.pop_front();

    cout << "After pop_back and pop_front: ";
    vec.print();

    vec[1] = 15;
    cout << "After changing element via operator[]: ";
    vec.print();

    vec.insert(1, 12);
    cout << "After insert: ";
    vec.print();

    vec.remove(2);
    cout << "After remove: ";
    vec.print();

    vec.clear();
    cout << "After clear: ";
    vec.print();

    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(2);

    vec.sort();
    cout << "After sort: ";
    vec.print();

    vec.reverse();
    cout << "After reverse: ";
    vec.print();

    vec.unique();
    cout << "After unique: ";
    vec.print();

    vec.shrink_to_fit();
    cout << "Capacity after shrink_to_fit: " << vec.capacity() << endl;

    vec.reserve(10);
    cout << "Capacity after reserve: " << vec.capacity() << endl;

    Vector<int> vec2;
    vec2.assign(3, 100);
    cout << "After assign: ";
    vec2.print();

    vec.swap(vec2);
    cout << "After swap (vec): ";
    vec.print();
    cout << "After swap (vec2): ";
    vec2.print();

    vec2.erase(1, 3);
    cout << "After erase: ";
    vec2.print();

    Vector<int> vec3;
    vec3.push_back(7);
    vec3.push_back(8);

    vec2 += vec3;
    cout << "After +=: ";
    vec2.print();

    Vector<int> vec4 = vec2 + vec3;
    cout << "After +: ";
    vec4.print();

    return 0;
}
