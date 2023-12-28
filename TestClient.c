#ifdef compile
nc -w5 -z -v 192.168.1.88 20004
sudo gcc -g -std=c99 -v TestClient.c -o TestClient
#endif

#define _OE_SOCKETS
#include <unistd.h>

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <poll.h>

#define IP_ADDRESS "192.168.1.88"
#define PORT 20004

int main(int, char const **);

int main(int argc, char const *argv[])
{
	int sock =0, valread;
	struct sockaddr_in serv_addr;
	char buffer[20000] = {0};
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return(-1);
	}

	//fcntl(sock, F_SETFL,O_NONBLOCK);

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	if (inet_pton(AF_INET, IP_ADDRESS, &serv_addr.sin_addr) <= 0)
	{
		printf("invalid address / Address not supported \n");
		return (-1);
	}

	int retno=0;
	retno = connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
	if (retno < 0)
	{
		printf("connection failed, errno = %d \n", errno);
		return (-1);
	}
	printf("connect success \n");

	#ifdef TEST
	retno = send(sock, "Hello from Client\0", strlen("Hello from Client"), 0 );
	if (retno <0)
	{
		printf("send failed, errno = %d \n", errno);
		return (-1);
	}
	else
	{
		printf("Hello successfully sent by Client \n");
	#endif
		printf("Before read() function \n");
		int remainbytes = 20000;
		struct pollfd ufds[1];
		ufds[0].fd =0;
		ufds[0].events = POLLIN;

		while (1)
		{
			poll(ufds, 1, 20000);

			valread = read(0, buffer, 20000);		// stuck here!!!
			printf("number of bytes read : %d\n", valread);
			if (valread < remainbytes)
				remainbytes = remainbytes - valread;
		}

		//printf("Before recv() function \n");
		//int iRecvSize = 0;
		//while ((iRecvSize = recv(sock, buffer, 20000-1, MSG_DONTWAIT)) >0)
		//while ((iRecvSize = recv(sock, buffer, 20000-1, 0)) >0)
		//{
		//	if ( (iRecvSize == -1) & (errno!=EWOULDBLOCK) )
		//		return(-1);
		//}
		printf("response from Server : %s \n", buffer);

		return 0;
	#ifdef TEST
	}
	#endif
}
