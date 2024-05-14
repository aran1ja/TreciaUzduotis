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
    std::size_t size;
    std::size_t capacity;

    void resize(std::size_t new_capacity) {
        T* new_data = new T[new_capacity];
        std::copy(data, data + size, new_data);
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    // Member types
    using value_type = T;
    using allocator_type = Allocator;
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

};

#endif // VECTOR_H
