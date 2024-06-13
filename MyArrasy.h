template<typename T>
class MyArray {
public:
    MyArray(size_t initialSize) : size(initialSize) {
        data = static_cast<T*>(std::malloc(size * sizeof(T)));
    }

    // Copy constructor
    MyArray(const MyArray& other) : size(other.size) {
        data = static_cast<T*>(std::malloc(size * sizeof(T)));
        std::copy(other.data, other.data + size, data);
    }

    // Copy assignment operator
    MyArray& operator=(const MyArray& other) {
        if (this != &other) {
            std::free(data);
            size = other.size;
            data = static_cast<T*>(std::malloc(size * sizeof(T)));
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }

    ~MyArray() {
        std::free(data);
    }

    T& operator[](size_t index) {
        return data[index];
    }

    void resize(size_t newSize) {
        T* newData = static_cast<T*>(std::realloc(data, newSize * sizeof(T)));
        if (newData == nullptr) {
            throw std::bad_alloc();
        }
        data = newData;
        size = newSize;
    }

    size_t get_size() const {
        return size;
    }

private:
    size_t size;
    T* data;
};