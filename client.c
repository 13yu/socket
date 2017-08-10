/*
    C ECHO client example using sockets
*/
#include<stdio.h> //printf
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr
 
int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char message[5000] , server_reply[2000];
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
    server.sin_addr.s_addr = inet_addr("101.200.190.134");
    server.sin_family = AF_INET;
    server.sin_port = htons( 88 );

    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
    puts("Connected\n");

    //keep communicating with server
	//Send some data
    int i = 0;
    for ( i = 0; i < 5000; i++)
    {
        message[i] = 'a';
    }

	if( send(sock , message , 5000 , 0) < 0)
	{
		puts("Send failed");
		return 1;
	}
	//Receive a reply from the server

	/*if( recv(sock , server_reply , 2000 , 0) < 0)*/
	/*{*/
		/*puts("recv failed");*/
	/*}*/
	/*puts("Server reply :");*/

	/*puts(server_reply);*/
    close(sock);
    return 0;
}
