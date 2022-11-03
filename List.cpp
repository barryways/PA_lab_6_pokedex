#include "pch.h"
#include "List.h"

void Lista::Add(int national_Number, String^ name_pokemon, int generation_pokemon) {
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

void Lista::RemoveAtStart() {
	Pokemon^ temporal = head;
	if (!IsEmpty())
	{
		head = head->next;
		if (Count() == 1)
		{
			tail = head;
		}
	}
}

void Lista::RemoveAtEnd() {
	Pokemon^ temporal = tail;
	if (!IsEmpty())
	{
		if (Count() == 1)
		{
			tail = tail->next;
			head = tail;
		}
		else {
			Pokemon^ anterior = head;
			temporal = anterior->next;
			while (temporal != tail)
			{
				anterior = temporal;
				temporal = temporal->next;
			}
			anterior->next = temporal->next;
			tail = anterior;
		}
	}
}

void Lista::RemoveAt(int index) {
	Pokemon^ temporal = head;
	if (!IsEmpty())
	{
		if (Count() == 1 || index == 0)
		{
			RemoveAtStart();
		}
		else {
			if (index >= Count())
			{
				RemoveAtEnd();
			}
			else {
				Pokemon^ anterior = head;
				temporal = anterior->next;
				int pos = 1;
				while (temporal != tail && pos < index)
				{
					anterior = temporal;
					temporal = temporal->next;
					pos++;
				}
				anterior->next = temporal->next;
			}
		}
	}
}

bool Lista::IsEmpty() {//Verifica si la lista esta vacía
	if (head == nullptr)
	{
		return true;//Si la cabeza apunta a null, la lista esta vacía
	}
	else {
		return false;
	}
}

int Lista::Count() {//Cuenta la cantidad de elementos en la lista
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
	length--;
	return true;
}