#include "Buffer.h"

Buffer::Buffer(size_t s) : size(s), data(new int[s]) {
    std::cout << "Constructor: Alocare " << size << " elemente.\n";
    for(size_t i = 0; i < size; ++i) {
        data[i] = 0;
    }
}

Buffer::~Buffer() {
    std::cout << "Destructor: Eliberare memorie.\n";
    delete[] data;
}

Buffer::Buffer(const Buffer& other) : size(other.size), data(new int[other.size]) {
    std::cout << "Copy Constructor: Copiere adanca (Deep Copy).\n";
    for(size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

Buffer::Buffer(Buffer&& other) noexcept : size(other.size), data(other.data) {
    std::cout << "Move Constructor: Mutare resurse.\n";
    other.size = 0;
    other.data = nullptr;
}

void Buffer::setValue(size_t index, int value) {
    if(index < size) data[index] = value;
}

void Buffer::print() const {
    if(!data) {
        std::cout << "[Buffer gol/mutat]\n";
        return;
    }
    for(size_t i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}