#include <iostream>

template <typename T>
class myVector {
public:
    myVector();
    myVector(const myVector& other);
    myVector(myVector&& other);

    ~myVector();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    void push_back(const T& value);
    void pop_back();
    void clear();
    void resize(size_t capacity);

    size_t size() const;
    size_t capacity() const;
    bool empty() const;

    class iterator;
    iterator begin();
    iterator end();

private:
    T* array_;
    size_t size_;
    size_t capacity_;
};
