#ifndef VECTOR_H
#define VECTOR_H

#include <memory>
#include <iterator>
#include <cstddef>

template <typename T>
class Vector {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    /**
     * Конструктор класса Vector
     */
    Vector() : data(nullptr), size(0), capacity(0) {}

    /**
     * Деструктор класса вектор
     */
    ~Vector() 
    {
        delete[] data;
    }

    /**
     * Перегрузка оператора []
     * 
     * @param   int     индекс получаемого элемента вектора
     * @return  T&      значение элемента под заданным индексом
     */
    T& operator[](int index) 
    {
        if (size < static_cast<size_t>(index) || index < 0) 
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    

    /**
     * Перегрузка оператора [] для константных объектов
     * 
     * @param   int         индекс получаемого элемента вектора
     * @return  const T&    значение элемента под заданным индексом
     */
    const T& operator[](int index) const
    {
        if (size <= static_cast<size_t>(index) || index < 0)
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    /**
     * Перегрузка оператора вывода в поток через дружественную функцию
     */
    friend std::ostream& operator<<(std::ostream &os, const Vector<T>& vector)
    {
        os << "Vector {";

        for (size_t i = 0; i < vector.GetSize(); i++)
        {
            os << vector[i];

            if (i < vector.GetSize() - 1)
            {
                os << ", ";
            }
        }

        os << "}";
        return os;
    }

    /**
     * Создание вектора размера n
     */
    void Create(size_t n) 
    {
        data = new T[n];
        size = 0;
        capacity = n;
    }

    /**
     * Проверка, пустой ли вектор
     * 
     * @return   bool   булевое значение, является ли вектор пустым
     */
    bool IsEmpty() const
    {
        return size == 0;
    }

    /**
     * Получение размера вектора
     * 
     * @return   size_t   размер вектора
     */
    size_t GetSize() const
    {
        return size;
    }

    /**
     * Получение емкости вектора
     * 
     * @return   sizet   емкость вектора
     */
    size_t GetCapacity() const
    {
        return capacity;
    }

    /**
     * Изменение размера вектора
     * 
     * @param   size_t   новый размер
     */
    void Resize(size_t n) 
    {
        if (n > capacity) 
        {
            T* new_data = new T[n];
            
            for (size_t i = 0; i < size; i++)
            {
                new_data[i] = data[i];
            }
            
            delete[] data;
            data = new_data;
            capacity = n;
        }
    }

    /**
     * Добавление элемента в конец вектора
     * 
     * @param   T   элемент для добавления
     */
    void PushBack(T element) 
    {
        if (size >= capacity)
        {
            Resize(capacity == 0 ? 1 : capacity * 2);
        }

        data[size++] = element;
    }

    /**
     * Удаление элемента с конца вектора
     */
    void PopBack() 
    {
        T* new_data = new T[size-1];
        
        for (size_t i = 0; i < size - 1; i++)
        {
            new_data[i] = data[i];
        }
        
        delete[] data;
        data = new_data;
        size--;
    }

    /**
     * Заполнение вектора числами
     */
    void FillVector()
    {
        for (size_t i = 0; i < capacity; i++) 
        {
            PushBack(i + 1);
        }
    }

    /**
     * Итератор, для обхода коллекции
     */
    struct Iterator
    {
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = int;
        using pointer           = int*;
        using reference         = int&;

        Iterator(pointer ptr) : data_ptr(ptr) {}

        reference operator*() const { return *data_ptr; }
        pointer operator->() { return data_ptr; }
        Iterator& operator++() { data_ptr++; return *this; }  
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
        friend bool operator== (const Iterator& a, const Iterator& b) { return a.data_ptr == b.data_ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.data_ptr != b.data_ptr; };

    private:
        pointer data_ptr;
    };

    Iterator begin() { return Iterator(&data[0]); }
    Iterator end()   { return Iterator(&data[size]); }
};

#endif // VECTOR_H