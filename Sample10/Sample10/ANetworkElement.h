#pragma once
#ifndef _A_NETWORK_ELEMENT_H
#define _A_NETWORK_ELEMENT_H


struct ANetworkElement {
protected:
	Queue<MessagePort> _incomingMessages;

	virtual void processIncomingMessage(MessagePort message) = 0;
public:
	virtual ~ANetworkElement() {}
	void InsertMessage(Message* message, ANetworkElement* messagePort);
	void InsertMessage(MessagePort messagePort);
	virtual void Process() = 0;
	virtual void Connect(ANetworkElement* element) = 0;
};

void ANetworkElement::InsertMessage(Message* message, ANetworkElement* messagePort) {
	_incomingMessages.Insert(MessagePort{message, messagePort });
}

void ANetworkElement::InsertMessage(MessagePort messagePort) {
	_incomingMessages.Insert(messagePort);
}

//////////////////////////////////////////////////////////

struct Hub : public ANetworkElement {
private:
	int _counter;
	ANetworkElement** _connectedElements;
	int _maximumConnectedElements;
	Queue<MessagePort> _processedMessages;

	void processIncomingMessage(MessagePort message) override;
public:
	Hub(int size);
	~Hub();
	void Connect(ANetworkElement* element) override;
	void Process() override;
};

inline Hub::Hub(int size) : _maximumConnectedElements(size), _counter(0) {
	if (size <= 0)
		throw std::invalid_argument("velikost musi byt vetsi nez 0");
	_connectedElements = new ANetworkElement * [size] {nullptr};
}

inline Hub::~Hub() {
	delete[] _connectedElements;
}

void Hub::Connect(ANetworkElement* element) {
	if (_maximumConnectedElements == _counter)
		throw std::invalid_argument("pole je jiz plne");
	_connectedElements[_counter++] = element;
}

inline void Hub::Process() {
	_incomingMessages.ProcessElements(this,(void(ANetworkElement::*) (MessagePort))&Hub::processIncomingMessage);
	//WTF
	while (!_incomingMessages.IsEmpty()){
		_incomingMessages.Remove();
	}
}

void Hub::processIncomingMessage(MessagePort message) {
	if (_processedMessages.Contains(message)){
		return;
	}
	for (int i = 0; i < _maximumConnectedElements; i++){
		if (_connectedElements[i] != nullptr && message.Port != _connectedElements[i]){
			_connectedElements[i]->InsertMessage(message.MessagePacket, this);
		}
	}
	_processedMessages.Insert(message);
}

//////////////////////////////////////////////////////////

struct Node : public ANetworkElement {
private:
	std::string _address;
	ANetworkElement* _connectedElement;
	Queue<MessagePort> _outgoingMessages;
	Queue<Message*> _allSentMessages;

	void processIncomingMessage(MessagePort message) override;
public:
	Node(std::string address);
	~Node();
	void Connect(ANetworkElement* element) override;
	void Process() override;
	void PrepareMessageForSending(std::string target, std::string content);

};

Node::Node(std::string address) : _address(address), _connectedElement(nullptr){
}

Node::~Node() {
	while (!_allSentMessages.IsEmpty()){
		delete _allSentMessages.Remove();
	}
}

void Node::processIncomingMessage(MessagePort message){
	if (message.MessagePacket->AdrTarget.compare(_address) == 0){
		std::cout << message.MessagePacket->AdrTarget << " RECV id:" 
			<< message.MessagePacket->Id << " src: " << message.MessagePacket->AdrSource << " msg:" << message.MessagePacket->Content << std::endl;
		if ((message.MessagePacket->Content).compare("ping") == 0){
			PrepareMessageForSending(message.MessagePacket->AdrSource, "pong");
		}
	}
}

void Node::Connect(ANetworkElement* element) {
	_connectedElement = element;
}
void Node::Process() {
	_incomingMessages.ProcessElements(this, (void(ANetworkElement::*) (MessagePort)) & Node::processIncomingMessage);
	while (!_incomingMessages.IsEmpty()) {
		_incomingMessages.Remove();
	}
	if(_connectedElement != nullptr)
	_outgoingMessages.ProcessElements(_connectedElement, &ANetworkElement::InsertMessage);
}
void Node::PrepareMessageForSending(std::string target, std::string content) {
	Message* createdMessage = new Message{ NewId(), _address, target, content };
	_allSentMessages.Insert(createdMessage);
	_outgoingMessages.Insert(MessagePort{ createdMessage, this });
}

#endif // !_A_NETWORK_ELEMENT_H