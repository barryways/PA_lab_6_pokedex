#include "pch.h"
#include "List.h"

void Lista::Add(String^ name_pokemon, int national_Number, int generation_pokemon) {
	Pokemon^ nuevo = gcnew Pokemon();
	nuevo->nationalNumber = national_Number;
	nuevo->nombre = name_pokemon;
	nuevo->generacion = generation_pokemon;
	if (IsEmpty()) {
		head = nuevo;
		tail = nuevo;
	}
	else {
		tail->next = nuevo;
		tail = nuevo;
	}
	size++;
}

bool Lista::AddAt(String^ nombre, int Numero, int generacion, int index)
{
	if (head == nullptr || index == 0)
	{
		Add(nombre, Numero, generacion);
		return true;
	}
	int i = 0;
	Pokemon^ Current = head;
	while (i < (index - 1) && Current != nullptr)
	{
		Current = Current->next;
		i++;
	}
	if (Current == nullptr)
		return false;
	Pokemon^ New = gcnew Pokemon();
	New->nombre = nombre;
	New->nationalNumber = Numero;
	New->generacion = generacion;
	New->next = Current->next;
	Current->next = New;
	size++;
}

int Lista::GetNationalNumber(int index) {
	if (index >= 0 && index < Count())
	{
		Pokemon^ temporal = head;
		int posicion = 0;

		while (posicion < index)
		{
			temporal = temporal->next;
			posicion++;
		}

		return temporal->nationalNumber;
	}
}

String^ Lista::GetNamePokemon(int index) {
	if (index >= 0 && index < Count())
	{
		Pokemon^ temporal = head;
		int posicion = 0;

		while (posicion < index)
		{
			temporal = temporal->next;
			posicion++;
		}

		return temporal->nombre;
	}
}
int Lista::GetGeneration(int index) {
	if (index >= 0 && index < Count())
	{
		Pokemon^ temporal = head;
		int posicion = 0;

		while (posicion < index)
		{
			temporal = temporal->next;
			posicion++;
		}

		return temporal->generacion;
	}
}

bool Lista::IsEmpty() {
	if (head == nullptr)
	{
		return true;
	}
	else {
		return false;
	}
}

int Lista::Count() {
	int cantidad = 0;
	for (Pokemon^ i = head; i != nullptr; i = i->next)
	{
		cantidad++;
	}
	return cantidad;
}

bool Lista::Delete(int value)
{
	int index = Search(value);
	if (index == -1)
		return false;
	return DeleteIndex(index);
}

String^ Lista::Print()
{
	String^ res = nullptr;
	Pokemon^ Current;
	Current = head;
	while (Current != nullptr)
	{
		res += Current->nombre + "\t" + Current->nationalNumber.ToString() + "\t" + Current->generacion.ToString() + "\n";
		Current = Current->next;
	}
	return res;
}


String^ Lista::PrintWithCommas()
{
	String^ res = nullptr;
	Pokemon^ Current;
	Current = head;
	while (Current != nullptr)
	{
		res += Current->nombre + "," + Current->nationalNumber.ToString() + "," + Current->generacion.ToString() + "\n";
		Current = Current->next;
	}
	return res;
}



int Lista::Search(int numero)
{
	int index = 0;
	Pokemon^ Current = head;
	while (Current->nationalNumber != numero && Current != nullptr)
	{
		Current = Current->next;
		index++;
	}
	if (Current == nullptr)
		return -1;
	else
		return index;
}

bool Lista::DeleteIndex(int index)
{
	if (index == 0)
	{
		Pokemon^ ToDelete = head;
		head = head->next;
		delete ToDelete;

	}
	else
	{
		Pokemon^ Anterior = head;
		int i = 0;
		while (i < index - 1)
		{
			Anterior = Anterior->next;
			i++;
		}
		Pokemon^ ToDelete = Anterior->next;
		Anterior->next = ToDelete->next;
		delete  ToDelete;

	}
	size--;
	return true;
}
bool Lista::IsSorted()
{
	bool Sorted = true;
	Pokemon^ Current = head;
	while (Current != nullptr && Current->next != nullptr)
	{
		if (Current->nationalNumber >= Current->next->nationalNumber)
			Sorted = false;
		Current = Current->next;
	}
	return Sorted;
}
