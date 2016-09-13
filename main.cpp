#include <SFML/Network.hpp>
#include <iostream>
#include "Client.h"
#include "Server.h"

int main()
{
	std::string name = "";
	std::cout << "What would you like your name to be? ";
	std::cin >> name;
	if (name == "server")
	{
		Server server;
		while (true)
		{
			server.recieveClients();
			std::string data = server.recieveData();
			server.broadcastData(data);
		}
	}
	std::cout << std::endl;

	std::string ip = "";
	std::cout << "Please enter IP address to connect to: ";
	std::cin >> ip;
	std::cout << std::endl;

	Client client(ip, 25565, name);
	while (true)
	{
		std::string message = client.getMessage();
		client.sendMessage(message);
		client.recieveMessage();
	}
	return 0;
}