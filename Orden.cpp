#include "pch.h"
#include "Orden.h"
#include "List.h"

void Orden::swap(Lista^ Lista, int i, int j) {
    	if (i != j)
	{
		String^ nom = Lista->GetNamePokemon(i);
		String^ nom2 = Lista->GetNamePokemon(j);
		int num = Lista->GetNationalNumber(i);
		int num2 = Lista->GetNationalNumber(j);
		int gen = Lista->GetGeneration(i);
		int gen2 = Lista->GetGeneration(j);
		Lista->DeleteIndex(i);
		Lista->Insert(nom2, num2, gen2, i);
		Lista->DeleteIndex(j);
		Lista->Insert(nom, num, gen, j);
	}
}


void Orden::shell_sort(int Numero, int Arreglo[]) {
   int i, j, k, incremento, aux;
   incremento = Numero / 2;
   while (incremento > 0) {
        for (i = incremento + 1; i <= Numero; i++) {
            j = i - incremento;
            while (j > 0) {
                if (Arreglo[j] >= Arreglo[j + incremento]) {
                    aux = Arreglo[j];
                    Arreglo[j] = Arreglo[j + incremento];
                    Arreglo[j + incremento] = aux;
                }
                else {
                    j = 0;
                }
                j = j - incremento;
            }
        }
        incremento = incremento / 2;
   }
}


void Orden::quick_sort(int Arreglo[], int primero, int ultimo) {
    int central, i, j;
    double pivote;
    central = (primero + ultimo) / 2;
    pivote = Arreglo[central];
    i = primero;
    j = ultimo;
    do
    {
        while (Arreglo[i] < pivote) i++;
        while (Arreglo[j] > pivote) j--;
        if (i <= j)
        {
            double temp;
            temp = Arreglo[i];
            Arreglo[i] = Arreglo[j];
            Arreglo[j] = temp;
            i++;
            j--;
        }
    }

    while (i <= j);
    if (primero < j)
        quick_sort(Arreglo, primero, j); 
    if (i < ultimo)
        quick_sort(Arreglo, i, ultimo); 
}


void Orden::selection_sort(int Arreglo[], int n) {
    for (int c = 0; c < n - 1; c++) {
        int mpos = c;
        int max = Arreglo[c];
        for (int i = c + 1; i < n; i++) {
            if (Arreglo[i] > max) {
                max = Arreglo[i];
                mpos = i;
            }
        }
        swap(Arreglo[c], Arreglo[mpos]);
    }
}