#pragma once
#ifndef MESSAGE_H
#define MESSAGE_H



struct Message {
	int Id;
	std::string AdrSource;
	std::string AdrTarget;
	std::string Content;
	Message(int Id, std::string adrSource, std::string adrTarget, std::string content) :
		Id(Id), AdrSource(adrSource), AdrTarget(adrTarget), Content(content) {
	}
	~Message() {}
};

struct ANetworkElement;
struct MessagePort {
	Message* MessagePacket;
	ANetworkElement* Port;
	MessagePort(Message* message, ANetworkElement* Port) : MessagePacket(message), Port(Port) {
	}
	~MessagePort() {
	}

	bool operator==(const MessagePort& right) const {
		return (MessagePacket->Id == right.MessagePacket->Id);
	}
};
#endif // !MESSAGE_H
