#pragma once
#include "stdafx.h"

struct node //структура циклического двунаправленного списка
{
	bool light;
	node* next;
	node* prev;
};
