#pragma once
#include <iostream>

class Buffer {
private:
    int* data;
    size_t size;

public:
    explicit Buffer(size_t s);

    ~Buffer();

    Buffer(const Buffer& other);

    Buffer(Buffer&& other) noexcept;

    void setValue(size_t index, int value);
    void print() const;
};