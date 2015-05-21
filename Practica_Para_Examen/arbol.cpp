#include "arbol.h"

Arbol::Arbol()
{
    this->inicio = NULL;
    this->hijo_derecho = NULL;
    this->hijo_izquierdo = NULL;
    pila_operaciones.push('+');
}

Arbol::Arbol(QString valor)
{
    this->valor = valor;
    this->inicio = NULL;
    this->hijo_derecho = NULL;
    this->hijo_izquierdo = NULL;
}

void Arbol::insertar(QString valor, Arbol* raiz)
{
    if(!raiz)
    {
        raiz = new Arbol(valor);
        return;
    }

    else if(raiz->valor == valor)
    {
        return;
    }
    if(raiz->valor < valor)
    {
        insertar(valor, raiz->hijo_izquierdo);
    }
    else
    {
        insertar(valor, raiz->hijo_derecho);
    }
}

Arbol* Arbol::buscar(QString valor, Arbol* raiz)
{
    if(!raiz)
    {
        return NULL;
    }
    if(raiz->valor == valor)
    {
        return raiz;
    }
    else if(valor > raiz->valor)
    {
        return buscar(valor, raiz->hijo_derecho);
    }
    else
    {
        return buscar(valor, raiz->hijo_izquierdo);
    }
}

void Arbol::eliminar(QString valor)
{
    if(!inicio)
    {
        return;
    }

    Arbol* borrar = buscar(valor, this->inicio);

    if(!borrar->hijo_derecho && !borrar->hijo_izquierdo)
    {
        return delete borrar;
    }

    Arbol* temp;

    if(borrar && !borrar->hijo_derecho)
    {
        temp = borrar;
        borrar = borrar->hijo_izquierdo;
        return delete temp;
    }

    else if(borrar && !borrar->hijo_izquierdo)
    {
        temp = borrar;
        borrar = borrar->hijo_derecho;
        return delete temp;
    }

    else
    {
        Arbol* temp_hijos = borrar->hijo_derecho;
        borrar = borrar->hijo_izquierdo;
        Arbol* temp_hijo_der = getMaxDer(borrar);
        temp_hijo_der->hijo_derecho = temp_hijos;
    }
}

Arbol* Arbol::getMaxDer(Arbol* raiz)
{
    while(raiz->hijo_derecho)
    {
        raiz = raiz->hijo_derecho;
    }
    return raiz;
}

void Arbol::preOrden(Arbol *raiz)
{
    if(!raiz)
    {
        return;
    }
    pila.push(raiz->valor);
    inOrden(raiz->hijo_izquierdo);
    inOrden(raiz->hijo_derecho);
}

void Arbol::inOrden(Arbol *raiz)
{
    if(!raiz)
    {
        return;
    }
    inOrden(raiz->hijo_izquierdo);
    pila.push(raiz->valor);
    inOrden(raiz->hijo_derecho);
}

void Arbol::postOrden(Arbol *raiz)
{
    if(!raiz)
    {
        return;
    }
    inOrden(raiz->hijo_izquierdo);
    inOrden(raiz->hijo_derecho);
    pila.push(raiz->valor);
}

void Arbol::ecuacion(Arbol *raiz)
{
    inOrden(raiz);
    while(!pila.empty())
    {
        resultado = pila.front();
        pila.pop();
        switch (resultado.toStdString()[0])
        {
        case 'x':
            pila_operaciones.push(resultado.toStdString()[0]);
            break;
        case '/':
            pila_operaciones.push(resultado.toStdString()[0]);
            break;
        case '-':
            pila_operaciones.push(resultado.toStdString()[0]);
            break;
        case '+':
            pila_operaciones.push(resultado.toStdString()[0]);
            break;
        default:
            pila_constantes.push(resultado.toInt());
            break;
        }
    }
    resolverEcuacion(pila_constantes, pila_operaciones);
}

int Arbol::resolverEcuacion(queue<int> constantes, queue<char> operadores)
{
    while(!operadores.empty() && !constantes.empty())
    {
        switch(operadores.front())
        {
        case 'x' :
            respuesta *= constantes.front();
            constantes.pop();
            operadores.pop();
            break;
        case '/' :
            respuesta /= constantes.front();
            constantes.pop();
            operadores.pop();
            break;
        case '-' :
            respuesta -= constantes.front();
            constantes.pop();
            operadores.pop();
            break;
        case '+' :
            respuesta += constantes.front();
            constantes.pop();
            operadores.pop();
            break;

        }
    }
    return respuesta;
}
