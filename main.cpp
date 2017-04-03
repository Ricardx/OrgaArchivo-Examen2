#include <QCoreApplication>
#include "arbol.h"
#include "nodo.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    arbol *b;
    int op;

    do {
        cout << "1. Agregar niño, 2. Agregar Lista a niño, 3.Imprimir" << endl;
        cin >> op;

        switch(op)
        {
            case 1:
                string nombre;
                int edad;
                int comport;
                int longi;
                int lati;
                cout << "Ingrese el nombre del niño" << endl;
                cin >> nombre;
                cout << "Ingrese la edad del niño" << endl;
                cin >> edad;
                cout << "Ingrese de una escala del 0 al 10 que tan bien se porto" << endl;
                cin >> comport;
                cout << "Ingrese longitud" << endl;
                cin >> longi;
                cout << "Ingrese latitud" << endl;
                cin >> lati;
                
                if(b->insert(nombre,comport,longi,lati,edad))
                {
                    cout<<"el niño se añadio al arbol"<<endl;
                } else {
                    cout<<"El niño no se añadio"<< endl;
                }
                break;

            case 2:
                string nombre1;
                cout << "Ingrese el nombre del niño" << endl;
                cin >> nombre1;
                b->agregarLista(nombre1);
                cout << "la Lista se añadio" << endl;
                break;

            case 3:
                b->traverse();
                break;
        }
    } while(op != 4);

    return a.exec();
}
