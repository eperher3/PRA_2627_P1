#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
        Node<T>* first;  // Puntero al primer nodo de la secuencia enlazada
        int n;           // Número de elementos que contiene la lista

    public:
        // Constructor sin argumentos
        ListLinked() {
            first = nullptr;
            n = 0;
        }

        // Destructor (libera la memoria de todos los nodos)
        ~ListLinked() {
            while (first != nullptr) {
                Node<T>* aux = first->next;
                delete first;
                first = aux;
            }
        }

        // Sobrecarga del operador []
        T operator[](int pos) {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición fuera de rango en operator[]");
            }
            Node<T>* aux = first;
            for (int i = 0; i < pos; i++) {
                aux = aux->next;
            }
            return aux->data;
        }

        // Inserta un elemento en una posición específica
        void insert(int pos, T e) override {
            if (pos < 0 || pos > n) {
                throw std::out_of_range("Posición fuera de rango en insert()");
            }
            if (pos == 0) {
                first = new Node<T>(e, first);
            } else {
                Node<T>* aux = first;
                for (int i = 0; i < pos - 1; i++) {
                    aux = aux->next;
                }
                aux->next = new Node<T>(e, aux->next);
            }
            n++;
        }

        // Inserta al principio
        void prepend(T e) override {
            insert(0, e);
        }

        // Inserta al final
        void append(T e) override {
            insert(n, e);
        }

        // Elimina y devuelve el elemento en una posición
        T remove(int pos) override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición fuera de rango en remove()");
            }
            Node<T>* to_delete;
            if (pos == 0) {
                to_delete = first;
                first = first->next;
            } else {
                Node<T>* aux = first;
                for (int i = 0; i < pos - 1; i++) {
                    aux = aux->next;
                }
                to_delete = aux->next;
                aux->next = to_delete->next;
            }
            T data = to_delete->data;
            delete to_delete;
            n--;
            return data;
        }

        // Devuelve el elemento en una posición sin eliminarlo
        T get(int pos) override {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición fuera de rango en get()");
            }
            Node<T>* aux = first;
            for (int i = 0; i < pos; i++) {
                aux = aux->next;
            }
            return aux->data;
        }

        // Busca un elemento y devuelve su posición, o -1 si no existe
        int search(T e) override {
            Node<T>* aux = first;
            int index = 0;
            while (aux != nullptr) {
                if (aux->data == e) {
                    return index;
                }
                aux = aux->next;
                index++;
            }
            return -1;
        }

        // Comprueba si la lista está vacía
        bool empty() override {
            return n == 0;
        }

        // Devuelve el número de elementos actuales
        int size() override {
            return n;
        }

        // Sobrecarga del operador de salida para imprimir la lista
        friend std::ostream& operator<<(std::ostream &out, ListLinked<T> &list) {
            out << "ListLinked [";
            Node<T>* aux = list.first;
            while (aux != nullptr) {
                out << aux->data;
                if (aux->next != nullptr) out << ", ";
                aux = aux->next;
            }
            out << "]";
            return out;
        }
};

#endif

