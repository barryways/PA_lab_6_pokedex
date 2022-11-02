#include "pch.h"
#include <iostream>
#include <sstream>
#include <fstream>



using namespace System;

int leerArchivo() {
    ifstream archivo("productos.csv");
    string linea;
    char delimitador = ',';
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las líneas
    while (getline(archivo, linea))
    {

        // Magia aquí...
    }

    archivo.close();
}

int main(array<System::String ^> ^args)
{

    return 0;
}
