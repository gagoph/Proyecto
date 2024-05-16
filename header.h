#include<iostream>

using namespace std;

//AMBIENTES

struct ambientes {
    string nombre;
    ambientes *next;
};

ambientes *nuevoAmbiente(string nombre) {
    ambientes *nuevoAmbiente = new ambientes;
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


//ESPECIES

struct especies {
    string nombre;
    float energia;
    string ambiente;
    especies *next;
};

especies* nuevaEspecie(string nombre, float energia, string ambiente) {
    especies* nuevaEspecie = new especies;
    nuevaEspecie->nombre = nombre;
    nuevaEspecie->energia = energia;
    nuevaEspecie->ambiente = ambiente;
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

void modificarNombreEspecies(especies *e, string nombre) {
    e->nombre = nombre;
}
void modificarEnergiaEspecies(especies *e, float energia) {
    e->energia = energia;
}
void modificarAmbienteEspecies(especies *e, string ambiente) {
    e->ambiente = ambiente;
}

void mostrarUnaEspecie(especies *e) {
    cout << " " << endl;
    cout << "Nombre: " << e->nombre << "\n";
    cout << "Energia" << e->energia << "\n";
    cout << "Ambiente" << e->ambiente << "\n";
    cout << " " << endl; 
}

void mostrarTodasEspecies(especies* e) {
    cout << "Nombre: " << e->nombre << endl;
    cout << "Energia: " << e->energia << endl;
    cout << "Ambiente: " << e->ambiente << endl;
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
    int valor;
    int consumo;
    accesorio *next;
};

accesorio *nuevoAccesorio(string nombre, string tipo, int valor, int consumo) {
    accesorio *nuevoAccesorio = new accesorio;
    nuevoAccesorio->nombre = nombre;
    nuevoAccesorio->tipo = tipo;
    nuevoAccesorio->valor = valor;
    nuevoAccesorio->consumo = consumo;
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


accesorio *buscarAccesorio(accesorio *a, string nombre) {
    accesorio *p = a;
    while ((p) && (p->nombre != nombre)) {
        p = p->next;
    }
    return p;
}

void modificarNombreAccesorio(accesorio *a, string nombre) {
    a->nombre = nombre;
}
void modificarTipoAccesorio(accesorio* a, string tipo) {
    a->tipo = tipo;
}
void modificarValorAccesorio(accesorio *a, int valor) {
    a->valor = valor;
}
void modificarConsumoAccesorio(accesorio *a, int consumo) {
    a->consumo = consumo;
}

void mostrarTodosAccesorios(accesorio *a) {
        cout << "Nombre: " << a->nombre << endl;
        cout << "Tipo: " << a->tipo << endl;
        cout << "Valor: " << a->valor << endl;
        cout << "Consumo: " << a->consumo << endl;
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

void eliminarAccesorio(accesorio **p, accesorio *i) {
    accesorio *a = *p;
    accesorio *aux;

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
    string especie;
    int energia;
    string ambiente;
    int salud = 100;
    int fidelidad;
    soldados *next;
};

soldados *nuevoSoldado(string nombre, string especie, int fidelidad) {
    soldados *nuevoSoldado = new soldados;
    nuevoSoldado->nombre = nombre;
    nuevoSoldado->especie = especie;
    nuevoSoldado->fidelidad = fidelidad;
    return nuevoSoldado;
}


soldados *buscarSoldados(soldados *e, string nombre) {
    soldados *p = e;
    while ((p) && (p->nombre != nombre)) {
        p = p->next;
    }
    return p;

}

void modificarNombreSoldado(soldados *e, string nombre) {
    e->nombre = nombre;
}
void modificarEspecieSoldado(soldados *e, string especie) {
    e->especie = especie;
}
void modificarFidelidadSoldado(soldados *e, int fidelidad) {
    e->fidelidad = fidelidad;
}

void mostrarSoldados(soldados *e) {
    if (e) {
        cout << e->nombre << "\n";
        if (e->next) {
            mostrarSoldados(e->next);
        }
    }

}

int contarTotalSoldados(soldados *e) {
    int c = 0;
    while ((e)) {
        c++;
        e = e->next;
    }
    return c;
}

void eliminarSoldado(soldados **p, soldados *i) {
    soldados *e = *p;
    soldados *aux;

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