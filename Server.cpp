#include "Server.h"
#include <SFML/Network.hpp>
#include <string>
#include <iostream>


Server::Server()
{
	if (_listener.listen(25565) == sf::Socket::Error)
	{
		std::cout << "Unable to listen on port 25565" << std::endl;

	}
	else
	{
		std::cout << "Unable to listen on port 25565 with IP " << sf::IpAddress::getLocalAddress() << std::endl;
	}
	sf::TcpSocket firstClient;
	_clients.push_back(firstClient);
}

void Server::recieveClients()
{
	if (_listener.accept(_clients.back()) != sf::Socket::Done)
	{
		sf::TcpSocket nextClient;
		_clients.push_back(nextClient);
	}
}

std::string Server::recieveData()
{
	char data[1000];
	std::string dataString;
	std::size_t received;
	for (int i = 0; i < _clients.size(); i++)
	{

		if (_clients[i].get().receive(data, 1000, received) != sf::Socket::Done)
		{
			std::cout << "Error: Corrupted data";
		}
		else
		{
			for (char character : data)
			{
				std::cout << character;
				dataString += character;
			}
			std::cout << std::endl;	}
	}
	return dataString;
}

void Server::broadcastData(std::string data)
{
	for (int i = 0; i < _clients.size(); i++)
	{
		std::vector<char> toSend;
		for (char character : data)
		{
			toSend.push_back(character);
		}
		char* toSendArray = &toSend[0];
		if (_clients[i].get().send(toSendArray, toSend.size()) != sf::Socket::Done)
		{
			std::cout << "Error sending message";
		}
	}
}


Server::~Server()
{
}
