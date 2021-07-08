#ifndef TP2_MAPA_H
#define TP2_MAPA_H
#include "constantes.h"
class mapa{
private:
    objeto ***objetos;
    int cant_humanos;
    int cant_vampiros;
    int cant_zombis;
    int cant_agua;
    int cant_cruces;
    int cant_balas;
    int cant_escopetas;
    int cant_estacas;
    bool Vanesa;
    bool Nosferatu;
    bool Vampirella;
    int filas;
    int col;
public:
    /*
     * Post:constructor de mapa
     */
    mapa();
    /*PRE::exista el archivo y que las filas y columnas sean pares
     * POST::Crea el tablero y lo completa
     */
    int crear();
    /*
     * PRE::
     * POST::busca un objeto por cuadrante
     */
    void buscar_objetos(int cuadrante ,const std::string& objetos);

    /*
     * POST::elimina un objeto
     */
    void dar_baja();
    /*PRE:el espacio este vacio
     * POST::crea un objeto en el lugar seleccionado
     */
    void dar_alta();
    /*
     * POST:muestra la informacion de los objetos en el tablero
     */
    void mostrar_informacion();
    /*
     * POST::lanza la opcion para inicar las busquedas de objeto
     */
    void buscar();
    /*
     * POST::muestra el tablero
     */
    void mostrar();
    /*
     * POST:elimina el talbero
     */
    ~mapa();
private:
    /*
    *POST::busca humanos
    */
    void buscar_humano(int cuadrante);
    /*
     *POST::busca vampiros
     */
    void buscar_vampiro(int cuadrante);
    /*
     *POST::busca los elementos
     */
    void buscar_otros(int cuadrante,const std::string& objeto);
    /*
     *POST::crea el tablero
     */
    void crear_tablero();
    /*
     *POST::cambia las filas del tablero
     */
    void cambiar_filas(int ancho);
    /*
     *POST::cambia las columnas de la matriz
     */
    void cambiar_col(int alto);
    //POST::crea un humano
    void crear_humano(int ancho,int alto);
    //POST::crea un cazavampiros
    void crear_cazador(int ancho,int alto);
    //PRE::no exista una Vanesa previa
    //POST::crea a Vanesa
    void crear_Vanesa(int ancho,int alto);
    //POST::crea un zombi
    void crear_zombi(int ancho,int alto);
    //POST::crea un vampiro
    void crear_vampiro(int ancho,int alto);
    //PRE::no exista un Nosferatu previo
    //POST::crea a Nosferatu
    void crear_Nosferatu(int ancho,int alto);
    //PRE::no exista una Vampirella previa
    //POST::crea a Vampirella
    void crear_Vampirella(int ancho,int alto);
    //POST::crea agua
    void crear_agua(int ancho,int alto,int cant);
    //POST::crea balas
    void crear_bala(int ancho,int alto,int cant);
    //POST::crea una cruz
    void crear_cruz(int ancho,int alto);
    //POST::crea una estaca
    void crear_estaca(int ancho,int alto);
    //POST::crea una escopeta
    void crear_escopeta(int ancho,int alto);
};
#endif //TP2_MAPA_H
