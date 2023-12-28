#include "open62541.h"
#include <stdio.h>
#include "myNewMonitor.h" 

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


extern char OPCUAServerIP[255];

extern char SoftwareVersion[255];
extern char DataBlockVersion[255];
extern char InstrumentTime[255];
extern char MeasurementTime[255];

extern char BootStatus[255];
extern char SnapshotStatus[255];
extern char SCPStatus[255];
extern char SFTPStatus[255];
extern char RunScriptStatus[255];
extern char ArchiveStatus[255];
extern char AncillarySensorStatus[255];

extern char Sensor[255];
extern UA_Int16 OperatingTime;
extern char WarningMessage[255];

extern UA_Float IgramPP;
extern UA_Float IgramDC;
extern UA_Float LaserPP;
extern UA_Float LaserDC;
extern UA_Float SingleBeamAt900;
extern UA_Float SingleBeamAt2500;
extern UA_Int16 SignalToNoiseAt2500;
extern UA_Float CenterBurstLocation;
extern UA_Float DetectorTemp;
extern UA_Float LaserFrequency;
extern UA_Int16 HardDriveSpace;
extern UA_Float Flow;
extern UA_Float Temperature;
extern UA_Float Pressure;
extern UA_Float TempOptics;
extern UA_Int16 BadScanCounter;
extern UA_Int16 FreeMemorySpace;

extern char LABFilename[255];
extern char LOGFilename[255];
extern char LgFilename[255];
extern char SecondLgFilename[255];

extern UA_Float SystemCounter;
extern UA_Float DetectorCounter;
extern UA_Float LaserCounter;
extern UA_Float FlowPumpCounter;
extern UA_Float DesiccantCounter;

extern UA_Int16 NoOfAlarms;
extern UA_Int16 NoOfNonAlarms;

extern int NoOfAlarmsNode;
extern AlarmStruct arrayOfAlarm[255];  //101

//extern char AlarmTag[255];
//extern char AlarmName[255];
//extern UA_Float AlarmProbability;
//extern char AlarmCASnumber[255];
//extern UA_Int16 AlarmConcentration;

extern int NoOfNonAlarmsNode;
extern NonAlarmStruct arrayOfNonAlarm[255];

//extern UA_NodeId r2_airgard_data_Id;

// for pub sub use
extern UA_NodeId ds1IgramPPId;
extern UA_NodeId ds1IgramDCId;
extern UA_NodeId ds1LaserPPId;
extern UA_NodeId ds1LaserDCId;

static int initialStartup = 1;


int StartOPCUAClient(UA_Client* uaClient, UA_NodeId r2_airgard_data_Id);
UA_ByteString loadFile(char* filename);

int StartOPCUAClient(UA_Client* uaClient, UA_NodeId r2_airgard_data_Id)
{
	//Instantiate an OPCUA Client to update OPCUA Server Address space
	//UA_Client *uaClient=NULL;
	int retval=0;
	size_t endpointDescriptionSize;
	UA_EndpointDescription *endpointDescriptions=NULL;

	if (uaClient != NULL)
	{
  		printf("============================================================\n");
    		printf("Entering StartOPCUAClient()\n");
    		printf("============================================================\n");


               // start OPCUA client
                UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "starting OPCUA client ...\n");


		//int retval;
		/* ============ shift to NA_mainOPCUAClient.c
		// load certificate and private key from /usr/local/ssl/certs/ & /usr/local/ssl/private/
		UA_ByteString certificate = loadFile("/etc/ssl/certs/cert.pem");
		UA_ByteString privateKey = loadFile("/usr/local/ssl/private/private-key.pem");

		// load the trustlist.  Load revocationlist is not supported now
		size_t trustListSize = 0;
		trustListSize = 0; //for testing first

		UA_STACKARRAY(UA_ByteString, trustList, trustListSize);
		for(size_t trustListCount; trustListCount < trustListSize; trustListCount++)
			trustList[trustListCount] = loadFile("/usr/local/ssl/trustlist/trustlist.crl");

		UA_ByteString *revocationList = NULL;
		size_t revocationListSize = 0;

		//uaClient = UA_Client_new();
		UA_ClientConfig *config = UA_Client_getConfig(uaClient);
		config->securityMode =UA_MESSAGESECURITYMODE_SIGNANDENCRYPT;
		UA_ClientConfig_setDefaultEncryption(config, certificate, privateKey, trustList, trustListSize, revocationList, revocationListSize);
		UA_ByteString_clear(&certificate);
		UA_ByteString_clear(&privateKey);
		for(size_t deleteCount = 0; deleteCount < trustListSize; deleteCount++)
			UA_ByteString_clear(&trustList[deleteCount]);

    		//UA_ClientConfig_setDefault(UA_Client_getConfig(uaClient));

    		// Listing endpoints
    		//endpointDescriptions = NULL;
    		//endpointDescriptionSize = 0;

		// OPCUA1 Server instance: 192.168.2.33
		// OPCUA2 Server instance: 102.168.2.109

		//UA_Client_connect(uaClient, "opc.tcp://192.168.2.33:4840");
		*/ 

		printf("in StartOPCUAClient.c : connecting to OPCUA Server at %s\n", OPCUAServerIP);

		UA_StatusCode retval=0;

                UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                                "Attempting to connect to OPCUA Server",retval);

		// ============== shift to NA_mainOPCUAClient.c
		//retval = UA_Client_connectUsername(uaClient,"opc.tcp://192.168.2.33:4840",
		//			"pi", "molekhaven24");

		// UA Client is running in the differenet IP as the UA Server.
		// load certificate and private key
		// stop here for SSL code :: UA_ByteString openSSLcert = loadFile("home/pi/open62541/
		//UA_Client_connect(uaClient,"localhost");

		/*
    		retval = UA_Client_getEndpoints(uaClient, "opc.tcp://192.168.2.109:4840",
							*endpointDescriptionSize, *endpointDescriptions);
		if (retval != UA_STATUSCODE_GOOD)
		{
			UA_Array_delete(endpointDescriptions, endpointDescriptionSize, &UA_TYPES[UA_TYPES_ENDPOINTDESCRIPTION]);
			UA_Client_delete(uaClient);
			return (-1);// EXIT_FAILURE;
		}
		*/
	}

	printf("********************************In StartOPCUAClient() to update UA Server Address space****************************************************\n");
	/* - shift to NA_mainOPCUAClient.c
	printf("%d endpoints found\n", (int)endpointDescriptionSize);
	for(size_t i=0;i<endpointDescriptionSize;i++)
	{
		printf("URL of endpoint %d is %ss\n",
			(int)i,
			(int)endpointDescriptions[i].endpointUrl.length,
			endpointDescriptions[i].endpointUrl.data);
	}
	*/

	//connect to UA_Server and update UA_AddressSpace with data

	// get the NodeId of r2_airgard_data_Id (since it cannot be passed from Server code to client code via public variable)


	UA_Variant *val = UA_Variant_new();	// for scalar variables
	UA_Variant *varStrSoftwareVersion;
	UA_Variant *varStrDataBlockVersion;
	UA_Variant *varStrInstrumentTime;
	UA_Variant *varStrMeasurementTime;
	UA_Variant *varStrBootStatus;
	UA_Variant *varStrSnapshotStatus;
	UA_Variant *varStrSCPStatus;
	UA_Variant *varStrSFTPStatus;
	UA_Variant *varStrRunScriptStatus;
	UA_Variant *varStrArchiveStatus;
	UA_Variant *varStrAncillarySensorStatus;
	UA_Variant *varStrSensor;
	UA_Variant *varStrWarningMessage;
	UA_Variant *varStrLABFilename;
	UA_Variant *varStrLOGFilename;
	UA_Variant *varStrLgFilename;
	UA_Variant *varStrSecondLgFilename;

	UA_Variant *varStrAlarms;
	UA_Variant *varStrAlarmTag;
	UA_Variant *varStrAlarmName;
	//UA_Variant *varStrAlarmProbability;
	UA_Variant *varStrAlarmCASnumber;
	//UA_Variant *varStrAlarmConcentration;

	UA_Variant *varStrNonAlarms;
        UA_Variant *varStrNonAlarmTag;
        UA_Variant *varStrNonAlarmName;
        //UA_Variant *varStrNonAlarmProbability;
        UA_Variant *varStrNonAlarmCASnumber;
        //UA_Variant *varStrNonAlarmConcentration;


	char mystring[32];
	//AlarmStruct varlarmStruct;

	printf("10000\n");
/*
	// definition from open62541.org
	static UA_INLINE UA_StatusCode
	UA_Client_writeValueAttribute(UA_Client *client, const UA_NodeId nodeId,
                              		const UA_Variant *newValue) {
    		return __UA_Client_writeAttribute(client, &nodeId, UA_ATTRIBUTEID_VALUE,
                                      newValue, &UA_TYPES[UA_TYPES_VARIANT]);
		}
	// end definition
*/

	//Start initialising/ clearing alarm / non alarm nodes
	// when program first start up, i want to force PreviousAlarmsQty and PreviousNonAlarmsQty = 0
	// then delete all existing AlarmNodes and NonAlarmNodes=> since it has just started up, there are no Alarm/NonAlarm nodes to remove
	// next cycle, (if there are AlarmNodes created in the previous cycle, it gets remove here

	UA_Int16 zero_data=0;
	UA_Variant *PreviousAlarmsQty;
	UA_Variant *PreviousNonAlarmsQty;
	int AlarmCounter=0, NonAlarmCounter=0;

	/*
	PreviousAlarmsQty = UA_Variant_new();
	PreviousNonAlarmsQty = UA_Variant_new();

	if (initialStartup == 1)
	{
		initialStartup = 0;
		UA_Variant_setScalar(PreviousAlarmsQty, &zero_data, &UA_TYPES[UA_TYPES_INT16]);
		UA_Variant_setScalar(PreviousNonAlarmsQty, &zero_data, &UA_TYPES[UA_TYPES_INT16]);

		AlarmCounter = 0;
		NonAlarmCounter = 0;
		printf("line 660 : after initialStartup : %d %d \n", AlarmCounter, NonAlarmCounter);

	}
	else
	{
		// subsequent cycle => get the number of AlarmNodes and Non AlarmNodes created in the previous cycle
		retval = UA_Client_readValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10401), PreviousAlarmsQty);
		if (retval == UA_STATUSCODE_GOOD && UA_Variant_hasScalarType(PreviousAlarmsQty, &UA_TYPES[UA_TYPES_INT16]))
		{
			UA_Int16 raw_data = *(UA_Int16 *)PreviousAlarmsQty->data;
			AlarmCounter = raw_data;
		}
		else
			AlarmCounter = 0;

		retval = UA_Client_readValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10402), PreviousNonAlarmsQty);
		if (retval == UA_STATUSCODE_GOOD && UA_Variant_hasScalarType(PreviousNonAlarmsQty, &UA_TYPES[UA_TYPES_INT16]))
		{
			UA_Int16 raw_data = *(UA_Int16 *)PreviousNonAlarmsQty->data;
			NonAlarmCounter = raw_data;
		}
		else
			NonAlarmCounter = 0;
	}

	printf("line 294 : before entering FOR loop to remove all Alarms and NonAlarms nodes \n");
	printf("PreviousAlarmsQty : %d, PreviousNonAlarmsQty : %d \n", AlarmCounter, NonAlarmCounter);  // return a huge value
	// Now, based on the previous qty, removes all child AlarmNodes and child NonAlarmNodes
	for (int i=0; i<AlarmCounter; i++)
	{
		char AlarmsNode[255];
		// remove child nodes first (variable nodes)
		if (uaClient!= NULL)
		{
			sprintf(AlarmsNode, "A%d:Tag", i+1);
			UA_Client_deleteNode(uaClient, UA_NODEID_STRING(1, AlarmsNode), false);
			sprintf(AlarmsNode, "A%d:Name", i+1);
			UA_Client_deleteNode(uaClient, UA_NODEID_STRING(1, AlarmsNode), false);
			sprintf(AlarmsNode, "A%d:Concentration", i+1);
			UA_Client_deleteNode(uaClient, UA_NODEID_STRING(1, AlarmsNode), false);
			sprintf(AlarmsNode, "A%d:CASnumber", i+1);
			UA_Client_deleteNode(uaClient, UA_NODEID_STRING(1, AlarmsNode), false); 
			sprintf(AlarmsNode, "A%d:Probability", i+1);
			UA_Client_deleteNode(uaClient, UA_NODEID_STRING(1, AlarmsNode), false);

                        // finally remove the parent (object node)
                        printf("NA_StartOPCUAClient: 320 : before delete parent node : Alarm-%d", i+1);
                        sprintf(AlarmsNode, "Alarm-%d", i+1);
                        UA_Client_deleteNode(uaClient, UA_NODEID_STRING(1, AlarmsNode), false);
		}
	}

	for (int i=0; i<NonAlarmCounter; i++)
	{
		char NonAlarmsNode[255];

		if (uaClient != NULL)
		{
			sprintf(NonAlarmsNode, "NA%d:Tag", i+1);
			UA_Client_deleteNode(uaClient, UA_NODEID_STRING(1, NonAlarmsNode), false);
			sprintf(NonAlarmsNode, "NA%d:Name", i+1);
			UA_Client_deleteNode(uaClient, UA_NODEID_STRING(1, NonAlarmsNode), false);
                        sprintf(NonAlarmsNode, "NA%d:Concentration", i+1);
                        UA_Client_deleteNode(uaClient, UA_NODEID_STRING(1, NonAlarmsNode), false);
                        sprintf(NonAlarmsNode, "NA%d:CASnumber", i+1);
                        UA_Client_deleteNode(uaClient, UA_NODEID_STRING(1, NonAlarmsNode), false);
                        sprintf(NonAlarmsNode, "NA%d:Probability", i+1);
                        UA_Client_deleteNode(uaClient, UA_NODEID_STRING(1, NonAlarmsNode), false);

                        // finally remove the parent (object node)
                        printf("NA_StartOPCUAClient: 344 : before delete parent node : NonAlarm-%d", i+1);
                        sprintf(NonAlarmsNode, "NonAlarm-%d", i+1);
                        UA_Client_deleteNode(uaClient, UA_NODEID_STRING(1, NonAlarmsNode), false);
		}
	}
        // no matter whether it is the first round or subsequent round, set the node value to 0
        UA_Variant_setScalar(val,&zero_data, &UA_TYPES[UA_TYPES_INT16]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10401), val);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10402), val);
	// finished initialising/ clearing alarm / non alarm nodes
	*/

	varStrSoftwareVersion = UA_Variant_new();
	if (varStrSoftwareVersion!=NULL) /*347*/
	{
		UA_String tmpSoftwareVersion = UA_STRING(SoftwareVersion);
        	UA_Variant_setScalarCopy(varStrSoftwareVersion, &tmpSoftwareVersion, &UA_TYPES[UA_TYPES_STRING]);
        	UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10001), varStrSoftwareVersion);
        	UA_Variant_delete(varStrSoftwareVersion);
	}

        varStrDataBlockVersion = UA_Variant_new();
	if (varStrDataBlockVersion!=NULL)
	{
		UA_String tmpDataBlockVersion = UA_STRING(DataBlockVersion);
        	UA_Variant_setScalarCopy(varStrDataBlockVersion, &tmpDataBlockVersion, &UA_TYPES[UA_TYPES_STRING]);
        	UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10002), varStrDataBlockVersion);
        	UA_Variant_delete(varStrDataBlockVersion);
	}

	//------
	//printf("10100\n");
        varStrInstrumentTime = UA_Variant_new();
	if (varStrInstrumentTime!=NULL)
	{
		UA_String tmpInstrumentTime = UA_STRING(InstrumentTime);
        	UA_Variant_setScalarCopy(varStrInstrumentTime, &tmpInstrumentTime, &UA_TYPES[UA_TYPES_STRING]);
        	UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10101), varStrInstrumentTime);
        	UA_Variant_delete(varStrInstrumentTime);
	}

        varStrMeasurementTime = UA_Variant_new();
	if (varStrMeasurementTime!=NULL)
	{
		UA_String tmpMeasurementTime = UA_STRING(MeasurementTime);
        	UA_Variant_setScalarCopy(varStrMeasurementTime, &tmpMeasurementTime, &UA_TYPES[UA_TYPES_STRING]);
        	UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10102), varStrMeasurementTime);
        	UA_Variant_delete(varStrMeasurementTime);
	}

	//-----
	//printf("10210\n");
        varStrBootStatus = UA_Variant_new();
	if (varStrBootStatus!=NULL)
	{
		UA_String tmpBootStatus = UA_STRING(BootStatus);
        	UA_Variant_setScalarCopy(varStrBootStatus, &tmpBootStatus, &UA_TYPES[UA_TYPES_STRING]);
        	UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10211), varStrBootStatus);
        	UA_Variant_delete(varStrBootStatus);
	}

        varStrSnapshotStatus = UA_Variant_new();
	if (varStrSnapshotStatus!=NULL)
	{
		UA_String tmpSnapshotStatus = UA_STRING(SnapshotStatus);
        	UA_Variant_setScalarCopy(varStrSnapshotStatus, &tmpSnapshotStatus, &UA_TYPES[UA_TYPES_STRING]);
        	UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10212), varStrSnapshotStatus);
        	UA_Variant_delete(varStrSnapshotStatus);
	}

        varStrSCPStatus = UA_Variant_new();
	if (varStrSCPStatus!=NULL)
	{
		UA_String tmpSCPStatus =UA_STRING(SCPStatus);
   		UA_Variant_setScalarCopy(varStrSCPStatus, &tmpSCPStatus, &UA_TYPES[UA_TYPES_STRING]);
        	UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10213), varStrSCPStatus);
        	UA_Variant_delete(varStrSCPStatus);
	}

        varStrSFTPStatus = UA_Variant_new();
	if (varStrSFTPStatus!=NULL)
	{
		UA_String tmpSFTPStatus = UA_STRING(SFTPStatus);
        	UA_Variant_setScalarCopy(varStrSFTPStatus, &tmpSFTPStatus, &UA_TYPES[UA_TYPES_STRING]);
        	UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10214), varStrSFTPStatus);
        	UA_Variant_delete(varStrSFTPStatus);
	}

	varStrRunScriptStatus = UA_Variant_new();
	if (varStrRunScriptStatus!=NULL)
	{
		UA_String tmpRunScriptStatus = UA_STRING(RunScriptStatus);
        	UA_Variant_setScalarCopy(varStrRunScriptStatus, &tmpRunScriptStatus, &UA_TYPES[UA_TYPES_STRING]);
        	UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10215), varStrRunScriptStatus);
        	UA_Variant_delete(varStrRunScriptStatus);
	}

        varStrArchiveStatus = UA_Variant_new();
	if (varStrArchiveStatus!=NULL)
	{
		UA_String tmpArchiveStatus = UA_STRING(ArchiveStatus);
        	UA_Variant_setScalarCopy(varStrArchiveStatus, &tmpArchiveStatus, &UA_TYPES[UA_TYPES_STRING]);
        	UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10216), varStrArchiveStatus);
        	UA_Variant_delete(varStrArchiveStatus);
	}

        varStrAncillarySensorStatus = UA_Variant_new();
	if (varStrAncillarySensorStatus!=NULL)
	{
		UA_String tmpAncillarySensorStatus = UA_STRING(AncillarySensorStatus);
        	UA_Variant_setScalarCopy(varStrAncillarySensorStatus, &tmpAncillarySensorStatus, &UA_TYPES[UA_TYPES_STRING]);
        	UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10217), varStrAncillarySensorStatus);
        	UA_Variant_delete(varStrAncillarySensorStatus);
	}
	//--
	//printf("10200\n");
        varStrSensor = UA_Variant_new();
	if (varStrSensor!=NULL)
	{
		UA_String tmpSensor = UA_STRING(Sensor);
        	UA_Variant_setScalarCopy(varStrSensor, &tmpSensor, &UA_TYPES[UA_TYPES_STRING]);
        	UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10201), varStrSensor);
        	UA_Variant_delete(varStrSensor);
	}

	// val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &OperatingTime, &UA_TYPES[UA_TYPES_INT16]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10202), val);
        //UA_Variant_delete(val);

        varStrWarningMessage = UA_Variant_new();
	if (varStrWarningMessage!=NULL)
	{
		UA_String tmpWarningMessage = UA_STRING(WarningMessage);
        	UA_Variant_setScalarCopy(varStrWarningMessage, &tmpWarningMessage, &UA_TYPES[UA_TYPES_STRING]);
        	UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10203), varStrWarningMessage);
        	UA_Variant_delete(varStrWarningMessage);
	}

	//--
	//printf("10300\n");
	//val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &IgramPP, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10301), val);
        //UA_Variant_delete(val);

        //val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &IgramDC, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10302), val);
        //UA_Variant_delete(val);

        //val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &LaserPP, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10303), val);
        //UA_Variant_delete(val);

        //val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &LaserDC, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10304), val);
        //UA_Variant_delete(val);

        //val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &SingleBeamAt900, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10305), val);
        //UA_Variant_delete(val);

        //val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &SingleBeamAt2500, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10306), val);
        //UA_Variant_delete(val);

        //val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &SignalToNoiseAt2500, &UA_TYPES[UA_TYPES_INT16]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10307), val);
        //UA_Variant_delete(val);

        //val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &CenterBurstLocation, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10308), val);
        //UA_Variant_delete(val);

        //val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &DetectorTemp, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10309), val);
        //UA_Variant_delete(val);

        //val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &LaserFrequency, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10310), val);
        //UA_Variant_delete(val);

        //val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &HardDriveSpace, &UA_TYPES[UA_TYPES_INT16]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10311), val);
        //UA_Variant_delete(val);

        //val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &Flow, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10312), val);
        //UA_Variant_delete(val);

        //val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &Temperature, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10313), val);
        //UA_Variant_delete(val);

        //val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &Pressure, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10314), val);
        //UA_Variant_delete(val);

        //val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &TempOptics, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10315), val);
        //UA_Variant_delete(val);

        //val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &BadScanCounter, &UA_TYPES[UA_TYPES_INT16]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10316), val);
        //UA_Variant_delete(val);

        //val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &FreeMemorySpace, &UA_TYPES[UA_TYPES_INT16]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10317), val);
        //UA_Variant_delete(val);

        varStrLABFilename = UA_Variant_new();
        if (varStrLABFilename!=NULL)
        {
                UA_String tmpLABFilename = UA_STRING(LABFilename);
                UA_Variant_setScalarCopy(varStrLABFilename, &tmpLABFilename, &UA_TYPES[UA_TYPES_STRING]);
                UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10318), varStrLABFilename);
                UA_Variant_delete(varStrLABFilename);
        }

        varStrLOGFilename = UA_Variant_new();
	if (varStrLOGFilename!=NULL)
	{
		UA_String tmpLOGFilename = UA_STRING(LOGFilename);
        	UA_Variant_setScalarCopy(varStrLOGFilename, &tmpLOGFilename, &UA_TYPES[UA_TYPES_STRING]);
        	UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10319), varStrLOGFilename);
        	UA_Variant_delete(varStrLOGFilename);
	}

        varStrLgFilename = UA_Variant_new();
	if (varStrLgFilename!=NULL)
	{
		UA_String tmpLgFilename = UA_STRING(LgFilename);
        	UA_Variant_setScalarCopy(varStrLgFilename, &tmpLgFilename, &UA_TYPES[UA_TYPES_STRING]);
        	UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10320), varStrLgFilename);
        	UA_Variant_delete(varStrLgFilename);
	}

        varStrSecondLgFilename = UA_Variant_new();
	if (varStrSecondLgFilename!=NULL)
	{
		UA_String tmpSecondLgFilename = UA_STRING(SecondLgFilename);
        	UA_Variant_setScalarCopy(varStrSecondLgFilename, &tmpSecondLgFilename, &UA_TYPES[UA_TYPES_STRING]);
        	UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10321), varStrSecondLgFilename);
        	UA_Variant_delete(varStrSecondLgFilename);
	}

        //val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &SystemCounter, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10322), val);
        //UA_Variant_delete(val);

        //val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &DetectorCounter, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10323), val);
        //UA_Variant_delete(val);

        //val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &LaserCounter, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10324), val);
        //UA_Variant_delete(val);

        //val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &FlowPumpCounter, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10325), val);
        //UA_Variant_delete(val);

        //val = UA_Variant_new();
        UA_Variant_setScalarCopy(val, &DesiccantCounter, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10326), val);
        //UA_Variant_delete(val);

	//--
	printf("In StartOPCUAClient() : 10400\n"); // Data Subtree
	printf("Update UA Address space : Data->Alarms : 10401 : %d\n", NoOfAlarms); // Alarms subtree
	UA_Variant_setScalarCopy(val, &NoOfAlarms, &UA_TYPES[UA_TYPES_INT16]);		// eg <Alarms>2</Alarms>
	UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10401), val);	// somehow UAExpert cannot see updates to <1. Alarms>

	// process in a loop iteration based on the value extracted from val;
        varStrAlarms = UA_Variant_new();
        if (varStrAlarms!=NULL)
        {
		//UA_Variant NoOfAlarmIterations;
		int AlarmIterator=NoOfAlarms;	// line 926
		UA_StatusCode retval;

		retval = UA_Client_readValueAttribute(uaClient, UA_NODEID_NUMERIC(1,10401), varStrAlarms);
		if(retval == UA_STATUSCODE_GOOD && UA_Variant_hasScalarType(varStrAlarms, &UA_TYPES[UA_TYPES_INT16])) 
		{
			UA_Int16 raw_data = *(UA_Int16 *)varStrAlarms->data;
			AlarmIterator = raw_data;
			printf("AlarmIterator value here is %d\n", AlarmIterator);
		}

		char Alarmstr[255],Tagstr[255], Namestr[255], Probabilitystr[255], CASnumberstr[255], Concentrationstr[255];
		for (int i=0; i<AlarmIterator; i++)
		{
			if (arrayOfAlarm == NULL)
			{
				printf("672: Fatal error : arrayOfAlarm not does exist\n");
				exit(-1);
			}
			//arrayOfAlarm[i] = malloc(sizeof(AlarmStruct));
			/*
			strcpy(arrayOfAlarm[i].Tag, "Test1");
			strcpy(arrayOfAlarm[i].Name, "Test2");
			strcpy(arrayOfAlarm[i].CASnumber, "Test3");
			arrayOfAlarm[i].Probability = 0.0;
			arrayOfAlarm[i].Concentration = 0;
			*/
			// create a new node under <Data->Alarm_(i)>; start with NodeID=20001 : need to differentiate between more than 1 Alarm segments
                        // Add objectnode to represent Airgard->data->Alarm_(i)
                        //shift before FOR : UA_NodeId r3_airgard_data_Alarm_Id;
			printf("creating node Data->Alarm-%d \n",i+1);

			UA_NodeId r3_airgard_data_Alarm_Id;	/* get the nodeid assigned by the server */
                        UA_ObjectAttributes oAttr_r3_data_Alarm_Info = UA_ObjectAttributes_default;
			sprintf(Alarmstr,"AlarmInfo-%d", i+1);
                        oAttr_r3_data_Alarm_Info.description = UA_LOCALIZEDTEXT("en-US", Alarmstr);
			sprintf(Alarmstr,"Alarm-%d", i+1);
                        oAttr_r3_data_Alarm_Info.displayName = UA_LOCALIZEDTEXT("en-US", Alarmstr);
                        //UA_Server_addObjectNode(server, UA_NODEID_NUMERIC(1, 20000+i),		// 20000 series

			UA_Client_addObjectNode(uaClient, UA_NODEID_STRING(1, Alarmstr),
			                r2_airgard_data_Id,				// only this is special as the address is pass in]
                                        UA_NODEID_NUMERIC(0, UA_NS0ID_HASSUBTYPE),
                                        UA_QUALIFIEDNAME(1, Alarmstr),
                                        UA_NODEID_NUMERIC(0, UA_NS0ID_BASEOBJECTTYPE),
                                        oAttr_r3_data_Alarm_Info, &r3_airgard_data_Alarm_Id);

			//if (retval != NULL) : segmentation fault
			//{
			//	printf("object : r3_airgard_data_Alarm_Id : %d\n", r3_airgard_data_Alarm_Id);
			//	printf("Successfully create new node under Data->Alarm-1 \n");
			//}
			//else printf("Node : Data->Alarm-1 already exist\n");
		//--

					//	printf("creating node Data->Alarm-%d:Tag-%d\n", i+1,i+1);
                        	UA_VariableAttributes vTagAttr = UA_VariableAttributes_default;
				sprintf(Tagstr,"Alarm:TagInfo-%d",i+1);
				vTagAttr.description = UA_LOCALIZEDTEXT("en-US", Tagstr);
				sprintf(Tagstr,"1. Tag-%d",i+1);
				vTagAttr.displayName = UA_LOCALIZEDTEXT("en-US", Tagstr);
                        	vTagAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
                        	UA_String iTag[255];
				UA_Variant_setArray(&vTagAttr.value, &iTag, 254, &UA_TYPES[UA_TYPES_STRING]);sprintf(Tagstr,"A%d:Tag",i+1);

					//printf("At Tag section, r3_airgard_data_Alarm_Id :%d\n", r3_airgard_data_Alarm_Id);
				UA_Client_addVariableNode(uaClient, UA_NODEID_STRING(1, Tagstr),
					r3_airgard_data_Alarm_Id,
			    		UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                                        UA_QUALIFIEDNAME(1, Tagstr),
                                        UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
                                        vTagAttr, NULL);
						printf("Successfully create new <Tag> variable node : Alarm-%d:Tag-%d \n",i+1,i+1);

		//--

					//printf("creating node Data->Alarm-%d:Name-%d\n",i+1,i+1);
	                        UA_VariableAttributes vNameAttr = UA_VariableAttributes_default;sprintf(Namestr,"Alarm:NameInfo-%d",i+1);
                	        vNameAttr.description = UA_LOCALIZEDTEXT("en-US", Namestr);sprintf(Namestr,"2. Name-%d",i+1);
        	                vNameAttr.displayName = UA_LOCALIZEDTEXT("en-US", Namestr);
                	        vNameAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
				UA_String iAlarmName[255];
        	                UA_Variant_setArray(&vNameAttr.value, &iAlarmName, 254, &UA_TYPES[UA_TYPES_STRING]);sprintf(Namestr,"A%d:Name",i+1);
		
				printf("Before UA_Server_addVariableNode, mystring should be (A1:Name) : %s, r3_airgard_data_Alarm_Id : %d \n", Namestr,r3_airgard_data_Alarm_Id);
                        	UA_Client_addVariableNode(uaClient, UA_NODEID_STRING(1, Namestr),
					r3_airgard_data_Alarm_Id,
                                        UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                                        UA_QUALIFIEDNAME(1, Namestr),
                                        UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
                                        vNameAttr, NULL);
                        			printf("Successfully create new <Name> variable node : Alarm-1:Name-1 \n");
		
		//--
					//printf("creating node Data->Alarm-%d:Probability-%d \n", i+1,i+1);
	                        UA_VariableAttributes vProbabilityAttr = UA_VariableAttributes_default; sprintf(Probabilitystr,"Alarm:ProbabilityInfo-%d",i+1);
                	        vProbabilityAttr.description = UA_LOCALIZEDTEXT("en-US", Probabilitystr); sprintf(Probabilitystr,"3. Probability-%d",i+1);
        	                vProbabilityAttr.displayName = UA_LOCALIZEDTEXT("en-US", Probabilitystr);
                	        vProbabilityAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	                        UA_Float iAlarmProbability;
        	                UA_Variant_setScalar(&vProbabilityAttr.value, &iAlarmProbability, &UA_TYPES[UA_TYPES_FLOAT]);
                	        sprintf(Probabilitystr,"A%d:Probability",i+1);
		
   	                        UA_Client_addVariableNode(uaClient, UA_NODEID_STRING(1, Probabilitystr),
                                        r3_airgard_data_Alarm_Id,
                                        UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                                        UA_QUALIFIEDNAME(1, Probabilitystr),
                                        UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
                                        vProbabilityAttr, NULL);
                        			printf("Successfully create new <Probability> variable node : Alarm-%d:Probability-%d \n",i+1,i+1);
		
		//--
					//printf("creating node Data->Alarm-%d:CASnumber-%d \n",i+1,i+1);
	                        UA_VariableAttributes vCASnumberAttr = UA_VariableAttributes_default; sprintf(CASnumberstr,"Alarm:CASnumberInfo-%d",i+1);
                	        vCASnumberAttr.description = UA_LOCALIZEDTEXT("en-US", CASnumberstr); sprintf(CASnumberstr,"4. CASnumber-%d",i+1);
                        	vCASnumberAttr.displayName = UA_LOCALIZEDTEXT("en-US", CASnumberstr);
	                        vCASnumberAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
        	                UA_String iAlarmCASnumber[255];
                	        UA_Variant_setArray(&vCASnumberAttr.value, &iAlarmCASnumber, 254, &UA_TYPES[UA_TYPES_STRING]);
	                        sprintf(CASnumberstr,"A%d:CASnumber",i+1);

        	                UA_Client_addVariableNode(uaClient, UA_NODEID_STRING(1, CASnumberstr),
                                        r3_airgard_data_Alarm_Id,
                                        UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                                        UA_QUALIFIEDNAME(1, CASnumberstr),
                                        UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
                                        vCASnumberAttr, NULL);						// CASnumber has issue; temporary use Name
                       				printf("Successfully create new <CAS> variable node : Alarm-1:CASnumber-1 \n");

		//--
					//printf("creating node Data->Alarm-%d:Concentration-%d \n", i+1,i+1);
	                        UA_VariableAttributes vConcentrationAttr = UA_VariableAttributes_default;
        	                sprintf(Concentrationstr,"Alarm:ConcentrationInfo-%d",i+1);
                	        vConcentrationAttr.description = UA_LOCALIZEDTEXT("en-US", Concentrationstr);
	                        sprintf(Concentrationstr,"5. Concentration-%d",i+1);
        	                vConcentrationAttr.displayName = UA_LOCALIZEDTEXT("en-US", Concentrationstr);
                	        vConcentrationAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	                        UA_Int16 iAlarmConcentration;
        	                UA_Variant_setScalar(&vConcentrationAttr.value, &iAlarmConcentration, &UA_TYPES[UA_TYPES_INT16]);
                	        sprintf(Concentrationstr,"A%d:Concentration",i+1);
		
                        	UA_Client_addVariableNode(uaClient, UA_NODEID_STRING(1, Concentrationstr),
                                        r3_airgard_data_Alarm_Id,
                                        UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
                                        UA_QUALIFIEDNAME(1, Concentrationstr),
                                        UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
                                        vConcentrationAttr, NULL);
            	            			printf("Successfully create new <Concentration> variable node : Alarm-%d:Concentration-%d \n",i+1,i+1);
		
		//--
			//printf("pause for 2 second before UA_Client_writeValueAttribute()"); sleep(2);

			//printf("Alarm info to be updated to OPCUA Address space : \n");
			//printf("Tag : %s \n", arrayOfAlarm[i].Tag);
			//printf("Name : %s \n", arrayOfAlarm[i].Name); // kiv for Tag, Name, CASnumber 
			//printf("Probability : %f \n", arrayOfAlarm[i].Probability);
			//printf("CASnumber : %s \n", arrayOfAlarm[i].CASnumber);
			//printf("Concentration	: %d \n", arrayOfAlarm[i].Concentration);

			// finally write Alarm subnodes to UA address space

			varStrAlarmTag = UA_Variant_new();
			if (varStrAlarmTag!=NULL)
			{
				UA_String tmpAlarmTag = UA_STRING(arrayOfAlarm[i].Tag);
				UA_Variant_setScalarCopy(varStrAlarmTag, &tmpAlarmTag, &UA_TYPES[UA_TYPES_STRING]);
                        	UA_Client_writeValueAttribute(uaClient, UA_NODEID_STRING(1, Tagstr), varStrAlarmTag);
 				UA_Variant_delete(varStrAlarmTag);
			}
			printf("here 2 \n");

		        varStrAlarmName = UA_Variant_new();
			if (varStrAlarmName!=NULL)
			{
				UA_String tmpAlarmName = UA_STRING(arrayOfAlarm[i].Name);
				UA_Variant_setScalarCopy(varStrAlarmName, &tmpAlarmName, &UA_TYPES[UA_TYPES_STRING]);
				UA_Client_writeValueAttribute(uaClient, UA_NODEID_STRING(1, Namestr), varStrAlarmName);
				UA_Variant_delete(varStrAlarmName);
			}

			float AlarmProbability = arrayOfAlarm[i].Probability;
        			UA_Variant_setScalarCopy(val, &AlarmProbability, &UA_TYPES[UA_TYPES_FLOAT]);
        			UA_Client_writeValueAttribute(uaClient, UA_NODEID_STRING(1, Probabilitystr), val);

			varStrAlarmCASnumber = UA_Variant_new();
			if (varStrAlarmCASnumber!=NULL)
			{
				UA_String tmpAlarmCASnumber = UA_STRING(arrayOfAlarm[i].CASnumber);
				UA_Variant_setScalarCopy(varStrAlarmCASnumber, &tmpAlarmCASnumber, &UA_TYPES[UA_TYPES_STRING]);
				UA_Client_writeValueAttribute(uaClient, UA_NODEID_STRING(1, CASnumberstr), varStrAlarmCASnumber);
        			UA_Variant_delete(varStrAlarmCASnumber);
			}

                        int AlarmConcentration = arrayOfAlarm[i].Concentration;
                                UA_Variant_setScalarCopy(val, &AlarmConcentration, &UA_TYPES[UA_TYPES_INT16]);
                                UA_Client_writeValueAttribute(uaClient, UA_NODEID_STRING(1, Concentrationstr), val);

		}

		// frees up the malloc memory space ArrayOfAlarms[i]
		//for (int i=0;i<Alarms; i++)
		//	free(arrayOfAlarm[i]); 	// free the individual array cells
		//free(arrayOfAlarm);		// free the main ptr
        }


        printf("Update UA Address space : Data->NonAlarms : 10402 : %d\n", NoOfNonAlarms); // Non Alarms subtree
        UA_Variant_setScalarCopy(val, &NoOfNonAlarms, &UA_TYPES[UA_TYPES_INT16]);           // eg <NonAlarms>0</NonAlarms>
        UA_Client_writeValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10402), val);

        varStrNonAlarms = UA_Variant_new();
        if (varStrNonAlarms!=NULL)
        {
		int NonAlarmIterator= NoOfNonAlarms;
		UA_StatusCode retval;

		retval = UA_Client_readValueAttribute(uaClient, UA_NODEID_NUMERIC(1, 10402), varStrNonAlarms);
		if (retval == UA_STATUSCODE_GOOD && UA_Variant_hasScalarType(varStrNonAlarms, &UA_TYPES[UA_TYPES_INT16]))
		{
			UA_Int16 raw_data = *(UA_Int16 *)varStrNonAlarms->data;
			NonAlarmIterator = raw_data;
			printf("NonAlarmIterator value here is %d\n", NonAlarmIterator);
		}

		char NonAlarmstr[255], NonTagstr[255], NonNamestr[255], NonProbabilitystr[255], NonCASnumberstr[255], NonConcentrationstr[255];
		for (int i=0; i<NonAlarmIterator; i++)
		{
			if (arrayOfAlarm == NULL)
			{
				printf("1360 : Fatal error : arrayOfNonAlarm does not exist\n");
				exit(-1);
			}

			// create a new node under <Data->Alarm_(i)>; start with NodeID=20001 : need to differentiate between more than 1 Alarm segments
			// Add objectnode to represent Airgard->data->Alarm_(i)
			// Add objectnode to represent Airgard->data->Alarm_(i

			printf("1370 creating node Data->NonAlarm-%d \n",i+1);

			UA_NodeId r3_airgard_data_NonAlarm_Id;     /* get the nodeid assigned by the server */
			UA_ObjectAttributes oAttr_r3_data_NonAlarm_Info = UA_ObjectAttributes_default;
			sprintf(NonAlarmstr,"NonAlarmInfo-%d", i+1);
			oAttr_r3_data_NonAlarm_Info.description = UA_LOCALIZEDTEXT("en-US", NonAlarmstr);
			sprintf(NonAlarmstr,"NonAlarm-%d", i+1);
			oAttr_r3_data_NonAlarm_Info.displayName = UA_LOCALIZEDTEXT("en-US", NonAlarmstr);
			//UA_Server_addObjectNode(server, UA_NODEID_NUMERIC(1, 20000+i),                // 20000 series

			UA_Client_addObjectNode(uaClient, UA_NODEID_STRING(1, NonAlarmstr),
				r2_airgard_data_Id,                             // line 1381: only this is special as the address is pass in]
				UA_NODEID_NUMERIC(0, UA_NS0ID_HASSUBTYPE),
				UA_QUALIFIEDNAME(1, NonAlarmstr),
				UA_NODEID_NUMERIC(0, UA_NS0ID_BASEOBJECTTYPE),
				oAttr_r3_data_NonAlarm_Info, &r3_airgard_data_NonAlarm_Id);

			//
				printf("creating node Data->NonAlarm-%d:Tag-%d\n", i+1,i+1);
				UA_VariableAttributes vNonTagAttr = UA_VariableAttributes_default; sprintf(NonTagstr,"NonAlarm:TagInfo-%d",i+1);
				vNonTagAttr.description = UA_LOCALIZEDTEXT("en-US", NonTagstr); sprintf(NonTagstr,"1. Tag-%d",i+1);
				vNonTagAttr.displayName = UA_LOCALIZEDTEXT("en-US", NonTagstr);

				vNonTagAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
				UA_String iNonTag[255];
				UA_Variant_setArray(&vNonTagAttr.value, &iNonTag, 254, &UA_TYPES[UA_TYPES_STRING]); sprintf(NonTagstr,"NA%d:Tag",i+1);

				//    printf("At Tag section, r3_airgard_data_NonAlarm_Id \n"); // r3_airgard_data_NonAlarm_Id);
				UA_Client_addVariableNode(uaClient, UA_NODEID_STRING_ALLOC(1, NonTagstr),
					r3_airgard_data_NonAlarm_Id,
					UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
					UA_QUALIFIEDNAME(1, NonTagstr),
					UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
					vNonTagAttr, NULL);
				printf("Successfully create new <Tag> variable node : NonAlarm-%d:Tag-%d \n",i+1,i+1);
				/**/

				//printf("1405 creating node Data->NonAlarm-%d:Name-%d \n",i+1,i+1);
				UA_VariableAttributes vNonNameAttr = UA_VariableAttributes_default; sprintf(NonNamestr,"NonAlarm:NameInfo-%d",i+1);
				vNonNameAttr.description = UA_LOCALIZEDTEXT("en-US", NonNamestr); sprintf(NonNamestr,"2. Name-%d",i+1);
				vNonNameAttr.displayName = UA_LOCALIZEDTEXT("en-US", NonNamestr);
				vNonNameAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
				UA_String iNonName[255];
				UA_Variant_setArray(&vNonNameAttr.value, &iNonName, 254, &UA_TYPES[UA_TYPES_STRING]); sprintf(NonNamestr,"NA%d:Name",i+1);

				//    printf("At Name section, r3_airgard_data_NonAlarm_Id \n"); // r3_airgard_data_NonAlarm_Id);
				UA_Client_addVariableNode(uaClient, UA_NODEID_STRING_ALLOC(1, NonNamestr),
					r3_airgard_data_NonAlarm_Id,
					UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
					UA_QUALIFIEDNAME(1, NonNamestr),
					UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
					vNonNameAttr, NULL);

				printf("1405 Successfully create new <Name> variable node : NonAlarm-%d:Name-%d \n",i+1,i+1);
				/**/
			//--
				//printf("1423 creating node Data->NonAlarm-%d:Probability-%d \n", i+1,i+1);
				UA_VariableAttributes vNonProbabilityAttr = UA_VariableAttributes_default; sprintf(NonProbabilitystr,"NonAlarm:ProbabilityInfo-%d",i+1);
				vNonProbabilityAttr.description = UA_LOCALIZEDTEXT("en-US", NonProbabilitystr); sprintf(NonProbabilitystr,"3. Probability-%d",i+1);
				vNonProbabilityAttr.displayName = UA_LOCALIZEDTEXT("en-US", NonProbabilitystr);
				vNonProbabilityAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
				UA_Float iNonProbability;
				UA_Variant_setScalar(&vNonProbabilityAttr.value, &iNonProbability, &UA_TYPES[UA_TYPES_FLOAT]); sprintf(NonProbabilitystr,"NA%d:Probability",i+1);

				//printf("At Probability section, r3_airgard_data_NonAlarm_Id \n"); // r3_airgard_data_NonAlarm_Id);
				UA_Client_addVariableNode(uaClient, UA_NODEID_STRING_ALLOC(1, NonProbabilitystr),
					r3_airgard_data_NonAlarm_Id,
					UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
					UA_QUALIFIEDNAME(1, NonProbabilitystr),
					UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
					vNonProbabilityAttr, NULL);
				printf("Successfully create new <Probability> variable node : NonAlarm-%d:Probability-%d \n",i+1,i+1);

			//--
				//printf("creating node Data->NonAlarm-%d:CASnumber-%d \n",i+1,i+1);
				UA_VariableAttributes vNonCASnumberAttr = UA_VariableAttributes_default; sprintf(NonCASnumberstr,"NonAlarm:CASnumberInfo-%d",i+1);
				vNonCASnumberAttr.description = UA_LOCALIZEDTEXT("en-US", NonCASnumberstr); sprintf(NonCASnumberstr,"4. CASnumber-%d",i+1);
				vNonCASnumberAttr.displayName = UA_LOCALIZEDTEXT("en-US", NonCASnumberstr);
				vNonCASnumberAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
				UA_String iNonCASnumber[255];
				UA_Variant_setArray(&vNonCASnumberAttr.value, &iNonCASnumber, 254, &UA_TYPES[UA_TYPES_STRING]); sprintf(NonCASnumberstr,"NA%d:CASnumber",i+1);

				//printf("At CASnumber section, r3_airgard_data_NonAlarm_Id :%d\n", r3_airgard_data_NonAlarm_Id);
				UA_Client_addVariableNode(uaClient, UA_NODEID_STRING_ALLOC(1, NonCASnumberstr),
					r3_airgard_data_NonAlarm_Id,
					UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
					UA_QUALIFIEDNAME(1, NonCASnumberstr),
					UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
					vNonCASnumberAttr, NULL); // vCASnumberAttr is the cause of the crash here; temporary replaced by vNonNameAttr
				printf("Successfully create new <CASnumber> variable node : NonAlarm-%d:CASnumber-%d \n",i+1,i+1);

			//--
				//printf("creating node Data->NonAlarm-%d:Concentration-%d \n", i+1,i+1);
				UA_VariableAttributes vNonConcentrationAttr = UA_VariableAttributes_default; sprintf(NonConcentrationstr,"NonAlarm:ConcentrationInfo-%d",i+1);
				vNonConcentrationAttr.description = UA_LOCALIZEDTEXT("en-US", NonConcentrationstr); sprintf(NonConcentrationstr,"5. Concentration-%d",i+1);
				vNonConcentrationAttr.displayName = UA_LOCALIZEDTEXT("en-US", NonConcentrationstr);
				vNonConcentrationAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
				UA_Int16 iNonConcentration;
				UA_Variant_setScalar(&vNonConcentrationAttr.value, &iNonConcentration, &UA_TYPES[UA_TYPES_INT16]);sprintf(NonConcentrationstr,"NA%d:Concentration",i+1);

				//printf("At Concentration section, r3_airgard_data_NonAlarm_Id :%d\n", r3_airgard_data_NonAlarm_Id);
				UA_Client_addVariableNode(uaClient, UA_NODEID_STRING_ALLOC(1, NonConcentrationstr),
					r3_airgard_data_NonAlarm_Id,
					UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
					UA_QUALIFIEDNAME(1, NonConcentrationstr),
					UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
					vNonConcentrationAttr, NULL);
				printf("Successfully create new <Concentration> variable node : NonAlarm-%d:Concentration-%d \n",i+1,i+1);

			//--
				//printf("NonAlarm info to be updated to OPCUA Address space : \n");
				//printf("Tag             : %s \n", arrayOfNonAlarm[i].Tag);
				//printf("Name            : %s \n", arrayOfNonAlarm[i].Name);
				//printf("Probability     : %f \n", arrayOfNonAlarm[i].Probability);
				//printf("CASnumber       : %s \n", arrayOfNonAlarm[i].CASnumber);
				//printf("Concentration   : %d \n", arrayOfNonAlarm[i].Concentration);

				// finally write NonAlarm subnodes to UA address space
				varStrNonAlarmTag = UA_Variant_new();
				if (varStrNonAlarmTag!=NULL)
				{
					UA_String tmpNonAlarmTag = UA_STRING(arrayOfNonAlarm[i].Tag);
					UA_Variant_setScalarCopy(varStrNonAlarmTag, &tmpNonAlarmTag, &UA_TYPES[UA_TYPES_STRING]);
					UA_Client_writeValueAttribute(uaClient, UA_NODEID_STRING(1, NonTagstr), varStrNonAlarmTag);
					UA_Variant_delete(varStrNonAlarmTag);
				}
				printf("here 2A \n");

				varStrNonAlarmName = UA_Variant_new();
				if (varStrNonAlarmName!=NULL)
				{
					UA_String tmpNonAlarmName = UA_STRING(arrayOfNonAlarm[i].Name);
					UA_Variant_setScalarCopy(varStrNonAlarmName, &tmpNonAlarmName, &UA_TYPES[UA_TYPES_STRING]);
					UA_Client_writeValueAttribute(uaClient, UA_NODEID_STRING(1, NonNamestr), varStrNonAlarmName);
					UA_Variant_delete(varStrNonAlarmName);
				}

				iNonProbability = arrayOfNonAlarm[i].Probability;
				UA_Variant_setScalarCopy(val, &iNonProbability, &UA_TYPES[UA_TYPES_FLOAT]);
				UA_Client_writeValueAttribute(uaClient, UA_NODEID_STRING(1, NonProbabilitystr), val);

				varStrNonAlarmCASnumber = UA_Variant_new();
				if (varStrNonAlarmCASnumber!=NULL)
				{
					UA_String tmpNonAlarmCASnumber = UA_STRING(arrayOfNonAlarm[i].CASnumber);
					UA_Variant_setScalarCopy(varStrNonAlarmCASnumber, &tmpNonAlarmCASnumber, &UA_TYPES[UA_TYPES_STRING]);
					UA_Client_writeValueAttribute(uaClient, UA_NODEID_STRING(1, NonCASnumberstr), varStrNonAlarmCASnumber);
					UA_Variant_delete(varStrNonAlarmCASnumber);
				}

				iNonConcentration = arrayOfAlarm[i].Concentration;
				UA_Variant_setScalarCopy(val, &iNonConcentration, &UA_TYPES[UA_TYPES_INT16]);
				UA_Client_writeValueAttribute(uaClient, UA_NODEID_STRING(1, NonConcentrationstr), val);

		} // end FOR
	} // end IF

	if (val!=NULL)
		UA_Variant_delete(val);

	printf("after UA_Variant_delete(val)\n");

	/* DO NOT FREE uaClient
	if (uaClient !=NULL)
	{
		UA_Client_disconnect(uaClient);
		free(uaClient);
	}
	printf("after free(uaClient)\n");
	*/

        // monitoreditems call initiation

        addMonitoredItemToSoftwareVersionVariable(uaClient);
        addMonitoredItemToDataBlockVersionVariable(uaClient);
        addMonitoredItemToInstrumentTimeVariable(uaClient);
        addMonitoredItemToMeasurementTimeVariable(uaClient);

        addMonitoredItemToBootStatusVariable(uaClient);
        addMonitoredItemToSnapshotStatusVariable(uaClient);
        addMonitoredItemToSCPStatusVariable(uaClient);
        addMonitoredItemToSFTPStatusVariable(uaClient);
        addMonitoredItemToRunScriptStatusVariable(uaClient);
        addMonitoredItemToArchiveStatusVariable(uaClient);
        addMonitoredItemToAncillarySensorStatusVariable(uaClient);

        addMonitoredItemToSensorVariable(uaClient);
        addMonitoredItemToOperatingTimeVariable(uaClient);
        addMonitoredItemToWarningMessageVariable(uaClient);

        addMonitoredItemToIgramPPVariable(uaClient);
        addMonitoredItemToIgramDCVariable(uaClient);
        addMonitoredItemToLaserPPVariable(uaClient);
        addMonitoredItemToLaserDCVariable(uaClient);
        addMonitoredItemToSingleBeamAt900Variable(uaClient);
        addMonitoredItemToSingleBeamAt2500Variable(uaClient);
        addMonitoredItemToSignalToNoiseAt2500Variable(uaClient);
        addMonitoredItemToCenterBurstLocationVariable(uaClient);
        addMonitoredItemToDetectorTempVariable(uaClient);
        addMonitoredItemToLaserFrequencyVariable(uaClient);
        addMonitoredItemToHardDriveSpaceVariable(uaClient);
        addMonitoredItemToFlowVariable(uaClient);
        addMonitoredItemToTemperatureVariable(uaClient);
        addMonitoredItemToPressureVariable(uaClient);
        addMonitoredItemToTempOpticsVariable(uaClient);
        addMonitoredItemToBadScanCounterVariable(uaClient);
        addMonitoredItemToFreeMemorySpaceVariable(uaClient);
        addMonitoredItemToLABFilenameVariable(uaClient);
        addMonitoredItemToLOGFilenameVariable(uaClient);
        addMonitoredItemToLgFilenameVariable(uaClient);
        addMonitoredItemToSecondLgFilenameVariable(uaClient);
        addMonitoredItemToSystemCounterVariable(uaClient);
        addMonitoredItemToDetectorCounterVariable(uaClient);
        addMonitoredItemToLaserCounterVariable(uaClient);
        addMonitoredItemToFlowPumpCounterVariable(uaClient);
        addMonitoredItemToDesiccantCounterVariable(uaClient);

	printf("After addMonitoredItem \n");
	return (0);

} // End StartOPCUAClient()
