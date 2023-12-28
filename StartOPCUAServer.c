#include "open62541.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>

static volatile UA_Boolean running = true;
extern int g_argc;
void* StartOPCUAServer(void* x_void_ptr, char *ipaddress);

static void stopHandler(int sig)
{
	UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "received ctrl-c");
	running = false;
}


void* StartOPCUAServer(void* x_void_ptr, char* ipaddress)
{
	int sockfd;

	signal(SIGINT, stopHandler);
	signal(SIGTERM, stopHandler);

	printf("In StartOPCUAServer thread: g_argc=%d\n", g_argc);

	UA_Server* server = (UA_Server*)x_void_ptr;
        //Add a new namespace to the server
        UA_Int16 ns_MKS = UA_Server_addNamespace(server, "MKS");
        UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "New Namespace added with Nr. %d \n", ns_MKS);


	//UA_Server *server = UA_Server_new();

		//Check for arguments :: <myNewServer 192.168.2.88 20004>
	/*
	if (g_argc == 2)   //hostname or ip address and a port number are available
	{
		UA_Int16 port_number = g_argv_port; //UA_Int16 port_number = atoi(g_argv[2]);
		UA_ServerConfig_setMinimal(UA_Server_getConfig(server), port_number, 0);
	}
	else
	{
		printf("in UA_ServerConfig_setDefault \n");
		UA_ServerConfig_setDefault(UA_Server_getConfig(server));
		printf("after UA_ServerConfig_setDefault \n");
	}
	*/
	if (g_argc == 2) //(g_argc == 2)
	{
		/*
			  #ifdef UA_ENABLE_PUBSUB
				// Details about the connection configuration and handling are located in
					//  the pubsub connection tutorial
				printf("\t----------------------Before setupUadpRange----------------- \n");
				//   setupUadpRange(server);
			  #endif
		*/
		//hostname or ip address available
			//copy the hostname from char * to an open62541 variable
		//printf("in g_argc segment %s %d\n", g_argv_ip, g_argv_port);

		char* OPCUAServerIP = ipaddress;
		UA_String hostname;
		UA_String_init(&hostname);
		//hostname.length = strlen(g_argv[1]);
		//hostname.data = (UA_Byte *) g_argv[1];
//hostname.length = strlen(g_argv_ip);
//hostname.data = (UA_Byte *) g_argv_ip; // this should be the ipaddress of the OPCUA Server : 192.168.2.33 

		hostname.data = (UA_Byte*)OPCUAServerIP;

		//Change the configuration - deprecated in v1.1.3
		UA_ServerConfig_setCustomHostname(UA_Server_getConfig(server), hostname);

		printf("hostname.data (ip) = %s\n", hostname.data);

		//#endif
	}

	UA_StatusCode retval;
	/*
		#ifdef UA_ENABLE_PUBSUB
					printf("\tJust about to start the OPCUA Server UADP thread\n");

					// start OPCUA Server
					UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "starting server...");

					retval = UA_Server_run(server, &running); // blocking call - to test United Automation (ok)
					if(retval != UA_STATUSCODE_GOOD)
							goto cleanup;
		#else
	*/
	printf("\tJust about to start the OPCUA Server TCP thread\n");

	// start OPCUA Server
	UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "starting OPCUA server ...\n");
	retval = UA_Server_run(server, &running); // blocking call - to test United Automation (ok)
	//retval = UA_Server_run_startup(server); //  non blocking call (not okay - BadTimeout
	if (retval != UA_STATUSCODE_GOOD)
		goto cleanup;
	else
		UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "OPCUA server started successfully ...\n");

	//	#endif 

cleanup:
	UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "OPCUA Server was unexpectedly shut down");
	UA_Server_delete(server);
	close(sockfd);
	//return retval == UA_STATUSCODE_GOOD ? EXIT_SUCCESS : EXIT_FAILURE;
//#endif
}
