#pragma once
#include <SFML/Network.hpp>
class Client
{
public:
	Client(std::string ip, int port, std::string name);
	std::string getMessage();
	void sendMessage(std::string message);
	void recieveMessage();
	~Client();
protected:
	std::string _name;
	sf::TcpSocket _socket;
	sf::Socket::Status _status;
};

