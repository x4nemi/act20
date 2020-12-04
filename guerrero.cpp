#include "guerrero.h"
#include <stdlib.h>

using namespace std;

Guerrero::Guerrero() { }

Guerrero::Guerrero(const string& id, const int& salud, const float& fuerza, const float& defensa, const string& tipo){
    this->id = id;
    this->salud = salud;
    this->fuerza = fuerza;
    this->defensa = defensa;
    string tipos[] = {"Lancero", "Arquero", "Paladin", "Mago"};
    tipoGuerrero = tipos[rand() % 4];
}

void Guerrero::setID(const string& id){
    this->id = id;
}

void Guerrero::setSalud(const int& salud){
    this->salud = salud;
}

void Guerrero::setFuerza(const float& fuerza){
    this->fuerza = fuerza;
}

void Guerrero::setDefensa(const float& defensa){
    this->defensa = defensa;
}

void Guerrero::setTipo(const string& tipo){
    tipoGuerrero = tipo;
}

string Guerrero::getID(){
    return id;
}

int Guerrero::getSalud(){
    return salud;
}

float Guerrero::getFuerza(){
    return fuerza;
}

float Guerrero::getDefensa(){
    return defensa;
}

string Guerrero::getTipo(){
    return tipoGuerrero;
}