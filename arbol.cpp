#include "arbol.h"

arbol::arbol(int _t)
{
    root = NULL;
    this->t = _t;
}

int arbol::fibonacci(int n, int back, int next, int cont)
{
    if(cont<=n)
    {
        return fibonacci(n, back, next+back, cont+1);
    }

    return back;
}

int arbol::fibo(int n)
{
    return fibonacci(n,1,0,0);
}

void arbol::traverse()
{
    if (root != NULL)
        root->traverse();
}

nodo *arbol::search(int k)
{
    return (root == NULL)? NULL : root->search(k);
}

Regalo arbol::agregargift(string regalo)
{
    Regalo gift;
    gift.desc = regalo;
    gift.control_parental = 'N';

    return gift;
}

void arbol::agregarLista(string nom)
{
    int k = hash(nom);
    nodo *tmp = search(k);

    Regalo gift;
    if(tmp->child->se_porto_bien == 0)
    {
      gift.desc = " ";
      gift.control_parental = 'N';
      tmp->child->Regalos.push_back(gift);
    }else if(tmp->child->se_porto_bien == 1)
    {
        string nombre;
        int cant = fibo(tmp->child->se_porto_bien);
        for(int i=0; i<cant; i++)
        {
            cout<<"Ingrese el regalo"<<endl;
            cin>>nombre;
            tmp->child->Regalos.push_back(agregargift(nombre));
        }
        cout<<" se agregaron los regalos"<<endl;
    }else if(tmp->child->se_porto_bien == 2)
    {
        string nombre;
        int cant = fibo(tmp->child->se_porto_bien);
        for(int i=0; i<cant; i++)
        {
            cout<<"Ingrese el regalo"<<endl;
            cin>>nombre;
            tmp->child->Regalos.push_back(agregargift(nombre));
        }
        cout<<" se agregaron los regalos"<<endl;
    }else if(tmp->child->se_porto_bien == 3)
    {
        string nombre;
        int cant = fibo(tmp->child->se_porto_bien);
        for(int i=0; i<cant; i++)
        {
            cout<<"Ingrese el regalo"<<endl;
            cin>>nombre;
            tmp->child->Regalos.push_back(agregargift(nombre));
        }
        cout<<" se agregaron los regalos"<<endl;
    }else if(tmp->child->se_porto_bien == 4)
    {
        string nombre;
        int cant = fibo(tmp->child->se_porto_bien);
        for(int i=0; i<cant; i++)
        {
            cout<<"Ingrese el regalo"<<endl;
            cin>>nombre;
            tmp->child->Regalos.push_back(agregargift(nombre));
        }
        cout<<" se agregaron los regalos"<<endl;
    }else if(tmp->child->se_porto_bien == 5)
    {
        string nombre;
        int cant = fibo(tmp->child->se_porto_bien);
        for(int i=0; i<cant; i++)
        {
            cout<<"Ingrese el regalo"<<endl;
            cin>>nombre;
            tmp->child->Regalos.push_back(agregargift(nombre));
        }
        cout<<" se agregaron los regalos"<<endl;
    }else if(tmp->child->se_porto_bien == 6)
    {
        string nombre;
        int cant = fibo(tmp->child->se_porto_bien);
        for(int i=0; i<cant; i++)
        {
            cout<<"Ingrese el regalo"<<endl;
            cin>>nombre;
            tmp->child->Regalos.push_back(agregargift(nombre));
        }
        cout<<" se agregaron los regalos"<<endl;
    }else if(tmp->child->se_porto_bien == 7)
    {
        string nombre;
        int cant = fibo(tmp->child->se_porto_bien);
        for(int i=0; i<cant; i++)
        {
            cout<<"Ingrese el regalo"<<endl;
            cin>>nombre;
            tmp->child->Regalos.push_back(agregargift(nombre));
        }
        cout<<" se agregaron los regalos"<<endl;
    }else if(tmp->child->se_porto_bien == 8)
    {
        string nombre;
        int cant = fibo(tmp->child->se_porto_bien);
        for(int i=0; i<cant; i++)
        {
            cout<<"Ingrese el regalo"<<endl;
            cin>>nombre;
            tmp->child->Regalos.push_back(agregargift(nombre));
        }
        cout<<" se agregaron los regalos"<<endl;
    }else if(tmp->child->se_porto_bien == 9)
    {
        string nombre;
        int cant = fibo(tmp->child->se_porto_bien);
        for(int i=0; i<cant; i++)
        {
            cout<<"Ingrese el regalo"<<endl;
            cin>>nombre;
            tmp->child->Regalos.push_back(agregargift(nombre));
        }
        cout<<" se agregaron los regalos"<<endl;
    }else if(tmp->child->se_porto_bien == 10)
    {
        string nombre;
        int cant = fibo(tmp->child->se_porto_bien);
        for(int i=0; i<cant; i++)
        {
            cout<<"Ingrese el regalo"<<endl;
            cin>>nombre;
            tmp->child->Regalos.push_back(agregargift(nombre));
        }
        cout<<" se agregaron los regalos"<<endl;
    }
}



bool arbol::buscarKid(string nom)
{


}

int arbol::hash(string nom)
{
    int hash = 0, strlen = nom.length(), i;
    char character;
    if (strlen == 0)
        return hash;
    for (i = 0; i < strlen; i++)
    {
        character = nom[i];
        hash = (31 * hash) + int(character);
    }
    return hash;
}


bool arbol::insert(string nom, int status, int longi, int lati, int edad)
{
    int k = hash(nom);
    cout<< k <<endl;
        if (root == NULL)
        {
            root = new nodo(t, true);
            root->child->nombre = nom;
            root->child->se_porto_bien = status;
            root->child->longitud = longi;
            root->child->latitud = lati;
            root->child->edad = edad;
            root->llaves[0] = k;
            root->c = 1;
            return true;
        }
        else
        {
            if(root->c == 3*t-1)
            {
                nodo *s = new nodo(t, false);
                s->child->nombre = nom;
                s->child->se_porto_bien = status;
                s->child->longitud = longi;
                s->child->latitud = lati;
                s->child->edad = edad;


                s->ptr[0] = root;


                s->splitChild(0, root);

                int i = 0;
                if (s->llaves[0] < k)
                    i++;
                s->ptr[i]->insertNonFull(k,nom,status,longi,lati,edad);
                root = s;
            }
            else
            {
                root->insertNonFull(k,nom,status,longi,lati,edad);
                return true;
            }
        }

        return false;
}

