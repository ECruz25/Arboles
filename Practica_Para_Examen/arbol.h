#ifndef ARBOL_H
#define ARBOL_H

#include "nodo.h"
#include <QString>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

class Arbol
{
public:
    Arbol();
    Arbol(QString valor);
    void insertar(QString valor, Arbol* raiz);
    Arbol* buscar(QString valor, Arbol* raiz);
    void eliminar(QString valor);
    Arbol* inicio;
    QString valor;
    Arbol* hijo_derecho;
    Arbol* hijo_izquierdo;
    Arbol* getMaxDer(Arbol* raiz);
    void ecuacion(Arbol* raiz);
    void inOrden(Arbol* raiz);
    void preOrden(Arbol* raiz);
    void postOrden(Arbol* raiz);
    QString ecuacion_string;
    QChar simbolo;
    int resolverEcuacion(queue<int> constantes, queue<char> operadores);
    queue<QString> pila;
    queue<int> pila_constantes;
    queue<char> pila_operaciones;
    QString resultado;
    int respuesta;
};

#endif // ARBOL_H
