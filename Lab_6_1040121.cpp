#include "pch.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "List.h"

using namespace System;


void leerArchivo() {//creditos a Parzibyte´s Blog (https://parzibyte.me/blog/2021/04/16/leer-csv-cpp/)
    std::ifstream archivo("Pokemon.csv");
    std::string linea;
    char delimitador = ',';
    getline(archivo, linea);
    while (getline(archivo, linea))
    {
        std::stringstream stream(linea);
        std::string nombrePokemon, nationalNumber, generacion;
        getline(stream, nombrePokemon, delimitador);
        getline(stream, nationalNumber, delimitador);
        getline(stream, generacion, delimitador);
        std::cout << "==================" << std::endl;
        std::cout << "Nombre del Pokemon: " << nombrePokemon << std::endl;
        std::cout << "National Number : " << nationalNumber << std::endl;
        std::cout << "Generacion: " << generacion << std::endl;
    }
    archivo.close();
}

void crearArchivo() {
    Lista^ lista = gcnew Lista();
    int opcion_crear_archivo;
    try
    {
        do
        {
            std::cout << "¿Qué desea hacer? \n\r1.Agregar pokemon\n\r2.Ver cantidad de pokemones\n\r3.Ordenar" << std::endl;
            std::cin >> opcion_crear_archivo;
            if (opcion_crear_archivo==1)
            {
                lista->Add(255, "Torchic", 3);

            }
        } while (opcion_crear_archivo != 0);
    }
    catch (const std::exception&)
    {
        std::cout << "Lo sentimos, esa opcion no es soportada por el programa" << std::endl;
    }
}

void cargarArchivo() {
    leerArchivo();
}

void eleccionMenu(int opcionMenu) {

    switch (opcionMenu)
    {
    case 1:
        std::cout << "Usted ingreso a la opcion \"Crear Archivo\"" << std::endl;
        crearArchivo();
        break;
    case 2:
        std::cout <<"Usted ingreso a la opcion \"Ordenar Archivo\"" << std::endl;
        cargarArchivo();
        break;
    case 0:
        std::cout << "Gracias por usar el programa" << std::endl;
        break;
    default:
        std::cout << "No selecciono una opcion valida para el programa" << std::endl;
        break;
    }
}

int main(array<System::String ^> ^args)
{
    
    
    int opcion;
    try
    {
        do
        {
            std::cout << "¿Qué desea hacer? \n\r1.Crear Archivo CSV\n\r1.Cargar Archivo CSV\n\r0.Salir" << std::endl;
            std::cin >> opcion;
            eleccionMenu(opcion);
        } while (opcion != 0);
    }
    catch (const std::exception&)
    {
        std::cout << "Lo sentimos, esa opcion no es soportada por el programa" << std::endl;
    }
    return 0;
}
