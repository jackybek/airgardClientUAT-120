#include "open62541.h"
#include <stdio.h>
#include <string.h>
//#include "AG_NewMonitor.h"
//#include "myNewPubSub.h"
#define MAX_BUFFER_SIZE 20000

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


extern char g_argv_ip[255];
extern int g_argv_port;
static UA_Boolean UA_Nodes_Setup = false;

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
extern UA_Int16 Flow;
extern UA_Int16 Temperature;
extern UA_Float Pressure;
extern UA_Int16 TempOptics;
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

static UA_NodeId r2_airgard_data_Id;

UA_NodeId CreateOPCUANodes(void* x_void_ptr);
void CreateMethodNodes(UA_Client *uaClient, UA_NodeId r2_airgard_method_Id);

//void* CreateAndPopulateNodes(void* x_void_ptr)
UA_NodeId CreateOPCUANodes(void* x_void_ptr)
{
    // Airgard subtree (root node)
    char XMLSoftwareVersion[255];
    char XMLDataBlockVersion[255];

    // TimeStamp subtree
    char XMLInstrumentTime[255];
    char XMLMeasurementTime[255];

    // StatusInfo subtree
    char XMLBootStatus[255];
    char XMLSnapshotStatus[255];
    char XMLSCPStatus[255];
    char XMLSFTPStatus[255];
    char XMLRunScriptStatus[255];
    char XMLArchiveStatus[255];
    char XMLAnciliarySensorStatus;

    // Status subtree
    char XMLSensor[255];
    int XMLOperatingTime = 0;
    char XMLWarningMessage[255];

    // Diagnostics subtree
        //float XMLIgramPP = 0.0;
        //float XMLIgramDC = 0.0;
    //float XMLLaserPP = 0.0;
    //float XMLLaserDC = 0.0;

    float XMLSingleBeamAt900 = 0.0;
    float XMLSingleBeamAt2500 = 0.0;
    int XMLSignalToNoiseRatioAt2500 = 0;
    float XMLCentreBurstLocation = 0.0;
    float XMLDetectorTemp = 0.0;
    float XMLLaserFrequency = 0.0;
    int XMLHardDriveSpace = 0;
    int XMLFlow = 0;
    int XMLTemperature = 0;
    float XMLPressure = 0.0;
    float XMLTempOptics = 0.0;
    int XMLBadScanCounter = 0;
    int XMLFreeMemorySpace = 0;
    char XMLLABFilename[255];
    char XMLLOGFilename[255];
    char XMLLgFilename[255];
    char XMLSecondLgFilename[255];
    float XMLSystemCounter = 0.0;
    float XMLDetectorCounter = 0.0;
    float XMLLaserCounter = 0.0;
    float XMLFlowPumpCounter = 0.0;
    float XMLDesiccantCounter = 0.0;

    // Data subtree
    int XMLAlarms = 0;
    int XMLNonAlarms = 0;

    int numbytes;
    char buffer[MAX_BUFFER_SIZE];
    struct hostent* he;
    struct sockaddr_in airgard_addr;        /* connector's address information */
    int counter = 0;


        //if (( he=gethostbyname(g_argv[1])) == NULL) /* get the host info */
        //if (( he=gethostbyname("192.168.2.88")) == NULL)

    printf("In NA_CreateOPCNodes thread : ip = %s, port = %d\n", g_argv_ip, g_argv_port);

    //UA_Server* server = (UA_Server*)x_void_ptr;
    UA_Client* client = (UA_Client*)x_void_ptr;

    if (!UA_Nodes_Setup) // UA_Nodes only needs to be created the first time
    {
        UA_Nodes_Setup = true;

        /* Create a rudimentary objectType
         *
         * BaseObjectType
         * |
         * + (V) SoftwareVersion
         * + (V) DataBlockVersion
         * +-(OT) TimestampType
         * |   + (V) InstrumentTime
         * |   + (V) MeasurementTime
         * +-(OT) StatusType
         * |   + (V) Sensor
         * |   + (V) OperatingTime
         * |   + (V) WarningMessage
         * |   +(OT) InfoType
         * |   |--+ (V) BootStatus
         * |   |  + (V) SnapshotStatus
         * |   |  + (V) SFTPStatus
         * |-(OT) DiagnosticsType
         * |   + (V) IgramPP
         * |   + (V) ...
         * |   + (V) DesiccantCounter
         * |-(OT) DataType (10400)
         * |   + (V) Alarms (20000)
         * |   + (OT) Alarm
         * |   |---+ (V) Tag
         * |   |   + (V) Name
         * |   |   + (V) Probability
         * |   |   + (V) CASnumber
         * |   |   + (V) Concentration
         * |   + (OT) Alarm
         * |   | <repeat>
         * |   + (V) NonAlarms (30000)
        */

        printf("======================In UA Nodes setup======================= \n");

        //Add a new namespace to the server
        //UA_Int16 ns_MKS = UA_Server_addNamespace(server, "MKS");
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "New Namespace added with Nr. %d \n", ns_MKS);

        // Add new object called Airgard Sensor
        UA_NodeId r1_airgardroot_Id;  /* get the nodeid assigned by the server */
	//UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "---UA_NodeId = %d\n", r1_airgardroot_Id);

        UA_ObjectAttributes oAttr = UA_ObjectAttributes_default;
        UA_Client_addObjectNode(client, UA_NODEID_STRING(1, "AirGardSensor"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),		// original UA_NS0ID_ORGANIZES
            UA_QUALIFIEDNAME(1, "AirGard"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEOBJECTTYPE),		// this refers to the Object Type identifier
            oAttr, &r1_airgardroot_Id);			// node id assigned by the server

        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Root Node created : Airgard\n", r1_airgardroot_Id);		// OK

    //***// Subtree: Airgard->Software Version (1,10000)

        // variable
        UA_VariableAttributes vSoftwareVersionAttr = UA_VariableAttributes_default;
        vSoftwareVersionAttr.description = UA_LOCALIZEDTEXT("en-US", "Software Version Info");
        vSoftwareVersionAttr.displayName = UA_LOCALIZEDTEXT("en-US", "1. Software Version");
        vSoftwareVersionAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
        //UA_String SoftwareVersion = (UA_String) XMLSoftwareVersion;
        UA_String SoftwareVersion[255];
        //strcpy(SoftwareVersion, XMLSoftwareVersion);
        UA_Variant_setArray(&vSoftwareVersionAttr.value, &SoftwareVersion, 254, &UA_TYPES[UA_TYPES_STRING]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10001),		// NodeId
            r1_airgardroot_Id,				// parent NodeId
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),	// parent Reference NodeId
            UA_QUALIFIEDNAME(1, "Software Version"),	// Qualified Name
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vSoftwareVersionAttr, NULL);

        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->VersionType->SoftwareVersion\n", r1_airgardroot_Id);

        // variable
        UA_VariableAttributes vDataBlockVersionAttr = UA_VariableAttributes_default;
        vDataBlockVersionAttr.description = UA_LOCALIZEDTEXT("en-US", "Data Block Version Info");
        vDataBlockVersionAttr.displayName = UA_LOCALIZEDTEXT("en-US", "2. Data Block Version");
        vDataBlockVersionAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
        //UA_String DataBlockVersion = (UA_String) XMLDataBlockVersion;
        UA_String DataBlockVersion[255];
        //strcpy(DataBlockVersion, XMLDataBlockVersion);
        UA_Variant_setArray(&vDataBlockVersionAttr.value, &DataBlockVersion, 254, &UA_TYPES[UA_TYPES_STRING]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10002), r1_airgardroot_Id,
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "2. Data Block Version"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vDataBlockVersionAttr, NULL);

        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->VersionType->DataBlockVersion\n", r1_airgardroot_Id);

        //***// Subtree: Airgard->Timestamp (1,10100)

            // Add objectnode to represent Airgard->Timestamp
        UA_NodeId r2_airgard_timestamp_Id;  /* get the nodeid assigned by the server */
        UA_ObjectAttributes oAttr_r2_timestamp = UA_ObjectAttributes_default;
        UA_Client_addObjectNode(client, UA_NODEID_STRING(1, "AirGardSensor_TimeStamp"),
            r1_airgardroot_Id,			// Make Airgard node <Contains> Timestamp node		//UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASSUBTYPE),
            UA_QUALIFIEDNAME(1, "Timestamp"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEOBJECTTYPE),
            oAttr_r2_timestamp, &r2_airgard_timestamp_Id);		// here

        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Object Node created : Airgard->Timestamp Node\n", r1_airgardroot_Id);

        // variable
        UA_VariableAttributes vInstrumentTimeAttr = UA_VariableAttributes_default;
        vInstrumentTimeAttr.description = UA_LOCALIZEDTEXT("en-US", "Instrument Time Info");
        vInstrumentTimeAttr.displayName = UA_LOCALIZEDTEXT("en-US", "1. Instrument Time");
        vInstrumentTimeAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
        //UA_String InstrumentTime = (UA_String) XMLInstrumentTime;
        UA_String InstrumentTime[255];
        //strcpy(InstrumenTime, XMLInstrumentTIme);
        UA_Variant_setArray(&vInstrumentTimeAttr.value, &InstrumentTime, 254, &UA_TYPES[UA_TYPES_STRING]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10101),
            r2_airgard_timestamp_Id,
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Instrument Time"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vInstrumentTimeAttr, NULL);

        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->TimestampType->Instrument Time\n", r2_airgard_timestamp_Id);

        // variable
        UA_VariableAttributes vMeasurementTimeAttr = UA_VariableAttributes_default;
        vMeasurementTimeAttr.description = UA_LOCALIZEDTEXT("en-US", "Measurement Time Info");
        vMeasurementTimeAttr.displayName = UA_LOCALIZEDTEXT("en-US", "2. Measurement Time");
        vMeasurementTimeAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
        //UA_String MeasurementTime = (UA_String) XMLMeasurementTime;
        UA_String  MeasurementTime[255];
        //strcpy(MeasurementTime, XMLMeasurementTime);
        UA_Variant_setArray(&vMeasurementTimeAttr.value, &MeasurementTime, 254, &UA_TYPES[UA_TYPES_STRING]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10102),
            r2_airgard_timestamp_Id,
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Measurement Time"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vMeasurementTimeAttr, NULL);

        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->TimestampType->Measurement Time\n", r2_airgard_timestamp_Id);

        //***// Subtree: Airgard->Status (1, 10200)

            // Add objectnode to represent Airgard->Status
        UA_NodeId r2_airgard_status_Id;
        UA_ObjectAttributes oAttr_r2_status = UA_ObjectAttributes_default;
        UA_Client_addObjectNode(client, UA_NODEID_STRING(1, "AirGardSensor_Status"),
            r1_airgardroot_Id,
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASSUBTYPE),
            UA_QUALIFIEDNAME(1, "Status"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEOBJECTTYPE),
            oAttr_r2_status, &r2_airgard_status_Id);

        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Object Node created : Airgard->Status \n", r2_airgard_status_Id);

        // variable
        UA_VariableAttributes vSensorAttr = UA_VariableAttributes_default;
        vSensorAttr.description = UA_LOCALIZEDTEXT("en-US", "Sensor Info");
        vSensorAttr.displayName = UA_LOCALIZEDTEXT("en-US", "1. Sensor");
        vSensorAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
        UA_String Sensor[255];
        UA_Variant_setArray(&vSensorAttr.value, &Sensor, 254, &UA_TYPES[UA_TYPES_STRING]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10201),
            r2_airgard_status_Id,
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Sensor"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vSensorAttr, NULL);

        // variable
        UA_VariableAttributes vOperatingTimeAttr = UA_VariableAttributes_default;
        vOperatingTimeAttr.description = UA_LOCALIZEDTEXT("en-US", "Operating Time Info");
        vOperatingTimeAttr.displayName = UA_LOCALIZEDTEXT("en-US", "2. Operating Time");
        vOperatingTimeAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
        UA_Int16 OperatingTime;
        UA_Variant_setScalar(&vOperatingTimeAttr.value, &OperatingTime, &UA_TYPES[UA_TYPES_INT16]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10202),
            r2_airgard_status_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Operating Time"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vOperatingTimeAttr, NULL);

        // variable
        UA_VariableAttributes vWarningMessageAttr = UA_VariableAttributes_default;
        vWarningMessageAttr.description = UA_LOCALIZEDTEXT("en-US", "WarningMessageInfo");
        vWarningMessageAttr.displayName = UA_LOCALIZEDTEXT("en-US", "3. Warning Message");
        vWarningMessageAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
        UA_String WarningMessage[255];
        UA_Variant_setArray(&vWarningMessageAttr.value, &WarningMessage, 254, &UA_TYPES[UA_TYPES_STRING]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10203),
            r2_airgard_status_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Warning Message"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vWarningMessageAttr, NULL);

        // Add objectnode to represent Airgard->Status->Info
        UA_NodeId r3_airgard_status_Info_Id;			// line 1345
        UA_ObjectAttributes oAttr_r3_status_Info = UA_ObjectAttributes_default;
        oAttr_r3_status_Info.description = UA_LOCALIZEDTEXT("en-US", "Info");
        oAttr_r3_status_Info.displayName = UA_LOCALIZEDTEXT("en-US", "1. Info");
        UA_Client_addObjectNode(client, UA_NODEID_STRING(1, "AirGardSensor_Status_Info"),
            r2_airgard_status_Id,
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASSUBTYPE),
            UA_QUALIFIEDNAME(1, "Info"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEOBJECTTYPE),
            oAttr_r3_status_Info, &r3_airgard_status_Info_Id);

        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //        "Object Node created : Airgard->Status->Info \n", r3_airgard_status_Info_Id);

        UA_VariableAttributes vBootStatusAttr = UA_VariableAttributes_default;
        vBootStatusAttr.description = UA_LOCALIZEDTEXT("en-US", "BootStatusInfo");
        vBootStatusAttr.displayName = UA_LOCALIZEDTEXT("en-US", "1. Boot Status");
        vBootStatusAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
        //UA_String BootStatus = (UA_String) XMLBootStatus;
        UA_String BootStatus[255];
        //strcpy(BootStatus, XMLBootStatus);
        UA_Variant_setArray(&vBootStatusAttr.value, &BootStatus, 254, &UA_TYPES[UA_TYPES_STRING]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10211), r3_airgard_status_Info_Id,
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(2, "Boot Status"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vBootStatusAttr, NULL);

        UA_VariableAttributes vSnapshotStatusAttr = UA_VariableAttributes_default;
        vSnapshotStatusAttr.description = UA_LOCALIZEDTEXT("en-US", "SnapshotStatusInfo");
        vSnapshotStatusAttr.displayName = UA_LOCALIZEDTEXT("en-US", "2. Snapshot Status");
        vSnapshotStatusAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
        //UA_String SnapshotStatus = (UA_String) XMLSnapshotStatus;
        UA_String SnapshotStatus[255];
        //strcpy(SnapshotStatus, XMLSnapshotStatus);
        UA_Variant_setArray(&vSnapshotStatusAttr.value, &SnapshotStatus, 254, &UA_TYPES[UA_TYPES_STRING]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10212),
            r3_airgard_status_Info_Id,
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(2, "Snapshot Status"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vSnapshotStatusAttr, NULL);

        UA_VariableAttributes vSCPStatusAttr = UA_VariableAttributes_default;
        vSCPStatusAttr.description = UA_LOCALIZEDTEXT("en-US", "SCPStatusInfo");
        vSCPStatusAttr.displayName = UA_LOCALIZEDTEXT("en-US", "3. SCP Status");
        vSCPStatusAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
        //UA_String SCPStatus = (UA_String) XMLSCPStatus;
        UA_String SCPStatus[255];
        //strcpy(SCPStatus, XMLSCPStatus);
        UA_Variant_setArray(&vSCPStatusAttr.value, &SCPStatus, 254, &UA_TYPES[UA_TYPES_STRING]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10213),
            r3_airgard_status_Info_Id,
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(2, "SCP Status"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vSCPStatusAttr, NULL);

        UA_VariableAttributes vSFTPStatusAttr = UA_VariableAttributes_default;
        vSFTPStatusAttr.description = UA_LOCALIZEDTEXT("en-US", "SFTPStatusInfo");
        vSFTPStatusAttr.displayName = UA_LOCALIZEDTEXT("en-US", "4. SFTP Status");
        vSFTPStatusAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
        //UA_String SFTPStatus = (UA_String) XMLSFTPStatus;
        UA_String SFTPStatus[255];
        //strcpy(SFTPStatus, XMLSFTPStatus);
        UA_Variant_setArray(&vSFTPStatusAttr.value, &SFTPStatus, 254, &UA_TYPES[UA_TYPES_STRING]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10214),
            r3_airgard_status_Info_Id,
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(2, "SFTP Status"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vSFTPStatusAttr, NULL);

        UA_VariableAttributes vRunScriptStatusAttr = UA_VariableAttributes_default;
        vRunScriptStatusAttr.description = UA_LOCALIZEDTEXT("en-US", "RunScriptStatusInfo");
        vRunScriptStatusAttr.displayName = UA_LOCALIZEDTEXT("en-US", "5. Run Script Status");
        vRunScriptStatusAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
        //UA_String RunScriptStatus = (UA_String) XMLRunScriptStatus;
        UA_String RunScriptStatus[255];
        //strcpy(RunScriptStatus, XMLRunScriptStatus);
        UA_Variant_setArray(&vRunScriptStatusAttr.value, &RunScriptStatus, 254, &UA_TYPES[UA_TYPES_STRING]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10215),
            r3_airgard_status_Info_Id,
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(2, "Run Script Status"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vRunScriptStatusAttr, NULL);

        UA_VariableAttributes vArchiveStatusAttr = UA_VariableAttributes_default;
        vArchiveStatusAttr.description = UA_LOCALIZEDTEXT("en-US", "ArchiveStatusInfo");
        vArchiveStatusAttr.displayName = UA_LOCALIZEDTEXT("en-US", "6. Archive Status");
        vArchiveStatusAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
        //UA_String ArchiveStatus = (UA_String) XMLArchiveStatus;
        UA_String ArchiveStatus[255];
        //strcpy(ArchiveStatus, XMLArchiveStatus);
        UA_Variant_setArray(&vArchiveStatusAttr.value, &ArchiveStatus, 254, &UA_TYPES[UA_TYPES_STRING]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10216),
            r3_airgard_status_Info_Id,
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(2, "Archive Status"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vArchiveStatusAttr, NULL);

        UA_VariableAttributes vAncillarySensorStatusAttr = UA_VariableAttributes_default;
        vAncillarySensorStatusAttr.description = UA_LOCALIZEDTEXT("en-US", "AncillarySensortatusInfo");
        vAncillarySensorStatusAttr.displayName = UA_LOCALIZEDTEXT("en-US", "7. Ancillary Sensor Status");
        vAncillarySensorStatusAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
        //UA_String AncillarySensorStatus = (UA_String) XMLAncillarySensorStatus;
        UA_String AncillarySensorStatus[255];
        //strcpy(AncillarySensorStatus, XMLAncillarySensorStatus);
        UA_Variant_setArray(&vAncillarySensorStatusAttr.value, &AncillarySensorStatus, 254, &UA_TYPES[UA_TYPES_STRING]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10217),
            r3_airgard_status_Info_Id,
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(2, "Ancillary Sensor Status"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vAncillarySensorStatusAttr, NULL);

        //***// Subtree: Airgard->Diagnostics (1,10300)

            // Add objectnode to represent Airgard->Diagnostics
        UA_NodeId r2_airgard_diagnostics_Id;
        UA_ObjectAttributes oAttr_r2_diagnostics = UA_ObjectAttributes_default;
        UA_Client_addObjectNode(client, UA_NODEID_STRING(1, "AirgardSensor_Diagnostics"),
            r1_airgardroot_Id,
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASSUBTYPE),
            UA_QUALIFIEDNAME(1, "Diagnostic"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEOBJECTTYPE),
            oAttr_r2_diagnostics, &r2_airgard_diagnostics_Id);

        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //	"Object Node created : Airgard->Diagnostics Node\n", r2_airgard_diagnostics_Id);

                    // variable
                    //UA_NodeId_init(&ds1IgramPPId); // for pub sub
        UA_VariableAttributes vIgramPPAttr = UA_VariableAttributes_default;
        vIgramPPAttr.description = UA_LOCALIZEDTEXT("en-US", "IgramPPInfo");
        vIgramPPAttr.displayName = UA_LOCALIZEDTEXT("en-US", "01. Igram PP");
        vIgramPPAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE | UA_ACCESSLEVELMASK_HISTORYREAD;
        vIgramPPAttr.historizing = true;
        //UA_Float IgramPP = (UA_Float) XMLIgramPP;	// value is set in print_element_names
        UA_Variant_setScalar(&vIgramPPAttr.value, &IgramPP, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10301),	// 1 refers to namespace : NS1
            r2_airgard_diagnostics_Id,
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Igram PP"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vIgramPPAttr, NULL);
        //vIgramPPAttr, NULL, &ds1IgramPPId);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->IgramPP\n", r2_airgard_diagnostics_Id);


        // variable
        //UA_NodeId_init(&ds1IgramPPId); // for pub sub
        UA_VariableAttributes vIgramDCAttr = UA_VariableAttributes_default;
        vIgramDCAttr.description = UA_LOCALIZEDTEXT("en-US", "IgramDCInfo");
        vIgramDCAttr.displayName = UA_LOCALIZEDTEXT("en-US", "02. Igram DC");
        vIgramDCAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	vIgramDCAttr.historizing = true;
        //UA_Float IgramDC = (UA_Float) XMLIgramDC;	// value is set in print_element_names
        UA_Variant_setScalar(&vIgramDCAttr.value, &IgramDC, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10302),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Igram DC"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vIgramDCAttr, NULL);
        //vIgramDCAttr, NULL, &ds1IgramDCId);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->IgramDC\n", r2_airgard_diagnostics_Id);

        // variable
        //UA_NodeId_init(&ds1LaserPPId); // for pub sub
        UA_VariableAttributes vLaserPPAttr = UA_VariableAttributes_default;
        vLaserPPAttr.description = UA_LOCALIZEDTEXT("en-US", "LaserPPInfo");
        vLaserPPAttr.displayName = UA_LOCALIZEDTEXT("en-US", "03. Laser PP");
        vLaserPPAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	vLaserPPAttr.historizing = true;
        //UA_Float LaserPP = (UA_Float) XMLLaserPP;     // value is set in print_element_names
        UA_Variant_setScalar(&vLaserPPAttr.value, &LaserPP, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10303),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Laser PP"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vLaserPPAttr, NULL);
        //vLaserPPAttr, NULL, &ds1LaserPPId);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->LaserPP\n", r2_airgard_diagnostics_Id);

        // variable
        //UA_NodeId_init(&ds1LaserDCId); // for pub sub
        UA_VariableAttributes vLaserDCAttr = UA_VariableAttributes_default;
        vLaserDCAttr.description = UA_LOCALIZEDTEXT("en-US", "LaserDCInfo");
        vLaserDCAttr.displayName = UA_LOCALIZEDTEXT("en-US", "04. Laser DC");
        vLaserDCAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	vLaserDCAttr.historizing = true;
        //UA_Float LaserDC = (UA_Float) XMLLaserDC; 	// value is set in print_element_names
        UA_Variant_setScalar(&vLaserDCAttr.value, &LaserDC, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10304),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Laser DC"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vLaserDCAttr, NULL);
        //vLaserDCAttr, NULL, &ds1LaserDCId);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->LaserDC\n", r2_airgard_diagnostics_Id);

        // variable
        UA_VariableAttributes vSingleBeamAt900Attr = UA_VariableAttributes_default;
        vSingleBeamAt900Attr.description = UA_LOCALIZEDTEXT("en-US", "SingleBeamAt900");
        vSingleBeamAt900Attr.displayName = UA_LOCALIZEDTEXT("en-US", "05. Single Beam At 900");
        vSingleBeamAt900Attr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	vSingleBeamAt900Attr.historizing = true;
        //UA_Float SingleBeamAt900 = (UA_Float) XMLSingleBeamAt900;	 // value is set in print_element_names
        UA_Variant_setScalar(&vSingleBeamAt900Attr.value, &SingleBeamAt900, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10305),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Single Beam At 900"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vSingleBeamAt900Attr, NULL);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->SingleBeamAt900\n", r2_airgard_diagnostics_Id);

        // variable
        UA_VariableAttributes vSingleBeamAt2500Attr = UA_VariableAttributes_default;
        vSingleBeamAt2500Attr.description = UA_LOCALIZEDTEXT("en-US", "SingleBeamAt2500");
        vSingleBeamAt2500Attr.displayName = UA_LOCALIZEDTEXT("en-US", "06. Single Beam At 2500");
        vSingleBeamAt2500Attr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	vSingleBeamAt2500Attr.historizing = true;
        //UA_Float SingleBeamAt2500 = (UA_Float) XMLSingleBeamAt2500;	 // value is set in print_element_names
        UA_Variant_setScalar(&vSingleBeamAt2500Attr.value, &SingleBeamAt2500, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10306),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Single Beam At 2500"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vSingleBeamAt2500Attr, NULL);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->SingleBeamAt2500\n", r2_airgard_diagnostics_Id);

        // variable
        UA_VariableAttributes vSignalToNoiseAt2500Attr = UA_VariableAttributes_default;
        vSignalToNoiseAt2500Attr.description = UA_LOCALIZEDTEXT("en-US", "SignalToNoiseAt2500");
        vSignalToNoiseAt2500Attr.displayName = UA_LOCALIZEDTEXT("en-US", "07. Signal To Noise At 2500");
        vSignalToNoiseAt2500Attr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	vSignalToNoiseAt2500Attr.historizing = true;
        //UA_Int16 SignalToNoiseRatioAt2500 = (UA_Int16) XMLSignalToNoiseRatioAt2500;
        UA_Variant_setScalar(&vSignalToNoiseAt2500Attr.value, &SignalToNoiseAt2500, &UA_TYPES[UA_TYPES_INT16]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10307),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Signal To Noise at 2500"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vSignalToNoiseAt2500Attr, NULL);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->SignalToNoiseAt2500\n", r2_airgard_diagnostics_Id);

        // variable
        UA_VariableAttributes vCenterBurstLocationAttr = UA_VariableAttributes_default;
        vCenterBurstLocationAttr.description = UA_LOCALIZEDTEXT("en-US", "CenterBurstLocation");
        vCenterBurstLocationAttr.displayName = UA_LOCALIZEDTEXT("en-US", "08. Center Burst Location");
        vCenterBurstLocationAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	vCenterBurstLocationAttr.historizing = true;
        // UA_Float CentreBurstLocation = (UA_Float) XMLCentreBurstLocation;
        UA_Variant_setScalar(&vCenterBurstLocationAttr.value, &CenterBurstLocation, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10308),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Center Burst Location"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vCenterBurstLocationAttr, NULL);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->CenterBurstLocation\n", r2_airgard_diagnostics_Id);

        // variable
        UA_VariableAttributes vDetectorTempAttr = UA_VariableAttributes_default;
        vDetectorTempAttr.description = UA_LOCALIZEDTEXT("en-US", "DetectorTemperature");
        vDetectorTempAttr.displayName = UA_LOCALIZEDTEXT("en-US", "09. Detector Temperature");
        vDetectorTempAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	vDetectorTempAttr.historizing = true;
        // UA_Float DetectorTemp = (UA_Float) XMLDetectorTemp;
        UA_Variant_setScalar(&vDetectorTempAttr.value, &DetectorTemp, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10309),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Detector Temperature"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vDetectorTempAttr, NULL);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->DetectorTemp\n", r2_airgard_diagnostics_Id);

        // Add the variable LaserFrequencyValue to server
        UA_VariableAttributes vLaserFrequencyAttr = UA_VariableAttributes_default;
        vLaserFrequencyAttr.description = UA_LOCALIZEDTEXT("en-US", "LaserFrequency");
        vLaserFrequencyAttr.displayName = UA_LOCALIZEDTEXT("en-US", "10. Laser Frequency");
        vLaserFrequencyAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	vLaserFrequencyAttr.historizing = true;
        // UA_Float LaserFrequency = (UA_Float) XMLLaserFrequency;
        UA_Variant_setScalar(&vLaserFrequencyAttr.value, &LaserFrequency, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10310),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Laser Frequency"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vLaserFrequencyAttr, NULL);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->LaserFrequency\n", r2_airgard_diagnostics_Id);

        // Add the variable HardDriveSpaceValue to server
        UA_VariableAttributes vHardDriveSpaceAttr = UA_VariableAttributes_default;
        vHardDriveSpaceAttr.description = UA_LOCALIZEDTEXT("en-US", "HardDriveSpace");
        vHardDriveSpaceAttr.displayName = UA_LOCALIZEDTEXT("en-US", "11. Hard Drive Space");
        vHardDriveSpaceAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	vHardDriveSpaceAttr.historizing = true;
        //UA_Int16 HardDriveSpace = (UA_Float) XMLHardDriveSpace;
        UA_Variant_setScalar(&vHardDriveSpaceAttr.value, &HardDriveSpace, &UA_TYPES[UA_TYPES_INT16]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10311),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Hard Disk Drive Space"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vHardDriveSpaceAttr, NULL);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->HardDriveSpace\n", r2_airgard_diagnostics_Id);

        // Add the variable FlowValue to server
        UA_VariableAttributes vFlowAttr = UA_VariableAttributes_default;
        vFlowAttr.description = UA_LOCALIZEDTEXT("en-US", "Flow");
        vFlowAttr.displayName = UA_LOCALIZEDTEXT("en-US", "12. Flow");
        vFlowAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	vFlowAttr.historizing = true;
        //UA_Float Flow = (UA_Float) XMLFlow;
        UA_Variant_setScalar(&vFlowAttr.value, &Flow, &UA_TYPES[UA_TYPES_INT16]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10312),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Flow"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vFlowAttr, NULL);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->Flow\n", r2_airgard_diagnostics_Id);

        // Add the variable TemperatureValue to server
        UA_VariableAttributes vTemperatureAttr = UA_VariableAttributes_default;
        vTemperatureAttr.description = UA_LOCALIZEDTEXT("en-US", "Temperature");
        vTemperatureAttr.displayName = UA_LOCALIZEDTEXT("en-US", "13. Temperature");
        vTemperatureAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	vTemperatureAttr.historizing = true;
        //UA_Float Temperature = (UA_Float) XMLTemperature;
        UA_Variant_setScalar(&vTemperatureAttr.value, &Temperature, &UA_TYPES[UA_TYPES_INT16]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10313),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Temperature"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vTemperatureAttr, NULL);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->Temperature\n", r2_airgard_diagnostics_Id);

        // Add the variable PressureValue to server
        UA_VariableAttributes vPressureAttr = UA_VariableAttributes_default;
        vPressureAttr.description = UA_LOCALIZEDTEXT("en-US", "Pressure");
        vPressureAttr.displayName = UA_LOCALIZEDTEXT("en-US", "14. Pressure");
        vPressureAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	vPressureAttr.historizing = true;
        //UA_Float Pressure = (UA_Float) XMLPressure;
        UA_Variant_setScalar(&vPressureAttr.value, &Pressure, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10314),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Pressure"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vPressureAttr, NULL);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->Pressure\n", r2_airgard_diagnostics_Id);

        // Add the variable TempOpticsValue to server
        UA_VariableAttributes vTempOpticsAttr = UA_VariableAttributes_default;
        vTempOpticsAttr.description = UA_LOCALIZEDTEXT("en-US", "TempOptics");
        vTempOpticsAttr.displayName = UA_LOCALIZEDTEXT("en-US", "15. Temp Optics");
        vTempOpticsAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	vTempOpticsAttr.historizing = true;
        //UA_Float Pressure = (UA_Float) XMLPressure;
        UA_Variant_setScalar(&vTempOpticsAttr.value, &TempOptics, &UA_TYPES[UA_TYPES_INT16]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10315),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Temp Optics"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vTempOpticsAttr, NULL);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->TempOptics\n", r2_airgard_diagnostics_Id);

        // Add the variable BadScanCounterValue to server
        UA_VariableAttributes vBadScanCounterAttr = UA_VariableAttributes_default;
        vBadScanCounterAttr.description = UA_LOCALIZEDTEXT("en-US", "BadScanCounter");
        vBadScanCounterAttr.displayName = UA_LOCALIZEDTEXT("en-US", "16. Bad Scan Counter");
        vBadScanCounterAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	vBadScanCounterAttr.historizing = true;
        //UA_Float Pressure = (UA_Float) XMLPressure;
        UA_Variant_setScalar(&vBadScanCounterAttr.value, &BadScanCounter, &UA_TYPES[UA_TYPES_INT16]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10316),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Bad Scan Counter"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vBadScanCounterAttr, NULL);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->BadScanCounter\n", r2_airgard_diagnostics_Id);

        // Add the variable FreeMemorySpaceValue to server
        UA_VariableAttributes vFreeMemorySpaceAttr = UA_VariableAttributes_default;
        vFreeMemorySpaceAttr.description = UA_LOCALIZEDTEXT("en-US", "FreeMemorySpace");
        vFreeMemorySpaceAttr.displayName = UA_LOCALIZEDTEXT("en-US", "17. Free Memory Space");
        vFreeMemorySpaceAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	vFreeMemorySpaceAttr.historizing = true;
        //UA_Float Pressure = (UA_Float) XMLPressure;
        UA_Variant_setScalar(&vFreeMemorySpaceAttr.value, &FreeMemorySpace, &UA_TYPES[UA_TYPES_INT16]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10317),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Free Memory Space"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vFreeMemorySpaceAttr, NULL);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->FreeMemorySpace\n", r2_airgard_diagnostics_Id);

        // Add the variable LABFilenameValue to server
        UA_VariableAttributes vLABFilenameAttr = UA_VariableAttributes_default;
        vLABFilenameAttr.description = UA_LOCALIZEDTEXT("en-US", "LABFilename");
        vLABFilenameAttr.displayName = UA_LOCALIZEDTEXT("en-US", "18. LAB Filename");
        vLABFilenameAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
        //UA_Float Pressure = (UA_Float) XMLPressure;
        UA_Variant_setScalar(&vLABFilenameAttr.value, &LABFilename, &UA_TYPES[UA_TYPES_STRING]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10318),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "LAB Filename"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vLABFilenameAttr, NULL);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->LABFilename\n", r2_airgard_diagnostics_Id);

        // Add the variable LOGFilenameValue to server
        UA_VariableAttributes vLOGFilenameAttr = UA_VariableAttributes_default;
        vLOGFilenameAttr.description = UA_LOCALIZEDTEXT("en-US", "LOGFilename");
        vLOGFilenameAttr.displayName = UA_LOCALIZEDTEXT("en-US", "19. LOG Filename");
        vLOGFilenameAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
        //UA_Float Pressure = (UA_Float) XMLPressure;
        UA_Variant_setScalar(&vLOGFilenameAttr.value, &LOGFilename, &UA_TYPES[UA_TYPES_STRING]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10319),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "LOG Filename"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vLOGFilenameAttr, NULL);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->LOGFilename\n", r2_airgard_diagnostics_Id);

        // Add the variable LgFilenameValue to server
        UA_VariableAttributes vLgFilenameAttr = UA_VariableAttributes_default;
        vLgFilenameAttr.description = UA_LOCALIZEDTEXT("en-US", "LgFilename");
        vLgFilenameAttr.displayName = UA_LOCALIZEDTEXT("en-US", "20. Lg Filename");
        vLgFilenameAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
        //UA_Float Pressure = (UA_Float) XMLPressure;
        UA_Variant_setScalar(&vLgFilenameAttr.value, &LgFilename, &UA_TYPES[UA_TYPES_STRING]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10320),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Lg Filename"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vLgFilenameAttr, NULL);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->LgFilename\n", r2_airgard_diagnostics_Id);

        // Add the variable SecondLgFilenameValue to server
        UA_VariableAttributes vSecondLgFilenameAttr = UA_VariableAttributes_default;
        vSecondLgFilenameAttr.description = UA_LOCALIZEDTEXT("en-US", "SecondLgFilename");
        vSecondLgFilenameAttr.displayName = UA_LOCALIZEDTEXT("en-US", "20. Second Lg Filename");
        vSecondLgFilenameAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
        //UA_Float Pressure = (UA_Float) XMLPressure;
        UA_Variant_setScalar(&vSecondLgFilenameAttr.value, &SecondLgFilename, &UA_TYPES[UA_TYPES_STRING]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10321),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Second Lg Filename"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vSecondLgFilenameAttr, NULL);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->SecondLgFilename\n", r2_airgard_diagnostics_Id);

        // Add the variable SystemCounterValue to server
        UA_VariableAttributes vSystemCounterAttr = UA_VariableAttributes_default;
        vSystemCounterAttr.description = UA_LOCALIZEDTEXT("en-US", "SystemCounter");
        vSystemCounterAttr.displayName = UA_LOCALIZEDTEXT("en-US", "21. System Counter");
        vSystemCounterAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	vSystemCounterAttr.historizing = true;
        //UA_Float Pressure = (UA_Float) XMLPressure;
        UA_Variant_setScalar(&vSystemCounterAttr.value, &SystemCounter, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10322),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "System Counter"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vSystemCounterAttr, NULL);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->SystemCounter\n", r2_airgard_diagnostics_Id);

        // Add the variable DetectorCounterValue to server
        UA_VariableAttributes vDetectorCounterAttr = UA_VariableAttributes_default;
        vDetectorCounterAttr.description = UA_LOCALIZEDTEXT("en-US", "DetectorCounter");
        vDetectorCounterAttr.displayName = UA_LOCALIZEDTEXT("en-US", "22. Detector Counter");
        vDetectorCounterAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	vDetectorCounterAttr.historizing = true;
        //UA_Float Pressure = (UA_Float) XMLPressure;
        UA_Variant_setScalar(&vDetectorCounterAttr.value, &DetectorCounter, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10323),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Detector Counter"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vDetectorCounterAttr, NULL);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->DetectorCounter\n", r2_airgard_diagnostics_Id);

        // Add the variable LaserCounterValue to server
        UA_VariableAttributes vLaserCounterAttr = UA_VariableAttributes_default;
        vLaserCounterAttr.description = UA_LOCALIZEDTEXT("en-US", "LaserCounter");
        vLaserCounterAttr.displayName = UA_LOCALIZEDTEXT("en-US", "23. Laser Counter");
        vLaserCounterAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	vLaserCounterAttr.historizing = true;
        //UA_Float Pressure = (UA_Float) XMLPressure;
        UA_Variant_setScalar(&vLaserCounterAttr.value, &LaserCounter, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10324),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Laser Counter"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vLaserCounterAttr, NULL);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->LaserCounter\n", r2_airgard_diagnostics_Id);

        // Add the variable FlowPumpCounterValue to server
        UA_VariableAttributes vFlowPumpCounterAttr = UA_VariableAttributes_default;
        vFlowPumpCounterAttr.description = UA_LOCALIZEDTEXT("en-US", "FlowPumpCounter");
        vFlowPumpCounterAttr.displayName = UA_LOCALIZEDTEXT("en-US", "24. Flow Pump Counter");
        vFlowPumpCounterAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	vFlowPumpCounterAttr.historizing = true;
        //UA_Float Pressure = (UA_Float) XMLPressure;
        UA_Variant_setScalar(&vFlowPumpCounterAttr.value, &FlowPumpCounter, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10325),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Flow Pump Counter"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vFlowPumpCounterAttr, NULL);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->FlowPumpCounter\n", r2_airgard_diagnostics_Id);

        // Add the variable DesiccantCounterValue to server
        UA_VariableAttributes vDesiccantCounterAttr = UA_VariableAttributes_default;
        vDesiccantCounterAttr.description = UA_LOCALIZEDTEXT("en-US", "DesiccantCounter");
        vDesiccantCounterAttr.displayName = UA_LOCALIZEDTEXT("en-US", "25. Desiccant Counter");
        vDesiccantCounterAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
	vDesiccantCounterAttr.historizing = true;
        //UA_Float Pressure = (UA_Float) XMLPressure;
        UA_Variant_setScalar(&vDesiccantCounterAttr.value, &DesiccantCounter, &UA_TYPES[UA_TYPES_FLOAT]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10326),
            r2_airgard_diagnostics_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "Desiccant Counter"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vDesiccantCounterAttr, NULL);
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Attribute Variable created: Airgard->Diagnostics->DesiccantCounter\n", r2_airgard_diagnostics_Id);


        // End Subtree: Diagnostics

        // Subtree: Data

                //***// Subtree: Airgard->Data (1,10400)

                        // Add objectnode to represent Airgard->Data
        //UA_NodeId r2_airgard_data_Id;   //:: line 1866 ::  shift the definition to the front of the function()
        UA_ObjectAttributes oAttr_r2_data = UA_ObjectAttributes_default;

	printf("NA_CreateOPCUANodes.c 928 : check if r2_airgard_data_Id node exist in the tree \n");
	UA_Client_readNodeIdAttribute(client, UA_NODEID_STRING(1, "AirgardSensor_Data"),
                              &r2_airgard_data_Id);

	if (UA_NodeId_isNull(&r2_airgard_data_Id)) // node does not exist
	        UA_Client_addObjectNode(client, UA_NODEID_STRING(1, "AirgardSensor_Data"),
        	    r1_airgardroot_Id,
            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASSUBTYPE),
            	UA_QUALIFIEDNAME(1, "Data"),
            	UA_NODEID_NUMERIC(0, UA_NS0ID_BASEOBJECTTYPE),
            	oAttr_r2_data, &r2_airgard_data_Id);
	//else do nothing

        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //        "Object Node created : Airgard->Data Node\n", r2_airgard_data_Id);

        printf("NA_CreateOPCUANodes.c : In line 945 : r2_airgard_data_Id = %d\n", r2_airgard_data_Id);
        // variable
        UA_VariableAttributes vAlarmsAttr = UA_VariableAttributes_default;
        vAlarmsAttr.description = UA_LOCALIZEDTEXT("en-US", "AlarmsInfo");
        vAlarmsAttr.displayName = UA_LOCALIZEDTEXT("en-US", "1. Alarms");
        vAlarmsAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
        //UA_Int16 Alarms;
        UA_Variant_setScalar(&vAlarmsAttr.value, &NoOfAlarms, &UA_TYPES[UA_TYPES_INT16]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10401),
            r2_airgard_data_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "1. Alarms"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vAlarmsAttr, NULL);

        // variable
        UA_VariableAttributes vNonAlarmsAttr = UA_VariableAttributes_default;
        vNonAlarmsAttr.description = UA_LOCALIZEDTEXT("en-US", "NonAlarmsInfo");
        vNonAlarmsAttr.displayName = UA_LOCALIZEDTEXT("en-US", "2. Non Alarms");
        vNonAlarmsAttr.accessLevel = UA_ACCESSLEVELMASK_READ | UA_ACCESSLEVELMASK_WRITE;
        //UA_Int16 NonAlarms;
        UA_Variant_setScalar(&vNonAlarmsAttr.value, &NoOfNonAlarms, &UA_TYPES[UA_TYPES_INT16]);
        UA_Client_addVariableNode(client, UA_NODEID_NUMERIC(1, 10402),
            r2_airgard_data_Id, UA_NODEID_NUMERIC(0, UA_NS0ID_HASPROPERTY),
            UA_QUALIFIEDNAME(1, "2. Non Alarms"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEDATAVARIABLETYPE),
            vNonAlarmsAttr, NULL);

        // <(OT) Alarm> sub nodes are created dynamically in extract_element_names()
        // TBD :Non Alarm sub nodes are created dynamically in extract_element_names()

    //--
            // Add objectnode to represent Airgard->Methods
	UA_NodeId r2_airgard_method_Id;   // get the nodeid assigned by the server
        UA_Client_readNodeIdAttribute(client, UA_NODEID_STRING(1, "AirgardSensor_Method"),
                              &r2_airgard_method_Id);

        if (UA_NodeId_isNull(&r2_airgard_method_Id)) // node does not exist
	{
		UA_ObjectAttributes oAttr_r2_method = UA_ObjectAttributes_default;
                UA_Client_addObjectNode(client, UA_NODEID_STRING(1, "AirgardSensor_Method"),
                    r1_airgardroot_Id,
                UA_NODEID_NUMERIC(0, UA_NS0ID_HASSUBTYPE),
                UA_QUALIFIEDNAME(1, "Methods"),
                UA_NODEID_NUMERIC(0, UA_NS0ID_BASEOBJECTTYPE),
                oAttr_r2_method, &r2_airgard_method_Id);
	}else printf("Found node r2_airgard_method_Id \n");
        //else do nothing
/*
        UA_NodeId r2_airgard_method_Id;   // get the nodeid assigned by the server 
        UA_ObjectAttributes oAttr_r2_method = UA_ObjectAttributes_default;
        UA_Client_addObjectNode(client, UA_NODEID_STRING(1, "AirGardSensor_Method"),
            r1_airgardroot_Id,
            UA_NODEID_NUMERIC(0, UA_NS0ID_HASSUBTYPE),                     // Make Airgard node <Contains> Method node
            UA_QUALIFIEDNAME(1, "Methods"),
            UA_NODEID_NUMERIC(0, UA_NS0ID_BASEOBJECTTYPE),
            oAttr_r2_method, &r2_airgard_method_Id);
*/
        //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Object Node created 1003: Airgard->Methods Node\n");


        // method call initiation - shift to AG_NewMethod.c
	// e.g. Airgard->Methods->GetIgrammPPMethod

	printf("AG_CreateOPCUANodes.c (992):: Before pass this stage \n");
	CreateMethodNodes(client, r2_airgard_method_Id); // use UA_Client_addMethodNode

	//UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
        //    "Method Nodes created : Airgard->Methods Node\n");


    } // end if

    return (r2_airgard_data_Id);

} // End CreateOPCUANodes()
