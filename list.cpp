#include<iostream>
#define MIN_CAPACITY 10

template <class T>
class List {
    public:
        List();
        ~List();

        void append(T item);
        void insert(size_t index, T item);

        T pop();
        T pop(size_t index);

        T get_item(size_t index);
        size_t get_size();
        size_t get_capacity();
    private:
        size_t size;
        size_t capacity;
        T* p_list;
};

//  Constructor
template <class T>
List<T>::List() {
    size = 0;
    capacity = MIN_CAPACITY;
    
    T* new_p_list = new T[MIN_CAPACITY];

    p_list = new_p_list;
}

//   Destructor
template <class T>
List<T>::~List() {
    delete[] p_list;
    p_list = nullptr;
}

//  Add an item to the end of the list
template <class T>
void List<T>::append(T item) {
    size++;
    if (size >= capacity) {
        capacity = capacity*2;
        T* newPointer = new T[capacity];
        for (size_t i = 0; i < size - 1; i++) {
            newPointer[i] = p_list[i];
        }
        delete [] p_list;
        p_list = newPointer;
        newPointer = nullptr;
    }
    p_list[size-1] = item;
}

//  Insert an item at a given position
// If index = new size <=> append()
template <class T>
void List<T>::insert(size_t index, T item) {
    size++;
    if (size >= capacity) {
        capacity = capacity*2;
    }
    T* newPointer = new T[capacity];
    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        if (i == index) {
             newPointer[i] = item;
             continue;
        }
        newPointer[i] = p_list[j];
        j++;
    }
    delete [] p_list;
    p_list = newPointer;
    newPointer = nullptr;
}

//  Remove the item at the given position in the list, and return it. 
//  If no index is specified, a.pop() removes and returns the last item in the list.
template <class T>
T List<T>::pop() {
    T temp = p_list[size-1];
    size--;
    T* newPointer = new T[capacity];
    for (size_t i = 0; i < size; i++) {
        newPointer[i] = p_list[i];
    }
    delete [] p_list;
    p_list = newPointer;
    newPointer = nullptr;
    return temp;
}

template <class T>
T List<T>::pop(size_t index) {
    size--;
    T temp = p_list[index];
    T* newPointer = new T[capacity];
    size_t j = 0;
    for (size_t i = 0; i < size; i++) {
        if (j == index) {
            i--;
            j++;
            continue;
        } 
        newPointer[i] = p_list[j]; 
        j++;
    }
    delete [] p_list;
    p_list = newPointer;
    newPointer = nullptr;
    return temp;
}

template <class T>
T List<T>::get_item(size_t index) {
    return p_list[index];
}

template <class T>
size_t List<T>::get_size() {
    return size;
}

template <class T>
size_t List<T>::get_capacity() {
    return capacity;
}

