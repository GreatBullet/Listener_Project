#include <iostream>
#include <string>
#include "TCP_Listener.h"
void Listener_MessageReceived(Class_tcp_Listener* listener, int client, std::string msg) {
	listener->Send(client, msg);
}

void main() {
	Class_tcp_Listener server("127.0.0.1", 54000, Listener_MessageReceived);
	if (server.init()) {
		server.Run();
	}
}
