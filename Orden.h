#pragma once
#include "List.h"
ref class Orden
{
public:
	void swap(Lista^ Lista, int i, int j);
	void selection_sort(Lista^ Lista);
	void shuffle(Lista^ Lista);
	void shell_sort(Lista^ Lista);
	int partition(Lista^ Lista, int low, int high);
	void quick_sort(Lista^ Lista, int low, int high);

};

