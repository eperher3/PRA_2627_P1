#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;          
    int max;         
    int n;           
    static const int MINSIZE = 2; 

    
    void resize(int new_size) {
        T* aux = new T[new_size];
        for (int i = 0; i < n; i++) {
            aux[i] = arr[i];
        }
        delete[] arr;
        arr = aux;
        max = new_size;
    }

public:
   
    ListArray() {
        arr = new T[MINSIZE];
        max = MINSIZE;
        n = 0;
    }
    
    ~ListArray() {
        delete[] arr;
    }

    
    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango en operator[]");
        }
        return arr[pos];
    }

    
    void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw std::out_of_range("Posición fuera de rango en insert()");
        }
        if (n >= max) {
            resize(max * 2);
        }
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = e;
        n++;
    }

    
    void prepend(T e) override {
        insert(0, e);
    }

   
    void append(T e) override {
        insert(n, e);
    }

    
    T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango en remove()");
        }
        T aux = arr[pos];
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        return aux;
    }

    
    T get(int pos) override {
        if (pos < 0 || pos >= n) {
            throw std::out_of_range("Posición fuera de rango en get()");
        }
        return arr[pos];
    }

    
    int search(T e) override {
        for (int i = 0; i < n; i++) {
            if (arr[i] == e) {
                return i;
            }
        }
        return -1;
    }

    
    bool empty() override {
        return n == 0;
    }

    
    int size() override {
        return n;
    }

    
    friend std::ostream& operator<<(std::ostream &out, ListArray<T> &list) {
        out << "ListArray [";
        for (int i = 0; i < list.size(); i++) {
            out << list.get(i);
            if (i < list.size() - 1) out << ", ";
        }
        out << "]";
        return out;
    }
};

#endif

