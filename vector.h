#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef> // For size_t
#include <algorithm> // For std::copy
#include <initializer_list> // For std::initializer_list
#include <stdexcept> // For std::out_of_range

template<typename T>
class Vector {
private:
    T* data;
    size_t size;
    size_t capacity;

    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        std::copy(data, data + size, new_data);
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:

    // Member types
    using value_type = T;
    using allocator_type = std::allocator<T>;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using reference = T&;
    using const_reference = const T&;
    using pointer = std::allocator_traits<Allocator>::pointer;
    using const_pointer = std::allocator_traits<Allocator>::const_pointer;
    using iterator = T*;
    using const_iterator = const T*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    // Member functions
    Vector() : data(nullptr), size(0), capacity(0) {}
    ~Vector() {
        delete[] data;
    }
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }

    // Element access
    reference at(size_type index) {
        if (index >= size) {
            throw std::out_of_range("Vector::at index out of range");
        }
        return data[index];
    }
    const_reference at(size_type index) const {
        if (index >= size) {
            throw std::out_of_range("Vector::at index out of range");
        }
        return data[index];
    }
    reference operator[](size_type index) { return data[index]; }
    const_reference operator[](size_type index) const { return data[index]; }
    reference front() { return data[0]; }
    const_reference front() const { return data[0]; }
    reference back() { return data[size - 1]; }
    const_reference back() const { return data[size - 1]; }
    pointer data() noexcept { return data; }
    const_pointer data() const noexcept { return data; }

    // Iterators
    iterator begin() noexcept { return data; }
    const_iterator begin() const noexcept { return data; }
    iterator end() noexcept { return data + size; }
    const_iterator end() const noexcept { return data + size; }
    reverse_iterator rbegin() noexcept { return reverse_iterator(end()); }
    const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(end()); }
    reverse_iterator rend() noexcept { return reverse_iterator(begin()); }
    const_reverse_iterator rend() const noexcept { return const_reverse_iterator(begin()); }

    // Capacity
    bool empty() const noexcept { return size == 0; }
    size_type size() const noexcept { return size; }
    size_type max_size() const noexcept { return std::numeric_limits<size_type>::max(); }
    void reserve(size_type new_capacity) {
        if (new_capacity > capacity) {
            resize(new_capacity);
        }
    }
    size_type capacity() const noexcept { return capacity; }
    void shrink_to_fit() {
        if (size < capacity) {
            resize(size);
        }
    }

    // Modifiers
    
    

};

#endif
