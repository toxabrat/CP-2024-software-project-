#include "myVector.h"
#include <cstddef>
#include <algorithm>

template <typename T>
myVector<T>::myVector() {
    array_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

template <typename T>
myVector<T>::myVector(const myVector& other) {
    size_ = other.size();
    capacity_ = other.capacity();
    array_ = new T[capacity_];
    std::copy(other.begin(), other.end(), array_);
}

template <typename T>
myVector<T>::myVector(myVector&& other) {
    size_ = other.size();
    capacity_ = other.capacity();
    array_ = other.data;
    other.array_ = nullptr;
}

template <typename T> 
myVector<T>::~myVector() {
    delete[] array_;
}

template <typename T> 
T& myVector<T>::operator[](size_t index) {
    return array_[index];
}

template <typename T>
const T& myVector<T>::operator[](size_t index) const {
    return array_[index];
}

template <typename T> 
void myVector<T>::push_back(const T& value) {
    if(size_ == capacity_) {
        resize(capacity_ * 2 + 1);
    }
    array_[size_] = value;
    size_ += 1;
}

template <typename T>
void myVector<T>::pop_back() {
    size_ -= 1;
}

template <typename T>
void myVector<T>::clear() {
    delete[] array_;
    size_ = 0;
    capacity_ = 0;
}

template <typename T>
size_t myVector<T>::size() const {
    return size_;
}

template <typename T>
size_t myVector<T>::capacity() const {
    return capacity_;
}

template <typename T>
bool myVector<T>::empty() const {
    return size_ == 0;
}

template <typename T> 
void myVector<T>::resize(size_t capacity) {
    T* replacement = new T[capacity];
    std::copy(array_, array_ + std::min(size_, capacity), replacement);
    delete[] array_;
    array_ = replacement;
    size_ = std::min(size_, capacity);
    capacity_ = capacity;
}

template <typename T>
typename myVector<T>::iterator myVector<T>::begin() {
    return iterator(array_);
}

template <typename T>
typename myVector<T>::iterator myVector<T>::end() {
    return iterator(array_ + size_);
}

template <typename T>
class myVector<T>::iterator {
public:
    iterator(T* ptr) : ptr_(ptr) {}

    iterator& operator++() {
        ++ptr_;
        return *this;
    }

    iterator& operator--() {
        --ptr_;
        return *this;
    }

    T& operator*() {
        return *ptr_;
    }

    bool operator==(iterator& other) {
        return ptr_ == other.ptr_;
    }

    bool operator!=(iterator& other) {
        return !(*this == other);  
    }

private:
    T* ptr_;
};
