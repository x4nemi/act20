#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <list>

#include "barco.h"

using namespace std;

class Civilizacion{
    private:
        string nombre;
        list<Barco*> puerto;
    public:
        Civilizacion() { }
        Civilizacion(const string& n) : nombre(n) { }

        void agregarBarco(Barco*);
        void capturarBarco();
        void mostrarBarcos();
        Barco* buscarBarco(const string&);
        void eliminarID(const string&);
        void eliminarCombX(const float&);

        void menuCiv();
        
};

#endif