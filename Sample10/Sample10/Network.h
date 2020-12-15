#pragma once
#ifndef _NETWORK_H
#define _NETWORK_H

static int _idMessage = 0;
int NewId() {
	return _idMessage++;
}

#include "Message.h"
#include "Queue.h"
#include "ANetworkElement.h"

struct Network {
private:
	//static int _idMessage;
	Queue<ANetworkElement*> _networkElements;
public:
	//static int NewId();
	Network() {};
	~Network() {};
	void Connect(ANetworkElement*);
	void ProcessAll();
}​​​​;

/*
int Network::NewId() {
	return _idMessage++;
}
*/
void Network::Connect(ANetworkElement* element) {
	_networkElements.Insert(element);
}

void Network::ProcessAll() {
	_networkElements.ProcessElements2(&ANetworkElement::Process);
}

#endif // !_NETWORK_H