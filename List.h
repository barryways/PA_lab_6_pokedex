#pragma once
#include "Pokemon.h"

ref class Lista
{
public:
	Pokemon^ head;
	Pokemon^ tail;

	int size;
	void Add(String^ name_pokemon, int national_Number, int generation_pokemon);
	bool AddAt(String^ nombre, int Numero, int generacion, int index);
	int Count();
	int GetNationalNumber(int index);
	String^ GetNamePokemon(int index);
	int GetGeneration(int index);
	bool Delete(int value);
	bool DeleteIndex(int index);
	int Search(int value);
	bool IsEmpty();
	String^ Print();
	String^ PrintWithCommas();
	bool IsSorted();
};