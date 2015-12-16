#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <QList>

using namespace std;

struct Regalo{
string desc;
char control_parental;
};

struct Kid{
string nombre;
int se_porto_bien; //valor del 0 al 10,  0 = Diablillo , 10 = La encarnación del Bien.
QList<Regalo> Regalos;
int longitud;
int latitud;
int edad;
};

struct claves{
    string nombre;
    long registro;
};

class nodo
{
public:
    nodo(int c_, bool hoj);
    int *llaves;
    int m;
    int c;
    nodo **ptr; // Puntero al arreglo de nodos hijos
    Kid *child; // data of kid
    int clave; // registro ( no repetido ) de los nodos
    bool hoja;  // false si es padre o root
    void insertNonFull(int k, string nom, int status, int longi, int lati, int edad);
    void splitChild(int i, nodo *y);
    void traverse();
    nodo *search(int k);

   friend class arbol;
};

#endif // NODO_H
