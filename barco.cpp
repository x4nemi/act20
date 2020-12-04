#include "barco.h"

using namespace std;

Barco::Barco() { }

Barco::Barco(const string& id, const float& c){
    this->id = id;
    combustible = c;
    velocidad = 0;
    armadura = 100.0;
}

void Barco::setID(const string& i){
    id = i;
}

void Barco::setCombustible(const float& c){
    combustible = c;
}

void Barco::setVelocidad(const int& v){
    velocidad = v;
}

void Barco::setArmadura(const float& a){
    armadura = a;
}

string Barco::getID(){
    return id;
}

float Barco::getCombustible() const{
    return combustible;
}

int Barco::getVelocidad(){
    return velocidad;
}

float Barco::getArmadura(){
    return armadura;
}

void Barco::pushGuerrero(const Guerrero& g){
    pilaGuerreros.push(g);
}

void Barco::popGuerrero(){
    pilaGuerreros.pop();
}

Guerrero Barco::getTopeGuerrero(){
    return pilaGuerreros.top();
}