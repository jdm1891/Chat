#include "Client.h"
#include <iostream>


Client::Client(std::string ip, int port, std::string name)
{
	_status = _socket.connect(sf::IpAddress(ip), port);
	_name = name;
	if (_status != sf::Socket::Done)
	{
		std::cout << "Unable to connect!" << std::endl;
	}
	else
	{
		std::cout << "Successfully connected to " << _socket.getRemoteAddress() << " at port " << _socket.getRemotePort() << std::endl;
	}
}

std::string Client::getMessage()
{
	std::string input;
	std::cout << _name << ": ";
	std::cin >> input;
	std::cout << std::endl;
	return input;
}

void Client::sendMessage(std::string message)
{
	message = _name + ": " + message;
	std::vector<char> toSend;
	for (char character : message)
	{
		toSend.push_back(character);
	}
	char* toSendArray = &toSend[0];
	if (_socket.send(toSendArray,toSend.size()) != sf::Socket::Done)
	{
		std::cout << "Error sending message";
	}
}

void Client::recieveMessage()
{
	char data[1000];
	std::size_t received;
	if (_socket.receive(data, 1000, received) != sf::Socket::Done)
	{
		std::cout << "Error: Corrupted data";
	}
	else
	{
		for (char character : data)
		{
			std::cout << character;
		}
		std::cout << std::endl;
	}
}


Client::~Client()
{
}
