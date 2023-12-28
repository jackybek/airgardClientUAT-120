//gcc -std=c99 -v -I/home/pi/open62541/ -I/home/pi/open62541/plugins/ -lpthread -lxml2 -lcrypto -lssl open62541.c StartOPCUAServer.c mainOPCUAServer.c -o myNewServer >& error-msg 

#include "open62541.h"
#include <stdio.h>

int main(int argc, char** argv);
void* StartOPCUAServer(void* x_void_ptr, char*);

int g_argc;
int sockfd;

int main(int argc, char *argv[])
{
        //pthread_t OPCUAServerthread;
        //pthread_t Airgardthread;
	int results;

	if (argc != 2)
	{
		printf("Usage : ./mainOPCUAServer <local ip address>\n");
		exit (0);
	}

        UA_Server *server = UA_Server_new();	// UA_Server_new(config)
	UA_ServerConfig *config = UA_Server_getConfig(server);
	UA_ServerConfig_setDefault(config);

        g_argc = argc;
//	strcpy(g_argv_ip, argv[1]);	// 192.168.2.88
//	g_argv_port = atoi(argv[2]);	// 20004

//	printf("In main(): g_argc = %d, argv = %s %s %s \n", g_argc, argv[0], argv[1], argv[2]);
//	printf("In main() after processing argv: g_argc = %d, g_argv = %s %s %d\n", g_argc, argv[0], g_argv_ip, g_argv_port);

    //if (results = pthread_create(&OPCUAServerthread, NULL, StartOPCUAServer, server))
		StartOPCUAServer(server, argv[1]); //(server, argc, argv);
		//printf("Error creating thread : StartOPCUAServer\n") ;
	//else
		//printf("%d Success : pthread_create StartOPCUAServer\n", results);


//        if (results = pthread_create(&Airgardthread, NULL, ConnectToAirgard, server))
//		printf("Error creating thread : ConnectToAirgard\n") ;
//	else
//		printf("%d Success : pthread_create ConnectToAirgard\n", results);

	//pthread_join(OPCthread, NULL);
	//pthread_join(Airgardthread, NULL);

	//pthread_exit(NULL);
	return 0;
}
