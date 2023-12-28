#include "open62541.h"
//#include <xml.h>
#include <libxml2/libxml/parser.h>
#include <libxml2/libxml/tree.h>
#include <libxml2/libxml/xmlreader.h>

//#include "myNewServer.h"
//#include "myNewMethod.h"

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
extern UA_Float SignalToNoiseAt2500;
extern UA_Float CenterBurstLocation;
extern UA_Float DetectorTemp;
extern UA_Float LaserFrequency;
extern UA_Float HardDriveSpace;
extern UA_Float Flow;
extern UA_Float Temperature;
extern UA_Float Pressure;
extern UA_Float TempOptics;
extern UA_Float BadScanCounter;
extern UA_Float FreeMemorySpace;

extern char LABFilename[255];
extern char LOGFilename[255];
extern char LgFilename[255];
extern char SecondLgFilename[255];

extern UA_Float SystemCounter;
extern UA_Float DetectorCounter;
extern UA_Float LaserCounter;
extern UA_Float FlowPumpCounter;
extern UA_Float DesiccantCounter;


UA_StatusCode GetSoftwareVersionMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{

	printf("entering GetSoftwareVersionMethodCallback ========\n");

    UA_String tmp = UA_STRING_ALLOC(SoftwareVersion);
    UA_Variant_setScalarCopy(output, &tmp, &UA_TYPES[UA_TYPES_STRING]);      // global var$
    UA_String_clear(&tmp);

    //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "GetSoftwareVersionMethodCallback was called");
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetDataBlockVersionMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_String tmp = UA_STRING_ALLOC(DataBlockVersion);
    UA_Variant_setScalarCopy(output, &tmp, &UA_TYPES[UA_TYPES_STRING]);      // global variable
    UA_String_clear(&tmp);

    //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "GetDataBlockVersionMethodCallback was called");
    return UA_STATUSCODE_GOOD;

}
UA_StatusCode GetInstrumentTimeMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_String tmp = UA_STRING_ALLOC(InstrumentTime);
    UA_Variant_setScalarCopy(output, &tmp, &UA_TYPES[UA_TYPES_STRING]);      // global var$
    UA_String_clear(&tmp);

    //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "GetInstrumentTimeMethodCallback was called");
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetMeasurementTimeMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_String tmp = UA_STRING_ALLOC(MeasurementTime);
    UA_Variant_setScalarCopy(output, &tmp, &UA_TYPES[UA_TYPES_STRING]);      // global var$
    UA_String_clear(&tmp);

    //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "GetMeasurementTimeMethodCallback was called");
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetBootStatusMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_String tmp = UA_STRING_ALLOC(BootStatus);
    UA_Variant_setScalarCopy(output, &BootStatus, &UA_TYPES[UA_TYPES_STRING]);      // global var$
    UA_String_clear(&tmp);

    //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "GetBootStatusMethodCallback was called");
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetSnapshotStatusMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_String tmp = UA_STRING_ALLOC(SnapshotStatus);
    UA_Variant_setScalarCopy(output, &tmp, &UA_TYPES[UA_TYPES_STRING]);      // global var$
    UA_String_clear(&tmp);

    //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "GetSnapshotStatusMethodCallback was called");
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetSCPStatusMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_String tmp = UA_STRING_ALLOC(SCPStatus);
    UA_Variant_setScalarCopy(output, &tmp, &UA_TYPES[UA_TYPES_STRING]);      // global var$
    UA_String_clear(&tmp);

    //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "GetSCPStatusMethodCallback was called");
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetSFTPStatusMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_String tmp = UA_STRING_ALLOC(SFTPStatus);
    UA_Variant_setScalarCopy(output, &tmp, &UA_TYPES[UA_TYPES_STRING]);      // global var$
    UA_String_clear(&tmp);

    //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "GetSFTStatusMethodCallback was called");
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetRunScriptStatusMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_String tmp = UA_STRING_ALLOC(RunScriptStatus);
    UA_Variant_setScalarCopy(output, &tmp, &UA_TYPES[UA_TYPES_STRING]);      // global var$
    UA_String_clear(&tmp);

    //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "GetRunScriptStatusMethodCallback was called");
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetArchiveStatusMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_String tmp = UA_STRING_ALLOC(ArchiveStatus);
    UA_Variant_setScalarCopy(output, &tmp, &UA_TYPES[UA_TYPES_STRING]);      // global var$
    UA_String_clear(&tmp);

    //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "GetArchiveStatusMethodCallback was called");
    return UA_STATUSCODE_GOOD;

}


UA_StatusCode GetAncillarySensorStatusMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_String tmp = UA_STRING_ALLOC(AncillarySensorStatus);
    UA_Variant_setScalarCopy(output, &tmp, &UA_TYPES[UA_TYPES_STRING]);      // global var$
    UA_String_clear(&tmp);

    //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "GetAncillaryStatusMethodCallback was called");
    return UA_STATUSCODE_GOOD;

}


UA_StatusCode GetSensorMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_String tmp = UA_STRING_ALLOC(Sensor);
    UA_Variant_setScalarCopy(output, &tmp, &UA_TYPES[UA_TYPES_STRING]);      // global var$
    UA_String_clear(&tmp);

    //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "GetSensorMethodCallback was called");
    return UA_STATUSCODE_GOOD;

}


UA_StatusCode GetOperatingTimeMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_Variant_setScalarCopy(output, &OperatingTime, &UA_TYPES[UA_TYPES_INT16]);      // global var$

    //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "GetOperatingTimeMethodCallback was called");
    return UA_STATUSCODE_GOOD;

}


UA_StatusCode GetWarningMessageMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_String tmp = UA_STRING_ALLOC(WarningMessage);
    UA_Variant_setScalarCopy(output, &tmp, &UA_TYPES[UA_TYPES_STRING]);      // global var$
    UA_String_clear(&tmp);

    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "GetWarningMessageMethodCallback was called");
    return UA_STATUSCODE_GOOD;

}


UA_StatusCode GetIgramPPMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
        /*
    UA_String *inputStr = (UA_String*)input->data;
    UA_String tmp = UA_STRING_ALLOC("Hello ");
    if(inputStr->length > 0) {
        tmp.data = (UA_Byte *)UA_realloc(tmp.data, tmp.length + inputStr->length);
        memcpy(&tmp.data[tmp.length], inputStr->data, inputStr->length);
        tmp.length += inputStr->length;
    }
        */

    //UA_Variant_setScalarCopy(output, &tmp, &UA_TYPES[UA_TYPES_FLOAT]);
    //UA_String_clear(&tmp);

        printf("----------------------In GetIgramPPMethodCallback call : %f %f-----------------\n", IgramPP, output);
    UA_Variant_setScalarCopy(output, &IgramPP, &UA_TYPES[UA_TYPES_FLOAT]);      // global variable

    //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "GetIgramPPMethodCallback was called");
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetIgramDCMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{

    UA_Variant_setScalarCopy(output, &IgramDC, &UA_TYPES[UA_TYPES_FLOAT]);      // global variable

    //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "GetIgramPPMethodCallback was called");
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetLaserPPMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{

    UA_Variant_setScalarCopy(output, &LaserPP, &UA_TYPES[UA_TYPES_FLOAT]);      // global variable

    //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "GetIgramPPMethodCallback was called");
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetLaserDCMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{

    UA_Variant_setScalarCopy(output, &LaserDC, &UA_TYPES[UA_TYPES_FLOAT]);      // global variable

    //UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, "GetIgramPPMethodCallback was called");
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetSingleBeamAt900MethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_Variant_setScalarCopy(output, &SingleBeamAt900, &UA_TYPES[UA_TYPES_FLOAT]);      // global variable
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetSingleBeamAt2500MethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_Variant_setScalarCopy(output, &SingleBeamAt2500, &UA_TYPES[UA_TYPES_FLOAT]);      // global variable
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetSignalToNoiseAt2500MethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_Variant_setScalarCopy(output, &SignalToNoiseAt2500, &UA_TYPES[UA_TYPES_INT16]);      // global variable
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetCenterBurstLocationMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_Variant_setScalarCopy(output, &CenterBurstLocation, &UA_TYPES[UA_TYPES_FLOAT]);      // global variable
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetDetectorTempMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_Variant_setScalarCopy(output, &DetectorTemp, &UA_TYPES[UA_TYPES_FLOAT]);      // global variable
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetLaserFrequencyMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_Variant_setScalarCopy(output, &LaserFrequency, &UA_TYPES[UA_TYPES_FLOAT]);      // global variable
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetHardDriveSpaceMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_Variant_setScalarCopy(output, &HardDriveSpace, &UA_TYPES[UA_TYPES_INT16]);      // global variable
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetFlowMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_Variant_setScalarCopy(output, &Flow, &UA_TYPES[UA_TYPES_INT16]);      // global variable
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetTemperatureMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_Variant_setScalarCopy(output, &Temperature, &UA_TYPES[UA_TYPES_FLOAT]);      // global variable
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetPressureMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_Variant_setScalarCopy(output, &Pressure, &UA_TYPES[UA_TYPES_FLOAT]);      // global variable
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetTempOpticsMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_Variant_setScalarCopy(output, &TempOptics, &UA_TYPES[UA_TYPES_FLOAT]);      // global variable
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetBadScanCounterMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_Variant_setScalarCopy(output, &BadScanCounter, &UA_TYPES[UA_TYPES_INT16]);      // global variable
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetFreeMemorySpaceMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_Variant_setScalarCopy(output, &FreeMemorySpace, &UA_TYPES[UA_TYPES_INT16]);      // global variable
    return UA_STATUSCODE_GOOD;

}


UA_StatusCode GetLABFilenameMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_String tmp = UA_STRING_ALLOC(LABFilename);
    UA_Variant_setScalarCopy(output, &tmp, &UA_TYPES[UA_TYPES_STRING]);      // global variable
    UA_String_clear(&tmp);
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetLOGFilenameMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_String tmp = UA_STRING_ALLOC(LOGFilename);
    UA_Variant_setScalarCopy(output, &tmp, &UA_TYPES[UA_TYPES_STRING]);      // global variable
    UA_String_clear(&tmp);
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetLgFilenameMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_String tmp = UA_STRING_ALLOC(LgFilename);
    UA_Variant_setScalarCopy(output, &tmp, &UA_TYPES[UA_TYPES_STRING]);      // global variable
    UA_String_clear(&tmp);
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetSecondLgFilenameMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_String tmp = UA_STRING_ALLOC(SecondLgFilename);
    UA_Variant_setScalarCopy(output, &tmp, &UA_TYPES[UA_TYPES_STRING]);      // global variable
    UA_String_clear(&tmp);
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetSystemCounterMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_Variant_setScalarCopy(output, &SystemCounter, &UA_TYPES[UA_TYPES_FLOAT]);      // global variable
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetDetectorCounterMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_Variant_setScalarCopy(output, &DetectorCounter, &UA_TYPES[UA_TYPES_FLOAT]);      // global variable
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetLaserCounterMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_Variant_setScalarCopy(output, &LaserCounter, &UA_TYPES[UA_TYPES_FLOAT]);      // global variable
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetFlowPumpCounterMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_Variant_setScalarCopy(output, &FlowPumpCounter, &UA_TYPES[UA_TYPES_FLOAT]);      // global variable
    return UA_STATUSCODE_GOOD;

}

UA_StatusCode GetDesiccantCounterMethodCallback(UA_Server *server,
                         const UA_NodeId *sessionId, void *sessionHandle,
                         const UA_NodeId *methodId, void *methodContext,
                         const UA_NodeId *objectId, void *objectContext,
                         size_t inputSize, const UA_Variant *input,
                         size_t outputSize, UA_Variant *output)
{
    UA_Variant_setScalarCopy(output, &DesiccantCounter, &UA_TYPES[UA_TYPES_FLOAT]);      // global variable
    return UA_STATUSCODE_GOOD;

}

//-----------------------------------------------------------------------------------------------------------------

void
addGetSoftwareVersionMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetSoftwareVersionOutput");
    outputArgument.name = UA_STRING("SoftwareVersionMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getSoftwareVersionAttr = UA_MethodAttributes_default;
    getSoftwareVersionAttr.description = UA_LOCALIZEDTEXT("en-US","GetSoftwareVersion");
    getSoftwareVersionAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetSoftwareVersion");
    getSoftwareVersionAttr.executable = true;
    getSoftwareVersionAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62528),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetSoftwareVersion"),
                            getSoftwareVersionAttr, &GetSoftwareVersionMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                "Method Node created : Airgard->Methods->GetSoftwareVersion Node\n");
}

void
addGetDataBlockVersionMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetDataBlockVersionOutput");
    outputArgument.name = UA_STRING("DataBlockVersionMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getDataBlockVersionAttr = UA_MethodAttributes_default;
    getDataBlockVersionAttr.description = UA_LOCALIZEDTEXT("en-US","GetDataBlockVersion");
    getDataBlockVersionAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetDataBlockVersion");
    getDataBlockVersionAttr.executable = true;
    getDataBlockVersionAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62529),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetDataBlockVersion"),
                            getDataBlockVersionAttr, &GetDataBlockVersionMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetInstrumentTimeMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetInstrumentTimeOutput");
    outputArgument.name = UA_STRING("InstrumentTimeMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getInstrumentTimeAttr = UA_MethodAttributes_default;
    getInstrumentTimeAttr.description = UA_LOCALIZEDTEXT("en-US","GetInstrumentTime");
    getInstrumentTimeAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetInstrumentTime");
    getInstrumentTimeAttr.executable = true;
    getInstrumentTimeAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62530),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetInstrumentTime"),
                            getInstrumentTimeAttr, &GetInstrumentTimeMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetMeasurementTimeMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetMeasurementTimeOutput");
    outputArgument.name = UA_STRING("MeasurementTimeOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getMeasurementTimeAttr = UA_MethodAttributes_default;
    getMeasurementTimeAttr.description = UA_LOCALIZEDTEXT("en-US","GetMeasurementTime");
    getMeasurementTimeAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetMeasurementTime");
    getMeasurementTimeAttr.executable = true;
    getMeasurementTimeAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62531),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetMeasurementTime"),
                            getMeasurementTimeAttr, &GetMeasurementTimeMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetBootStatusMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetBootStatusOutput");
    outputArgument.name = UA_STRING("BootStatusOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getBootStatusAttr = UA_MethodAttributes_default;
    getBootStatusAttr.description = UA_LOCALIZEDTEXT("en-US","GetBootStatus");
    getBootStatusAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetBootStatus");
    getBootStatusAttr.executable = true;
    getBootStatusAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62532),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetBootStatus"),
                            getBootStatusAttr, &GetBootStatusMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetSnapshotStatusMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetSnapshotStatusOutput");
    outputArgument.name = UA_STRING("SnapshotStatusOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getSnapshotStatusAttr = UA_MethodAttributes_default;
    getSnapshotStatusAttr.description = UA_LOCALIZEDTEXT("en-US","GetSnapshotStatus");
    getSnapshotStatusAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetSnapshotStatus");
    getSnapshotStatusAttr.executable = true;
    getSnapshotStatusAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62533),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetSnapshotStatus"),
                            getSnapshotStatusAttr, &GetSnapshotStatusMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetSCPStatusMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetSCPStatusOutput");
    outputArgument.name = UA_STRING("SCPStatusOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getSCPStatusAttr = UA_MethodAttributes_default;
    getSCPStatusAttr.description = UA_LOCALIZEDTEXT("en-US","GetSCPStatus");
    getSCPStatusAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetSCPStatus");
    getSCPStatusAttr.executable = true;
    getSCPStatusAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62534),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetSCPStatusInfo"),
                            getSCPStatusAttr, &GetSCPStatusMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}


void
addGetSFTPStatusMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetSFTPStatusOutput");
    outputArgument.name = UA_STRING("SFTPStatusOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getSFTPStatusAttr = UA_MethodAttributes_default;
    getSFTPStatusAttr.description = UA_LOCALIZEDTEXT("en-US","GetSFTPStatus");
    getSFTPStatusAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetSFTPStatus");
    getSFTPStatusAttr.executable = true;
    getSFTPStatusAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62535),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetSFTPStatus"),
                            getSFTPStatusAttr, &GetSFTPStatusMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}


void
addGetRunScriptStatusMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetRunScriptStatusOutput");
    outputArgument.name = UA_STRING("RunScriptStatusOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getRunScriptStatusAttr = UA_MethodAttributes_default;
    getRunScriptStatusAttr.description = UA_LOCALIZEDTEXT("en-US","GetRunScriptStatus");
    getRunScriptStatusAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetRunScriptStatus");
    getRunScriptStatusAttr.executable = true;
    getRunScriptStatusAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62536),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetRunScriptStatus"),
                            getRunScriptStatusAttr, &GetRunScriptStatusMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}


void
addGetArchiveStatusMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetArchiveStatusOutput");
    outputArgument.name = UA_STRING("ArchiveStatusOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getArchiveStatusAttr = UA_MethodAttributes_default;
    getArchiveStatusAttr.description = UA_LOCALIZEDTEXT("en-US","GetArchiveStatus");
    getArchiveStatusAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetArchiveStatus");
    getArchiveStatusAttr.executable = true;
    getArchiveStatusAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62537),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetArchiveStatus"),
                            getArchiveStatusAttr, &GetArchiveStatusMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}


void
addGetAncillarySensorStatusMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetAncillaryStatusOutput");
    outputArgument.name = UA_STRING("AncillaryStatusOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getAncillarySensorStatusAttr = UA_MethodAttributes_default;
    getAncillarySensorStatusAttr.description = UA_LOCALIZEDTEXT("en-US","GetAncillarySensorStatus");
    getAncillarySensorStatusAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetAncillarySensorStatus");
    getAncillarySensorStatusAttr.executable = true;
    getAncillarySensorStatusAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62537),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetAncillarySensorStatus"),
                            getAncillarySensorStatusAttr, &GetAncillarySensorStatusMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetSensorMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetSensorOutput");
    outputArgument.name = UA_STRING("SensorOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getSensorAttr = UA_MethodAttributes_default;
    getSensorAttr.description = UA_LOCALIZEDTEXT("en-US","GetSensor");
    getSensorAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetSensor");
    getSensorAttr.executable = true;
    getSensorAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62538),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetSensor"),
                            getSensorAttr, &GetSensorMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetOperatingTimeMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetOperatingTimeOutput");
    outputArgument.name = UA_STRING("OperatingTimeOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_INT16].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getOperatingTimeAttr = UA_MethodAttributes_default;
    getOperatingTimeAttr.description = UA_LOCALIZEDTEXT("en-US","GetOperatingTime");
    getOperatingTimeAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetOperatingTime");
    getOperatingTimeAttr.executable = true;
    getOperatingTimeAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62539),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetOperatingTime"),
                            getOperatingTimeAttr, &GetOperatingTimeMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetWarningMessageMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetWarningMessageOutput");
    outputArgument.name = UA_STRING("WarningMessageOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getWarningMessageAttr = UA_MethodAttributes_default;
    getWarningMessageAttr.description = UA_LOCALIZEDTEXT("en-US","GetWarningMessage");
    getWarningMessageAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetWarningMessage");
    getWarningMessageAttr.executable = true;
    getWarningMessageAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62540),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetWarningMessage"),
                            getWarningMessageAttr, &GetWarningMessageMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}



void
addGetIgramPPMethod(UA_Server *server, UA_NodeId parent)
{
        // no effect : not required since we are not querying using a parameter
        /*
    UA_Argument inputArgument;
    UA_Argument_init(&inputArgument);
    inputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetIgramPPInput");
    inputArgument.name = UA_STRING("IgramPPMethodInput");
    inputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    inputArgument.valueRank = UA_VALUERANK_SCALAR;
        */

    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetIgramPPOutput");
    outputArgument.name = UA_STRING("IgramPPMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getIgramPPAttr = UA_MethodAttributes_default;
    getIgramPPAttr.description = UA_LOCALIZEDTEXT("en-US","GetIgramPP");
    getIgramPPAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetIgramPP");
    getIgramPPAttr.executable = true;
    getIgramPPAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62541),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetIgramPP"),
                            getIgramPPAttr, &GetIgramPPMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetIgramDCMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetIgramDCOutput");
    outputArgument.name = UA_STRING("IgramDCMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getIgramDCAttr = UA_MethodAttributes_default;
    getIgramDCAttr.description = UA_LOCALIZEDTEXT("en-US","GetIgramDC");
    getIgramDCAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetIgramDC");
    getIgramDCAttr.executable = true;
    getIgramDCAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62542),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetIgramDC"),
                            getIgramDCAttr, &GetIgramDCMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetLaserPPMethod(UA_Server *server, UA_NodeId parent) 
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetLaserPPOutput");
    outputArgument.name = UA_STRING("LaserPPMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getLaserPPAttr = UA_MethodAttributes_default;
    getLaserPPAttr.description = UA_LOCALIZEDTEXT("en-US","GetLaserPP");
    getLaserPPAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetLaserPP");
    getLaserPPAttr.executable = true;
    getLaserPPAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62543),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetLaserPP"),
                            getLaserPPAttr, &GetLaserPPMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetLaserDCMethod(UA_Server *server, UA_NodeId parent) 
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetLaserDCOutput");
    outputArgument.name = UA_STRING("LaserDCMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getLaserDCAttr = UA_MethodAttributes_default;
    getLaserDCAttr.description = UA_LOCALIZEDTEXT("en-US","GetLaserDC");
    getLaserDCAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetLaserDC");
    getLaserDCAttr.executable = true;
    getLaserDCAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62544),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetLaserDC"),
                            getLaserDCAttr, &GetLaserDCMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetSingleBeamAt900Method(UA_Server *server, UA_NodeId parent) 
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetSingleBeamAt900Output");
    outputArgument.name = UA_STRING("SingleBeamAt900MethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getSingleBeamAt900Attr = UA_MethodAttributes_default;
    getSingleBeamAt900Attr.description = UA_LOCALIZEDTEXT("en-US","GetSingleBeamAt900");
    getSingleBeamAt900Attr.displayName = UA_LOCALIZEDTEXT("en-US","GetSingleBeamAt900");
    getSingleBeamAt900Attr.executable = true;
    getSingleBeamAt900Attr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62545),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetSingleBeamAt900"),
                            getSingleBeamAt900Attr, &GetSingleBeamAt900MethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetSingleBeamAt2500Method(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetSingleBeamAt2500Output");
    outputArgument.name = UA_STRING("SingleBeamAt2500MethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getSingleBeamAt2500Attr = UA_MethodAttributes_default;
    getSingleBeamAt2500Attr.description = UA_LOCALIZEDTEXT("en-US","GetSingleBeamAt2500");
    getSingleBeamAt2500Attr.displayName = UA_LOCALIZEDTEXT("en-US","GetSingleBeamAt2500");
    getSingleBeamAt2500Attr.executable = true;
    getSingleBeamAt2500Attr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62546),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetSingleBeamAt2500"),
                            getSingleBeamAt2500Attr, &GetSingleBeamAt2500MethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetSignalToNoiseAt2500Method(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetSignalToNoiseAt2500Output");
    outputArgument.name = UA_STRING("SignalToNoiseAt2500MethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_INT16].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getSignalToNoiseAt2500Attr = UA_MethodAttributes_default;
    getSignalToNoiseAt2500Attr.description = UA_LOCALIZEDTEXT("en-US","GetSignalToNoiseAt2500");
    getSignalToNoiseAt2500Attr.displayName = UA_LOCALIZEDTEXT("en-US","GetSignalToNoiseAt2500");
    getSignalToNoiseAt2500Attr.executable = true;
    getSignalToNoiseAt2500Attr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62547),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetSignalToNoiseAt2500"),
                            getSignalToNoiseAt2500Attr, &GetSignalToNoiseAt2500MethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetCenterBurstLocationMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetCenterBurstLocationOutput");
    outputArgument.name = UA_STRING("CenterBurstLocationMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getCenterBurstLocationAttr = UA_MethodAttributes_default;
    getCenterBurstLocationAttr.description = UA_LOCALIZEDTEXT("en-US","GetCentreBurstLocation");
    getCenterBurstLocationAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetCenterBurstLocation");
    getCenterBurstLocationAttr.executable = true;
    getCenterBurstLocationAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62548),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetCenterBurstLocation"),
                            getCenterBurstLocationAttr, &GetCenterBurstLocationMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetDetectorTempMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetDetectorTempOutput");
    outputArgument.name = UA_STRING("DetectorTempMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getDetectorTempAttr = UA_MethodAttributes_default;
    getDetectorTempAttr.description = UA_LOCALIZEDTEXT("en-US","GetDetectorTemp");
    getDetectorTempAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetDetectorTemp");
    getDetectorTempAttr.executable = true;
    getDetectorTempAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62549),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetDetectorTemp"),
                            getDetectorTempAttr, &GetDetectorTempMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetLaserFrequencyMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetLaserFrequencyOutput");
    outputArgument.name = UA_STRING("LaserFrequencyMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getLaserFrequencyAttr = UA_MethodAttributes_default;
    getLaserFrequencyAttr.description = UA_LOCALIZEDTEXT("en-US","GetLaserFrequency");
    getLaserFrequencyAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetLaserFrequency");
    getLaserFrequencyAttr.executable = true;
    getLaserFrequencyAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62550),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetLaserFrequency"),
                            getLaserFrequencyAttr, &GetLaserFrequencyMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetHardDriveSpaceMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetHardDriveSpaceOutput");
    outputArgument.name = UA_STRING("HardDriveSpaceMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_INT16].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getHardDriveSpaceAttr = UA_MethodAttributes_default;
    getHardDriveSpaceAttr.description = UA_LOCALIZEDTEXT("en-US","GetHardDriveSpace");
    getHardDriveSpaceAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetHardDriveSpace");
    getHardDriveSpaceAttr.executable = true;
    getHardDriveSpaceAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62551),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetHardDriveSpace"),
                            getHardDriveSpaceAttr, &GetHardDriveSpaceMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetFlowMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetFlowOutput");
    outputArgument.name = UA_STRING("FlowMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getFlowAttr = UA_MethodAttributes_default;
    getFlowAttr.description = UA_LOCALIZEDTEXT("en-US","GetFlow");
    getFlowAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetFlow");
    getFlowAttr.executable = true;
    getFlowAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62552),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetFlow"),
                            getFlowAttr, &GetFlowMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetTemperatureMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetTemperatureOutput");
    outputArgument.name = UA_STRING("TemperatureMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getTemperatureAttr = UA_MethodAttributes_default;
    getTemperatureAttr.description = UA_LOCALIZEDTEXT("en-US","GetTemperature");
    getTemperatureAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetTemperature");
    getTemperatureAttr.executable = true;
    getTemperatureAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62553),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetTempeature"),
                            getTemperatureAttr, &GetTemperatureMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetPressureMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetPressureOutput");
    outputArgument.name = UA_STRING("PressureMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getPressureAttr = UA_MethodAttributes_default;
    getPressureAttr.description = UA_LOCALIZEDTEXT("en-US","GetPressure");
    getPressureAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetPressure");
    getPressureAttr.executable = true;
    getPressureAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62554),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetPressure"),
                            getPressureAttr, &GetPressureMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetTempOpticsMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetTempOpticsOutput");
    outputArgument.name = UA_STRING("TempOpticsMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getTempOpticsAttr = UA_MethodAttributes_default;
    getTempOpticsAttr.description = UA_LOCALIZEDTEXT("en-US","GetTempOptics");
    getTempOpticsAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetTempOptics");
    getTempOpticsAttr.executable = true;
    getTempOpticsAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62555),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetTempOptics"),
                            getTempOpticsAttr, &GetTempOpticsMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetBadScanCounterMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetBadScanCounterOutput");
    outputArgument.name = UA_STRING("BadScanCounterMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_INT16].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getBadScanCounterAttr = UA_MethodAttributes_default;
    getBadScanCounterAttr.description = UA_LOCALIZEDTEXT("en-US","GetBadScanCounterOptics");
    getBadScanCounterAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetBadScanCounterOptics");
    getBadScanCounterAttr.executable = true;
    getBadScanCounterAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62556),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetBadScanCounter"),
                            getBadScanCounterAttr, &GetBadScanCounterMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetFreeMemorySpaceMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetFreeMemorySpaceOutput");
    outputArgument.name = UA_STRING("FreeMemorySpaceMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_INT16].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getFreeMemorySpaceAttr = UA_MethodAttributes_default;
    getFreeMemorySpaceAttr.description = UA_LOCALIZEDTEXT("en-US","GetFreeMemorySpace");
    getFreeMemorySpaceAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetFreeMemorySpace");
    getFreeMemorySpaceAttr.executable = true;
    getFreeMemorySpaceAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62557),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetTempOptics"),
                            getFreeMemorySpaceAttr, &GetFreeMemorySpaceMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetLABFilenameMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetLABFilenameOutput");
    outputArgument.name = UA_STRING("LABFilenameMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getLABFilenameAttr = UA_MethodAttributes_default;
    getLABFilenameAttr.description = UA_LOCALIZEDTEXT("en-US","GetLABFilename");
    getLABFilenameAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetLABFilename");
    getLABFilenameAttr.executable = true;
    getLABFilenameAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62558),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetLABFilename"),
                            getLABFilenameAttr, &GetLABFilenameMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetLOGFilenameMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetLOGFilenameOutput");
    outputArgument.name = UA_STRING("LOGFilenameMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getLOGFilenameAttr = UA_MethodAttributes_default;
    getLOGFilenameAttr.description = UA_LOCALIZEDTEXT("en-US","GetLOGFilename");
    getLOGFilenameAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetLOGFilename");
    getLOGFilenameAttr.executable = true;
    getLOGFilenameAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62559),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetLOGFilename"),
                            getLOGFilenameAttr, &GetLOGFilenameMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetLgFilenameMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetLgFilenameOutput");
    outputArgument.name = UA_STRING("LgFilenameMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getLgFilenameAttr = UA_MethodAttributes_default;
    getLgFilenameAttr.description = UA_LOCALIZEDTEXT("en-US","GetLgFilename");
    getLgFilenameAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetLgFilename");
    getLgFilenameAttr.executable = true;
    getLgFilenameAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62560),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetLgFilename"),
                            getLgFilenameAttr, &GetLgFilenameMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetSecondLgFilenameMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetSecondLgFilenameOutput");
    outputArgument.name = UA_STRING("SecondLgFilenameMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getSecondLgFilenameAttr = UA_MethodAttributes_default;
    getSecondLgFilenameAttr.description = UA_LOCALIZEDTEXT("en-US","GetSecondLgFilename");
    getSecondLgFilenameAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetSecondLgFilename");
    getSecondLgFilenameAttr.executable = true;
    getSecondLgFilenameAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62561),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetSecondLgFilename"),
                            getSecondLgFilenameAttr, &GetSecondLgFilenameMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}


void
addGetSystemCounterMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetSystemCounterOutput");
    outputArgument.name = UA_STRING("SystemCounterMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getSystemCounterAttr = UA_MethodAttributes_default;
    getSystemCounterAttr.description = UA_LOCALIZEDTEXT("en-US","GetSystemCounter");
    getSystemCounterAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetSystemCounter");
    getSystemCounterAttr.executable = true;
    getSystemCounterAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62562),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetSystemCounter"),
                            getSystemCounterAttr, &GetSystemCounterMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetDetectorCounterMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetDetectorCounterOutput");
    outputArgument.name = UA_STRING("DetectorCounterMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getDetectorCounterAttr = UA_MethodAttributes_default;
    getDetectorCounterAttr.description = UA_LOCALIZEDTEXT("en-US","GetDetectorCounter");
    getDetectorCounterAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetDetectorCounter");
    getDetectorCounterAttr.executable = true;
    getDetectorCounterAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62563),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetDetectorCounter"),
                            getDetectorCounterAttr, &GetDetectorCounterMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetLaserCounterMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetLaserCounterOutput");
    outputArgument.name = UA_STRING("LaserCounterMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getLaserCounterAttr = UA_MethodAttributes_default;
    getLaserCounterAttr.description = UA_LOCALIZEDTEXT("en-US","GetLaserCounter");
    getLaserCounterAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetLaserCounter");
    getLaserCounterAttr.executable = true;
    getLaserCounterAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62564),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetLaserCounter"),
                            getLaserCounterAttr, &GetLaserCounterMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetFlowPumpCounterMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetFlowPumpCounterOutput");
    outputArgument.name = UA_STRING("FlowPumpCounterMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getFlowPumpCounterAttr = UA_MethodAttributes_default;
    getFlowPumpCounterAttr.description = UA_LOCALIZEDTEXT("en-US","GetFlowPumpCounter");
    getFlowPumpCounterAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetFlowPumpCounter");
    getFlowPumpCounterAttr.executable = true;
    getFlowPumpCounterAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62565),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetFlowPumpCounter"),
                            getFlowPumpCounterAttr, &GetFlowPumpCounterMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetDesiccantCounterMethod(UA_Server *server, UA_NodeId parent)
{
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetDesiccantCounterOutput");
    outputArgument.name = UA_STRING("DesiccantCounterMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;

    UA_MethodAttributes getDesiccantCounterAttr = UA_MethodAttributes_default;
    getDesiccantCounterAttr.description = UA_LOCALIZEDTEXT("en-US","GetDesiccantCounter");
    getDesiccantCounterAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetDesiccantCounter");
    getDesiccantCounterAttr.executable = true;
    getDesiccantCounterAttr.userExecutable = true;
    UA_Server_addMethodNode(server, UA_NODEID_NUMERIC(1,62566),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetDesiccantCounter"),
                            getDesiccantCounterAttr, &GetDesiccantCounterMethodCallback,
                            0, NULL, 1, &outputArgument, NULL, NULL);

    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                "Method Node created : Airgard->Methods->GetDesiccantCounter Node\n");


}


