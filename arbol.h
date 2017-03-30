#ifndef ARBOL_H
#define ARBOL_H
#include "nodo.h"
#include <iostream>

using namespace std;

class arbol
{
    public:
        arbol(int _t);
        nodo *root;
        int t;    
        void agregarLista(string nom);
        Regalo agregargift(string regalo);
        bool buscarKid(string nom);
        int hash(string nom);
        int fibonacci(int n, int back, int next, int cont);
        int fibo(int n);
        void traverse();
        nodo* search(int k);
        bool insert(string nom, int status, int longi, int lati, int edad);
};

#endif // ARBOL_H
