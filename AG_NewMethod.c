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
addGetSoftwareVersionMethod(UA_Client *uaClient, UA_NodeId parent)
{
	UA_NodeId outNodeId;
    	UA_MethodAttributes getSoftwareVersionAttr = UA_MethodAttributes_default;
    	getSoftwareVersionAttr.description = UA_LOCALIZEDTEXT("en-US","GetSoftwareVersion");
        getSoftwareVersionAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetSoftwareVersion");
        getSoftwareVersionAttr.executable = true;
        getSoftwareVersionAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62528),
                        	parent, //r2_airgard_method_Id,
                        	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                        	UA_QUALIFIEDNAME(1, "GetSoftwareVersion"),
                        	getSoftwareVersionAttr,
                        	&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);

	/*
     UA_Client_call(client,
			objectId,
			outNodeId,
			inputSize,
			NULL,
			outputSize,
			output);
	*/
}

void
addGetDataBlockVersionMethod(UA_Client *uaClient, UA_NodeId parent)
{

	UA_NodeId outNodeId;

	UA_MethodAttributes getDataBlockVersionAttr = UA_MethodAttributes_default;
	getDataBlockVersionAttr.description = UA_LOCALIZEDTEXT("en-US","GetDataBlockVersion");
	getDataBlockVersionAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetDataBlockVersion");
	getDataBlockVersionAttr.executable = true;
	getDataBlockVersionAttr.userExecutable = true;
	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62529),
        			parent,  //r2_airgard_method_Id,
				UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
				UA_QUALIFIEDNAME(1, "GetDataBlockVersion"),
                                getDataBlockVersionAttr,
                               	&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetInstrumentTimeMethod(UA_Client *uaClient, UA_NodeId parent)
{
        UA_NodeId outNodeId;

        UA_MethodAttributes getInstrumentTimeAttr = UA_MethodAttributes_default;
        getInstrumentTimeAttr.description = UA_LOCALIZEDTEXT("en-US","GetInstrumentTime");
        getInstrumentTimeAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetInstrumentTime");
        getInstrumentTimeAttr.executable = true;
        getInstrumentTimeAttr.userExecutable = true;
        UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62530),
                                parent, //r2_airgard_method_Id,
                                UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                                UA_QUALIFIEDNAME(1, "GetInstrumentTime"),
                                getInstrumentTimeAttr,
                                &outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetMeasurementTimeMethod(UA_Client *uaClient, UA_NodeId parent)
{
	UA_NodeId outNodeId;

    	UA_MethodAttributes getMeasurementTimeAttr = UA_MethodAttributes_default;
    	getMeasurementTimeAttr.description = UA_LOCALIZEDTEXT("en-US","GetMeasurementTime");
    	getMeasurementTimeAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetMeasurementTime");
    	getMeasurementTimeAttr.executable = true;
    	getMeasurementTimeAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62531),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetMeasurementTime"),
                            getMeasurementTimeAttr,
                            &outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetBootStatusMethod(UA_Client *uaClient, UA_NodeId parent)
{
        UA_NodeId outNodeId;

    	UA_MethodAttributes getBootStatusAttr = UA_MethodAttributes_default;
    	getBootStatusAttr.description = UA_LOCALIZEDTEXT("en-US","GetBootStatus");
    	getBootStatusAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetBootStatus");
    	getBootStatusAttr.executable = true;
    	getBootStatusAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62532),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetBootStatus"),
                            getBootStatusAttr,
                            &outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetSnapshotStatusMethod(UA_Client *uaClient, UA_NodeId parent)
{

	UA_NodeId outNodeId;
    	UA_MethodAttributes getSnapshotStatusAttr = UA_MethodAttributes_default;
    	getSnapshotStatusAttr.description = UA_LOCALIZEDTEXT("en-US","GetSnapshotStatus");
    	getSnapshotStatusAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetSnapshotStatus");
    	getSnapshotStatusAttr.executable = true;
    	getSnapshotStatusAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62533),
                            parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            UA_QUALIFIEDNAME(1, "GetSnapshotStatus"),
                            getSnapshotStatusAttr,
                            &outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetSCPStatusMethod(UA_Client *uaClient, UA_NodeId parent)
{
	UA_NodeId outNodeId;

    	UA_MethodAttributes getSCPStatusAttr = UA_MethodAttributes_default;
    	getSCPStatusAttr.description = UA_LOCALIZEDTEXT("en-US","GetSCPStatus");
    	getSCPStatusAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetSCPStatus");
    	getSCPStatusAttr.executable = true;
    	getSCPStatusAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62534),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetSCPStatus"),
                            	getSCPStatusAttr,
                            	&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetSFTPStatusMethod(UA_Client *uaClient, UA_NodeId parent)
{
	UA_NodeId outNodeId;

    	UA_MethodAttributes getSFTPStatusAttr = UA_MethodAttributes_default;
    	getSFTPStatusAttr.description = UA_LOCALIZEDTEXT("en-US","GetSFTPStatus");
    	getSFTPStatusAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetSFTPStatus");
    	getSFTPStatusAttr.executable = true;
    	getSFTPStatusAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62535),
				parent,
                                UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                                UA_QUALIFIEDNAME(1, "GetSFTPStatus"),
                                getSFTPStatusAttr,
                                &outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetRunScriptStatusMethod(UA_Client *uaClient, UA_NodeId parent)
{

	UA_NodeId outNodeId;

    	UA_MethodAttributes getRunScriptStatusAttr = UA_MethodAttributes_default;
    	getRunScriptStatusAttr.description = UA_LOCALIZEDTEXT("en-US","GetRunScriptStatus");
    	getRunScriptStatusAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetRunScriptStatus");
    	getRunScriptStatusAttr.executable = true;
    	getRunScriptStatusAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62536),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetRunScriptStatus"),
                            	getRunScriptStatusAttr, //&GetRunScriptStatusMethodCallback,
                            	&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetArchiveStatusMethod(UA_Client *uaClient, UA_NodeId parent)
{
	UA_NodeId outNodeId;

    	UA_MethodAttributes getArchiveStatusAttr = UA_MethodAttributes_default;
    	getArchiveStatusAttr.description = UA_LOCALIZEDTEXT("en-US","GetArchiveStatus");
    	getArchiveStatusAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetArchiveStatus");
    	getArchiveStatusAttr.executable = true;
    	getArchiveStatusAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62537),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetArchiveStatus"),
                            	getArchiveStatusAttr, //&GetArchiveStatusMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetAncillarySensorStatusMethod(UA_Client *uaClient, UA_NodeId parent)
{
	UA_NodeId outNodeId;

    	UA_MethodAttributes getAncillarySensorStatusAttr = UA_MethodAttributes_default;
    	getAncillarySensorStatusAttr.description = UA_LOCALIZEDTEXT("en-US","GetAncillarySensorStatus");
    	getAncillarySensorStatusAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetAncillarySensorStatus");
    	getAncillarySensorStatusAttr.executable = true;
    	getAncillarySensorStatusAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62537),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetAncillarySensorStatus"),
                            	getAncillarySensorStatusAttr, //&GetAncillarySensorStatusMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetSensorMethod(UA_Client *uaClient, UA_NodeId parent)
{
	UA_NodeId outNodeId;

    	UA_MethodAttributes getSensorAttr = UA_MethodAttributes_default;
    	getSensorAttr.description = UA_LOCALIZEDTEXT("en-US","GetSensor");
    	getSensorAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetSensor");
    	getSensorAttr.executable = true;
    	getSensorAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62538),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetSensor"),
                            	getSensorAttr, //&GetSensorMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetOperatingTimeMethod(UA_Client *uaClient, UA_NodeId parent)
{
	UA_NodeId outNodeId;

    	UA_MethodAttributes getOperatingTimeAttr = UA_MethodAttributes_default;
    	getOperatingTimeAttr.description = UA_LOCALIZEDTEXT("en-US","GetOperatingTime");
    	getOperatingTimeAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetOperatingTime");
    	getOperatingTimeAttr.executable = true;
    	getOperatingTimeAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62539),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetOperatingTime"),
                            	getOperatingTimeAttr, //&GetOperatingTimeMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetWarningMessageMethod(UA_Client *uaClient, UA_NodeId parent)
{
	UA_NodeId outNodeId;

    	UA_MethodAttributes getWarningMessageAttr = UA_MethodAttributes_default;
    	getWarningMessageAttr.description = UA_LOCALIZEDTEXT("en-US","GetWarningMessage");
    	getWarningMessageAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetWarningMessage");
    	getWarningMessageAttr.executable = true;
    	getWarningMessageAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62540),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetWarningMessage"),
                            	getWarningMessageAttr, //&GetWarningMessageMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetIgramPPMethod(UA_Client *uaClient, UA_NodeId parent)
{
	UA_NodeId outNodeId;

    	UA_MethodAttributes getIgramPPAttr = UA_MethodAttributes_default;
    	getIgramPPAttr.description = UA_LOCALIZEDTEXT("en-US","GetIgramPP");
    	getIgramPPAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetIgramPP");
    	getIgramPPAttr.executable = true;
    	getIgramPPAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62541),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetIgramPP"),
                            	getIgramPPAttr, //&GetIgramPPMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetIgramDCMethod(UA_Client *uaClient, UA_NodeId parent)
{
	UA_NodeId outNodeId;

    	UA_MethodAttributes getIgramDCAttr = UA_MethodAttributes_default;
    	getIgramDCAttr.description = UA_LOCALIZEDTEXT("en-US","GetIgramDC");
    	getIgramDCAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetIgramDC");
    	getIgramDCAttr.executable = true;
    	getIgramDCAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62542),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetIgramDC"),
                            	getIgramDCAttr, //&GetIgramDCMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetLaserPPMethod(UA_Client *uaClient, UA_NodeId parent)
{
	UA_NodeId outNodeId;

   	UA_MethodAttributes getLaserPPAttr = UA_MethodAttributes_default;
    	getLaserPPAttr.description = UA_LOCALIZEDTEXT("en-US","GetLaserPP");
    	getLaserPPAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetLaserPP");
    	getLaserPPAttr.executable = true;
    	getLaserPPAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62543),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetLaserPP"),
                            	getLaserPPAttr, //&GetLaserPPMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetLaserDCMethod(UA_Client *uaClient, UA_NodeId parent) 
{
	UA_NodeId outNodeId;

    	UA_MethodAttributes getLaserDCAttr = UA_MethodAttributes_default;
    	getLaserDCAttr.description = UA_LOCALIZEDTEXT("en-US","GetLaserDC");
    	getLaserDCAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetLaserDC");
    	getLaserDCAttr.executable = true;
    	getLaserDCAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62544),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetLaserDC"),
                            	getLaserDCAttr, //&GetLaserDCMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetSingleBeamAt900Method(UA_Client *uaClient, UA_NodeId parent) 
{
	UA_NodeId outNodeId;

    	UA_MethodAttributes getSingleBeamAt900Attr = UA_MethodAttributes_default;
    	getSingleBeamAt900Attr.description = UA_LOCALIZEDTEXT("en-US","GetSingleBeamAt900");
    	getSingleBeamAt900Attr.displayName = UA_LOCALIZEDTEXT("en-US","GetSingleBeamAt900");
    	getSingleBeamAt900Attr.executable = true;
    	getSingleBeamAt900Attr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62545),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetSingleBeamAt900"),
                            	getSingleBeamAt900Attr, //&GetSingleBeamAt900MethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetSingleBeamAt2500Method(UA_Client *uaClient, UA_NodeId parent)
{
	UA_NodeId outNodeId;

    	UA_MethodAttributes getSingleBeamAt2500Attr = UA_MethodAttributes_default;
    	getSingleBeamAt2500Attr.description = UA_LOCALIZEDTEXT("en-US","GetSingleBeamAt2500");
    	getSingleBeamAt2500Attr.displayName = UA_LOCALIZEDTEXT("en-US","GetSingleBeamAt2500");
    	getSingleBeamAt2500Attr.executable = true;
    	getSingleBeamAt2500Attr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62546),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetSingleBeamAt2500"),
                            	getSingleBeamAt2500Attr, //&GetSingleBeamAt2500MethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetSignalToNoiseAt2500Method(UA_Client *uaClient, UA_NodeId parent)
{
	UA_NodeId outNodeId;

    	UA_MethodAttributes getSignalToNoiseAt2500Attr = UA_MethodAttributes_default;
    	getSignalToNoiseAt2500Attr.description = UA_LOCALIZEDTEXT("en-US","GetSignalToNoiseAt2500");
    	getSignalToNoiseAt2500Attr.displayName = UA_LOCALIZEDTEXT("en-US","GetSignalToNoiseAt2500");
    	getSignalToNoiseAt2500Attr.executable = true;
    	getSignalToNoiseAt2500Attr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62547),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetSignalToNoiseAt2500"),
                            	getSignalToNoiseAt2500Attr, //&GetSignalToNoiseAt2500MethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetCenterBurstLocationMethod(UA_Client *uaClient, UA_NodeId parent)
{

	UA_NodeId outNodeId;

    	UA_MethodAttributes getCenterBurstLocationAttr = UA_MethodAttributes_default;
    	getCenterBurstLocationAttr.description = UA_LOCALIZEDTEXT("en-US","GetCentreBurstLocation");
    	getCenterBurstLocationAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetCenterBurstLocation");
    	getCenterBurstLocationAttr.executable = true;
    	getCenterBurstLocationAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62548),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetCenterBurstLocation"),
                            	getCenterBurstLocationAttr, //&GetCenterBurstLocationMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetDetectorTempMethod(UA_Client *uaClient, UA_NodeId parent)
{
	UA_NodeId outNodeId;

    	UA_MethodAttributes getDetectorTempAttr = UA_MethodAttributes_default;
    	getDetectorTempAttr.description = UA_LOCALIZEDTEXT("en-US","GetDetectorTemp");
    	getDetectorTempAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetDetectorTemp");
    	getDetectorTempAttr.executable = true;
    	getDetectorTempAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62549),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetDetectorTemp"),
                            	getDetectorTempAttr, //&GetDetectorTempMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetLaserFrequencyMethod(UA_Client *uaClient, UA_NodeId parent)
{
	UA_NodeId outNodeId;

    	UA_MethodAttributes getLaserFrequencyAttr = UA_MethodAttributes_default;
    	getLaserFrequencyAttr.description = UA_LOCALIZEDTEXT("en-US","GetLaserFrequency");
    	getLaserFrequencyAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetLaserFrequency");
    	getLaserFrequencyAttr.executable = true;
    	getLaserFrequencyAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62550),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetLaserFrequency"),
                            	getLaserFrequencyAttr, //&GetLaserFrequencyMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetHardDriveSpaceMethod(UA_Client *uaClient, UA_NodeId parent)
{
	/*
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetHardDriveSpaceOutput");
    outputArgument.name = UA_STRING("HardDriveSpaceMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_INT16].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;
	*/
	UA_NodeId outNodeId;

    	UA_MethodAttributes getHardDriveSpaceAttr = UA_MethodAttributes_default;
    	getHardDriveSpaceAttr.description = UA_LOCALIZEDTEXT("en-US","GetHardDriveSpace");
    	getHardDriveSpaceAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetHardDriveSpace");
    	getHardDriveSpaceAttr.executable = true;
    	getHardDriveSpaceAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62551),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetHardDriveSpace"),
                            	getHardDriveSpaceAttr, //&GetHardDriveSpaceMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetFlowMethod(UA_Client *uaClient, UA_NodeId parent)
{
/*
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetFlowOutput");
    outputArgument.name = UA_STRING("FlowMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;
*/
	UA_NodeId outNodeId;

    	UA_MethodAttributes getFlowAttr = UA_MethodAttributes_default;
    	getFlowAttr.description = UA_LOCALIZEDTEXT("en-US","GetFlow");
    	getFlowAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetFlow");
    	getFlowAttr.executable = true;
    	getFlowAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62552),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetFlow"),
                            	getFlowAttr, //&GetFlowMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetTemperatureMethod(UA_Client *uaClient, UA_NodeId parent)
{
/*
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetTemperatureOutput");
    outputArgument.name = UA_STRING("TemperatureMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;
*/
	UA_NodeId outNodeId;

    	UA_MethodAttributes getTemperatureAttr = UA_MethodAttributes_default;
    	getTemperatureAttr.description = UA_LOCALIZEDTEXT("en-US","GetTemperature");
    	getTemperatureAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetTemperature");
    	getTemperatureAttr.executable = true;
    	getTemperatureAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62553),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetTempeature"),
                            	getTemperatureAttr, //&GetTemperatureMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetPressureMethod(UA_Client *uaClient, UA_NodeId parent)
{
/*
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetPressureOutput");
    outputArgument.name = UA_STRING("PressureMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;
*/
	UA_NodeId outNodeId;

    	UA_MethodAttributes getPressureAttr = UA_MethodAttributes_default;
   	getPressureAttr.description = UA_LOCALIZEDTEXT("en-US","GetPressure");
    	getPressureAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetPressure");
    	getPressureAttr.executable = true;
    	getPressureAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62554),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetPressure"),
                            	getPressureAttr, //&GetPressureMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetTempOpticsMethod(UA_Client *uaClient, UA_NodeId parent)
{
/*
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetTempOpticsOutput");
    outputArgument.name = UA_STRING("TempOpticsMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;
*/

	UA_NodeId outNodeId;

    	UA_MethodAttributes getTempOpticsAttr = UA_MethodAttributes_default;
    	getTempOpticsAttr.description = UA_LOCALIZEDTEXT("en-US","GetTempOptics");
    	getTempOpticsAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetTempOptics");
    	getTempOpticsAttr.executable = true;
    	getTempOpticsAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62555),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetTempOptics"),
                            	getTempOpticsAttr, //&GetTempOpticsMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetBadScanCounterMethod(UA_Client *uaClient, UA_NodeId parent)
{
/*
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetBadScanCounterOutput");
    outputArgument.name = UA_STRING("BadScanCounterMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_INT16].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;
*/
	UA_NodeId outNodeId;

    	UA_MethodAttributes getBadScanCounterAttr = UA_MethodAttributes_default;
    	getBadScanCounterAttr.description = UA_LOCALIZEDTEXT("en-US","GetBadScanCounterOptics");
    	getBadScanCounterAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetBadScanCounterOptics");
    	getBadScanCounterAttr.executable = true;
    	getBadScanCounterAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62556),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetBadScanCounter"),
                            	getBadScanCounterAttr, //&GetBadScanCounterMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetFreeMemorySpaceMethod(UA_Client *uaClient, UA_NodeId parent)
{
/*
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetFreeMemorySpaceOutput");
    outputArgument.name = UA_STRING("FreeMemorySpaceMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_INT16].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;
*/
	UA_NodeId outNodeId;

    	UA_MethodAttributes getFreeMemorySpaceAttr = UA_MethodAttributes_default;
    	getFreeMemorySpaceAttr.description = UA_LOCALIZEDTEXT("en-US","GetFreeMemorySpace");
    	getFreeMemorySpaceAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetFreeMemorySpace");
    	getFreeMemorySpaceAttr.executable = true;
    	getFreeMemorySpaceAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62557),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetTempOptics"),
                            	getFreeMemorySpaceAttr, //&GetFreeMemorySpaceMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetLABFilenameMethod(UA_Client *uaClient, UA_NodeId parent)
{
/*
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetLABFilenameOutput");
    outputArgument.name = UA_STRING("LABFilenameMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;
*/
	UA_NodeId outNodeId;

    	UA_MethodAttributes getLABFilenameAttr = UA_MethodAttributes_default;
    	getLABFilenameAttr.description = UA_LOCALIZEDTEXT("en-US","GetLABFilename");
    	getLABFilenameAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetLABFilename");
    	getLABFilenameAttr.executable = true;
    	getLABFilenameAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62558),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetLABFilename"),
                            	getLABFilenameAttr, //&GetLABFilenameMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);
}

void
addGetLOGFilenameMethod(UA_Client *uaClient, UA_NodeId parent)
{
/*
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetLOGFilenameOutput");
    outputArgument.name = UA_STRING("LOGFilenameMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;
*/
	UA_NodeId outNodeId;

    	UA_MethodAttributes getLOGFilenameAttr = UA_MethodAttributes_default;
    	getLOGFilenameAttr.description = UA_LOCALIZEDTEXT("en-US","GetLOGFilename");
    	getLOGFilenameAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetLOGFilename");
    	getLOGFilenameAttr.executable = true;
    	getLOGFilenameAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62559),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetLOGFilename"),
                            	getLOGFilenameAttr, //&GetLOGFilenameMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetLgFilenameMethod(UA_Client *uaClient, UA_NodeId parent)
{
/*
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetLgFilenameOutput");
    outputArgument.name = UA_STRING("LgFilenameMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;
*/
	UA_NodeId outNodeId;

    	UA_MethodAttributes getLgFilenameAttr = UA_MethodAttributes_default;
    	getLgFilenameAttr.description = UA_LOCALIZEDTEXT("en-US","GetLgFilename");
    	getLgFilenameAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetLgFilename");
    	getLgFilenameAttr.executable = true;
    	getLgFilenameAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62560),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetLgFilename"),
                            	getLgFilenameAttr, //&GetLgFilenameMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetSecondLgFilenameMethod(UA_Client *uaClient, UA_NodeId parent)
{
/*
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetSecondLgFilenameOutput");
    outputArgument.name = UA_STRING("SecondLgFilenameMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_STRING].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;
*/
	UA_NodeId outNodeId;

    	UA_MethodAttributes getSecondLgFilenameAttr = UA_MethodAttributes_default;
    	getSecondLgFilenameAttr.description = UA_LOCALIZEDTEXT("en-US","GetSecondLgFilename");
    	getSecondLgFilenameAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetSecondLgFilename");
    	getSecondLgFilenameAttr.executable = true;
    	getSecondLgFilenameAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62561),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetSecondLgFilename"),
                            	getSecondLgFilenameAttr, //&GetSecondLgFilenameMethodCallback,
				&outNodeId);
                            //0, NULL, 1, &outputArgument, NULL, NULL);

}


void
addGetSystemCounterMethod(UA_Client *uaClient, UA_NodeId parent)
{
/*
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetSystemCounterOutput");
    outputArgument.name = UA_STRING("SystemCounterMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;
*/
	UA_NodeId outNodeId;
    	UA_MethodAttributes getSystemCounterAttr = UA_MethodAttributes_default;
    	getSystemCounterAttr.description = UA_LOCALIZEDTEXT("en-US","GetSystemCounter");
    	getSystemCounterAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetSystemCounter");
    	getSystemCounterAttr.executable = true;
    	getSystemCounterAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62562),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetSystemCounter"),
                            	getSystemCounterAttr, //&GetSystemCounterMethodCallback,
                            	&outNodeId);
				//0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetDetectorCounterMethod(UA_Client *uaClient, UA_NodeId parent)
{
/*
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetDetectorCounterOutput");
    outputArgument.name = UA_STRING("DetectorCounterMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;
*/

	UA_NodeId outNodeId;

    	UA_MethodAttributes getDetectorCounterAttr = UA_MethodAttributes_default;
    	getDetectorCounterAttr.description = UA_LOCALIZEDTEXT("en-US","GetDetectorCounter");
    	getDetectorCounterAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetDetectorCounter");
    	getDetectorCounterAttr.executable = true;
    	getDetectorCounterAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62563),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetDetectorCounter"),
                            	getDetectorCounterAttr, //&GetDetectorCounterMethodCallback,
				&outNodeId);
	                        //0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetLaserCounterMethod(UA_Client *uaClient, UA_NodeId parent)
{
/*
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetLaserCounterOutput");
    outputArgument.name = UA_STRING("LaserCounterMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;
*/

	UA_NodeId outNodeId;

    	UA_MethodAttributes getLaserCounterAttr = UA_MethodAttributes_default;
    	getLaserCounterAttr.description = UA_LOCALIZEDTEXT("en-US","GetLaserCounter");
    	getLaserCounterAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetLaserCounter");
    	getLaserCounterAttr.executable = true;
    	getLaserCounterAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62564),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetLaserCounter"),
                            	getLaserCounterAttr, //&GetLaserCounterMethodCallback,
				&outNodeId);
                            	//0, NULL, 1, &outputArgument, NULL, NULL);

}

void
addGetFlowPumpCounterMethod(UA_Client *uaClient, UA_NodeId parent)
{
/*
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetFlowPumpCounterOutput");
    outputArgument.name = UA_STRING("FlowPumpCounterMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;
*/
	UA_NodeId outNodeId;

    	UA_MethodAttributes getFlowPumpCounterAttr = UA_MethodAttributes_default;
    	getFlowPumpCounterAttr.description = UA_LOCALIZEDTEXT("en-US","GetFlowPumpCounter");
    	getFlowPumpCounterAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetFlowPumpCounter");
    	getFlowPumpCounterAttr.executable = true;
    	getFlowPumpCounterAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62565),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetFlowPumpCounter"),
                            	getFlowPumpCounterAttr, //&GetFlowPumpCounterMethodCallback,
				&outNodeId);
                            	//0, NULL, 1, &outputArgument, NULL, NULL);

}


void
addGetDesiccantCounterMethod(UA_Client *uaClient, UA_NodeId parent)
{
/*
    UA_Argument outputArgument;
    UA_Argument_init(&outputArgument);
    outputArgument.description = UA_LOCALIZEDTEXT("en-US", "GetDesiccantCounterOutput");
    outputArgument.name = UA_STRING("DesiccantCounterMethodOutput");
    outputArgument.dataType = UA_TYPES[UA_TYPES_FLOAT].typeId;
    outputArgument.valueRank = UA_VALUERANK_SCALAR;
*/

	UA_NodeId outNodeId;

    	UA_MethodAttributes getDesiccantCounterAttr = UA_MethodAttributes_default;
    	getDesiccantCounterAttr.description = UA_LOCALIZEDTEXT("en-US","GetDesiccantCounter");
    	getDesiccantCounterAttr.displayName = UA_LOCALIZEDTEXT("en-US","GetDesiccantCounter");
    	getDesiccantCounterAttr.executable = true;
    	getDesiccantCounterAttr.userExecutable = true;
    	UA_Client_addMethodNode(uaClient, UA_NODEID_NUMERIC(1,62566),
                            	parent,                     //UA_NODEID_NUMERIC(0, UA_NS0ID_OBJECTSFOLDER),
                            	UA_NODEID_NUMERIC(0, UA_NS0ID_HASCOMPONENT),
                            	UA_QUALIFIEDNAME(1, "GetDesiccantCounter"),
                            	getDesiccantCounterAttr, //&GetDesiccantCounterMethodCallback,
				&outNodeId);
                            	//0, NULL, 1, &outputArgument, NULL, NULL);

}


void CreateMethodNodes(UA_Client *client, UA_NodeId r2_airgard_method_Id)
{

	UA_NodeId methodNode_Id;

        UA_Client_readNodeIdAttribute(client, UA_NODEID_NUMERIC(1,62528),&methodNode_Id);
        if (UA_NodeId_isNull(&methodNode_Id)) // node does not exist, create it
		addGetSoftwareVersionMethod(client, r2_airgard_method_Id);
	else
		printf("methodNode 62528 exist \n");
/*
	addGetDataBlockVersionMethod(client, r2_airgard_method_Id);
        addGetInstrumentTimeMethod(client, r2_airgard_method_Id);
        addGetMeasurementTimeMethod(client, r2_airgard_method_Id);

        addGetBootStatusMethod(client, r2_airgard_method_Id);
        addGetSnapshotStatusMethod(client, r2_airgard_method_Id);
        addGetSCPStatusMethod(client, r2_airgard_method_Id);
        addGetSFTPStatusMethod(client, r2_airgard_method_Id);
        addGetRunScriptStatusMethod(client, r2_airgard_method_Id);
        addGetArchiveStatusMethod(client, r2_airgard_method_Id);
        addGetAncillarySensorStatusMethod(client, r2_airgard_method_Id);

        addGetSensorMethod(client, r2_airgard_method_Id);
        addGetOperatingTimeMethod(client, r2_airgard_method_Id);
        addGetWarningMessageMethod(client, r2_airgard_method_Id);

        addGetIgramPPMethod(client, r2_airgard_method_Id);
        addGetIgramDCMethod(client, r2_airgard_method_Id);
        addGetLaserPPMethod(client, r2_airgard_method_Id);
        addGetLaserDCMethod(client, r2_airgard_method_Id);
        addGetSingleBeamAt900Method(client, r2_airgard_method_Id);
        addGetSingleBeamAt2500Method(client, r2_airgard_method_Id);
        addGetSignalToNoiseAt2500Method(client, r2_airgard_method_Id);
        addGetCenterBurstLocationMethod(client, r2_airgard_method_Id);
        addGetDetectorTempMethod(client, r2_airgard_method_Id);
        addGetLaserFrequencyMethod(client, r2_airgard_method_Id);
        addGetHardDriveSpaceMethod(client, r2_airgard_method_Id);
        addGetFlowMethod(client, r2_airgard_method_Id);
        addGetTemperatureMethod(client, r2_airgard_method_Id);
        addGetPressureMethod(client, r2_airgard_method_Id);
        addGetTempOpticsMethod(client, r2_airgard_method_Id);
        addGetBadScanCounterMethod(client, r2_airgard_method_Id);
        addGetFreeMemorySpaceMethod(client, r2_airgard_method_Id);
        addGetLABFilenameMethod(client, r2_airgard_method_Id);
        addGetLOGFilenameMethod(client, r2_airgard_method_Id);
        addGetLgFilenameMethod(client, r2_airgard_method_Id);
        addGetSecondLgFilenameMethod(client, r2_airgard_method_Id);
        addGetSystemCounterMethod(client, r2_airgard_method_Id);
        addGetDetectorCounterMethod(client, r2_airgard_method_Id);
        addGetLaserCounterMethod(client, r2_airgard_method_Id);
        addGetFlowPumpCounterMethod(client, r2_airgard_method_Id);
        addGetDesiccantCounterMethod(client, r2_airgard_method_Id);
*/
        UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
            "Method Nodes created : Airgard->Methods Node\n");

}



