#ifndef NODO_H
#define NODO_H

#include <iostream>

class Nodo
{
public:
    Nodo();
    Nodo(int valor);
    Nodo* hijo_derecho;
    Nodo* hijo_izquierdo;
    int valor;
};

#endif // NODO_H
