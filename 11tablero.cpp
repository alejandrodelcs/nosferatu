void cargarTerreno(){
    std::ifstream archivo;
    archivo.open("tablero.txt", std::ios::in);

    std::string coordenadaXStr, coordenadaYStr;
    int ancho,largo;
    std::string terreno;

    if (archivo.is_open()){
        std::cout << "el archivo de tablero se abrio de manera exitosa" << std::endl;
        getline(archivo, coordenadaXStr, ' ');
        getline(archivo, coordenadaYStr);
        ancho = stoi(coordenadaXStr);
        largo = stoi(coordenadaYStr);
        for (int j = 0; j < largo; j++) {
            for(int i=0; i< ancho; i++){
                getline(archivo, terreno, ',');
                //tablero[j][i].asignarTerreno(terreno);
            }
        }
    }
}