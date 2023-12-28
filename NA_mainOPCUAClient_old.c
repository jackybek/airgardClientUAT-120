//gcc -std=c99 -v -I/home/pi/open62541/ -I/home/pi/open62541/plugins/ -I/usr/include/libxml2/ -lpthread -lxml2 -lcrypto -lssl open62541.c myNewMonitor.c myNewMethod.c
//NA_PopulateOPCUANodes.c NA_CreateOPCUANodes.c NA_ExtractXMLElementNames.c NA_Misc.c NA_StartOPCUAClient.c NA_mainOPCUAClient.c myNewPubSub.c -o myNewClient >& error-msg

#include "open62541.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]);
UA_NodeId CreateOPCUANodes(void *);
void PopulateOPCUANodes(char *);
int StartOPCUAClient(UA_Client *, UA_NodeId);


typedef struct {
char Tag[255];
char Name[255];
float Probability;
char CASnumber[255];
int Concentration;
} AlarmStruct;

typedef struct {
char Tag[255];
char Name[255];
float Probability;
char CASnumber[255];
int Concentration;
} NonAlarmStruct;

int g_argc = 0;
char g_argv_ip[255];	// sensor ip
int g_argv_port = 0;	// sensor port
char OPCUAServerIP[255];	// OPCUA Server IP


char SoftwareVersion[255];
char DataBlockVersion[255];
char InstrumentTime[255];
char MeasurementTime[255];

char BootStatus[255];
char SnapshotStatus[255];
char SCPStatus[255];
char SFTPStatus[255];
char RunScriptStatus[255];
char ArchiveStatus[255];
char AncillarySensorStatus[255];

char Sensor[255];
UA_Int16 OperatingTime;
char WarningMessage[255];

UA_Float IgramPP = (UA_Float) 0.0;
UA_Float IgramDC = (UA_Float) 0.0;
UA_Float LaserPP = (UA_Float) 0.0;
UA_Float LaserDC = (UA_Float) 0.0;
UA_Float SingleBeamAt900 = (UA_Float) 0.0;
UA_Float SingleBeamAt2500 = (UA_Float) 0.0;
UA_Int16 SignalToNoiseAt2500 = (UA_Int16) 0.0;
UA_Float CenterBurstLocation = (UA_Float) 0.0;
UA_Float DetectorTemp = (UA_Float) 0.0;
UA_Float LaserFrequency = (UA_Float) 0.0;
UA_Int16 HardDriveSpace = (UA_Int16) 0.0;
UA_Float Flow = (UA_Float) 0.0;
UA_Float Temperature = (UA_Float) 0.0;
UA_Float Pressure = (UA_Float) 0.0;
UA_Float TempOptics = (UA_Float) 0.0;
UA_Int16 BadScanCounter = (UA_Int16) 0;
UA_Int16 FreeMemorySpace = (UA_Int16) 0;

char LABFilename[255];
char LOGFilename[255];
char LgFilename[255];
char SecondLgFilename[255];

UA_Float SystemCounter = (UA_Float) 0.0;
UA_Float DetectorCounter = (UA_Float) 0.0;
UA_Float LaserCounter = (UA_Float) 0.0;
UA_Float FlowPumpCounter = (UA_Float) 0.0;
UA_Float DesiccantCounter = (UA_Float) 0.0;

UA_Int16 NoOfAlarms;
UA_Int16 NoOfNonAlarms;

int NoOfAlarmsNode;
AlarmStruct arrayOfAlarm[255];
char AlarmTag[255];
char AlarmName[255];
UA_Float AlarmProbability = (UA_Float) 0.0;
char AlarmCASnumber[255];
UA_Int16 AlarmConcentration = (UA_Int16) 0;

int NoOfNonAlarmsNode;
NonAlarmStruct arrayOfNonAlarm[255];

// for pub sub use
UA_NodeId ds1IgramPPId;
UA_NodeId ds1IgramDCId;
UA_NodeId ds1LaserPPId;
UA_NodeId ds1LaserDCId;


int main(int argc, char *argv[])
{
        //pthread_t OPCUAClientthread;
        //pthread_t Airgardthread;
	int results;
	//UA_NodeId outNodeId;
	//int isTreePresent=0;

	if (argc != 4)
	{
		printf("Usage : ./mainOPCUAClient <Sensor IP> <Sensor Port> <OPCUA Server IP>\n");
		exit (0);
	}

 //       UA_Server *server = UA_Server_new();	// UA_Server_new(config)
//	UA_ServerConfig *config = UA_Server_getConfig(server);
//	UA_ServerConfig_setDefault(config);

    g_argc = argc;
	strcpy(g_argv_ip, argv[1]);	// 192.168.2.88
	g_argv_port = atoi(argv[2]);	// 20004
	sprintf(OPCUAServerIP, "opc.tcp://%s:4840", argv[3]);

	printf("In main(): g_argc = %d, argv = %s %s %s %s \n", g_argc, argv[0], argv[1], argv[2], argv[3]);
	printf("In main() after processing argv: g_argc = %d, g_argv = %s %s %d %s\n", g_argc, argv[0], g_argv_ip, g_argv_port, OPCUAServerIP);

//        if (results = pthread_create(&OPCthread, NULL, StartOPCUAServer, server))
//		printf("Error creating thread : StartOPCUAServer\n") ;
//	else
//		printf("%d Success : pthread_create StartOPCUAServer\n", results);


	UA_Client* uaClient = UA_Client_new();
	UA_ClientConfig_setDefault(UA_Client_getConfig(uaClient));
	UA_StatusCode retval = UA_Client_connect(uaClient, OPCUAServerIP); // connects to the OPCUAServer IP
	if (retval != UA_STATUSCODE_GOOD)
	{
		UA_Client_delete(uaClient);
		printf("NA_mainOPCUAClient.c : Cannot connect to OPCUAServer : %s \n", OPCUAServerIP);
		return (int)retval;
	}

    //if (results = pthread_create(&Airgardthread, NULL, CreateAndPopulateNodes, client))
	//	printf("Error creating thread : ConnectToAirgard\n") ;
	//else
	{
		// check if the tree is already created in the server
		//UA_Client_readNodeIdAttribute(uaClient,UA_NODEID_STRING(1, "AirGardSensor"),&outNodeId);

		//if (UA_NodeId_isNull(&outNodeId))	// tree structure is already present
		//	isTreePresent=0;
		//else
		//	isTreePresent=1;

		//UA_NodeId r2_airgard_data_Id = CreateAndPopulateNodes(client);
		UA_NodeId r2_airgard_data_Id = CreateOPCUANodes(uaClient);	//, isTreePresent);
		while (1)
		{
			PopulateOPCUANodes(g_argv_ip);	// refers to the sensor ip
			//printf("%d Success : pthread_create ConnectToAirgard\n", results);
			retval = StartOPCUAClient(uaClient, r2_airgard_data_Id);
			sleep(9);
		}
	}

	//pthread_join(OPCthread, NULL);
	//pthread_join(Airgardthread, NULL);

	//pthread_exit(NULL);
	return 0;
}
