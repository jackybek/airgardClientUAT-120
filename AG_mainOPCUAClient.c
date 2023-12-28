#ifdef COMPILE
gcc -std=c99 -v -I/home/pi/open62541/ -I/home/pi/open62541/plugins/ -I/usr/include/libxml2/ -lpthread -lxml2 -lcrypto -lssl open62541.c  \
AG_PopulateOPCUANodes.c AG_ExtractXMLElementNames.c AG_Misc.c AG_StartOPCUAClient.c AG_mainOPCUAClient.c -o myNewClient >& error-msg
// AG_CreateOPCUANodes.c 
#endif

#define PRODUCT_URI "http://virtualskies.com.sg"
#define APPLICATION_NAME "Airgard OPCUA adaptor based on open62541"
#define APPLICATION_URI "urn:virtualskies.com.sg"	// follow definition in StartOPCUAServer.c

#include "open62541.h"
#include <stdio.h>
#include <string.h>
#include <modbus/modbus.h>

int main(int argc, char *argv[]);
UA_NodeId CreateOPCUANodes(UA_Client *);
void PopulateOPCUANodes(char *);
int StartOPCUAClient(UA_Client *);
int StartModbusPolling(char *);


UA_ByteString loadFile(const char *const path);

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

// for method call
UA_NodeId outNodeSoftwareVersion;
UA_NodeId outNodeDataBlockVersion;
UA_NodeId outNodeInstrumentTime;

modbus_t *mb;

/*
int StartModbusPolling(char *ipaddress)
{
	mb = initialiseModbusConnection(ipaddress);
	readModbusData(mb);

	return 0;
}
*/

int main(int argc, char *argv[])
{
        //pthread_t OPCUAClientthread;
        //pthread_t Airgardthread;
	int results;
	//UA_NodeId outNodeId;
	//int isTreePresent=0;
	UA_Client *uaClient;
	UA_ClientConfig *config1;
	UA_StatusCode retval;

	if (argc != 4)
	{
		printf("Usage : ./myNewClient <Sensor IP> <Sensor Port> <OPCUA Server IP> <Modbus Master IP\n");
		exit (0);
	}
	else
	{
 		// UA_Server *server = UA_Server_new();	// UA_Server_new(config)
		// UA_ServerConfig *config = UA_Server_getConfig(server);
		// UA_ServerConfig_setDefault(config);

        	g_argc = argc;
		strcpy(g_argv_ip, argv[1]);	// 192.168.2.88
		g_argv_port = atoi(argv[2]);	// 20004
		sprintf(OPCUAServerIP, "opc.tcp://%s:4840", argv[3]);

		printf("In main(): g_argc = %d, argv = %s %s %s %s \n", g_argc, argv[0], argv[1], argv[2], argv[3]);
		printf("In main() after processing argv: g_argc = %d, g_argv = %s %s %d %s\n", g_argc, argv[0], g_argv_ip, g_argv_port, OPCUAServerIP);

        	// Add Encryption : sample taken from github/examples/access_control_encrypt/client_access_control_encrypt.c
                //int retval;
                UA_ByteString certificate = loadFile("/etc/ssl/certs/62541ClientCert.pem"); //=> symbolic link
		//UA_ByteString certificate = loadFile("/usr/local/ssl/certs/62541ClientCert.pem"); // actual location
		if (certificate.length == 0)
		{
			UA_LOG_FATAL(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "Unable to load file : 62541ClientCert.pem");
                        goto cleanup;
		}

                UA_ByteString privateKey = loadFile("/usr/local/ssl/private/private-key.pem");
                if (privateKey.length == 0)
		{
			UA_LOG_FATAL(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "Unable to load file : private-key.pem");
                        goto cleanup;
		}

		UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "NA_mainOPCUAClient : successfully loaded certificate and privateKey");

                // load the trustlist.  Load revocationlist is not supported now
                size_t trustListSize = 0;
                UA_STACKARRAY(UA_ByteString, trustList, trustListSize);
                for(size_t trustListCount=0; trustListCount < trustListSize; trustListCount++)
                        trustList[trustListCount] = loadFile("/usr/local/ssl/trustlist/trustlist.crl");

                UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "NA_mainOPCUAClient : successfully loaded trustList");

                /* Loading of a revocation list currently unsupported */
                UA_ByteString *revocationList = NULL;
                size_t revocationListSize = 0;

        	uaClient = UA_Client_new();
        	config1 = UA_Client_getConfig(uaClient);
		//UA_ClientConfig_setDefault(config1);

//config1->timeout = 60000;
//config1->stateCallback = stateCallback;
		config1->localConnectionConfig = UA_ConnectionConfig_default;

                UA_ApplicationDescription_clear(&config1->clientDescription);
                config1->clientDescription.applicationUri = UA_STRING_ALLOC(APPLICATION_URI);
                config1->clientDescription.productUri = UA_STRING_ALLOC(PRODUCT_URI);
                config1->clientDescription.applicationName = UA_LOCALIZEDTEXT_ALLOC("en", APPLICATION_NAME);
                config1->clientDescription.applicationType = UA_APPLICATIONTYPE_CLIENT;

		// Secure client connect
    		// config1->securityPoliciesSize = 4;	// Basic128Rsa15, Basic256, Basic256Sha256, Aes128Sha256RsaOaep
		config1->securityMode = UA_MESSAGESECURITYMODE_SIGNANDENCRYPT;	// require encryption
		config1->securityPolicyUri = UA_STRING_ALLOC("");
		config1->secureChannelLifeTime = 10 * 60 * 1000;	// 10 minutes
    		config1->securityPolicies = (UA_SecurityPolicy*)UA_malloc(sizeof(UA_SecurityPolicy));
    		if (!config1->securityPolicies)
        		return UA_STATUSCODE_BADOUTOFMEMORY;
                UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "NA_mainOPCUAClient : config->securityPolicies : success");

    		config1->initConnectionFunc = UA_ClientConnectionTCP_init; /* for async client */
    		config1->pollConnectionFunc = UA_ClientConnectionTCP_poll; /* for async connection */
    		config1->customDataTypes = NULL;

		// Set stateCallback : https://raw.githubusercontent.com/open62541/open62541/master/examples/client_method_async.c
		// static void stateCallback(UA_Client *client, UA_SecureChannelState channelState, UA_SessionState sessionState, UA_StatusCode connectStatus)
		//config1->timeout = 60000;
    		//config1->stateCallback = stateCallback;	// function implemented in AG_NewMethod.c

		config1->connectivityCheckInterval = 0;
    		config1->requestedSessionTimeout = 1200000; /* requestedSessionTimeout */
    		config1->inactivityCallback = NULL;
    		config1->clientContext = NULL;
		config1->connectivityCheckInterval = 3000; // in milliseconds

		#ifdef UA_ENABLE_SUBSCRIPTIONS
			config1->outStandingPublishRequests = 10;
    			config1->subscriptionInactivityCallback = NULL;
		#endif

                UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "Calling setDefaultEncryption");
                UA_ClientConfig_setDefaultEncryption(config1, certificate, privateKey,
                                                        trustList, trustListSize,
                                                        revocationList, revocationListSize);
                UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "Finished calling setDefaultEncryption");


                UA_ByteString_clear(&certificate);
                UA_ByteString_clear(&privateKey);
                for(size_t deleteCount = 0; deleteCount < trustListSize; deleteCount++)
                        UA_ByteString_clear(&trustList[deleteCount]);

                UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "NA_mainOPCUAClient : successfully setDefaultEncryption");


		/*
		retval = UA_CertificateVerification_Trustlist(&config1->certificateVerification,
                                                  trustList, trustListSize,
                                                  NULL, 0,
                                                  revocationList, revocationListSize);
		if (retval != UA_STATUSCODE_GOOD)
		{
			UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "NA_mainOPCUAClient : UA_CertificateVerification_Trustlist : failure");
        		return retval;
		}
		else
                	UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "NA_mainOPCUAClient : UA_CertificateVerification_Trustlist : success");

		// Populate SecurityPolicies
		UA_SecurityPolicy *sp = (UA_SecurityPolicy*) UA_realloc(config1->securityPolicies, sizeof(UA_SecurityPolicy) * 4);
    		if(!sp)
        		return UA_STATUSCODE_BADOUTOFMEMORY;
                UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "NA_mainOPCUAClient : UA_SecurityPolicy realloc : success");

    		config1->securityPolicies = sp;
		for (int i=0; i < config1->securityPoliciesSize; i++)
		{
		printf("in the loop : %d \n", i);

    		 	retval = UA_SecurityPolicy_Basic128Rsa15(&config1->securityPolicies[i],		// config1->securityPoliciesSize],
                                             certificate, privateKey, &config1->logger);
    			if(retval == UA_STATUSCODE_GOOD)
        		{
				UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "added Basic128Rsa15");
				++config1->securityPoliciesSize;
			}
    			else
        			UA_LOG_WARNING(&config1->logger, UA_LOGCATEGORY_USERLAND,
                       				"Line 243 Could not add SecurityPolicy#Basic128Rsa15 with error code %s", UA_StatusCode_name(retval));   // bad invalid argument!!!

                    retval = UA_SecurityPolicy_Basic256(&config1->securityPolicies[i],			//[config1->securityPoliciesSize],
                                             certificate, privateKey, &config1->logger);
                        if(retval == UA_STATUSCODE_GOOD)
                        {
			        ++config1->securityPoliciesSize;
				UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "added Basic256");
			}
                        else
                                UA_LOG_WARNING(&config1->logger, UA_LOGCATEGORY_USERLAND,
                                                "Line 254: Could not add SecurityPolicy#Basic256 with error code %s", UA_StatusCode_name(retval));	// bad invalid argument !!!

                    retval = UA_SecurityPolicy_Basic256Sha256(&config1->securityPolicies[i], 		//[config1->securityPoliciesSize],
					      certificate, privateKey, &config1->logger);
                        if(retval == UA_STATUSCODE_GOOD)
			{
                                ++config1->securityPoliciesSize;
				UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "added Basic256Sha256");
			}
                        else
                                UA_LOG_WARNING(&config1->logger, UA_LOGCATEGORY_USERLAND,
                                                "Line 265: Could not add SecurityPolicy#Basic256Sha256 with error code %s", UA_StatusCode_name(retval)); 	// bad invalid argument !!!


		    retval = UA_SecurityPolicy_Aes128Sha256RsaOaep(&config1->securityPolicies[i],            //[config1->securityPoliciesSize],
                                              certificate, privateKey, &config1->logger);
                        if(retval == UA_STATUSCODE_GOOD)
                        {
                                ++config1->securityPoliciesSize;
                                UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "added Aes128Sha256Oaep");
                        }
                        else
                                UA_LOG_WARNING(&config1->logger, UA_LOGCATEGORY_USERLAND,
                                                "Line 277: Could not add SecurityPolicy#Aes128Sha256RsaOaep with error code %s", UA_StatusCode_name(retval));         // bad invalid argument !!!

		}

		// check after populating Security Policies
                for (size_t i= 0; i< config1->securityPoliciesSize; i++)
                {
                        UA_SecurityPolicy *sp = &config1->securityPolicies[i];
                        retval = config1->certificateVerification.verifyApplicationURI(config1->certificateVerification.context,
                                                                                &sp->localCertificate,
                                                                                &config1->clientDescription.applicationUri);
                        if (retval != UA_STATUSCODE_GOOD)
                        {
                                UA_LOG_WARNING(&config1->logger, UA_LOGCATEGORY_CLIENT,
                                                "NA_mainOPCUAClient: The configured ApplicationURI does not match the URI "
                                                "specified in the certificate for the SecurityPolicy <%d> <%s>",
                                                (int)sp->policyUri.length, sp->policyUri.data);
                        }
                }

		if(config1->securityPoliciesSize == 0)
		{
        		UA_free(config1->securityPolicies);
        		config1->securityPolicies = NULL;
    		}
		//end populating security policies
		*/

                UA_ByteString_clear(&certificate);
                UA_ByteString_clear(&privateKey);
                for(size_t deleteCount = 0; deleteCount < trustListSize; deleteCount++)
                       UA_ByteString_clear(&trustList[deleteCount]);

                // OPCUA1 Server instance: 192.168.2.33
                // OPCUAServerIP = opc.tcp://192.168.2.33:4840
                // after setting up the encryption, connects to the OPCUAServer IP
		// first connect to server without creating a session

		/*
		UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "Just about to call UA_Client_ConnectSecureChannel() at line 342");
		retval = UA_Client_connectSecureChannel(uaClient, OPCUAServerIP); // fail : The configured ApplicationURI does not match the URI specified in the certificate for the SecurityPolicy
		if (retval != UA_STATUSCODE_GOOD)
		{
                        UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "NA_mainOPCUAClient.c : Cannot connect to OPCUAServer : %s", OPCUAServerIP);
                        return(EXIT_FAILURE);
                }
		UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "UA_Client_connectSecureChannel : success");
		*/

        // end add encryption

		// next connect to the server and create+activate a session with username / password
		//retval = UA_Client_connect(uaClient, OPCUAServerIP); // use anonymous login

		UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "AG_mainOPCUAClient.c : Just about to call UA_Client_connectUsername() at line 355");
                retval = UA_Client_connectUsername(uaClient, OPCUAServerIP, "admin", "defaultadminpassword24");
                if (retval != UA_STATUSCODE_GOOD)
                {
                        UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "AG_mainOPCUAClient.c : Cannot login securely to OPCUAServer : %s", OPCUAServerIP);
                        return(EXIT_FAILURE);
                }
		UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "AG_mainOPCUAClient.c : UA_Client_connectUsername() : success");

		/*
    		if ( results = pthread_create(&modbuspollthread, NULL, StartModbusPolling, "192.168.1.119") )	// the modbus master is running on ASUS notebook
			UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "AG_mainOPCUAClient.c Error creating modbus thread : StartModbusPolling \n") ;
		*/
	//else

		// check if the tree is already created in the server
		//UA_Client_readNodeIdAttribute(uaClient,UA_NODEID_STRING(1, "AirGardSensor"),&outNodeId);

		//if (UA_NodeId_isNull(&outNodeId))	// tree structure is already present
		//	isTreePresent=0;
		//else
		//	isTreePresent=1;

		//UA_NodeId r2_airgard_data_Id = CreateAndPopulateNodes(client);
		/*
		UA_NodeId r2_airgard_data_Id = CreateOPCUANodes(uaClient);	//, isTreePresent);
		if (UA_NodeId_isNull(&r2_airgard_data_Id))
		{
			UA_LOG_ERROR(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "AG_mainOPCUAlient : fail to get handle to r2_airgard_data_Id");
			goto cleanup;
		}
		*/
		while (1)
		{
			PopulateOPCUANodes(g_argv_ip);	// refers to the sensor ip
			//printf("%d Success : pthread_create ConnectToAirgard\n", results);
			//retval = StartOPCUAClient(uaClient, r2_airgard_data_Id);
			StartOPCUAClient(uaClient);
			UA_Client_run_iterate(uaClient, 5000);

			//sleep(9);
		}
	}

cleanup:

	//pthread_join(OPCthread, NULL);
	//pthread_join(modbuspollthread, NULL);

	//pthread_exit(NULL);
	printf("In CLEANUP segment !!!! \n");
	UA_Client_disconnect(uaClient);
	UA_Client_delete(uaClient);

	return 0;
}

