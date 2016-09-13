#pragma once
#include <SFML/Network.hpp>
#include <string>
class Server
{
public:
	Server();
	void recieveClients();
	std::string recieveData();
	void broadcastData(std::string data);
	~Server();
protected:
	std::vector<std::reference_wrapper<sf::TcpSocket>> _clients;
	sf::TcpListener _listener;
};

