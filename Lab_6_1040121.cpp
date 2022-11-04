#include "pch.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "List.h"
#include "Orden.h"
using namespace System;

void escribirArchivo(std::string listaCompleta) {
    std::ofstream archivo;

    archivo.open("exportado.csv", std::ios::out);
    if (archivo.fail())
    {
        std::cout << "no se pudo interactuar con el archivo" << std::endl;
    }
    archivo << listaCompleta;
}

void MarshalString(String^ s, std::string& os) {
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
}

std::string lista_imprimir(Lista^ lista, std::string listaPrinter) {
    MarshalString(lista->Print(), listaPrinter);
    return listaPrinter;
}

std::string lista_imprimir_commas(Lista^ lista, std::string listaPrinter) {
    MarshalString(lista->PrintWithCommas(), listaPrinter);
    return listaPrinter;
}



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

void cargarArchivo() {
    leerArchivo();
}

void MenuOrdenar(Lista^ lista, int opcion) {
    Orden^ ordenamiento = gcnew Orden();
    switch (opcion)
    {
    case 1://selection
        ordenamiento->selection_sort(lista);
        break;
    case 2://quick
        ordenamiento->quick_sort(lista, 0, (lista->size-1));
        break;
    case 3://shell
        ordenamiento->shell_sort(lista);
        break;
    default:
        break;
    }

}



void crearArchivo() {
    Lista^ lista = gcnew Lista();
    int opcion_crear_archivo;
    try
    {
        do
        {
            std::string listaPrinter;
            
            std::cout << "¿Qué desea hacer? \n\r1.Agregar pokemon\n\r2.Ver cantidad de pokemones\n\r3.Ordenar\n\r4.Exportar fichero" << std::endl;
            std::cin >> opcion_crear_archivo;
            switch (opcion_crear_archivo)
            {
            case 1:
                try
                {
                    std::string nombrePokemon;
                    std::cout << "Que pokemon desea agregar (nombre)" << std::endl;
                    std::cin >> nombrePokemon;

                    String^ nombrePokemon_c = gcnew String(nombrePokemon.c_str());
                    int nationalNumber = 0;
                    std::cout << "Que pokemon desea agregar (national number)" << std::endl;
                    std::cin >> nationalNumber;


                    int numeroGeneracion = 0;
                    std::cout << "Que pokemon desea agregar (generacion)" << std::endl;
                    std::cin >> numeroGeneracion;

                    if (numeroGeneracion != NULL && nationalNumber != NULL && nombrePokemon != "")
                    {
                        lista->Add(nombrePokemon_c, nationalNumber, numeroGeneracion);
                        std::cout << "Sus datos fueron guardados exitosamente" << std::endl;
                    }
                    else {
                        std::cout << "No se pudieron guardar sus datos debido a que hay un error en algun dato ingresado" << std::endl;
                    }

                }
                catch (const std::exception&)
                {
                    std::cout << "No se pudieron guardar sus datos debido a que hay un error en algun dato ingresado, verifique" << std::endl;
                }
                break;
            case 2:
                
                std::cout << lista_imprimir(lista, listaPrinter) << std::endl;
                break;
            case 3:
                int opcionOrdenar;
                std::cout << "¿Con que metodo desea ordenar la lista?\n\r1.Selection Sort\n\r2.Quick Sort\n\r3.Shell Sort" << std::endl;
                std::cin >> opcionOrdenar;
                if (opcionOrdenar !=NULL)
                {
                    MenuOrdenar(lista, opcionOrdenar);
                }
                break;
            case 4:
                escribirArchivo(lista_imprimir_commas(lista, listaPrinter));
                break;
            default:
                break;
            }

        } while (opcion_crear_archivo != 0);
    }
    catch (const std::exception&)
    {
        std::cout << "Lo sentimos, esa opcion no es soportada por el programa" << std::endl;
    }
}



void eleccionMenu(int opcionMenu) {

    switch (opcionMenu)
    {
    case 1:
        std::cout << "Usted ingreso a la opcion \"Crear Archivo\"" << std::endl;
        crearArchivo();
        break;
    case 2:
        std::cout <<"Usted ingreso a la opcion \"Cargar Archivo\"" << std::endl;
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
            std::cout << "¿Qué desea hacer? \n\r1.Crear Archivo CSV\n\r2.Cargar Archivo CSV\n\r0.Salir" << std::endl;
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
