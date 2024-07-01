#include<iostream>
#include<vector>

using namespace std;

//AMBIENTES

struct ambientes {
    string nombre;
    ambientes* next;
};

ambientes* nuevoAmbiente(string nombre) {
    ambientes* nuevoAmbiente = new ambientes;
    nuevoAmbiente->nombre = nombre;
    nuevoAmbiente->next = NULL;

    return nuevoAmbiente;
}

void mostrarAmbientes(ambientes* amb) {
    cout << "Nombre: " << amb->nombre << endl;
    cout << endl;
    if (amb->next) {
        mostrarAmbientes(amb->next);
    }
}

void insertarAmbiente(ambientes** amb, ambientes* p) {
    ambientes* aux = *amb;
    while ((aux) && (aux->next)) {
        aux = aux->next;
    }
    aux->next = p;
}

ambientes* buscarAmbiente(ambientes* amb, string nombre) {
    ambientes* p = amb;
    while ((p) && (p->nombre != nombre)) {
        p = p->next;
    }
    return p;
}

void eliminarAmbiente(ambientes** p, ambientes* i) {
    ambientes* amb = *p;
    ambientes* aux;

    if (*p == i) {
        aux = *p;
        *p = (*p)->next;
        delete aux;

    }
    else {
        while (amb->next != NULL && amb->next != i) {
            amb = amb->next;

        }
        if (amb->next != NULL) {
            aux = amb->next;
            amb->next = amb->next->next;
            delete aux;

        }
    }
}

void modificarAmbiente(ambientes* a, string nombre) {
    a->nombre = nombre;
}


//ESPECIES

struct especies {
    string nombre;
    int energia;
    ambientes* ambiente;
    especies* next;
};

especies* nuevaEspecie(string nombre, int energia, ambientes* a) {
    especies* nuevaEspecie = new especies;
    nuevaEspecie->nombre = nombre;
    nuevaEspecie->energia = energia;
    nuevaEspecie->ambiente = a;
    nuevaEspecie->next = NULL;
    return nuevaEspecie;
}

void insertarEspecie(especies** e, especies* p) {
    especies* aux = *e;
    while ((aux) && (aux->next)) {
        aux = aux->next;
    }
    aux->next = p;
}

especies* buscarEspecie(especies* e, string nombre) {
    especies* p = e;
    while ((p) && (p->nombre != nombre)) {
        p = p->next;
    }
    return p;

}

void modificarNombreEspecies(especies* e, string nombre) {
    e->nombre = nombre;
}
void modificarEnergiaEspecies(especies* e, int energia) {
    e->energia = energia;
}
void modificarAmbienteEspecies(especies* e, ambientes* a) {
    e->ambiente = a;
}

void mostrarUnaEspecie(especies* e) {
    cout << " " << endl;
    cout << "Nombre: " << e->nombre << "\n";
    cout << "Energia: " << e->energia << "\n";
    cout << "Ambiente: " << e->ambiente->nombre << "\n";
    cout << " " << endl;
}

void mostrarTodasEspecies(especies* e) {
    cout << "Nombre: " << e->nombre << endl;
    cout << "Energia: " << e->energia << endl;
    cout << "Ambiente: " << e->ambiente->nombre << endl;
    cout << endl;
    if (e->next) {
        mostrarTodasEspecies(e->next);
    }
}

void eliminarEspecie(especies** p, especies* i) {
    especies* e = *p;
    especies* aux;

    if (*p == i) {
        aux = *p;
        *p = (*p)->next;
        delete aux;

    }
    else {
        while (e->next != NULL && e->next != i) {
            e = e->next;

        }
        if (e->next != NULL) {
            aux = e->next;
            e->next = e->next->next;
            delete aux;

        }
    }
}


//ACCESORIOS

struct accesorio {
    string nombre;
    string tipo;
    int valor = 0;
    string recuperacion = "";
    int consumo = 0;
    int contenedor = 0;
    accesorio* next;
};

accesorio* nuevoAccesorio(string nombre, string tipo, int valor, string recuperacion, int consumo, int contenedor) {
    accesorio* nuevoAccesorio = new accesorio;
    nuevoAccesorio->nombre = nombre;
    nuevoAccesorio->tipo = tipo;
    nuevoAccesorio->valor = valor;
    nuevoAccesorio->recuperacion = recuperacion;
    nuevoAccesorio->consumo = consumo;
    nuevoAccesorio->contenedor = contenedor;
    nuevoAccesorio->next = NULL;
    return nuevoAccesorio;
}

void insertarAccesorio(accesorio** a, accesorio* p) {
    accesorio* aux = *a;
    while ((aux) && (aux->next)) {
        aux = aux->next;
    }
    aux->next = p;
}


accesorio* buscarAccesorio(accesorio* a, string nombre) {
    accesorio* p = a;
    while ((p) && (p->nombre != nombre)) {
        p = p->next;
    }
    return p;
}

void modificarNombreAccesorio(accesorio* a, string nombre) {
    a->nombre = nombre;
}
void modificarTipoAccesorio(accesorio* a, string tipo) {
    a->tipo = tipo;
}
void modificarValorAccesorio(accesorio* a, int valor) {
    a->valor = valor;
}
void modificarConsumoAccesorio(accesorio* a, int consumo) {
    a->consumo = consumo;
}

void mostrarTodosAccesorios(accesorio* a) {
    cout << "Nombre: " << a->nombre << endl;
    cout << "Tipo: " << a->tipo << endl;
    cout << "Valor: " << a->valor << endl;
    cout << "Recuperacion: " << a->recuperacion << endl;
    cout << "Consumo: " << a->consumo << endl;
    cout << "Contenedor: " << a->contenedor << endl;
    cout << endl;
    if (a->next) {
        mostrarTodosAccesorios(a->next);
    }
}

void mostrarUnAccesorio(accesorio* a) {
    cout << endl;
    cout << "Nombre: " << a->nombre << endl;
    cout << "Tipo: " << a->tipo << endl;
    cout << "Valor: " << a->valor << endl;
    cout << "Consumo: " << a->consumo << endl;
    cout << endl;
}

void eliminarAccesorio(accesorio** p, accesorio* i) {
    accesorio* a = *p;
    accesorio* aux;

    if (*p == i) {
        aux = *p;
        *p = (*p)->next;
        delete aux;
    }
    else {
        while (a->next != NULL && a->next != i) {
            a = a->next;

        }
        if (a->next != NULL) {
            aux = a->next;
            a->next = a->next->next;
            delete aux;
        }
    }
}


//SOLDADOS

struct soldados {
    string nombre;
    especies* especie;
    int energia;
    ambientes *ambiente;
    int salud = 100;
    accesorio* mochila[5];
    int fidelidad = 0;
    soldados* next;
};

soldados* nuevoSoldado(string nombre, especies *e) {
    soldados* nuevoSoldado = new soldados;
    nuevoSoldado->nombre = nombre;
    nuevoSoldado->especie = e;
    nuevoSoldado->energia = e->energia;
    nuevoSoldado->ambiente = e->ambiente;
    nuevoSoldado->next = NULL;
    return nuevoSoldado;
}

void insertarSoldado(soldados** s, soldados* p) {
    soldados* aux = *s;
    while ((aux) && (aux->next)) {
        aux = aux->next;
    }
    aux->next = p;
}

soldados* buscarSoldados(soldados* s, string nombre) {
    soldados* p = s;
    while ((p) && (p->nombre != nombre)) {
        p = p->next;
    }
    return p;
}

void modificarNombreSoldado(soldados* s, string nombre) {
    s->nombre = nombre;
}
void modificarEspecieSoldado(especies* e, soldados* s, string nombre) {
    if (buscarEspecie(e, nombre)) {
        s->especie = buscarEspecie(e, nombre);
        s->energia = buscarEspecie(e, nombre)->energia;
        s->ambiente = buscarEspecie(e, nombre)->ambiente;
    }
    else {
        cout << "La especie indicada no existe." << endl;
    }
}
void modificarFidelidadSoldado(soldados* e, int fidelidad) {
    e->fidelidad = fidelidad;
}

void mostrarTodosSoldados(soldados* s) {
    cout << "Nombre: " << s->nombre << endl;
    cout << "Especie: " << s->especie->nombre << endl;
    cout << "Energia: " << s->energia << endl;
    cout << "Ambiente: " << s->ambiente->nombre << endl;
    cout << "Salud: " << s->salud << endl;
    cout << endl;
    if (s->next) {
        mostrarTodosSoldados(s->next);
    }
}

void mostrarUnSoldado(soldados* s) {
    cout << endl;
    cout << "Nombre: " << s->nombre << endl;
    cout << "Especie: " << s->especie->nombre << endl;
    cout << "Energia: " << s->energia << endl;
    cout << "Ambiente: " << s->ambiente->nombre << endl;
    cout << "Salud: " << s->salud << endl;
    cout << endl;
}

void eliminarSoldado(soldados** p, soldados* i) {
    soldados* e = *p;
    soldados* aux;

    if (*p == i) {
        aux = *p;
        *p = (*p)->next;
        delete aux;

    }
    else {
        while (e->next != NULL && e->next != i) {
            e = e->next;

        }
        if (e->next != NULL) {
            aux = e->next;
            e->next = e->next->next;
            delete aux;
        }
    }
}

bool agregarAccesoriosMochila(soldados* s, accesorio* a) {
    string a1 = "";
    string a2 = "";
    string a3 = "";
    string a4 = "";
    string a5 = "";
    cout << "Escribe el nombre del primer accesorio: ";
    cin.ignore();
    getline(cin, a1);
        if (buscarAccesorio(a, a1)) {
            s->mochila[0] = buscarAccesorio(a, a1);
            cout << endl;
            cout << "Escribe el nombre del segundo accesorio: ";
            getline(cin, a2);
            if (buscarAccesorio(a, a2)) {
                s->mochila[1] = buscarAccesorio(a, a2);
                cout << endl;
                cout << "Escribe el nombre del tercer accesorio: ";
                getline(cin, a3);
                if (buscarAccesorio(a, a3)) {
                    s->mochila[2] = buscarAccesorio(a, a3);
                    cout << endl;
                    cout << "Escribe el nombre del cuarto accesorio: ";
                    getline(cin, a4);
                    if (buscarAccesorio(a, a4)) {
                        s->mochila[3] = buscarAccesorio(a, a4);
                        cout << endl;
                        cout << "Escribe el nombre del quinto accesorio: ";
                        getline(cin, a5);
                        if (buscarAccesorio(a, a5)) {
                            s->mochila[4] = buscarAccesorio(a, a5);
                            return true;
                        }
                        else {
                            cout << "El accesorio ingresado no existe." << endl;
                            return false;
                        }
                    }
                    else {
                        cout << "El accesorio ingresado no existe." << endl;
                        return false;
                    }
                }
                else {
                    cout << "El accesorio ingresado no existe." << endl;
                    return false;
                }
            }
            else {
                cout << "El accesorio ingresado no existe." << endl;
                return false;
            }
        }
        else {
            cout << "El accesorio ingresado no existe" << endl;
            return false;
        }
}

void eliminarAccesorioMochila(soldados* s, accesorio* a, string accesorioE, string accesorioR) {
    for (int i = 0; i < 5; i++) {
        if ((s->mochila[i]->nombre == accesorioE) && (buscarAccesorio(a, accesorioR))) {
            s->mochila[i] = buscarAccesorio(a, accesorioR);
        }
    }
}

void mostrarMochila(soldados* s) {
    for (int i = 0; i < 5; i++) {
        cout << "Nombre: " << s->mochila[i]->nombre << endl;
        cout << "Tipo: " << s->mochila[i]->tipo << endl;
        cout << "Valor: " << s->mochila[i]->valor << endl;
        cout << "Consumo: " << s->mochila[i]->consumo << endl;
        cout << endl;
    }
}

void mostrarTodosSoldadosExcepto(soldados* s, string nombre, string nombre1, string nombre2, string nombre3, string nombre4, string nombre5) {
    if ((s == buscarSoldados(s, nombre)) || (s == buscarSoldados(s, nombre1)) || (s == buscarSoldados(s, nombre2)) || (s == buscarSoldados(s, nombre3)) || (s == buscarSoldados(s, nombre4)) || (s == buscarSoldados(s, nombre5))) {
        if (s->next) {
            mostrarTodosSoldadosExcepto(s->next, nombre, nombre1, nombre2, nombre3, nombre4, nombre5);
        }
    }
    else {
        cout << "Nombre: " << s->nombre << endl;
        cout << "Especie: " << s->especie->nombre << endl;
        cout << "Energia: " << s->energia << endl;
        cout << "Ambiente: " << s->ambiente->nombre << endl;
        cout << "Salud: " << s->salud << endl;
        cout << endl;
        if (s->next) {
            mostrarTodosSoldadosExcepto(s->next, nombre, nombre1, nombre2, nombre3, nombre4, nombre5);
        }
    }
}

void elegirSoldadosBatalla(bool* elegirSoldadosBatallaBool, soldados* s,accesorio *a ,soldados*& soldado_11, soldados*& soldado_21, soldados*& soldado_12, soldados*& soldado_22, soldados*& soldado_13, soldados*& soldado_23) {
    string sol_11 = "", sol_12 = "", sol_13 = "", sol_21 = "", sol_22 = "", sol_23 = "";
    cout << endl;
    //SOLDADO 1 J1
    cout << "Jugador 1. Elija un soldado: " << endl;
    mostrarTodosSoldados(s);
    cout << endl;
    cout << "- ";
    cin >> sol_11;
    if (buscarSoldados(s, sol_11)) {
        soldado_11 = buscarSoldados(s, sol_11);
        //MOCHILA SOLDADO 1 J1
        cout << "Ahora agrega 5 accesorios a la mochila. " << endl;
        cout << endl;
        mostrarTodosAccesorios(a);

        string a1, a2, a3, a4, a5;
        cout << "Escribe el nombre del primer accesorio: ";
        cin.ignore();
        getline(cin, a1);
        if (buscarAccesorio(a, a1)) {
            soldado_11->mochila[0] = buscarAccesorio(a, a1);
            cout << endl;
            cout << "Escribe el nombre del segundo accesorio: ";
            getline(cin, a2);
            if (buscarAccesorio(a, a2)) {
                soldado_11->mochila[1] = buscarAccesorio(a, a2);
                cout << endl;
                cout << "Escribe el nombre del tercer accesorio: ";
                getline(cin, a3);
                if (buscarAccesorio(a, a3)) {
                    soldado_11->mochila[2] = buscarAccesorio(a, a3);
                    cout << endl;
                    cout << "Escribe el nombre del cuarto accesorio: ";
                    getline(cin, a4);
                    if (buscarAccesorio(a, a4)) {
                        soldado_11->mochila[3] = buscarAccesorio(a, a4);
                        cout << endl;
                        cout << "Escribe el nombre del quinto accesorio: ";
                        getline(cin, a5);
                        if (buscarAccesorio(a, a5)) {
                            soldado_11->mochila[4] = buscarAccesorio(a, a5);
                        }
                        else {
                            cout << "El accesorio ingresado no existe." << endl;
                            return;
                        }
                    }
                    else {
                        cout << "El accesorio ingresado no existe." << endl;
                        return;
                    }
                }
                else {
                    cout << "El accesorio ingresado no existe." << endl;
                    return;
                }
            }
            else {
                cout << "El accesorio ingresado no existe." << endl;
                return;
            }
        }
        else {
            cout << "El accesorio ingresado no existe" << endl;
            return;
        }

        //SOLDADO 1 J2
        cout << endl;
        cout << "Jugador 2. Elija un soldado: " << endl;
        mostrarTodosSoldadosExcepto(s, sol_11, sol_21, sol_12, sol_22, sol_13, sol_23);
        cout << endl;
        cout << "- ";
        cin >> sol_21;
        if (sol_21 != sol_11) {
            if (buscarSoldados(s, sol_21)) {
                soldado_21 = buscarSoldados(s, sol_21);
                //MOCHILA SOLDADO 1 J2
                cout << "Ahora agrega 5 accesorios a la mochila. " << endl;
                cout << endl;
                mostrarTodosAccesorios(a);

                a1, a2, a3, a4, a5 = "";
                cout << "Escribe el nombre del primer accesorio: ";
                cin.ignore();
                getline(cin, a1);
                if (buscarAccesorio(a, a1)) {
                    soldado_21->mochila[0] = buscarAccesorio(a, a1);
                    cout << endl;
                    cout << "Escribe el nombre del segundo accesorio: ";
                    getline(cin, a2);
                    if (buscarAccesorio(a, a2)) {
                        soldado_21->mochila[1] = buscarAccesorio(a, a2);
                        cout << endl;
                        cout << "Escribe el nombre del tercer accesorio: ";
                        getline(cin, a3);
                        if (buscarAccesorio(a, a3)) {
                            soldado_21->mochila[2] = buscarAccesorio(a, a3);
                            cout << endl;
                            cout << "Escribe el nombre del cuarto accesorio: ";
                            getline(cin, a4);
                            if (buscarAccesorio(a, a4)) {
                                soldado_21->mochila[3] = buscarAccesorio(a, a4);
                                cout << endl;
                                cout << "Escribe el nombre del quinto accesorio: ";
                                getline(cin, a5);
                                if (buscarAccesorio(a, a5)) {
                                    soldado_21->mochila[4] = buscarAccesorio(a, a5);
                                }
                                else {
                                    cout << "El accesorio ingresado no existe." << endl;
                                    return;
                                }
                            }
                            else {
                                cout << "El accesorio ingresado no existe." << endl;
                                return;
                            }
                        }
                        else {
                            cout << "El accesorio ingresado no existe." << endl;
                            return;
                        }
                    }
                    else {
                        cout << "El accesorio ingresado no existe." << endl;
                        return;
                    }
                }
                else {
                    cout << "El accesorio ingresado no existe" << endl;
                    return;
                }

                //SOLDADO 2 J1
                cout << endl;
                cout << "Jugador 1. Elija otro soldado: " << endl;
                mostrarTodosSoldadosExcepto(s, sol_11, sol_21, sol_12, sol_22, sol_13, sol_23);
                cout << endl;
                cout << "- ";
                cin >> sol_12;
                if ((sol_12 != sol_11) && (sol_12 != sol_21)) {
                    if (buscarSoldados(s, sol_12)) {
                        soldado_12 = buscarSoldados(s, sol_12);
                        //MOCHILA SOLDADO 2 J1
                        cout << "Ahora agrega 5 accesorios a la mochila. " << endl;
                        cout << endl;
                        mostrarTodosAccesorios(a);

                        a1, a2, a3, a4, a5 = "";
                        cout << "Escribe el nombre del primer accesorio: ";
                        cin.ignore();
                        getline(cin, a1);
                        if (buscarAccesorio(a, a1)) {
                            soldado_12->mochila[0] = buscarAccesorio(a, a1);
                            cout << endl;
                            cout << "Escribe el nombre del segundo accesorio: ";
                            getline(cin, a2);
                            if (buscarAccesorio(a, a2)) {
                                soldado_12->mochila[1] = buscarAccesorio(a, a2);
                                cout << endl;
                                cout << "Escribe el nombre del tercer accesorio: ";
                                getline(cin, a3);
                                if (buscarAccesorio(a, a3)) {
                                    soldado_12->mochila[2] = buscarAccesorio(a, a3);
                                    cout << endl;
                                    cout << "Escribe el nombre del cuarto accesorio: ";
                                    getline(cin, a4);
                                    if (buscarAccesorio(a, a4)) {
                                        soldado_12->mochila[3] = buscarAccesorio(a, a4);
                                        cout << endl;
                                        cout << "Escribe el nombre del quinto accesorio: ";
                                        getline(cin, a5);
                                        if (buscarAccesorio(a, a5)) {
                                            soldado_12->mochila[4] = buscarAccesorio(a, a5);
                                        }
                                        else {
                                            cout << "El accesorio ingresado no existe." << endl;
                                            return;
                                        }
                                    }
                                    else {
                                        cout << "El accesorio ingresado no existe." << endl;
                                        return;
                                    }
                                }
                                else {
                                    cout << "El accesorio ingresado no existe." << endl;
                                    return;
                                }
                            }
                            else {
                                cout << "El accesorio ingresado no existe." << endl;
                                return;
                            }
                        }
                        else {
                            cout << "El accesorio ingresado no existe" << endl;
                            return;
                        }

                        //SOLDADO 2 J2
                        cout << endl;
                        cout << "Jugador 2. Elija otro soldado: " << endl;
                        mostrarTodosSoldadosExcepto(s, sol_11, sol_21, sol_12, sol_22, sol_13, sol_23);
                        cout << endl;
                        cout << "- ";
                        cin >> sol_22;
                        if ((sol_22 != sol_11) && (sol_22 != sol_21) && (sol_22 != sol_12)) {
                            if (buscarSoldados(s, sol_22)) {
                                soldado_22 = buscarSoldados(s, sol_22);
                                //MOCHILA SOLDADO 2 J2
                                cout << "Ahora agrega 5 accesorios a la mochila. " << endl;
                                cout << endl;
                                mostrarTodosAccesorios(a);

                                a1, a2, a3, a4, a5 = "";
                                cout << "Escribe el nombre del primer accesorio: ";
                                cin.ignore();
                                getline(cin, a1);
                                if (buscarAccesorio(a, a1)) {
                                    soldado_22->mochila[0] = buscarAccesorio(a, a1);
                                    cout << endl;
                                    cout << "Escribe el nombre del segundo accesorio: ";
                                    getline(cin, a2);
                                    if (buscarAccesorio(a, a2)) {
                                        soldado_22->mochila[1] = buscarAccesorio(a, a2);
                                        cout << endl;
                                        cout << "Escribe el nombre del tercer accesorio: ";
                                        getline(cin, a3);
                                        if (buscarAccesorio(a, a3)) {
                                            soldado_22->mochila[2] = buscarAccesorio(a, a3);
                                            cout << endl;
                                            cout << "Escribe el nombre del cuarto accesorio: ";
                                            getline(cin, a4);
                                            if (buscarAccesorio(a, a4)) {
                                                soldado_22->mochila[3] = buscarAccesorio(a, a4);
                                                cout << endl;
                                                cout << "Escribe el nombre del quinto accesorio: ";
                                                getline(cin, a5);
                                                if (buscarAccesorio(a, a5)) {
                                                    soldado_22->mochila[4] = buscarAccesorio(a, a5);
                                                }
                                                else {
                                                    cout << "El accesorio ingresado no existe." << endl;
                                                    return;
                                                }
                                            }
                                            else {
                                                cout << "El accesorio ingresado no existe." << endl;
                                                return;
                                            }
                                        }
                                        else {
                                            cout << "El accesorio ingresado no existe." << endl;
                                            return;
                                        }
                                    }
                                    else {
                                        cout << "El accesorio ingresado no existe." << endl;
                                        return;
                                    }
                                }
                                else {
                                    cout << "El accesorio ingresado no existe" << endl;
                                    return;
                                }

                                //SOLDADO 3 J1
                                cout << endl;
                                cout << "Jugador 1. Elija otro soldado: " << endl;
                                mostrarTodosSoldadosExcepto(s, sol_11, sol_21, sol_12, sol_22, sol_13, sol_23);
                                cout << endl;
                                cout << "- ";
                                cin >> sol_13;
                                if ((sol_13 != sol_11) && (sol_13 != sol_21) && (sol_13 != sol_12) && (sol_13 != sol_22)) {
                                    if (buscarSoldados(s, sol_13)) {
                                        soldado_13 = buscarSoldados(s, sol_13);
                                        //MOCHILA SOLDADO 3 J1
                                        cout << "Ahora agrega 5 accesorios a la mochila. " << endl;
                                        cout << endl;
                                        mostrarTodosAccesorios(a);

                                        a1, a2, a3, a4, a5 = "";
                                        cout << "Escribe el nombre del primer accesorio: ";
                                        cin.ignore();
                                        getline(cin, a1);
                                        if (buscarAccesorio(a, a1)) {
                                            soldado_13->mochila[0] = buscarAccesorio(a, a1);
                                            cout << endl;
                                            cout << "Escribe el nombre del segundo accesorio: ";
                                            getline(cin, a2);
                                            if (buscarAccesorio(a, a2)) {
                                                soldado_13->mochila[1] = buscarAccesorio(a, a2);
                                                cout << endl;
                                                cout << "Escribe el nombre del tercer accesorio: ";
                                                getline(cin, a3);
                                                if (buscarAccesorio(a, a3)) {
                                                    soldado_13->mochila[2] = buscarAccesorio(a, a3);
                                                    cout << endl;
                                                    cout << "Escribe el nombre del cuarto accesorio: ";
                                                    getline(cin, a4);
                                                    if (buscarAccesorio(a, a4)) {
                                                        soldado_13->mochila[3] = buscarAccesorio(a, a4);
                                                        cout << endl;
                                                        cout << "Escribe el nombre del quinto accesorio: ";
                                                        getline(cin, a5);
                                                        if (buscarAccesorio(a, a5)) {
                                                            soldado_13->mochila[4] = buscarAccesorio(a, a5);
                                                        }
                                                        else {
                                                            cout << "El accesorio ingresado no existe." << endl;
                                                            return;
                                                        }
                                                    }
                                                    else {
                                                        cout << "El accesorio ingresado no existe." << endl;
                                                        return;
                                                    }
                                                }
                                                else {
                                                    cout << "El accesorio ingresado no existe." << endl;
                                                    return;
                                                }
                                            }
                                            else {
                                                cout << "El accesorio ingresado no existe." << endl;
                                                return;
                                            }
                                        }
                                        else {
                                            cout << "El accesorio ingresado no existe" << endl;
                                            return;
                                        }

                                        //SOLDADO 3 J2
                                        cout << endl;
                                        cout << "Jugador 2. Elija otro soldado: " << endl;
                                        mostrarTodosSoldadosExcepto(s, sol_11, sol_21, sol_12, sol_22, sol_13, sol_23);
                                        cout << endl;
                                        cout << "- ";
                                        cin >> sol_23;
                                        if ((sol_23 != sol_11) && (sol_23 != sol_21) && (sol_23 != sol_12) && (sol_23 != sol_22) && (sol_23 != sol_13)) {
                                            if (buscarSoldados(s, sol_23)) {
                                                soldado_23 = buscarSoldados(s, sol_23);
                                                //MOCHILA SOLDADO 3 J2
                                                cout << "Ahora agrega 5 accesorios a la mochila. " << endl;
                                                cout << endl;
                                                mostrarTodosAccesorios(a);

                                                a1, a2, a3, a4, a5 = "";
                                                cout << "Escribe el nombre del primer accesorio: ";
                                                cin.ignore();
                                                getline(cin, a1);
                                                if (buscarAccesorio(a, a1)) {
                                                    soldado_23->mochila[0] = buscarAccesorio(a, a1);
                                                    cout << endl;
                                                    cout << "Escribe el nombre del segundo accesorio: ";
                                                    getline(cin, a2);
                                                    if (buscarAccesorio(a, a2)) {
                                                        soldado_23->mochila[1] = buscarAccesorio(a, a2);
                                                        cout << endl;
                                                        cout << "Escribe el nombre del tercer accesorio: ";
                                                        getline(cin, a3);
                                                        if (buscarAccesorio(a, a3)) {
                                                            soldado_23->mochila[2] = buscarAccesorio(a, a3);
                                                            cout << endl;
                                                            cout << "Escribe el nombre del cuarto accesorio: ";
                                                            getline(cin, a4);
                                                            if (buscarAccesorio(a, a4)) {
                                                                soldado_23->mochila[3] = buscarAccesorio(a, a4);
                                                                cout << endl;
                                                                cout << "Escribe el nombre del quinto accesorio: ";
                                                                getline(cin, a5);
                                                                if (buscarAccesorio(a, a5)) {
                                                                    soldado_23->mochila[4] = buscarAccesorio(a, a5);
                                                                    *elegirSoldadosBatallaBool = true;
                                                                }
                                                                else {
                                                                    cout << "El accesorio ingresado no existe." << endl;
                                                                    return;
                                                                }
                                                            }
                                                            else {
                                                                cout << "El accesorio ingresado no existe." << endl;
                                                                return;
                                                            }
                                                        }
                                                        else {
                                                            cout << "El accesorio ingresado no existe." << endl;
                                                            return;
                                                        }
                                                    }
                                                    else {
                                                        cout << "El accesorio ingresado no existe." << endl;
                                                        return;
                                                    }
                                                }
                                                else {
                                                    cout << "El accesorio ingresado no existe" << endl;
                                                    return;
                                                }
                                            }
                                            else {
                                                cout << "El soldado ingresado no existe." << endl;
                                                return;
                                            }
                                        }
                                        else {
                                            cout << "El soldado ingresado ya fue elegido." << endl;
                                            return;
                                        }
                                    }
                                    else {
                                        cout << "El soldado ingresado no existe." << endl;
                                        return;
                                    }
                                }
                                else {
                                    cout << "El soldado ingresado ya fue elegido." << endl;
                                    return;
                                }
                            }
                            else {
                                cout << "El soldado ingresado no existe." << endl;
                                return;
                            }
                        }
                        else {
                            cout << "El soldado ingresado ya fue elegido." << endl;
                            return;
                        }
                    }
                    else {
                        cout << "El soldado ingresado no existe." << endl;
                        return;
                    }
                }
                else {
                    cout << "El soldado ingresado ya fue elegido." << endl;
                    return;
                }
            }
            else {
                cout << "El soldado ingresado no existe." << endl;
                return;
            }
        }
        else {
            cout << "El soldado ingresado ya existe." << endl;
            return;
        }
    }
    else {
        cout << "El soldado ingresado no existe." << endl;
        return;
    }
}

int numeroRandom() {
    srand(time(0));
    return rand() % 2;
}

void asignarFidelidad(soldados*& soldado_11, soldados*& soldado_21, soldados*& soldado_12, soldados*& soldado_22, soldados*& soldado_13, soldados*& soldado_23) {
    int fidelidadS1 = numeroRandom();

    cout << "La fidelidad del Jugador 1 es: " << (fidelidadS1) << endl;

    if (fidelidadS1 == 0) {
        soldado_11->fidelidad = 0;
        soldado_12->fidelidad = 0;
        soldado_13->fidelidad = 0;

        soldado_21->fidelidad = 1;
        soldado_22->fidelidad = 1;
        soldado_23->fidelidad = 1;
    }
    else {
        soldado_11->fidelidad = 1;
        soldado_12->fidelidad = 1;
        soldado_13->fidelidad = 1;

        soldado_21->fidelidad = 0;
        soldado_22->fidelidad = 0;
        soldado_23->fidelidad = 0;
    }
}

ambientes* ambienteRandom(ambientes* a) {
    int numeroAmbientes = 4;
    srand(time(0));
    int numeroAmbienteRandom = rand() % numeroAmbientes;
    if (numeroAmbienteRandom < 0) return nullptr;
    ambientes* aux = a;
    int numeroActual = 0;
    while (aux != nullptr && numeroActual < numeroAmbienteRandom) {
        aux = aux->next;
        numeroActual++;
    }
    if (numeroActual == numeroAmbienteRandom) {
        return aux;
    }
    else {
        cout << "ERROR generando ambiente random" << endl;
    }
}

bool buscarAccesorioMochila(soldados* soldado, accesorio* accesorio) {
    for (int i = 0; i < 5; i++) {
        if (soldado->mochila[i] == accesorio) {
            return true;
        }
        else {
            continue;
        }
    }
    return false;
}

void ataque(ambientes* ambienteRand, bool* ganador, soldados*& soldado1, soldados*& soldado2, accesorio* accesorio1J1, accesorio* accesorio2J1, accesorio* accesorio1J2, accesorio* accesorio2J2) {
    int random = numeroRandom();
    
    //Chequear compatibilidad con el ambiente
    bool penalizacionJ1 = true;
    bool penalizacionJ2 = true;

    if ((soldado1->ambiente != ambienteRand)) {
        if (accesorio1J1->tipo == "Condicionamiento") {
            if (accesorio1J1->recuperacion == ambienteRand->nombre) {
                penalizacionJ1 = false;
            }
        }
        if (accesorio2J1->tipo == "Condicionamiento") {
            if (accesorio2J1->recuperacion == ambienteRand->nombre) {
                penalizacionJ1 = false;
            }
        }
    }
    if ((soldado2->ambiente != ambienteRand)) {
        if (accesorio1J2->tipo == "Condicionamiento") {
            if (accesorio1J2->recuperacion == ambienteRand->nombre) {
                penalizacionJ2 = false;
            }
        }
        else if (accesorio2J2->tipo == "Condicionamiento") {
            if (accesorio2J2->recuperacion == ambienteRand->nombre) {
                penalizacionJ2 = false;
            }
        }
    }

    //Escudos
    int escudoJ1 = 0;
    int escudoJ2 = 0;
    if (accesorio1J1->tipo == "Defensa") {
        if (soldado1->energia > accesorio1J1->consumo) {
            escudoJ1 = accesorio1J1->valor;
            soldado1->energia -= accesorio1J1->consumo;
        }
        else {
            cout << "No se tiene suficiente energia para utilizar: " << accesorio1J1->nombre << endl;
        }
    }
    else if (accesorio2J1->tipo == "Defensa") {
        if (soldado1->energia > accesorio2J1->consumo) {
            escudoJ1 = accesorio2J1->valor;
            soldado1->energia -= accesorio2J1->consumo;
        }
        else {
            cout << "No se tiene suficiente energia para utilizar: " << accesorio2J1->nombre << endl;
        }
    }
    if (accesorio1J2->tipo == "Defensa") {
        if (soldado2->energia > accesorio1J2->consumo) {
            escudoJ2 = accesorio1J2->valor;
            soldado2->energia -= accesorio1J2->consumo;
        }
        else {
            cout << "No se tiene suficiente energia para utilizar: " << accesorio1J2->nombre << endl;
        }
    }
    else if (accesorio2J2->tipo == "Defensa") {
        if (soldado2->energia > accesorio2J2->consumo) {
            escudoJ2 = accesorio2J2->valor;
            soldado2->energia -= accesorio2J2->consumo;
        }
        else {
            cout << "No se tiene suficiente energia para utilizar: " << accesorio2J2->nombre << endl;
        }
    }

    //Supervivencia
    if (accesorio1J1->tipo == "Supervivencia") {
        if (soldado1->energia > accesorio1J1->consumo) {
            if (accesorio1J1->recuperacion == "Salud") {
                soldado1->energia -= accesorio1J1->consumo;
                soldado1->salud += accesorio1J1->valor;
            }
            else {
                soldado1->salud -= accesorio1J1->consumo;
                soldado1->energia += accesorio1J1->valor;
            }
        }
        else {
            cout << "No se tiene suficiente energia para utilizar el " << accesorio1J1->nombre << endl;
        }
    }
    else if (accesorio2J1->tipo == "Supervivencia") {
        if (soldado1->energia > accesorio2J1->consumo) {
            if (accesorio2J1->recuperacion == "Salud") {
                soldado1->energia -= accesorio2J1->consumo;
                soldado1->salud += accesorio2J1->valor;
            }
            else {
                soldado1->salud -= accesorio2J1->consumo;
                soldado1->energia += accesorio2J1->valor;
            }
        }
        else {
            cout << "No se tiene suficiente energia para utilizar el " << accesorio2J1->nombre << endl;
        }
    }
    if (accesorio1J2->tipo == "Supervivencia") {
        if (soldado2->energia > accesorio1J2->consumo) {
            if (accesorio1J2->recuperacion == "Salud") {
                soldado2->energia -= accesorio1J2->consumo;
                soldado2->salud += accesorio1J2->valor;
            }
            else {
                soldado2->salud -= accesorio1J2->consumo;
                soldado2->energia += accesorio1J2->valor;
            }
        }
        else {
            cout << "No se tiene suficiente energia para utilizar el " << accesorio1J2->nombre << endl;
        }
    }
    else if (accesorio2J2->tipo == "Supervivencia") {
        if (soldado2->energia > accesorio2J2->consumo) {
            if (accesorio2J2->recuperacion == "Salud") {
                soldado2->energia -= accesorio2J2->consumo;
                soldado2->salud += accesorio2J2->valor;
            }
            else {
                soldado2->salud -= accesorio2J2->consumo;
                soldado2->energia += accesorio2J2->valor;
            }
        }
        else {
            cout << "No se tiene suficiente energia para utilizar el " << accesorio2J2->nombre << endl;
        }
    }

    //Quitar vida si hay penalizacion
    if (penalizacionJ1) {
        soldado1->salud -= 30;
    }
    if (penalizacionJ2) {
        soldado2->salud -= 30;
    }

    //Ataque
    if (random == 0) {
        //Jugador1 Ataca
        cout << "Jugador 1 ATACA!" << endl;
        if ((soldado1->salud > 0 && soldado1->energia > 0) && (soldado2->salud > 0 && soldado2->energia > 0)) {
            cout << endl;
            if (accesorio1J1->tipo == "Ataque") {
                if (soldado1->energia > accesorio1J1->consumo) {
                    soldado1->energia -= accesorio1J1->consumo;
                    if (escudoJ2 != 0) {
                        if (escudoJ2 > accesorio1J1->valor) {
                            escudoJ2 -= accesorio1J1->valor;
                        }
                    }
                    else {
                        int resto = accesorio1J1->valor - escudoJ2;
                        escudoJ2 = 0;
                        soldado2->salud -= resto;
                    }
                }
            }
            else if (accesorio2J1->tipo == "Ataque") {
                if (soldado1->energia > accesorio2J1->consumo) {
                    soldado1->energia -= accesorio2J1->consumo;
                    if (escudoJ2 != 0) {
                        if (escudoJ2 > accesorio2J1->valor) {
                            escudoJ2 -= accesorio2J1->valor;
                        }
                    }
                    else {
                        int resto = accesorio2J1->valor - escudoJ2;
                        escudoJ2 = 0;
                        soldado2->salud -= resto;
                    }
                }
            }
        }
    }
    else if (random == 1) {
        //Jugador 2 Ataca
        cout << "Jugador 2 ATACA!" << endl;
        cout << endl;
        if (accesorio1J2->tipo == "Ataque") {
            if (soldado2->energia > accesorio1J2->consumo) {
                soldado2->energia -= accesorio1J2->consumo;
                if (escudoJ1 != 0) {
                    if (escudoJ1 > accesorio1J2->valor) {
                        escudoJ1 -= accesorio1J2->valor;
                    }
                }
                else {
                    int resto = accesorio1J2->valor - escudoJ1;
                    escudoJ1 = 0;
                    soldado1->salud -= resto;
                }
            }
        }
        else if (accesorio2J2->tipo == "Ataque") {
            if (soldado2->energia > accesorio1J2->consumo) {
                soldado2->energia -= accesorio2J2->consumo;
                if (escudoJ1 != 0) {
                    if (escudoJ1 > accesorio2J2->valor) {
                        escudoJ1 -= accesorio2J2->valor;
                    }
                }
                else {
                    int resto = accesorio2J2->valor - escudoJ1;
                    escudoJ1 = 0;
                    soldado1->salud -= resto;
                }
            }
        }
    }
    
    if ((soldado1->salud < 0) || (soldado1->energia < 0)) {
        cout << endl;
        cout << "El jugador 2 ha ganado!!!" << endl;
        cout << endl;
        *ganador = true;
    }
    else if ((soldado2->salud < 0) || (soldado2->energia < 0)) {
        cout << endl;
        cout << "El jugador 1 ha ganado!!!" << endl;
        cout << endl;
        *ganador = true;
    }

    if (*ganador == false) {
        cout << endl;
        cout << "Soldado jugador 1: " << endl;
        mostrarUnSoldado(soldado1);
        cout << endl;
        cout << "Soldado jugador 2: " << endl;
        mostrarUnSoldado(soldado2);
    }           
}

void peleaSoldados(accesorio* a, ambientes* ambRand, bool* ganador, soldados* soldado1, soldados* soldado2) {
    int primerAtaque = numeroRandom();
    string nombreAccesorio1J1;
    accesorio* accesorio1J1;
    string nombreAccesorio2J1;
    accesorio* accesorio2J1;

    string nombreAccesorio1J2;
    accesorio* accesorio1J2;
    string nombreAccesorio2J2;
    accesorio* accesorio2J2;


    cout << endl;

    cout << "Jugador 1. Elija dos accesorios: " << endl;
    cout << endl;
    mostrarMochila(soldado1);
    cout << endl;
    cout << "Accesorio 1: ";
    cin.ignore();
    getline(cin, nombreAccesorio1J1);
    if (buscarAccesorio(a, nombreAccesorio1J1)) {
        accesorio1J1 = buscarAccesorio(a, nombreAccesorio1J1);
        if (buscarAccesorioMochila(soldado1, accesorio1J1)) {
            cout << endl;
            cout << "Accesorio 2: ";
            getline(cin, nombreAccesorio2J1);
            cout << nombreAccesorio2J1 << endl;
            if (buscarAccesorio(a, nombreAccesorio2J1)) {
                accesorio2J1 = buscarAccesorio(a, nombreAccesorio2J1);
                if (buscarAccesorioMochila(soldado1, accesorio2J1)) {
                    accesorio2J1 = buscarAccesorio(a, nombreAccesorio2J1);
                    cout << endl;
                    cout << "Jugador 2. Elija dos accesorios para defender: " << endl;
                    cout << endl;
                    mostrarMochila(soldado2);
                    cout << endl;
                    cout << "Accesorio 1: ";
                    getline(cin, nombreAccesorio1J2);
                    if (buscarAccesorio(a, nombreAccesorio1J2)) {
                        accesorio1J2 = buscarAccesorio(a, nombreAccesorio1J2);
                        if (buscarAccesorioMochila(soldado2, accesorio1J2)) {
                            cout << endl;
                            cout << "Accesorio 2: ";
                            getline(cin, nombreAccesorio2J2);
                            if (buscarAccesorio(a, nombreAccesorio2J2)) {
                                accesorio2J2 = buscarAccesorio(a, nombreAccesorio2J2);
                                if (buscarAccesorioMochila(soldado2, accesorio2J2)) {
                                    cout << endl;
                                    
                                    ataque(ambRand, ganador, soldado1, soldado2, accesorio1J1, accesorio2J1, accesorio1J2, accesorio2J2);

                                }
                                else {
                                    cout << "El accesorio ingresado no se encuentra en la mochila" << endl;
                                    return;
                                }
                            }
                            else {
                                cout << "El accesorio ingresado no existe" << endl;
                                return;
                            }
                        }
                        else {
                            cout << "El accesorio ingresado no se encuentra en la mochila" << endl;
                            return;
                        }
                    }
                    else {
                        cout << "El accesorio ingresado no existe" << endl;
                        return;
                    }
                }
                else {
                    cout << "El accesorio ingresado no se encuentra en la mochila" << endl;
                    return;
                }
            }
            else {
                cout << "El accesorio ingresado no existe" << endl;
                return;
            }
        }
        else {
            cout << "El accesorio ingresado no se encuentra en la mochila" << endl;
            return;
        }
    }
    else {
        cout << "El accesorio ingresado no existe" << endl;
        return;
    }
}


void batalla(accesorio* a, soldados* s, ambientes* amb, bool* ganador, soldados*& soldado_11, soldados*& soldado_21, soldados*& soldado_12, soldados*& soldado_22, soldados*& soldado_13, soldados*& soldado_23) {
    string nombreSoldadoBatalla1;
    string nombreSoldadoBatalla2;

    soldados* soldadoBatalla1;
    soldados* soldadoBatalla2;

    ambientes* ambRand = ambienteRandom(amb);

    cout << "El ambiente en el que la batalla va a ocurrir es: " << ambRand->nombre << endl;
    cout << endl;

    while (*ganador == false) {
        cout << "Jugador 1. Elija un soldado para la batalla: " << endl;
        cout << endl;
        cout << soldado_11->nombre << endl;
        cout << soldado_11->energia << endl;
        cout << soldado_11->ambiente->nombre << endl;
        cout << soldado_11->salud << endl;
        cout << soldado_11->mochila[0]->nombre << ", " << soldado_11->mochila[1]->nombre << ", " << soldado_11->mochila[2]->nombre << ", " << soldado_11->mochila[3]->nombre << ", " << soldado_11->mochila[4]->nombre << endl;
        cout << endl;
        cout << soldado_12->nombre << endl;
        cout << soldado_12->energia << endl;
        cout << soldado_12->ambiente->nombre << endl;
        cout << soldado_12->salud << endl;
        cout << soldado_12->mochila[0]->nombre << ", " << soldado_12->mochila[1]->nombre << ", " << soldado_12->mochila[2]->nombre << ", " << soldado_12->mochila[3]->nombre << ", " << soldado_12->mochila[4]->nombre << endl;
        cout << endl;
        cout << soldado_13->nombre << endl;
        cout << soldado_13->energia << endl;
        cout << soldado_13->ambiente->nombre << endl;
        cout << soldado_13->salud << endl;
        cout << soldado_13->mochila[0]->nombre << ", " << soldado_13->mochila[1]->nombre << ", " << soldado_13->mochila[2]->nombre << ", " << soldado_13->mochila[3]->nombre << ", " << soldado_13->mochila[4]->nombre << endl;
        cout << endl;
        cin >> nombreSoldadoBatalla1;
        if (buscarSoldados(s, nombreSoldadoBatalla1)) {
            soldadoBatalla1 = buscarSoldados(s, nombreSoldadoBatalla1);

            cout << endl;
            cout << endl;
            cout << "Jugador 2. Elija un soldado para la batalla: " << endl;
            cout << endl;
            cout << soldado_21->nombre << endl;
            cout << soldado_21->energia << endl;
            cout << soldado_21->ambiente->nombre << endl;
            cout << soldado_21->salud << endl;
            cout << soldado_21->mochila[0]->nombre << ", " << soldado_21->mochila[1]->nombre << ", " << soldado_21->mochila[2]->nombre << ", " << soldado_21->mochila[3]->nombre << ", " << soldado_21->mochila[4]->nombre << endl;
            cout << endl;
            cout << soldado_22->nombre << endl;
            cout << soldado_22->energia << endl;
            cout << soldado_22->ambiente->nombre << endl;
            cout << soldado_22->salud << endl;
            cout << soldado_22->mochila[0]->nombre << ", " << soldado_22->mochila[1]->nombre << ", " << soldado_22->mochila[2]->nombre << ", " << soldado_22->mochila[3]->nombre << ", " << soldado_22->mochila[4]->nombre << endl;
            cout << endl;
            cout << soldado_23->nombre << endl;
            cout << soldado_23->energia << endl;
            cout << soldado_23->ambiente->nombre << endl;
            cout << soldado_23->salud << endl;
            cout << soldado_23->mochila[0]->nombre << ", " << soldado_23->mochila[1]->nombre << ", " << soldado_23->mochila[2]->nombre << ", " << soldado_23->mochila[3]->nombre << ", " << soldado_23->mochila[4]->nombre << endl;
            cout << endl;
            cin >> nombreSoldadoBatalla2;
            if (buscarSoldados(s, nombreSoldadoBatalla2)) {
                soldadoBatalla2 = buscarSoldados(s, nombreSoldadoBatalla2);
                peleaSoldados(a, ambRand, ganador, soldadoBatalla1, soldadoBatalla2);
            }
        }
        else {
            cout << "El soldado ingresado no existe" << endl;
            return;
        }
    }
}
