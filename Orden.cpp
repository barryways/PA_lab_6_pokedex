#include "pch.h"
#include "Pokemon.h"
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
		Lista->AddAt(nom2, num2, gen2, i);
		Lista->DeleteIndex(j);
		Lista->AddAt(nom, num, gen, j);
	}
}


void Orden::selection_sort(Lista^ Lista)
{
	int i;
	int indiceIntercambio;
	i = (Lista->size) - 1;
	while (i > 0)
	{
		indiceIntercambio = 0;
		for (int j = 0; j < i; j++)
		{
			if (Lista->GetNationalNumber(j + 1) < Lista->GetNationalNumber(j))
			{
				swap(Lista, j, j + 1);
				indiceIntercambio = j;
			}
		}
		i = indiceIntercambio;
	}
}


void Orden::shuffle(Lista^ Lista)
{
	for (int i = 0; i < Lista->size; i++)
	{
		Random rnd;
		swap(Lista, i, rnd.Next(0, Lista->size));
	}
}

void Orden::shell_sort(Lista^ Lista)
{
	while (!Lista->IsSorted())
	{
		shuffle(Lista);
	}
}

int Orden::partition(Lista^ Lista, int low, int high)
{
	int pivot = Lista->GetNationalNumber(high);
	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (Lista->GetNationalNumber(j) < pivot)
		{
			i++;
			swap(Lista, i, j);
		}
	}
	swap(Lista, i + 1, high);
	return i + 1;
}

void Orden::quick_sort(Lista^ Lista, int low, int high)
{
	if (low < high)
	{
		int pi = partition(Lista, low, high);
		quick_sort(Lista, low, pi - 1);
		quick_sort(Lista, pi + 1, high);
	}
}
