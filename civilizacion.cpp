#include "civilizacion.h"

using namespace std;

void Civilizacion::agregarBarco(Barco* b){
    puerto.push_back(b); //al final
}

void Civilizacion::menuCiv(){
    int opc;

    while(true){
        cout << "1. Agregar Barco" << endl;
        cout << "2. Mostrar todos los Barcos" << endl;
        cout << "3. Buscar barco" << endl;
        cout << "4. Eliminar" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opc; cin.ignore();

        if(!opc) break;

        cout << endl << endl;

        if(opc >= 2 and opc <= 4 and !puerto.size()){
            cout << "Aun no hay barcos capturados" << endl << endl;
            continue;
        }

        switch (opc){
        case 1:
            capturarBarco();
            cout << "Barco agregado...";
            break;
        case 2:
            mostrarBarcos();
            break;
        case 3:
        {
            string id;
            cout << "ID: ";
            getline(cin, id);

            Barco *barco = buscarBarco(id);
            if(barco == nullptr){
                cout << "Barco no encontrado";
            }
            else{
                cout << "Barco encontrado:" << endl;
                cout << left;
                cout << setw(10) << "ID";
                cout << setw(15) << "Combustible";
                cout << setw(15) << "Velocidad";
                cout << setw(15) << "Armadura" << endl;
                cout << *barco;

                Barco &b = *barco;
                b.menuBarco();
            }
        }
            break;
        case 4:
        {
            string op;
            cout << "a. Por ID" << endl;
            cout << "b. Por combustible menor a 'x' cantidad" << endl;
            cout << "Opcion: ";
            getline(cin, op);

            if(op == "a"){
                string id;
                cout << "ID: ";
                getline(cin, id);
                eliminarID(id);

                cout << "Eliminado(s)...";
            }
            else if(op == "b"){
                float c;
                cout << "Valor de X: ";
                cin >> c; cin.ignore();

                eliminarCombX(c);
                cout << "Eliminado(s)...";
            }else{
                cout << "Opcion incorrecta";
            }
        }
            break;
        default:
            cout << "Opcion incorrecta";
            break;
        }
        cout << endl << endl;
    }
}

void Civilizacion::capturarBarco(){
    string id;
    float combustible; 
    
    cout << "Id: ";
    getline(cin, id);
    
    cout << "Combustible: ";
    cin >> combustible; cin.ignore();

    Barco *b = new Barco(id, combustible);

    agregarBarco(b);
}

void Civilizacion::mostrarBarcos(){
    cout << left;
    cout << setw(10) << "ID";
    cout << setw(15) << "Combustible";
    cout << setw(15) << "Velocidad";
    cout << setw(15) << "Armadura" << endl;
    for(auto const &b : puerto){
        cout << *b << endl;
    }
}

Barco* Civilizacion::buscarBarco(const string& id){
    for(auto it = puerto.begin(); it != puerto.end(); it++){
        Barco *b = *it;

        if(id == b->getID()){
            return *it;
        }
    }
    return nullptr;

}

void Civilizacion::eliminarID(const string& id){
    for(auto it = puerto.begin(); it != puerto.end(); it++){
        Barco *b = *it;

        if(id == b->getID()){
            puerto.erase(it);
            break;
        }
    }
}

void Civilizacion::eliminarCombX(const float& x){
    puerto.remove_if([x](Barco *b){ return b->getCombustible() < x;});
}
