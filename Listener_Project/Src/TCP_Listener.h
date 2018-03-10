#pragma once
#include <WS2tcpip.h> // Header file for Winsock functions
#include<string>
#pragma comment(lib,"ws2_32.lib")// Winsock Library file
#define MAX_BUFFER_SIZE 4096
// TODO: Callback to data received
class Class_tcp_Listener;

typedef void(*MessageReceivedHandler)(Class_tcp_Listener*listener, int socketId, std::string msg);

class Class_tcp_Listener {
public:
	Class_tcp_Listener(std::string ipAddress, int port, MessageReceivedHandler handler);
	~Class_tcp_Listener();
	// send a message to the specified client
	void Send(int clientSocket, std::string msg);

	//Initialize winsock
	bool init();
	//main process loop
	void Run();
	//Cleanup
	void Cleanup();

	//Receive loop
	//Send back Message
	//Cleanup
private:
	//create a socket
	SOCKET CreateSocket();
	//Wait for a connection
	SOCKET WaitForConnection(SOCKET listening);
	std::string				m_ipAddress;
	int						m_port;
	MessageReceivedHandler	MessageReceived;
};