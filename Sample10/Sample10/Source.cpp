#include <functional>
#include <iostream>
#include <string>
#include "Network.h"


#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


void createNetwork() {
	Network* s = new Network{ };
	Hub* h1 = new Hub{ 8 };
	Hub* h2 = new Hub{ 8 };
	Hub* h3 = new Hub{ 8 };
	Hub* h4 = new Hub{ 16 };
	Hub* h5 = new Hub{ 24 };
	Node* u1 = new Node{ "a1" };
	Node* u2 = new Node{ "a2" };
	Node* u3 = new Node{ "a3" };
#define propoj(a,b) a->Connect(b); b->Connect(a)
#define propojs(a,b,c) propoj(a,b); c->Connect(a); c->Connect(b)
	propojs(u1, h1, s);
	propojs(u2, h3, s);
	propojs(u3, h5, s);
	propojs(h1, h2, s);
	propojs(h2, h3, s);
	propojs(h1, h4, s);
	propojs(h4, h5, s);
	propojs(h5, h2, s);
	u1->PrepareMessageForSending("a2", "ping");
	u1->PrepareMessageForSending("a3", "ping");
	for (int i = 0; i < 100; i++)
		s->ProcessAll();

	delete s;
	delete h1;
	delete h2;
	delete h3;
	delete h4;
	delete h5;
	delete u1;
	delete u2;
	delete u3;
}

int main(int argc, char** argv)
{
	createNetwork();
	_CrtDumpMemoryLeaks();
	return 0;
}