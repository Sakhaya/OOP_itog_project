// Vector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#ifndef DATA_VECTOR_H
#define DATA_VECTOR_H

#include <iostream>

template<typename T>
class Vector {
private:
    T* arr_;//указатель на область памяти, где будет храниться массив 
    size_t size_{};//размер вектора
    size_t capacity_{};//максимальный размер вектора

    void addMemory() {//метод выделения новой памяти
        capacity_ *= 2;
        T* tmp = arr_;
        arr_ = new T[capacity_];
        for (size_t i = 0; i < size_; i++)
            arr_[i] = tmp[i];
        delete[] tmp;
    }
public:
    Vector() {//конструктор класса 
        arr_ = new T[1];
        capacity_ = 1;
    }

    [[nodiscard]] bool isEmpty()const { //метод, который проверяет пустой ли список 
        return size_ == 0;
    }

    [[nodiscard]] size_t size() const {//метод получения размера вектора 
        return size_;
    }

    [[nodiscard]] size_t capacity() const {//метод получения максимального размера вектора
        return capacity_;
    }

    void pushBack(const T& value) {//метод добавления элемента 
        if (size_ >= capacity_) addMemory();
        arr_[size_++] = value;
    }

    void remove(size_t index) {//метод удаления элемента
        for (size_t i = index + 1; i < size_; i++) {
            arr_[i - 1] = arr_[i];
        }
        --size;
    }

    T& operator[](size_t index) {
        return arr_[index];
    }

    const T& operator[](size_t index) const {
        return arr_[index];
    }

    ~Vector() {
        delete[] arr_;
    }

    T* begin() {
        return &arr_[0];
    }

    const T* begin() const {
        return &arr_[0];
    }

    T* end() {
        return &arr_[size_];
    }

    const T* end() const {
        return &arr_[size_];
    }

    Vector(Vector& other) {
        if (this != &other) {
            delete[] arr_;
            arr_ = new T[other.capacity_];
            for (size_t i = 0; i < other.size_; ++i) arr_[i] = other.arr_[i];
            size_ = other.size_;
            capacity_ = other.capacity_;
        }
    }
    Vector(Vector&& other)  noexcept {
        if (this != &other) {
            delete[] arr_;
            arr_ = other.arr_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.arr_ = nullptr;
            other.size_ = other.capacity_ = 0;
        }
    }

    Vector& operator=(Vector& other) {
        if (this != &other) {
            delete[] arr_;
            arr_ = new T[other.capacity_];
            for (size_t i = 0; i < other.size_; ++i) arr_[i] = other.arr_[i];
            size_ = other.size_;
            capacity_ = other.capacity_;
        }
        return *this;
    }

    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            delete[] arr_;
            arr_ = other.arr_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.arr_ = nullptr;
            other.size_ = other.capacity_ = 0;
        }
        return *this;
    }
};

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
     for (size_t i = 0; i < vec.size(); i++) 
        os << vec[i] << " " << std::endl;
        return os;
    
}

#endif