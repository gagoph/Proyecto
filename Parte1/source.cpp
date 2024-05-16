#include<iostream>
#include "headers.h"
using namespace std;

int main() {

    //AMBIENTES PRECARGADOS
    ambientes* amb1 = nuevoAmbiente("Gliphtor");
    ambientes* amb2 = nuevoAmbiente("Glimphor");
    ambientes* amb3 = nuevoAmbiente("Xylo-9");
    ambientes* amb4 = nuevoAmbiente("Quasar");
    ambientes* amb5 = nuevoAmbiente("Nubosis");
    ambientes* amb6 = nuevoAmbiente("Cronos-7");
    insertarAmbiente(&amb1, amb2);
    insertarAmbiente(&amb1, amb3);
    insertarAmbiente(&amb1, amb4);
    insertarAmbiente(&amb1, amb5);
    insertarAmbiente(&amb1, amb6);

    //ESPECIES PRECARGADAS
    especies* esp1 = nuevaEspecie("Zorblax", 7.5, "Gliphtor");
    especies* esp2 = nuevaEspecie("Glimphtorians", 9.2, "Glimphor");
    especies* esp3 = nuevaEspecie("Xyloquarks", 4.7, "Xylo-9");
    especies* esp4 = nuevaEspecie("Plasmoides", 6.8, "Quasar");
    especies* esp5 = nuevaEspecie("Nebulites", 5.1, "Nubosis");
    especies* esp6 = nuevaEspecie("Quantumites", 11.5, "Cronos-7");
    insertarEspecie(&esp1, esp2);
    insertarEspecie(&esp1, esp3);
    insertarEspecie(&esp1, esp4);
    insertarEspecie(&esp1, esp5);
    insertarEspecie(&esp1, esp6);

    //ACCESORIOS PRECARGADOS
    accesorio* acc1 = nuevoAccesorio("Espada de las Estrellas", "Ataque", 50, 5);
    accesorio* acc2 = nuevoAccesorio("Amuleto de la Resiliencia", "Defensa", 30, 5);
    accesorio* acc3 = nuevoAccesorio("Botas del Caminante", "Supervivencia", 20, 8);
    accesorio* acc4 = nuevoAccesorio("Anillo de la Vitalidad", "Acondicionamiento", 0, 0);
    accesorio* acc5 = nuevoAccesorio("Capa de las Sombras", "Defensa", 25, 6);
    accesorio* acc6 = nuevoAccesorio("Gafas de Clarividencia", "Supervivencia", 15, 5);
    insertarAccesorio(&acc1, acc2);
    insertarAccesorio(&acc1, acc3);
    insertarAccesorio(&acc1, acc4);
    insertarAccesorio(&acc1, acc5);
    insertarAccesorio(&acc1, acc6);

    //SOLDADOS PRECARGADOS
    soldados* sol1 = nuevoSoldado("Zephyr", "Zorblax", 7.5, "Gliphtor", 1);
    soldados* sol2 = nuevoSoldado("Astrum", "Glimphtorians", 9.2, "Glimphor", 2);
    soldados* sol3 = nuevoSoldado("Quixar", "Xyloquarks", 4.7, "Xylo-9", 2);
    soldados* sol4 = nuevoSoldado("Ignis", "Plasmoides", 6.8, "Quasar", 1);
    soldados* sol5 = nuevoSoldado("Nebulon", "Nebulites", 5.1, "Nubosis", 1);
    soldados* sol6 = nuevoSoldado("Zyra", "Quantumites", 11.5, "Cronos-7", 2);
    insertarSoldado(&sol1, sol2);
    insertarSoldado(&sol1, sol3);
    insertarSoldado(&sol1, sol4);
    insertarSoldado(&sol1, sol5);
    insertarSoldado(&sol1, sol6);


    int num, num1, num2, num3, num3_1, num4;

    do {
        cout << "1. Gestionar especies" << endl;
        cout << "2. Gestionar accesorios" << endl;
        cout << "3. Gestionar soldados" << endl; 
        cout << "4. Gestionar ambientes" << endl;
        cout << "5. Batalla" << endl;
        cout << "6. Score" << endl;
        cout << "7. Terminar programa" << endl;
        cout << " " << endl;
        cin >> num;
        cout << endl;

        switch(num) {
        case 1: 
            cout << "1. Crear/Agregar especies" << endl;
            cout << "2. Modificar especies" << endl;
            cout << "3. Eliminar especies" << endl;
            cout << "4. Mostrar especies" << endl;
            cout << "5. Regresar al menu principal" << endl;
            cout << " " << endl;
            cin >> num1;
            cout << endl;

            switch(num1) {
            case 1: {
                //Crea o agrega especies
                string nombre;
                int energia;
                string ambiente;

                cout << "Ingrese el nombre: ";
                cin >> nombre;
                cout << "Ingrese la energia: ";
                cin >> energia;
                cout << "Ingrese un ambiente de los mostrados: " << endl;
                cout << endl;
                mostrarAmbientes(amb1);
                cout << endl;
                cout << "- ";
                cin >> ambiente;
                cout << endl;
                if (buscarAmbiente(amb1, ambiente)) {
                    especies* e = nuevaEspecie(nombre, energia, ambiente);
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

                    cout << "Indique el numero del campo que desea cambiar?: " << endl;
                    cin >> numx;

                    switch (numx) {
                    case 1:
                        //Modificar Nombre

                        cout << "Indica el nuevo nombre: ";
                        cin >> nuevoNombre;

                        modificarNombreEspecies(buscarEspecie(esp1, nombre), nuevoNombre);
                    break;
                    case 2:
                        //Modificar Energia

                        cout << "Indica la nueva cantidad de energia: ";
                        cin >> nuevaEnergia;

                        modificarEnergiaEspecies(buscarEspecie(esp1, nombre), nuevaEnergia);
                    break;
                    case 3:
                        //Modificar Ambiente

                        cout << "Indica el nuevo ambiente: ";
                        cin >> nuevoAmbiente;

                        modificarAmbienteEspecies(buscarEspecie(esp1, nombre), nuevoAmbiente);
                    break;
                    }
                }
                else {
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
            cout << "1. Crear/Agregar accesorios" << endl;
            cout << "2. Modificar accesorios" << endl;
            cout << "3. Eliminar eccesorios" << endl;
            cout << "4. Mostrar accesorios" << endl;
            cout << "5. Regresar al menu principal" << endl;
            cout << " " << endl;
            cin >> num2;

            switch(num2) {
            case 1: {
                //Crea o agrega accesorios
                string nombre;
                string tipo;
                int valor;
                int consumo;

                cout << "Ingrese el nombre: ";
                cin >> nombre;
                cout << "Ingrese el tipo: ";
                cin >> tipo;
                cout << "Ingrese el valor: ";
                cin >> valor;
                cout << "Ingrese el consumo: ";
                cin >> consumo;
                cout << endl;

                accesorio* a = nuevoAccesorio(nombre, tipo, valor, consumo);
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

                cout << "Indique el nombre del accesorio que deseas modificar: ";
                cin >> nombre;

                if (buscarAccesorio(acc1, nombre)) {
                    mostrarUnAccesorio(buscarAccesorio(acc1, nombre));

                    cout << "Indique el numero del campo que desea cambiar?: " << endl;
                    cin >> numx;

                    switch (numx) {
                    case 1:
                        //Modificar Nombre
                        cout << "Indica el nuevo nombre: ";
                        cin >> nuevoNombre;

                        modificarNombreAccesorio(buscarAccesorio(acc1, nombre), nuevoNombre);
                    break;
                    case 2:
                        //Modificar Tipo
                        cout << "Indica el nuevo tipo: ";
                        cin >> nuevoTipo;

                        modificarTipoAccesorio(buscarAccesorio(acc1, nombre), nuevoTipo);
                    break;
                    case 3:
                        //Modificar Valor

                        cout << "Indica el nuevo valor: ";
                        cin >> nuevoValor;

                        modificarValorAccesorio(buscarAccesorio(acc1, nombre), nuevoValor);
                    break;
                    case 4:
                        //Modificar Consumo
                        cout << "Indica el nuevo consumo: ";
                        cin >> nuevoConsumo;

                        modificarConsumoAccesorio(buscarAccesorio(acc1, nombre), nuevoConsumo);
                    break;
                    }
                }
                else {
                    cout << "No existe un accesorio con ese nombre." << endl;
                    cout << endl;
                }
            }
            break;
            case 3: {
                //Elmina accesorios
                string nombre;
                cout << "Indique el nombre de la especie que quiere eliminar: ";
                cin >> nombre;

                eliminarAccesorio(&acc1, buscarAccesorio(acc1, nombre));
                cout << endl;
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
            cout << "1. Crear/Agregar soldados" << endl;
            cout << "2. Modificar soldados" << endl;
            cout << "3. Eliminar soldados" << endl;
            cout << "4. Mostrar soldados" << endl;
            cout << "5. Gestionar mochila" << endl;
            cout << "6. Regresar al menu principal" << endl;
            cout << " " << endl;
            cin >> num3;

            switch(num3) {
            case 1: {
                //Crea o agrega soldados
                string nombre;
                string especie;
                float energia;
                string ambiente;
                int fidelidad;


                cout << "Ingrese el nombre: ";
                cin >> nombre;
                cout << "Ingrese la fidelidad (1 Humanos, 2 Alienigenas): ";
                cin >> fidelidad;
                cout << "Ingrese una especie de las mostradas: " << endl;
                cout << endl;
                mostrarTodasEspecies(esp1);
                cout << endl;
                cout << "- ";
                cin >> especie;
                cout << endl;
                if (buscarEspecie(esp1, especie)) {
                    energia = buscarEspecie(esp1, especie)->energia;
                    ambiente = buscarEspecie(esp1, especie)->ambiente;
                    soldados* s = nuevoSoldado(nombre, especie, energia, ambiente, fidelidad);
                    insertarSoldado(&sol1, s);
                }
                else {
                    cout << "Ninguna especie coincide con la ingresada." << endl;
                    cout << endl;
                }
            }
            break;
            case 2: 
                //Modifica las soldados
                cout << "MODIFICAR SOLDADOS" << endl;
            break;
            case 3: 
                //Elimina las soldados
                cout << "ELIMINAR SOLDADOS" << endl;
            break;
            case 4: {
                //Muestra los soldados
                mostrarTodosSoldados(sol1);
            }
            break;
            case 5: 
                cout << "1. Agregar 5 accesorios" << endl;
                cout << "2. Eliminar accesorios" << endl;
                cout << "3. Mostrar accesorios en la mochila" << endl;
                cout << "4. Regresar al menu principal" << endl;
                cout << " " << endl;
                cin >> num3_1;

                switch(num3_1) {

                    case 1: 
                        //Agrega 5 accesorios
                        cout << "AGREGAR 5 ACCESORIOS" << endl;
                    break;
                    case 2: 
                        //Elimina accesorios
                        cout << "ELIMINA ACCESORIOS" << endl;
                    break;
                    case 3: 
                        //Muestra accesorios
                        cout << "MOSTRAR ACCESORIOS" << endl;
                    break;
                    case 4: 
                        //Devolver al menu principal
                        cout << "DEVOLVER AL MENU PRINCIPAL" << endl;
                    break;
                }
                break;
            case 6: 
                //Devolver al menu principal
                cout << "DEVOLVER AL MENU PRINCIPAL" << endl;
                break;
        }
        break;
        case 4: 
            cout << "1. Crear/Agregar ambientes" << endl;
            cout << "2. Eliminar ambientes" << endl;
            cout << "3. Mostrar ambientes" << endl;
            cout << "4. Regresar al menu principal" << endl;
            cout << " " << endl;
            cin >> num4;
            cout << endl;

            switch(num4) {
            case 1: {
                //Crea o agrega ambientes
                string nombre;

                cout << "Ingrese el nombre: ";
                cin >> nombre;
                cout << endl;

                ambientes *amb = nuevoAmbiente(nombre);
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
            case 4: 
                //Devolver al menu principal
                cout << endl;
            break;
            }
            break;
        case 5: 
            //Batalla
            cout << "BATALLA" << endl;
            break;
        case 6: 
            //Score
            cout << "MOSTRAR SCORE";
            break;
        } 

    } while (num != 7);
}
