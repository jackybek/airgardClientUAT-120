#include "open62541.h"
//#include "myNewMonitor.h"


void dataChangeNotificationCallback(UA_Server *server, UA_UInt32 monitoredItemId,
                               void *monitoredItemContext, const UA_NodeId *nodeId,
                               void *nodeContext, UA_UInt32 attributeId,
                               const UA_DataValue *value)
{
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "Received Notification");

}

void addMonitoredItemToSoftwareVersionVariable(UA_Server *server)
{
        UA_NodeId SoftwareVersionNodeId = UA_NODEID_NUMERIC(0, 10001);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(SoftwareVersionNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToDataBlockVersionVariable(UA_Server *server)
{
        UA_NodeId DataBlockVersionNodeId = UA_NODEID_NUMERIC(0, 10002);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(DataBlockVersionNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}


void addMonitoredItemToInstrumentTimeVariable(UA_Server *server)
{
        UA_NodeId InstrumentTimeNodeId = UA_NODEID_NUMERIC(0, 10101);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(InstrumentTimeNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToMeasurementTimeVariable(UA_Server *server)
{
        UA_NodeId MeasurementTimeNodeId = UA_NODEID_NUMERIC(0, 10102);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(MeasurementTimeNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToBootStatusVariable(UA_Server *server)
{
        UA_NodeId BootStatusNodeId = UA_NODEID_NUMERIC(0, 10211);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(BootStatusNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToSnapshotStatusVariable(UA_Server *server)
{
        UA_NodeId SnapshotStatusNodeId = UA_NODEID_NUMERIC(0, 10212);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(SnapshotStatusNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToSCPStatusVariable(UA_Server *server)
{
        UA_NodeId SCPStatusNodeId = UA_NODEID_NUMERIC(0, 10213);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(SCPStatusNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToSFTPStatusVariable(UA_Server *server)
{
        UA_NodeId SFTPStatusNodeId = UA_NODEID_NUMERIC(0, 10214);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(SFTPStatusNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void  addMonitoredItemToRunScriptStatusVariable(UA_Server *server)
{
        UA_NodeId RunScriptStatusNodeId = UA_NODEID_NUMERIC(0, 10215);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(RunScriptStatusNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToArchiveStatusVariable(UA_Server *server)
{
        UA_NodeId ArchiveStatusNodeId = UA_NODEID_NUMERIC(0, 10216);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(ArchiveStatusNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToAncillarySensorStatusVariable(UA_Server *server)
{
        UA_NodeId AncillarySensorStatusNodeId = UA_NODEID_NUMERIC(0, 10217);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(AncillarySensorStatusNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}



void addMonitoredItemToSensorVariable(UA_Server *server)
{
        UA_NodeId SensorNodeId = UA_NODEID_NUMERIC(0, 10201);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(SensorNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToOperatingTimeVariable(UA_Server *server)
{
        UA_NodeId OperatingTimeNodeId = UA_NODEID_NUMERIC(0, 10202);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(OperatingTimeNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToWarningMessageVariable(UA_Server *server)
{
        UA_NodeId WarningMessageNodeId = UA_NODEID_NUMERIC(0, 10203);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(WarningMessageNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}


void addMonitoredItemToIgramPPVariable(UA_Server *server)
{
  	UA_NodeId IgramPPNodeId = UA_NODEID_NUMERIC(0, 10301);
    	UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(IgramPPNodeId);
    	monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
    	UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToIgramDCVariable(UA_Server *server)
{
        UA_NodeId IgramDCNodeId = UA_NODEID_NUMERIC(0, 10302);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(IgramDCNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToLaserPPVariable(UA_Server *server)
{
        UA_NodeId LaserPPNodeId = UA_NODEID_NUMERIC(0, 10303);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(LaserPPNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToLaserDCVariable(UA_Server *server)
{
        UA_NodeId LaserDCNodeId = UA_NODEID_NUMERIC(0, 10304);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(LaserDCNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToSingleBeamAt900Variable(UA_Server *server)
{
        UA_NodeId SingleBeamAt900NodeId = UA_NODEID_NUMERIC(0, 10305);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(SingleBeamAt900NodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToSingleBeamAt2500Variable(UA_Server *server)
{
        UA_NodeId SingleBeamAt2500NodeId = UA_NODEID_NUMERIC(0, 10306);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(SingleBeamAt2500NodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToSignalToNoiseAt2500Variable(UA_Server *server)
{
        UA_NodeId SignalToNoiseAt2500NodeId = UA_NODEID_NUMERIC(0, 10307);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(SignalToNoiseAt2500NodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToCenterBurstLocationVariable(UA_Server *server)
{
        UA_NodeId CenterBurstLocationNodeId = UA_NODEID_NUMERIC(0, 10308);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(CenterBurstLocationNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToDetectorTempVariable(UA_Server *server)
{
        UA_NodeId DetectorTempNodeId = UA_NODEID_NUMERIC(0, 10309);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(DetectorTempNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToLaserFrequencyVariable(UA_Server *server)
{
        UA_NodeId LaserFrequencyNodeId = UA_NODEID_NUMERIC(0, 10310);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(LaserFrequencyNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToHardDriveSpaceVariable(UA_Server *server)
{
        UA_NodeId HardDriveSpaceNodeId = UA_NODEID_NUMERIC(0, 10311);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(HardDriveSpaceNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToFlowVariable(UA_Server *server)
{
        UA_NodeId FlowNodeId = UA_NODEID_NUMERIC(0, 10312);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(FlowNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToTemperatureVariable(UA_Server *server)
{
        UA_NodeId TemperatureNodeId = UA_NODEID_NUMERIC(0, 10313);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(TemperatureNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToPressureVariable(UA_Server *server)
{
        UA_NodeId PressureNodeId = UA_NODEID_NUMERIC(0, 10314);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(PressureNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToTempOpticsVariable(UA_Server *server)
{
        UA_NodeId TempOpticsNodeId = UA_NODEID_NUMERIC(0, 10315);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(TempOpticsNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToBadScanCounterVariable(UA_Server *server)
{
        UA_NodeId BadScanCounterNodeId = UA_NODEID_NUMERIC(0, 10316);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(BadScanCounterNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToFreeMemorySpaceVariable(UA_Server *server)
{
        UA_NodeId FreeMemorySpaceNodeId = UA_NODEID_NUMERIC(0, 10317);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(FreeMemorySpaceNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToLABFilenameVariable(UA_Server *server)
{
        UA_NodeId LABFilenameNodeId = UA_NODEID_NUMERIC(0, 10318);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(LABFilenameNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToLOGFilenameVariable(UA_Server *server)
{
        UA_NodeId LOGFilenameNodeId = UA_NODEID_NUMERIC(0, 10319);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(LOGFilenameNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToLgFilenameVariable(UA_Server *server)
{
        UA_NodeId LgFilenameNodeId = UA_NODEID_NUMERIC(0, 10320);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(LgFilenameNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToSecondLgFilenameVariable(UA_Server *server)
{
        UA_NodeId SecondLgFilenameNodeId = UA_NODEID_NUMERIC(0, 10321);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(SecondLgFilenameNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToSystemCounterVariable(UA_Server *server)
{
        UA_NodeId SystemCounterNodeId = UA_NODEID_NUMERIC(0, 10322);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(SystemCounterNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToDetectorCounterVariable(UA_Server *server)
{
        UA_NodeId DetectorCounterNodeId = UA_NODEID_NUMERIC(0, 10323);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(DetectorCounterNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToLaserCounterVariable(UA_Server *server)
{
        UA_NodeId LaserCounterNodeId = UA_NODEID_NUMERIC(0, 10324);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(LaserCounterNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToFlowPumpCounterVariable(UA_Server *server)
{
        UA_NodeId FlowPumpCounterNodeId = UA_NODEID_NUMERIC(0, 10325);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(FlowPumpCounterNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}

void addMonitoredItemToDesiccantCounterVariable(UA_Server *server)
{
        UA_NodeId DesiccantCounterNodeId = UA_NODEID_NUMERIC(0, 10326);
        UA_MonitoredItemCreateRequest monRequest = UA_MonitoredItemCreateRequest_default(DesiccantCounterNodeId);
        monRequest.requestedParameters.samplingInterval = 100.0; /* 100 ms interval */
        UA_Server_createDataChangeMonitoredItem(server, UA_TIMESTAMPSTORETURN_SOURCE,
                                            monRequest, NULL, dataChangeNotificationCallback);
}


