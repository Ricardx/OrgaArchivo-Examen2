#include "nodo.h"

nodo::nodo(int c_, bool hoj)
{

        m = c_;
        hoja = hoj;
        llaves = new int[2*m-1];
        ptr = new nodo *[2*m];
        c = 0;
}

void nodo::splitChild(int i, nodo *y)
{
        nodo *z = new nodo(y->m, y->hoja);
        z->c = m - 1;

        for (int j = 0; j < m-1; j++)
            z->llaves[j] = y->llaves[j+m];

        if (y->hoja == false)
        {
            for (int j = 0; j < m; j++)
                z->ptr[j] = y->ptr[j+m];
        }
        y->c = m - 1;

        for (int j = c; j >= i+1; j--)
            ptr[j+1] = ptr[j];

        ptr[i+1] = z;

        for (int j = c-1; j >= i; j--)
            llaves[j+1] = llaves[j];

        llaves[i] = y->llaves[m-1];

        c = c + 1;
}


void nodo::insertNonFull(int k, string nom, int status, int longi, int lati, int edad)
{
        int i = m-1;

        if (hoja == true)
        {
            while (i >= 0 && llaves[i] > k)
            {
                llaves[i+1] = llaves[i];
                i--;
            }

            llaves[i+1] = k;
            m = m+1;
            child->nombre = nom;
            child->se_porto_bien = status;
            child->longitud = longi;
            child->latitud = lati;
            child->edad = edad;
        }
        else
        {
            while (i >= 0 && llaves[i] > k)
                i--;

            if (ptr[i+1]->c == 2*m-1)
            {
                splitChild(i+1, ptr[i+1]);
                if (llaves[i+1] < k)
                    i++;
            }
            ptr[i+1]->insertNonFull(k,nom,status,longi,lati,edad);
        }
}


void nodo::traverse()
{
        int i;
        for (i = 0; i < c; i++)
        {
            if (hoja == false)
                ptr[i]->traverse();
            cout << " " << llaves[i];
            cout << child->nombre << endl;
        }
        if (hoja == false)
            ptr[i]->traverse();
}

nodo *nodo::search(int k)
{
    int i = 0;
    while (i < c && k > llaves[i])
        i++;

    if (llaves[i] == k)
        return this;

    if (hoja == true)
        return NULL;

    return ptr[i]->search(k);
}

