#include "stdafx.h"
#include "Node.h"

Node::Node(bool light)
{
	Light = light;
	Next = NULL;
	Prev = NULL;
}
