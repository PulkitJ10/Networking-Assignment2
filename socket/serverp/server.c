/**
* @file server.c
* @brief Server side C program to demonstrate basic Socket Programming.
*
* @author Pulkit Jeph
*
* @date 8/1/2019
*/
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8080 
int main(int argc, char const *argv[]) 
{ 
	int server_fd, new_socket, valread; 
	struct sockaddr_in address; 
	int opt = 1; 
	int addrlen = sizeof(address); 
	char buffer[1024] = {0}; 
	char *hello = "Hello from server!"; 
	
    /**
* This will be used to create a socket file descriptor.
* @author Pulkit
* @param server_fd  Socket descriptor, an integer
* @date 8/1/2019
*/
	// Creating socket file descriptor 
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
	{ 
		perror("Socket failed!"); 
		exit(EXIT_FAILURE); 
	} 

/**
* This will be used to forcefully attach the socket to port 8080.
* @author Pulkit
* @param server_fd  Socket descriptor, an integer
* @date 8/1/2019
*/	
	// Forcefully attaching socket to the port 8080 
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
												&opt, sizeof(opt))) 
	{ 
		perror("setsockopt"); 
		exit(EXIT_FAILURE); 
	} 
	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY; 
	address.sin_port = htons( PORT ); 
	
 /**
* This will be used to forcefully attach the socket to port 8080.
* @author Pulkit
* @param server_fd  Socket descriptor,an integer
* @date 8/1/2019
*/	

	// Forcefully attaching socket to the port 8080 
	if (bind(server_fd, (struct sockaddr *)&address, 
								sizeof(address))<0) 
	{ 
		perror("Bind failed!"); 
		exit(EXIT_FAILURE); 
	} 
	if (listen(server_fd, 3) < 0) 
	{ 
		perror("listen"); 
		exit(EXIT_FAILURE); 
	} 
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
					(socklen_t*)&addrlen))<0) 
	{ 
		perror("accept"); 
		exit(EXIT_FAILURE); 
	} 
	valread = read( new_socket , buffer, 1024); 
	printf("%s\n",buffer ); 
	send(new_socket , hello , strlen(hello) , 0 ); 
	printf("Hello message sent!\n"); 
	return 0; 
} 
