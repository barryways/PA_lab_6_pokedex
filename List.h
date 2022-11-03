#pragma once
#include "Pokemon.h"

ref class Lista
{
public:
	Pokemon^ head;
	Pokemon^ tail;

	void Add(int national_Number, String^ name_pokemon, int generation_pokemon);
	int Count();
	int GetNationalNumber(int index);
	String^ GetNamePokemon(int index);
	int GetGeneration(int index);
	void RemoveAtStart();
	void RemoveAtEnd();
	void RemoveAt(int index);
	bool IsEmpty();
};