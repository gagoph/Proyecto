#include<iostream>
#include<string>
#include "header.h"
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main() {

    int cantidad;
    string linea;
    string x;

    //LECTURA ARCHIVOS
    //Cabeza ambientes
    ambientes* amb1 = nuevoAmbiente("Gliphtor");
    //Lectura del ambiente
    ifstream archivoAmbientes("ambiente.inv");
    if (!archivoAmbientes.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }
    archivoAmbientes >> cantidad;
    archivoAmbientes.ignore();
    while (getline(archivoAmbientes, linea)) {
        ambientes* ambiente;
        if (linea == "--");
        else {
            string nombre;
            nombre = linea;
            ambientes* nuevo = nuevoAmbiente(nombre);
            insertarAmbiente(&amb1, nuevo);
        }
    }
    archivoAmbientes.close();

    //Cabeza especies
    especies* esp1 = nuevaEspecie("Zorblax", 7.5, buscarAmbiente(amb1, "Gliphtor"));
    //Lectura de las especies
    ifstream archivoEspecies("especies.inv");
    if (!archivoEspecies.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }
    archivoEspecies >> cantidad;
    archivoEspecies.ignore();
    for (int i = 0; i < cantidad; i++) {
        especies* especie;
        int nuevaEnergia = 0;
        getline(archivoEspecies, linea);
        x = linea;
        getline(archivoEspecies, linea); 
        string nuevoNombre = linea;

        getline(archivoEspecies, linea); 
        size_t found = linea.find(":");
        if (found!= string::npos) {
            string energiaStr = linea.substr(found + 1);
            nuevaEnergia = stoi(energiaStr);
        }
        getline(archivoEspecies, linea); 
        found = linea.find(":");
        if (found!= string::npos) {
            string saludStr = linea.substr(found + 1);
            int nuevaSalud = stoi(saludStr);
        }
        getline(archivoEspecies, linea); 
        string nuevoNombreAmbiente = linea;
        ambientes* nuevoAmbiente = buscarAmbiente(amb1, nuevoNombreAmbiente);
        especies* nuevaEsp = nuevaEspecie(nuevoNombre, nuevaEnergia, nuevoAmbiente);
        insertarEspecie(&esp1, nuevaEsp);
    }
    archivoEspecies.close();

    //Cabeza accesorios
    accesorio* acc1 = nuevoAccesorio("Espada de las Estrellas", "Ataque", 50, "", 10, 0);
    ifstream archivoAccesorios("accesorios.inv");
    if (!archivoAccesorios.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }
    archivoAccesorios >> cantidad;
    archivoAccesorios.ignore();
    for(int i = 0; i < cantidad; i++) {
        accesorio* acc;
        string nuevoTipo;
        int nuevoValor;
        string nuevaRecuperacion;
        int nuevaEnergia;
        int nuevoContenedor;
        getline(archivoAccesorios, linea);
        x = linea;
        getline(archivoAccesorios, linea);
        string nuevoNombre = linea;
        getline(archivoAccesorios, linea);
        size_t found = linea.find(":");
        if (found!= string::npos) {
            string tipoStr = linea.substr(found + 1);
            nuevoTipo = tipoStr;
        }
        getline(archivoAccesorios, linea); 
        size_t found2 = linea.find(":");
        if (found2!= string::npos) {
            string valorStr = linea.substr(found2 + 1);
            nuevoValor = stoi(valorStr);
        }
        getline(archivoAccesorios, linea);
        size_t found3 = linea.find(":");
        if (found3!= string::npos) {
            string recuperacionStr = linea.substr(found3 + 1);
            nuevaRecuperacion = recuperacionStr;
        }
        getline(archivoAccesorios, linea); 
        size_t found5 = linea.find(":");
        if (found5!= string::npos) {
            string energiaStr = linea.substr(found5 + 1);
            nuevaEnergia = stoi(energiaStr);
        }
        getline(archivoAccesorios, linea); 
        size_t found4 = linea.find(":");
        if (found4!= string::npos) {
            string contenedorStr = linea.substr(found4 + 1);
            nuevoContenedor = stoi(contenedorStr);
        }
        accesorio* nuevoAcc = nuevoAccesorio(nuevoNombre, nuevoTipo, nuevoValor, nuevaRecuperacion, nuevaEnergia, nuevoContenedor);
        insertarAccesorio(&acc1, nuevoAcc);
    }
    archivoAccesorios.close();

    //Soldados Pre-cargados
    soldados* sol1 = nuevoSoldado("Zephyr", buscarEspecie(esp1, "Reptilianos"));
    soldados* sol2 = nuevoSoldado("Astrum", buscarEspecie(esp1, "Pleyadianos"));
    soldados* sol3 = nuevoSoldado("Quixar", buscarEspecie(esp1, "Andromedanos"));
    soldados* sol4 = nuevoSoldado("Ignis", buscarEspecie(esp1, "Ashtar"));
    soldados* sol5 = nuevoSoldado("Nebulon", buscarEspecie(esp1, "Marcianos"));
    soldados* sol6 = nuevoSoldado("Zyra", buscarEspecie(esp1, "Humanos"));
    insertarSoldado(&sol1, sol2);
    insertarSoldado(&sol1, sol3);
    insertarSoldado(&sol1, sol4);
    insertarSoldado(&sol1, sol5);
    insertarSoldado(&sol1, sol6);


    int num, num1, num2, num3, num3_1, num4;

    soldados* soldado_11 = nullptr;
    soldados* soldado_21 = nullptr;
    soldados* soldado_12 = nullptr;
    soldados* soldado_22 = nullptr;
    soldados* soldado_13 = nullptr;
    soldados* soldado_23 = nullptr;

    bool elegirSoldadosBatallaBool = false;
    bool ganador = false;

    do {
        cout << " ____  _  _  _  _  __    ___  ____  _____  _  _    ____  _  _  ____  ____    __   ____  ____  ____  ____  ____  ___  ____  ____  ____ \n";
        cout << "(_  _)( \\( )( \\/ )/__\\  / __)(_  _)(  _  )( \\( )  ( ___)( \\/ )(_  _)(  _ \\  /__\\ (_  _)( ___)(  _ \\(  _ \\( ___)/ __)(_  _)(  _ \\( ___)\n";
        cout << " _)(_  )  (  \\  //(__)\\ \\__ \\ _)(_  )(_)(  )  (    )__)  )  (   )(   )   / /(__)\\  )(   )__)  )   / )   / )__) \\__ \\  )(   )   / )__) \n";
        cout << "(____)(_)\\_)  \\/(__)(__)(___/(____)(_____)(_)\\_)  (____)(_\\/_\\_) (__) (_\\_)(__)(__)(__) (____)(_\\/_\\_)(_\\_)(____)(___/ (__) (_\\_)(____)\n";
        cout << "" << endl;
        cout << "                                                           _..._\n";
        cout << "                                                         .'     '.\n";
        cout << "                                                        / \\     / \\\n";
        cout << "                                                       (  |     |  )\n";
        cout << "                                                       (`\"`  \"  `\"`)\n";
        cout << "                                                        \\         /\n";
        cout << "                                                         \\  ___  /\n";
        cout << "                                                          '.___.'\n";
        cout << endl;
        cout << "                                                   1. Gestionar especies" << endl;
        cout << "                                                   2. Gestionar accesorios" << endl;
        cout << "                                                   3. Gestionar soldados" << endl;
        cout << "                                                   4. Gestionar ambientes" << endl;
        cout << "                                                   5. Batalla" << endl;
        cout << "                                                   6. Terminar programa" << endl;
        cout << " " << endl;
        cin >> num;
        cout << endl;

        switch (num) {
        case 1:
            cout << "                                                   1. Crear/Agregar especies" << endl;
            cout << "                                                   2. Modificar especies" << endl;
            cout << "                                                   3. Eliminar especies" << endl;
            cout << "                                                   4. Mostrar especies" << endl;
            cout << "                                                   5. Regresar al menu principal" << endl;
            cout << " " << endl;
            cin >> num1;
            cout << endl;

            switch (num1) {
            case 1: {
                //Crea o agrega especies
                string nombre;
                int energia;
                string ambiente;

                cout << "Ingrese el nombre: ";
                cin >> nombre;
                cout << "Ingrese la energia (numero): ";
                cin >> energia;
                cout << "Ingrese un nombre de los ambientes mostrados: " << endl;
                cout << endl;
                mostrarAmbientes(amb1);
                cout << endl;
                cout << "- ";
                cin >> ambiente;
                cout << endl;
                if (buscarAmbiente(amb1, ambiente)) {
                    especies* e = nuevaEspecie(nombre, energia, buscarAmbiente(amb1, ambiente));
                    insertarEspecie(&esp1, e);
                }
                else {
                    cout << "Ningun ambiente coincide con el ingresado." << endl;
                    cout << endl;
                }
            }
                break;
            case 2: {
                //Modifica las especies
                string nombre;
                string nuevoNombre;
                int nuevaEnergia;
                string nuevoAmbiente;
                int numx = 0;
                cout << "Indique el nombre de la especie que se quiere modificar: ";
                cin >> nombre;

                if (buscarEspecie(esp1, nombre)) {
                    mostrarUnaEspecie(buscarEspecie(esp1, nombre));

                    cout << "Indique el numero del campo que desea cambiar?: ";
                    cin >> numx;
                    cout << endl;

                    switch (numx) {
                    case 1:
                        //Modificar Nombre

                        cout << "Indica el nuevo nombre: ";
                        cin >> nuevoNombre;
                        cout << endl;

                        modificarNombreEspecies(buscarEspecie(esp1, nombre), nuevoNombre);
                        break;
                    case 2:
                        //Modificar Energia

                        cout << "Indica la nueva cantidad de energia: ";
                        cin >> nuevaEnergia;
                        cout << endl;

                        modificarEnergiaEspecies(buscarEspecie(esp1, nombre), nuevaEnergia);
                        break;
                    case 3:
                        //Modificar Ambiente

                        cout << "Indica el nuevo ambiente: ";
                        cin >> nuevoAmbiente;
                        cout << endl;

                        if (buscarAmbiente(amb1, nuevoAmbiente)) {
                            modificarAmbienteEspecies(buscarEspecie(esp1, nombre), buscarAmbiente(amb1, nuevoAmbiente));
                        }
                        else {
                            cout << "El ambiente ingresado no existe" << endl;
                            cout << endl;
                        }
                        break;
                    }
                }
                else {
                    cout << endl;
                    cout << "No existe una especie con ese nombre." << endl;
                    cout << endl;
                }
            }
                break;
            case 3: {
                //Eliminar especies
                string nombre;
                cout << "Indique el nombre de la especie que quiere eliminar: ";
                cin >> nombre;

                eliminarEspecie(&esp1, buscarEspecie(esp1, nombre));

                cout << endl;
            }
                break;
            case 4: {
                //Mostrar especies
                mostrarTodasEspecies(esp1);
            }
                break;
            case 5:
                //Devolver al menu principal
                cout << endl;
                break;
            }
            break;
        case 2:
            cout << "                                                   1. Crear/Agregar accesorios" << endl;
            cout << "                                                   2. Modificar accesorios" << endl;
            cout << "                                                   3. Eliminar eccesorios" << endl;
            cout << "                                                   4. Mostrar accesorios" << endl;
            cout << "                                                   5. Regresar al menu principal" << endl;
            cout << " " << endl;
            cin >> num2;

            switch (num2) {
            case 1: {
                //Crea o agrega accesorios
                string nombre;
                string tipo;
                int valor;
                int consumo;
                string recuperacion;
                int contenedor;

                cout << endl;
                cout << "Ingrese el nombre: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese el tipo: ";
                cin >> tipo;
                cout << "Ingrese el valor (numero): ";
                cin >> valor;
                cout << "Ingrese la recuperacion si la hay: ";
                cin >> recuperacion;
                cout << "Ingrese el consumo (numero): ";
                cin >> consumo;
                cout << "Ingrese el valor del contenedor si lo hay: ";
                cin >> contenedor;
                cout << endl;

                accesorio* a = nuevoAccesorio(nombre, tipo, valor, recuperacion, consumo, contenedor);
                insertarAccesorio(&acc1, a);
            }
                break;
            case 2: {
                //Modifica accesorios
                string nombre;
                string nuevoNombre;
                string nuevoTipo;
                int nuevoValor;
                int nuevoConsumo;
                int numx = 0;

                cout << endl;
                cout << "Indique el nombre del accesorio que deseas modificar: ";
                cin.ignore();
                getline(cin, nombre);
                
                if (buscarAccesorio(acc1, nombre)) {
                    mostrarUnAccesorio(buscarAccesorio(acc1, nombre));

                    cout << "Indique el numero del campo que desea cambiar?: ";
                    cin >> numx;
                    cout << endl;

                    switch (numx) {
                    case 1:
                        //Modificar Nombre
                        cout << "Indica el nuevo nombre: ";
                        cin.ignore();
                        getline(cin, nuevoNombre);
                        cout << endl;

                        modificarNombreAccesorio(buscarAccesorio(acc1, nombre), nuevoNombre);
                        break;
                    case 2:
                        //Modificar Tipo
                        cout << "Indica el nuevo tipo: ";
                        cin >> nuevoTipo;
                        cout << endl;

                        modificarTipoAccesorio(buscarAccesorio(acc1, nombre), nuevoTipo);
                        break;
                    case 3:
                        //Modificar Valor

                        cout << "Indica el nuevo valor: ";
                        cin >> nuevoValor;
                        cout << endl;

                        modificarValorAccesorio(buscarAccesorio(acc1, nombre), nuevoValor);
                        break;
                    case 4:
                        //Modificar Consumo
                        cout << "Indica el nuevo consumo: ";
                        cin >> nuevoConsumo;
                        cout << endl;

                        modificarConsumoAccesorio(buscarAccesorio(acc1, nombre), nuevoConsumo);
                        break;
                    }
                }
                else {
                    cout << endl;
                    cout << "No existe un accesorio con ese nombre." << endl;
                    cout << endl;
                }
            }
                break;
            case 3: {
                //Elmina accesorios
                string nombre;
                cout << endl;
                cout << "Indique el nombre del accesorio que quiere eliminar: ";
                cin.ignore();
                getline(cin, nombre);

                if(buscarAccesorio(acc1, nombre)) {
                    eliminarAccesorio(&acc1, buscarAccesorio(acc1, nombre));
                    cout << endl;
                }
                else {
                    cout << endl;
                    cout << "El accesorio ingresado no existe." << endl;
                    cout << endl;
                }
            }
            break;
            case 4: {
                //Mostrar Accesorios
                mostrarTodosAccesorios(acc1);
            }
            break;
            case 5:
                //Devolver al menu principal
                cout << endl;
            break;
            }
            break;
        case 3:
            cout << "                                                   1. Crear/Agregar soldados" << endl;
            cout << "                                                   2. Modificar soldados" << endl;
            cout << "                                                   3. Eliminar soldados" << endl;
            cout << "                                                   4. Mostrar soldados" << endl;
            cout << "                                                   5. Regresar al menu principal" << endl;
            cout << " " << endl;
            cin >> num3;

            switch (num3) {
            case 1: {
                //Crea o agrega soldados
                string nombre;
                string especie;
                int fidelidad;

                cout << endl;
                cout << "Ingrese el nombre: ";
                cin >> nombre;
                cout << "Ingrese una especie de las mostradas: " << endl;
                cout << endl;
                mostrarTodasEspecies(esp1);
                cout << endl;
                cout << "- ";
                cin >> especie;
                cout << endl;
                if (buscarEspecie(esp1, especie)) {
                    soldados* s = nuevoSoldado(nombre, buscarEspecie(esp1, especie));
                    insertarSoldado(&sol1, s);
                }
                else {
                    cout << "Ninguna especie coincide con la ingresada." << endl;
                    cout << endl;
                }
            }
            break;
            case 2: {
                //Modifica los soldados
                string nombre;
                string nuevoNombre;
                string nuevaEspecie;
                int nuevaFidelidad;
                int numx = 0;

                cout << endl;
                cout << "Indique el nombre del soldado que deseas modificar: ";
                cin.ignore();
                getline(cin, nombre);

                if (buscarSoldados(sol1, nombre)) {
                    mostrarUnSoldado(buscarSoldados(sol1, nombre));

                    cout << "Indique el numero del campo que desea cambiar?: ";
                    cin >> numx;
                    cout << endl;

                    switch (numx) {
                    case 1:
                        //Modificar Nombre
                        cout << "Indica el nuevo nombre: ";
                        cin.ignore();
                        getline(cin, nuevoNombre);
                        cout << endl;

                        modificarNombreSoldado(buscarSoldados(sol1, nombre), nuevoNombre);
                    break;
                    case 2:
                        //Modificar Especie
                        cout << "Indica la nueva especie: ";
                        cin >> nuevaEspecie;
                        cout << endl;

                        modificarEspecieSoldado(esp1, buscarSoldados(sol1, nombre), nuevaEspecie);
                    break;
                    case 3: 
                        //Modificar Especie
                        cout << "Indica la nueva especie: ";
                        cin >> nuevaEspecie;
                        cout << endl;

                        modificarEspecieSoldado(esp1, buscarSoldados(sol1, nombre), nuevaEspecie);
                    break;
                    case 4: 
                        //Modificar Especie
                        cout << "Indica la nueva especie: ";
                        cin >> nuevaEspecie;
                        cout << endl;

                        modificarEspecieSoldado(esp1, buscarSoldados(sol1, nombre), nuevaEspecie);
                    break;
                    case 5:
                        //Modificar Fidelidad

                        cout << "Indica el nuevo valor de fidelidad (1 Humanos, 2 Alienigenas): ";
                        cin >> nuevaFidelidad;
                        cout << endl;

                        modificarFidelidadSoldado(buscarSoldados(sol1, nombre), nuevaFidelidad);
                    break;
                    }
                }
                else {
                    cout << endl;
                    cout << "No existe un soldado con ese nombre." << endl;
                    cout << endl;
                }
            }
            break;
            case 3: {
                //Elimina las soldados
                string nombre;

                cout << "Indique el nombre del soldado que desea eliminar: ";
                cin >> nombre;

                eliminarSoldado(&sol1, buscarSoldados(sol1, nombre));
            }
            break;
            case 4: {
                //Muestra los soldados
                cout << endl;
                mostrarTodosSoldados(sol1);
            }
                break;
            case 5:
                //Regresa al menu principal
                cout << endl;
            break;
            }
        break;
        case 4:
            cout << "                                                   1. Crear/Agregar ambientes" << endl;
            cout << "                                                   2. Eliminar ambientes" << endl;
            cout << "                                                   3. Mostrar ambientes" << endl;
            cout << "                                                   4. Modifica los ambientes" << endl;
            cout << "                                                   5. Regresar al menu principal" << endl;
            cout << " " << endl;
            cin >> num4;
            cout << endl;

            switch (num4) {
            case 1: {
                //Crea o agrega ambientes
                string nombre;

                cout << "Ingrese el nombre: ";
                cin >> nombre;
                cout << endl;

                ambientes* amb = nuevoAmbiente(nombre);
                insertarAmbiente(&amb1, amb);
            }
            break;
            case 2: {
                //Elimina ambientes
                string nombre;
                cout << "Indique el nombre del ambiente que quiere eliminar: ";
                cin >> nombre;

                if (buscarAmbiente(amb1, nombre)) {
                    eliminarAmbiente(&amb1, buscarAmbiente(amb1, nombre));
                    cout << endl;
                }
                else {
                    cout << "No existe el ambiente ingresado." << endl;
                    cout << endl;
                }
            }
            break;
            case 3: {
                //Muestra los ambientes
                mostrarAmbientes(amb1);
            }
            break;
            case 4: {
                //Modifica los ambientes
                string nombre;
                string nuevoNombre;

                cout << "Indica el nombre de la especie que deseas modificar: ";
                cin >> nombre;
                cout << endl;
                if (buscarAmbiente(amb1, nombre)) {
                    cout << "Indica el nuevo nombre: ";
                    cin >> nuevoNombre;
                    cout << endl;
                    modificarAmbiente(buscarAmbiente(amb1, nombre), nuevoNombre);
                }
                else {
                    cout << "No existe un ambiente con ese nombre" << endl;
                    cout << endl;
                }
            }
            break;
            case 5:
                //Devolver al menu principal
                cout << endl;
            break;
            }
        break;
        case 5: {
            elegirSoldadosBatalla(&elegirSoldadosBatallaBool, sol1, acc1, soldado_11, soldado_21, soldado_12, soldado_22, soldado_13, soldado_23);
            if (elegirSoldadosBatallaBool) {
                asignarFidelidad(soldado_11, soldado_21, soldado_12, soldado_22, soldado_13, soldado_23);
                ambientes* ambienteR = ambienteRandom(amb1);
                cout << endl;
                cout << "El ambiente donde ocurrira la batalla es : " << ambienteR->nombre << endl;
                cout << endl;
                batalla(acc1, sol1, amb1, &ganador, soldado_11, soldado_21, soldado_12, soldado_22, soldado_13, soldado_23);
            }
            else {
                cout << endl;
            }
        }
        break;
        }

    } while (num != 6);

}
