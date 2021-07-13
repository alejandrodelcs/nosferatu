#include "mapa.h"
#include <iostream>

mapa::mapa() {
    cant_humanos =0 ;
    cant_vampiros = 0;
    cant_zombis = 0;
    cant_agua = 0;
    cant_cruces = 0;
    cant_balas = 0;
    cant_escopetas = 0;
    cant_estacas = 0;
    Vanesa = false;
    Nosferatu = false;
    Vampirella =false;
    filas=0;
    col=0;
}
void mapa::cambiar_filas(int ancho){
    filas=ancho;
}
void mapa::cambiar_col(int alto){
    col=alto;
}

int mapa::crear(){
    std::ifstream archivo("../estado.txt");
    std::string nombre;
    std::string especial;
    std::string alto;
    std::string ancho;
    std::string aux;
    if (!archivo){
        std::cout<<"no existe";
        throw ;
    }
    while (!archivo.eof()){
        getline(archivo,nombre,' ');
        getline(archivo,especial,'(');
        getline(archivo,ancho,',');
        getline(archivo,alto,')');
        getline(archivo,aux,'\n');
        if(nombre=="tablero"){
            cambiar_filas(stoi(ancho));
            cambiar_col(stoi(alto));
            crear_tablero();
        }
        else if (nombre=="humano"){
            if(especial=="CV ")crear_cazador(stoi(ancho), stoi(alto));
            else crear_humano(stoi(ancho), stoi(alto));
        }
        else if(nombre=="Vanesa")crear_Vanesa(stoi(ancho), stoi(alto));
        else if(nombre=="vampiro")crear_vampiro(stoi(ancho), stoi(alto));
        else if(nombre=="zombi")crear_zombi(stoi(ancho), stoi(alto));
        else if(nombre=="Nosferatu")crear_Nosferatu(stoi(ancho), stoi(alto));
        else if(nombre=="Vampirella")crear_Vampirella(stoi(ancho), stoi(alto));
        else if(nombre=="agua")crear_agua(stoi(ancho), stoi(alto),2);
        else if(nombre=="cruz")crear_cruz(stoi(ancho), stoi(alto));
        else if(nombre=="bala")crear_bala(stoi(ancho), stoi(alto),2);
        else if(nombre=="escopeta")crear_escopeta(stoi(ancho), stoi(alto));
        else if(nombre=="estaca")crear_estaca(stoi(ancho), stoi(alto));
    }
    return 0;
}

void mapa::mostrar(){
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < col; ++j) {
            if(objetos[i][j]!=nullptr)std::cout<<objetos[i][j]->dar_simbolo()<<' ';
            else std::cout<<"*"<<' ';
        }
        std::cout<<std::endl;
    }
}
void mapa::dar_baja() {
    int fila, columna;
    std::cout<<"ingrese fila y columna de la posicion"<<std::endl;
    std::cout<<"fila = ";
    std::cin>>fila;
    std::cout<<"columna = ";
    std::cin>>columna;
    if((fila>=0 && fila <= filas) && (columna>=0 && columna <= col) && objetos[fila][columna]!=nullptr){
        objetos[fila][columna]->mostrar();
        std::cout<<"ha muerto"<<std::endl;
        if(objetos[fila][columna]->dar_simbolo() == "h") cant_humanos--;
        else if(objetos[fila][columna]->dar_simbolo()=="H") cant_humanos--;
        else if(objetos[fila][columna]->dar_simbolo()=="W"){
            cant_humanos--;
            Vanesa=false;
        }
        else if(objetos[fila][columna]->dar_simbolo()=="z") cant_zombis--;
        else if(objetos[fila][columna]->dar_simbolo()=="v") cant_vampiros--;
        else if(objetos[fila][columna]->dar_simbolo()=="V") {
            cant_vampiros--;
            Vampirella=false;
        }
        else if(objetos[fila][columna]->dar_simbolo()=="N"){
            cant_vampiros--;
            Nosferatu=false;
        }
        else if(objetos[fila][columna]->dar_simbolo()=="c")cant_cruces--;
        else if(objetos[fila][columna]->dar_simbolo()=="a")cant_agua -= objetos[fila][columna]->dar_cantidad();
        else if(objetos[fila][columna]->dar_simbolo()=="e")cant_estacas--;
        else if(objetos[fila][columna]->dar_simbolo()=="E")cant_escopetas--;
        else if(objetos[fila][columna]->dar_simbolo()=="b")cant_balas -= objetos[fila][columna]->dar_cantidad();
        delete objetos[fila][columna];
        objetos[fila][columna] = nullptr;
    }
    else{
        std::cout<<"ERROR AL ELIMINAR"<<std::endl;
    }
}
void mapa::dar_alta() {
    int fila, columna;
    char simbolo;
    std::cout<<"ingrese fila y columna de la posicion y el simbolo del objeto"<<std::endl;
    std::cout<<"fila = ";
    std::cin>>fila;
    std::cout<<"columna = ";
    std::cin>>columna;
    std::cout<<"simbolo = ";
    std::cin>>simbolo;
    if((fila>=0 && fila <= filas) && (columna>=0 && columna <= col) && (objetos[fila][columna]==nullptr)){
        if(simbolo=='h')crear_humano(fila,columna);
        else if(simbolo=='H')crear_cazador(fila,columna);
        else if(simbolo=='W')crear_Vanesa(fila,columna);
        else if(simbolo=='z')crear_zombi(fila,columna);
        else if(simbolo=='v')crear_vampiro(fila,columna);
        else if(simbolo=='V')crear_Vampirella(fila,columna);
        else if(simbolo=='N')crear_Nosferatu(fila,columna);
        else if(simbolo=='c')crear_cruz(fila,columna);
        else if(simbolo=='a'){
            int cant;
            std::cout<<"ingrese cantidad = ";
            std::cin>>cant;
            crear_agua(fila,columna,cant);
        }
        else if(simbolo=='e')crear_estaca(fila,columna);
        else if(simbolo=='E')crear_escopeta(fila,columna);
        else if(simbolo=='b'){
            int cant;
            std::cout<<"ingrese cantidad = ";
            std::cin>>cant;
            crear_bala(fila,columna,cant);
        }
    }
}
void mapa::crear_tablero(){
    if(filas%2==0 && col%2==0) {
        objetos = new objeto **[filas];
        for (int i = 0; i < filas; ++i) {
            objetos[i] = new objeto *[col];
        }
        for (int x = 0; x < filas; ++x) {
            for (int y = 0; y < col; ++y) {
                objetos[x][y] = nullptr;
            }
        }
    }
    else throw ;
}
void mapa::crear_humano(int ancho,int alto){
    objetos[ancho][alto] = new humano(ancho,alto);
    cant_humanos++;
}
void mapa::crear_cazador(int ancho, int alto) {
    objetos[ancho][alto]  = new cazavampiro(ancho,alto);
    cant_humanos++;
}
void mapa::crear_Vanesa(int ancho,int alto){
    if(!Vanesa) {
        objetos[ancho][alto] = new class Vanesa(ancho, alto);
        cant_humanos++;
        Vanesa = true;
    }
}
void mapa::crear_zombi(int ancho,int alto){
    objetos[ancho][alto]  = new zombi(ancho,alto);
    cant_zombis++;
}
void mapa::crear_vampiro(int ancho,int alto){
    objetos[ancho][alto]  = new vampiro(ancho,alto);
    cant_vampiros++;
}
void mapa::crear_Nosferatu(int ancho,int alto){
    if(!Nosferatu) {
        objetos[ancho][alto] = new class Nosferatu(ancho, alto);
        cant_vampiros++;
        Nosferatu = true;
    }
}
void mapa::crear_Vampirella(int ancho,int alto) {
    if (!Vampirella) {
        objetos[ancho][alto] = new class Vampirella(ancho, alto);
        cant_vampiros++;
        Vampirella = true;
    }
}
void mapa::crear_agua(int ancho, int alto, int cant) {
    objetos[ancho][alto] = new agua(ancho,alto,cant);
    cant_agua++;
}
void mapa::crear_bala(int ancho,int alto,int cant){
    objetos[ancho][alto]  = new balas(ancho,alto,cant);
    cant_balas += cant;
}
void mapa::crear_cruz(int ancho,int alto){
    objetos[ancho][alto]  = new cruz(ancho,alto);
    cant_cruces++;
}
void mapa::crear_estaca(int ancho,int alto){
    objetos[ancho][alto]  = new estaca(ancho,alto);
    cant_estacas++;
}
void mapa::crear_escopeta(int ancho,int alto){
    objetos[ancho][alto]  = new escopeta(ancho,alto);
    cant_escopetas++;
}

void mapa::mostrar_informacion() {
    double total = cant_humanos + cant_vampiros + cant_zombis;
    double total_melee= cant_agua + cant_cruces + cant_estacas;
    std::cout<<"elemento      |"<<" cantidad   |"<<" Porcentaje sobre el total"<<std::endl;
    std::cout<<"----------------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"Humanos       |"<<"  "<<cant_humanos<<"         |"<<(cant_humanos * 100)/total<<std::endl;
    std::cout<<"----------------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"vampiros      |"<<"  "<<cant_vampiros<<"         |"<<(cant_vampiros * 100)/total<<std::endl;
    std::cout<<"----------------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"zombies       |"<<"  "<<cant_zombis<<"         |"<<(cant_zombis * 100)/total<<std::endl;
    std::cout<<"----------------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"aguabendita   |"<<"  "<<cant_agua<<"         |"<<(cant_agua * 100)/total_melee<<std::endl;
    std::cout<<"----------------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"cruces        |"<<"  "<<cant_cruces<<"         |"<<(cant_cruces * 100)/total_melee<<std::endl;
    std::cout<<"----------------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"balas         |"<<"  "<<cant_balas<<"         |"<<(cant_balas * 100)/cant_escopetas<<std::endl;
    std::cout<<"----------------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"escopetas     |"<<"  "<<cant_escopetas<<"         |"<<(cant_escopetas * 100)/cant_balas<<std::endl;
    std::cout<<"----------------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"estacas       |"<<"  "<<cant_estacas<<"         |"<<(cant_estacas * 100)/total_melee<<std::endl;
    std::cout<<"----------------------------------------------------------------------------------------"<<std::endl;
}

void mostrar_menu_objetos(){
    std::cout << "\nElija el objeto por el que desea consultar:" << std::endl;
    std::cout << "\t   " << c_humano << " - " << "HUMANO" << std::endl;
    std::cout << "\t   " << c_zombi << " - " << "ZOMBI" << std::endl;
    std::cout << "\t   " << c_vampiro << " - " << "VAMPIRO" << std::endl;
    std::cout << "\t   " << c_agua << " - " << "AGUA_BENDITA" << std::endl;
    std::cout << "\t   " << c_cruz << " - " << "CRUZ" << std::endl;
    std::cout << "\t   " << c_estaca << " - " << "ESTACA" << std::endl;
    std::cout << "\t   " << c_escopeta<< " - " << "ESCOPETA" << std::endl;
    std::cout << "\t   " << c_balas << " - " << "BALA" << std::endl;
    std::cout << "\t   " << c_Vanesa << " - " << "VANESA" << std::endl;
    std::cout << "\t   " << c_Vampirella << " - " << "VAMPIRELLA" << std::endl;
    std::cout << "\t " << c_Nosferatu << " - " << "NOSFERATU" << std::endl;
    std::cout << "\t " << c_Cazador << " - " << "humano cazavampiros" << std::endl;
    std::cout << "\t(" << c_salir << ") - Salir del menú" << std::endl;
}
void mostrar_menu_cuadrantes(){
    std::cout << "\nElija cuadrante por el que desea consultar:"<< std::endl;
    std::cout << "\t   " << 1 << " - cuadrante noroeste" << std::endl;
    std::cout << "\t   " << 2 << " - cuadrante noreste" << std::endl;
    std::cout << "\t   " << 3 << " - cuadrante suroeste" << std::endl;
    std::cout << "\t   " << 4 << " - cuadrante sureste" << std::endl;
    std::cout << "\t(" << 0 << ") - Salir del menú" << std::endl;
}
void mapa::buscar_otros(int cuadrante,const std::string& objeto) {
    bool esta=false;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < col; ++j) {
            if ((cuadrante == 1 && objetos[i][j]!= nullptr ) && (objetos[i][j]->dar_simbolo()==objeto)&&
            objetos[i][j]->dar_fila() < filas/2 && objetos[i][j]->dar_col() <col/2) {
                esta = true;
            } else if ((cuadrante == 2 && objetos[i][j]!= nullptr) && (objetos[i][j]->dar_simbolo()==objeto)
            && objetos[i][j]->dar_fila() < filas/2 && objetos[i][j]->dar_col() >=col/2) {
                esta = true;
            } else if ((cuadrante == 3 && objetos[i][j]!= nullptr) && (objetos[i][j]->dar_simbolo()==objeto)
            && objetos[i][j]->dar_fila() >= filas/2 && objetos[i][j]->dar_col() <col/2) {
                esta = true;
            } else if ((cuadrante == 4 && objetos[i][j]!= nullptr) && (objetos[i][j]->dar_simbolo()==objeto)
            && objetos[i][j]->dar_fila() >= filas/2 && objetos[i][j]->dar_col() >=col/2) {
                esta = true;
            }
        }
    }
    if (esta){
        std::cout<<"existe en ese cuadrante"<<std::endl;
    }
    else{
        std::cout<<" no existe en ese cuadrante"<<std::endl;
    }
}
void mapa::buscar_humano(int cuadrante){
    bool esta=false;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < col; ++j) {
            if ((cuadrante == 1 && objetos[i][j]!= nullptr) && (objetos[i][j]->dar_simbolo()==c_humano ||
                                    objetos[i][j]->dar_simbolo()==c_Vanesa||
                                    objetos[i][j]->dar_simbolo()==c_Cazador)
                                    && objetos[i][j]->dar_fila() < filas/2 && objetos[i][j]->dar_col() <col/2) {
                esta = true;
            } else if ((cuadrante == 2 && objetos[i][j]!= nullptr) && (objetos[i][j]->dar_simbolo()==c_humano ||
                                            objetos[i][j]->dar_simbolo()==c_Vanesa||
                                            objetos[i][j]->dar_simbolo()==c_Cazador)
                                            && objetos[i][j]->dar_fila() < filas/2 && objetos[i][j]->dar_col() >=col/2) {
                esta = true;
            } else if ((cuadrante == 3 && objetos[i][j]!= nullptr) && (objetos[i][j]->dar_simbolo()==c_humano ||
                                            objetos[i][j]->dar_simbolo()==c_Vanesa||
                                            objetos[i][j]->dar_simbolo()==c_Cazador)
                                            && objetos[i][j]->dar_fila() >= filas/2 && objetos[i][j]->dar_col() <col/2) {
                esta = true;
            } else if ((cuadrante == 4 && objetos[i][j]!= nullptr) && (objetos[i][j]->dar_simbolo()==c_humano ||
                                            objetos[i][j]->dar_simbolo()==c_Vanesa||
                                            objetos[i][j]->dar_simbolo()==c_Cazador)
                                            && objetos[i][j]->dar_fila() >= filas/2 && objetos[i][j]->dar_col() >=col/2) {
                esta = true;
            }
        }
    }
    if (esta){
        std::cout<<"existe en ese cuadrante"<<std::endl;
    }
    else{
        std::cout<<" no existe en ese cuadrante"<<std::endl;
    }
}
void mapa::buscar_vampiro(int cuadrante){
    bool esta=false;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < col; ++j) {
            if ((cuadrante == 1 && objetos[i][j]!= nullptr) && (objetos[i][j]->dar_simbolo()==c_vampiro ||
                                     objetos[i][j]->dar_simbolo()==c_Nosferatu||
                                     objetos[i][j]->dar_simbolo()==c_Vampirella)
                                     && (objetos[i][j]->dar_fila() < filas/2 && objetos[i][j]->dar_col() <col/2)) {
                esta = true;
            }
            else if ((cuadrante == 2 && objetos[i][j]!= nullptr) && (objetos[i][j]->dar_simbolo()==c_vampiro ||
                                            objetos[i][j]->dar_simbolo()==c_Nosferatu||
                                            objetos[i][j]->dar_simbolo()==c_Vampirella)
                                            && objetos[i][j]->dar_fila() < filas/2 && objetos[i][j]->dar_col() >= col/2) {
                esta = true;
            }
            else if ((cuadrante == 3 && objetos[i][j]!= nullptr) && (objetos[i][j]->dar_simbolo()==c_vampiro ||
                                            objetos[i][j]->dar_simbolo()==c_Nosferatu||
                                            objetos[i][j]->dar_simbolo()==c_Vampirella)
                                            && objetos[i][j]->dar_fila() >= filas/2 && objetos[i][j]->dar_col() <col/2) {
                esta = true;
            }
            else if ((cuadrante == 4 && objetos[i][j]!= nullptr) && (objetos[i][j]->dar_simbolo()==c_vampiro ||
                                            objetos[i][j]->dar_simbolo()==c_Nosferatu||
                                            objetos[i][j]->dar_simbolo()==c_Vampirella)
                                            && objetos[i][j]->dar_fila() >= filas/2 && objetos[i][j]->dar_col() >=col/2) {
                esta = true;
            }
        }
    }
    if (esta){
        std::cout<<"existe en ese cuadrante"<<std::endl;
    }
    else{
        std::cout<<" no existe en ese cuadrante"<<std::endl;
    }
}

void mapa::buscar_objetos(int cuadrante, const std::string& objeto){
    if(objeto==c_humano)buscar_humano(cuadrante);
    else if(objeto==c_vampiro)buscar_vampiro(cuadrante);
    else buscar_otros(cuadrante,objeto);
}
bool validar_objeto(const std::string& objeto){
    return (objeto == c_humano||
            objeto == c_zombi||
            objeto == c_vampiro||
            objeto == c_agua||
            objeto == c_cruz||
            objeto == c_estaca||
            objeto == c_escopeta||
            objeto == c_balas||
            objeto == c_Vanesa||
            objeto == c_Vampirella||
            objeto == c_Nosferatu||
            objeto == c_Cazador||
            objeto == c_salir);
}
bool validar_cuadrante(int cuadrante){
    return (cuadrante==1||cuadrante==2||cuadrante==3||cuadrante==4||cuadrante==0);
}
void mapa::buscar(){
    int cuadrante=-1;
    std::string objeto;
    while(!validar_cuadrante(cuadrante)){
        mostrar_menu_cuadrantes();
        std::cin >> cuadrante;
    }
    if(cuadrante==0)std::cout<<"adios"<<std::endl;
    else {
        while(!validar_objeto(objeto)){
            mostrar_menu_objetos();
            std::cin>>objeto;
        }
        if(objeto == c_salir)std::cout<<"adios"<<std::endl;
        else buscar_objetos(cuadrante,objeto);
    }
}
mapa::~mapa() {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < col; ++j) {
            delete objetos[i][j];
        }
    }
    for (int i = 0; i < filas; ++i) {
        delete[] objetos[i];
        objetos[i]=nullptr;
    }
    delete []objetos;
    objetos=nullptr;
}
