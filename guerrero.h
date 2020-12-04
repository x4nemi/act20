#ifndef GUERRERO_H
#define GUERRERO_H

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

class Guerrero{
    private:
        string id;
        int salud;
        float fuerza;
        float defensa;
        string tipoGuerrero;

    public:
        Guerrero();
        Guerrero(const string&, const int&, const float&, const float&, const string&);

        void setID(const string&);
        void setSalud(const int&);
        void setFuerza(const float&);
        void setDefensa(const float&);
        void setTipo(const string&);

        string getID();
        int getSalud();
        float getFuerza();
        float getDefensa();
        string getTipo();
};

#endif 