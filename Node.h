#ifndef NODE_H
#define NODE_H

#include <ostream>

template <typename T> 
class Node {
    public:
        T data;          // El elemento almacenado, de tipo genérico T
        Node<T>* next;   // Puntero al siguiente nodo de la secuencia

        // Método constructor con valor por defecto para next
        Node(T data, Node<T>* next = nullptr) {
            this->data = data;
            this->next = next;
        }

        // Sobrecarga global del operador << para imprimir el nodo
        friend std::ostream& operator<<(std::ostream &out, const Node<T> &node) {
            out << node.data;
            return out;
        }
};

#endif
t commit -m "Add Node class implementation"
