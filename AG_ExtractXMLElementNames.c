#include "open62541.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libxml2/libxml/parser.h>
#include <libxml2/libxml/tree.h>
#include <libxml2/libxml/xmlreader.h>

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

extern int NoOfAlarmsNode;
extern int NoOfNonAlarmsNode;
AlarmStruct arrayOfAlarm[255];  //101
AlarmStruct arrayOfNonAlarm[255];
extern char AlarmTag[255];
extern char AlarmName[255];
extern UA_Float AlarmProbability;
extern char AlarmCASnumber[255];
extern UA_Int16 AlarmConcentration;

// for historizing use
extern UA_NodeId outIgramPPId;

// for pub sub use
extern UA_NodeId ds1IgramPPId;
extern UA_NodeId ds1IgramDCId;
extern UA_NodeId ds1LaserPPId;
extern UA_NodeId ds1LaserDCId;


int ExtractXMLElementNames(xmlNode* a_node);
xmlNodePtr srSeekChildNodeNamed(xmlNode* p, char* name, int len);

int ExtractXMLElementNames(xmlNode *a_node)
{
	// extract elements from XML file; this is NOT the OPCStructure

	xmlNode *curr_node = NULL;
	xmlNode *ori_node = a_node;	// keeps the pointer at the start position for seek()
	int NumOfChildNodes = 0;
	//char currentNodeName[255];
	int retval;

	xmlNode *alarm_node= a_node; // use to traverse alarm segment only
	xmlNode *alarm_childnode = NULL;
	xmlNode *nonalarm_node = a_node; // use to travese nonalarm segment only
	xmlNode *nonalarm_childnode = NULL;

	char mystring[255];

    //printf("============================================================\n");
    //printf("Entering NA_ExtractXMLElementNames() \n");
    //printf("============================================================\n");

	for (curr_node=a_node; curr_node;curr_node=curr_node->next)
	{
		if (curr_node->type == XML_ELEMENT_NODE)
		{
			//printf("AG_ExtractXMLElementNames.c : %s \n", curr_node->name);

			if (strncmp(curr_node->name, "SoftwareVersion", 15) == 0)			// curr_node->name
			{
				strcpy(SoftwareVersion, (char*)xmlNodeGetContent(curr_node));
				printf("Software Version node found : %s\n", SoftwareVersion);
			}
			else if (strncmp(curr_node->name, "DataBlockVersion", 16) == 0)
			{
				strcpy(DataBlockVersion, (char*)xmlNodeGetContent(curr_node));
				printf("Data Block Version node found : %s\n", DataBlockVersion);
			}
			// end <Airgard> section
			else if (strncmp(curr_node->name, "InstrumentTime", 14) == 0)
			{
				strcpy(InstrumentTime, (char*)xmlNodeGetContent(curr_node));
				//printf("Instrument Time node found : %s\n", InstrumentTime);
			}
			else if (strncmp(curr_node->name, "MeasurementTime", 15) == 0)
			{
				strcpy(MeasurementTime, (char*)xmlNodeGetContent(curr_node));
				//printf("Measurement Time node found : %s\n", MeasurementTime);
			}
			// <Info> Section
                        	       	else if (strncmp(curr_node->name, "BootStatus",10) == 0)
                               		{
                                        	strcpy(BootStatus, (char*)xmlNodeGetContent(curr_node));
                                        	//printf("\tBootStatus node found : %s\n", BootStatus);
					}
                                        else if (strncmp(curr_node->name, "SnapshotStatus",14) == 0)
                                        {
                                                strcpy(SnapshotStatus, (char*)xmlNodeGetContent(curr_node));
                                                //printf("\tSnapshotStatus node found : %s\n", SnapshotStatus);
                                        }
                                        else if (strncmp(curr_node->name, "SCPStatus",9) == 0)
                                        {
                                                strcpy(SCPStatus, (char*)xmlNodeGetContent(curr_node));
                                                //printf("\tSCPStatus node found : %s\n", SCPStatus);
                                        }
                                        else if (strncmp(curr_node->name, "SFTPStatus",10) == 0)
                                        {
                                                strcpy(SFTPStatus, (char*)xmlNodeGetContent(curr_node));
                                                //printf("\tSFTPStatus node found : %s\n", SFTPStatus);
                                        }
                                        else if (strncmp(curr_node->name, "RunScriptStatus",15) == 0)
                                        {
                                                strcpy(RunScriptStatus, (char*)xmlNodeGetContent(curr_node));
                                                //printf("\tRunScriptStatus node found : %s\n", RunScriptStatus);
                                        }
                                        else if (strncmp(curr_node->name, "ArchiveStatus",13) == 0)
                                        {
                                                strcpy(ArchiveStatus, (char*)xmlNodeGetContent(curr_node));
                                                //printf("\tArchiveStatus node found : %s\n", ArchiveStatus);
                                        }
                                        else if (strncmp(curr_node->name, "AncillarySensorStatus",21) == 0)
                                        {
                                                strcpy(AncillarySensorStatus, (char*)xmlNodeGetContent(curr_node));
                                                //printf("\tAncillarySensorStatus node found : %s\n", AncillarySensorStatus);
                                        }
					// end <Info> Section
			else if (strncmp(curr_node->name, "Sensor", 6) == 0)
			{
				strcpy(Sensor, (char*)xmlNodeGetContent(curr_node));
				//printf("\tSensor node found : %s\n", Sensor);
			}
			else if (strncmp(curr_node->name, "OperatingTime", 13) == 0)
			{
				OperatingTime = atoi(xmlNodeGetContent(curr_node));
				//printf("\tOperatingTime node found : %d\n", OperatingTime);
			}
			else if (strncmp(curr_node->name, "WarningMessage", 14) == 0)
			{
				strcpy(WarningMessage, (char*)xmlNodeGetContent(curr_node));
				//printf("\tWarningMessage node found : %s\n", WarningMessage);
			}
			// end  <Status> Section
			else if (strncmp(curr_node->name, "IgramPP",7) == 0)
			{
				int r_int = rand() % 20;
				IgramPP = (UA_Float) atof(xmlNodeGetContent(curr_node)) + (float)r_int;
				//printf("IgramPP node found : %f\n", IgramPP);
			}
			else if (strncmp(curr_node->name, "IgramDC", 7) == 0)
			{
				int r_int = rand() % 20;
				IgramDC = (UA_Float) atof(xmlNodeGetContent(curr_node)) + (float)r_int;
				//printf("IgramDC node found : %f\n", IgramDC);
			}
			else if (strncmp(curr_node->name, "LaserPP",7) == 0)
			{
				int r_int = rand() % 20;
				LaserPP = (UA_Float) atof(xmlNodeGetContent(curr_node)) + (float)r_int;
				//printf("LaserPP node found : %f\n", LaserPP);
			}
			else if (strncmp(curr_node->name, "LaserDC",7) == 0)
			{
				int r_int = rand() % 20;
				LaserDC = (UA_Float) atof(xmlNodeGetContent(curr_node)) + (float)r_int;
				//printf("LaserDC node found : %f\n", LaserDC);
			}
			else if (strncmp(curr_node->name, "SingleBeamAt900",15) == 0)
			{
				int r_int = rand() % 20;
				SingleBeamAt900 = (UA_Float) atof(xmlNodeGetContent(curr_node)) + (float)r_int;
				//printf("SingleBeamAt900 node found : %f\n", SingleBeamAt900);
			}
                        else if (strncmp(curr_node->name, "SingleBeamAt2500",16) == 0)
                        {
				int r_int = rand() % 20;
                                SingleBeamAt2500 = (UA_Float) atof(xmlNodeGetContent(curr_node)) + (float)r_int;
                                //printf("SingleBeamAt2500 node found : %f\n", SingleBeamAt2500);
                        }
                        else if (strncmp(curr_node->name, "SignalToNoiseAt2500",19) == 0)
                        {
				int r_int = rand() % 20;
                                SignalToNoiseAt2500 = (UA_Int16) atoi(xmlNodeGetContent(curr_node)) + (float)r_int;
                                //printf("SignalToNoiseAt2500 node found : %d\n", SignalToNoiseAt2500);
                        }
                        else if (strncmp(curr_node->name, "CenterBurstLocation",19) == 0)
                        {
				int r_int = rand() % 20;
                                CenterBurstLocation = (UA_Float) atof(xmlNodeGetContent(curr_node)) + (float)r_int;
                                //printf("CenterBurstLocation node found : %f\n", CenterBurstLocation);
                        }
			else if (strncmp(curr_node->name, "DetectorTemp",12) == 0)
			{
				int r_int = rand() % 20;
				DetectorTemp = (UA_Float) atof(xmlNodeGetContent(curr_node)) + (float)r_int;
				//printf("DetectorTemp node found : %f\n", DetectorTemp);
			}
                        else if (strncmp(curr_node->name, "LaserFrequency",14) == 0)
                        {
				int r_int = rand() % 20;
                                LaserFrequency = (UA_Float) atof(xmlNodeGetContent(curr_node)) + (float)r_int;
                                //printf("LaserFrequency node found : %f\n", LaserFrequency);
                        }
                        else if (strncmp(curr_node->name, "HardDriveSpace",14) == 0)
                        {
				int r_int = rand() % 20;
                                HardDriveSpace = (UA_Int16) atoi(xmlNodeGetContent(curr_node))+ r_int;
                                //printf("HardDriveSpace node found : %d\n", HardDriveSpace);
                        }
                        else if (strncmp(curr_node->name, "Flow",4) == 0)
                        {
				int r_int = rand() % 20;
                                Flow = (UA_Int16) atoi(xmlNodeGetContent(curr_node)) + (float)r_int;
                                //printf("Flow node found : %f\n", Flow);
                        }
                        else if (strncmp(curr_node->name, "Temperature",11) == 0)
                        {
				int r_int = rand() % 20;
                                Temperature = (UA_Int16) atoi(xmlNodeGetContent(curr_node)) + (float)r_int;
                                //printf("Temperature node found : %f\n", Temperature);
                        }
                        else if (strncmp(curr_node->name, "Pressure",8) == 0)
                        {
				int r_int = rand() % 20;
                                Pressure = (UA_Float) atof(xmlNodeGetContent(curr_node)) + (float)r_int;
                                //printf("Pressure node found : %f\n", Pressure);
                        }
                        else if (strncmp(curr_node->name, "TempOptics",10) == 0)
                        {
				int r_int = rand() % 20;
                                TempOptics = (UA_Int16) atoi(xmlNodeGetContent(curr_node)) + (float)r_int;
                                //printf("TempOptics node found : %f\n", TempOptics);
                        }
                        else if (strncmp(curr_node->name, "BadScanCounter",14) == 0)
                        {
				int r_int = rand() % 20;
                                BadScanCounter = (UA_Int16) atoi(xmlNodeGetContent(curr_node)) + r_int;
                                //printf("BadScanCounter node found : %d\n", BadScanCounter);
                        }
                        else if (strncmp(curr_node->name, "FreeMemorySpace",15) == 0)
                        {
				int r_int = rand() % 20;
                                FreeMemorySpace = (UA_Int16) atoi(xmlNodeGetContent(curr_node)) + r_int;
                                //printf("FreeMemorySpace node found : %d\n", FreeMemorySpace);
                        }
                        else if (strncmp(curr_node->name, "LABFilename",11) == 0)
                        {
                                strcpy(LABFilename, xmlNodeGetContent(curr_node));
                                //printf("LABFilename node found : %s\n", LABFilename);
                        }
                        else if (strncmp(curr_node->name, "LOGFilename",11) == 0)
                        {
                                strcpy(LOGFilename, xmlNodeGetContent(curr_node));
                                //printf("LOGFilename node found : %s\n", LOGFilename);
                        }
                        else if (strncmp(curr_node->name, "LgFilename",10) == 0)
                        {
                                strcpy(LgFilename, xmlNodeGetContent(curr_node));
                                //printf("LgFilename node found : %s\n", LgFilename);
                        }
                        else if (strncmp(curr_node->name, "SecondLgFilename",16) == 0)
                        {
                                strcpy(SecondLgFilename, xmlNodeGetContent(curr_node));
                                //printf("SecondLgFilename node found : %s\n", SecondLgFilename);
                        }
                        else if (strncmp(curr_node->name, "SystemCounter",13) == 0)
                        {
				int r_int = rand() % 20;
                                SystemCounter = (UA_Float) atof(xmlNodeGetContent(curr_node)) + (float)r_int;
                                //printf("SystemCounter node found : %f\n", SystemCounter);
                        }
                        else if (strncmp(curr_node->name, "DetectorCounter",15) == 0)
                        {
				int r_int = rand() % 20;
                                DetectorCounter = (UA_Float) atof(xmlNodeGetContent(curr_node)) + (float)r_int;
                                //printf("DetectorCounter node found : %f\n", DetectorCounter);
                        }
                        else if (strncmp(curr_node->name, "LaserCounter",12) == 0)
                        {
				int r_int = rand() % 20;
                                LaserCounter = (UA_Float) atof(xmlNodeGetContent(curr_node)) + (float)r_int;
                                printf("LaserCounter node found : %f\n", LaserCounter);
				sleep(5);
                        }
                        else if (strncmp(curr_node->name, "FlowPumpCounter",15) == 0)
                        {

				int r_int = rand() % 20;
                                FlowPumpCounter = (UA_Float) atof(xmlNodeGetContent(curr_node)) + (float)r_int;
                                printf("FlowPumpCounter node found : %f\n", FlowPumpCounter);
				sleep(5);
                        }
                        else if (strncmp(curr_node->name, "DesiccantCounter",16) == 0)
                        {
				int r_int = rand() % 20;
                                DesiccantCounter = (UA_Float) atof(xmlNodeGetContent(curr_node)) + r_int;
                                //printf("DesiccantCounter node found : %f\n", DesiccantCounter);
                        }
			//end <Diagnostic> section
			else if (strncmp(curr_node->name, "Alarms",6) == 0)
			{
				// here only check the node <Data>-><Alarms>
				// xmlNodeGetContent() : from libxml2
				NoOfAlarmsNode = (UA_Int16) atoi(xmlNodeGetContent(curr_node));
				NoOfAlarms = NoOfAlarmsNode;		// update to global variable
					//printf("line 487 : NoOfAlarmsNode = %d, NodeName = %s \n", NoOfAlarmsNode, curr_node->name);

				if (NoOfAlarmsNode > 0)		// check for NULL pointer
				{
					//printf("491: NoOfAlarmsNode = %d \n", NoOfAlarmsNode);
					//printf("in IF section: %s\n", xmlNodeGetContent(curr_node)); // value = 1 : correct <Alarms>1</Alarms>

					alarm_node = curr_node;
					//printf("1. After alarm_node = curr_node: %s \n", alarm_node->name); // value = Alarms : correct 
					alarm_node = alarm_node->next; // advance pointer to <Alarm> node
					//printf("2. After alarm_node = alarm_node->next: %s \n", alarm_node->name); // value = text : wrong } 
					//printf("2a. xmlNodeGetContent is %s \n", (char *)xmlNodeGetContent(alarm_node));
					alarm_node = alarm_node->next; 
					//printf("3.  After advance : node name is <%s> \n", alarm_node->name);		// value = Alarm : correct

					alarm_childnode = alarm_node;
					for (int i=0; i < NoOfAlarmsNode; i++)
					{
						// <Alarms>1</Alarms>
						// <Alarm>		<== alarm_node
						//   <Tag>CWA1</Tag>
						//   <Name>CWA1</Name>
						//   <Probability>3.3<//Probability>
						//   <CASnumber>123-4</CASnumber>
						//   <Concentration>3</Concentration>
						// </Alarm>

						alarm_childnode = alarm_node->children;
						//printf("line 515: Inspect alarm_childnode \n");

						alarm_childnode = alarm_childnode->next; // jump over text
						//printf("TAG: <%s> %s \n", alarm_childnode->name, (char *)xmlNodeGetContent(alarm_childnode));	// TAG
						strncpy(arrayOfAlarm[i].Tag, xmlNodeGetContent(alarm_childnode), 254); // extract the value from node : <Tag>
						alarm_childnode = alarm_childnode->next;

						alarm_childnode = alarm_childnode->next; // jump over text
                                                //printf("NAME: <%s> %s \n", alarm_childnode->name, (char *)xmlNodeGetContent(alarm_childnode));   // NAME
                                                strncpy(arrayOfAlarm[i].Name, xmlNodeGetContent(alarm_childnode), 254); // extract the value from node  <Name>
                                                alarm_childnode = alarm_childnode->next;

						alarm_childnode = alarm_childnode->next; // jump over text
                                                //printf("PROBABILITY: <%s> %f \n", alarm_childnode->name, (UA_Float)atof(xmlNodeGetContent(alarm_childnode)));
                                                arrayOfAlarm[i].Probability, (float)atof(xmlNodeGetContent(alarm_childnode)); // extract the value from node : <Probability>
                                                alarm_childnode = alarm_childnode->next;

						alarm_childnode = alarm_childnode->next; // jump over text
                                                //printf("CASnumber: <%s> %s \n", alarm_childnode->name, (char *)xmlNodeGetContent(alarm_childnode));   // CASnumber
                                                strncpy(arrayOfAlarm[i].CASnumber, (char *)xmlNodeGetContent(alarm_childnode), 254); // extract the value from node : <CASnumber>
                                                alarm_childnode = alarm_childnode->next;

						alarm_childnode = alarm_childnode->next; // jump over text
                                                //printf("CONCENTRATION: <%s> %d \n", alarm_childnode->name, (int)atoi(xmlNodeGetContent(alarm_childnode)));   // Concentration
                                                arrayOfAlarm[i].Concentration =(int)atoi( xmlNodeGetContent(alarm_childnode)); // extract the value from node : <AlarmConcentration>
						//printf("===================================\n");

						if ((i+1) < NoOfAlarmsNode)
						{
							// printf("check the position of alarm_childnode : %s %s \n", alarm_childnode->name, (char *)xmlNodeGetContent(alarm_childnode));
							alarm_childnode = alarm_childnode->next; // jump over </Concentration>
							alarm_childnode = alarm_childnode->next; // jump over </Alarm>

							// repeat the cycle for the next <Alarm> segment
							alarm_node = alarm_node->next;		// jump over text
							alarm_node = alarm_node->next;		// advance pointer to next node : <Alarm>
							//printf("check the position of alarm_node : %s %s \n", alarm_node->name, (char *)xmlNodeGetContent(alarm_node)); // correct : <Alarm>
						}
						else
							break;// exit FOR loop

					}
					//printf("Alarms node found in extract_element_names()\n");
					//printf("----No of alarms discovered : <Data> -> <Alarms>%d<Alarms>---- : %d\n", NoOfAlarmsNode, NoOfAlarmsNode);
				}
				else printf("Did not enter IF loop (Alarms)\n");
			}
			else if (strncmp(curr_node->name, "NonAlarms",9) == 0)
			{
				// here only check the node <Data>-><NonAlarms>
				// xmlNodeGetContent() : from libxml2
				NoOfNonAlarmsNode = (UA_Int16) atoi(xmlNodeGetContent(curr_node));
				NoOfNonAlarms = NoOfNonAlarmsNode;            // update to global variable
					//printf("line 578 : NoOfNonAlarmsNode = %d, NodeName = %s \n", NoOfNonAlarmsNode, curr_node->name);

				if (NoOfNonAlarmsNode > 0)                         // check for NULL pointer
				{
					//printf("582: NoOfNonAlarmsNode = %d \n", NoOfNonAlarmsNode);
					//printf("in IF section: %s\n", xmlNodeGetContent(curr_node)); // value = 1 : correct <NonAlarms>1</NonAlarms>

					nonalarm_node = curr_node;                 // use a new pointer to traverse the alarms segment; start at <NonAlarms>
					//printf("1. After nonalarm_node = curr_node: %s \n", nonalarm_node->name);     // value = Alarms : correct
					nonalarm_node = nonalarm_node->next;          // advance pointer to <Alarm> node
					//printf("2. After nonalarm_node = nonalarm_node->next: %s \n", nonalarm_node->name);      // value = text : wrong
					//printf("2a. xmlNodeGetContent  is %s \n", (char *)xmlNodeGetContent(nonalarm_node));
					nonalarm_node = nonalarm_node->next;
					//printf("3.  After advance : node name is <%s> \n", nonalarm_node->name);           // value = NonAlarm : correct

					nonalarm_childnode = nonalarm_node;
					for (int i=0; i < NoOfNonAlarmsNode; i++)          //kiv: , alarm_childnode; i++)
					{
						// <NonAlarms>1</NonAlarms>
						// <NonAlarm>              <== nonalarm_node
						//   <Tag>CWA1</Tag>
						//   <Name>CWA1</Name>
						//   <Probability>3.3</Probability>
						//   <CASnumber>123-4</CASnumber>
						//   <Concentration>3</Concentration>
						// </NonAlarm>

						nonalarm_childnode = nonalarm_node->children;
						//printf("line 607: Inspect nonalarm_childnode \n");

						nonalarm_childnode = nonalarm_childnode->next; // jump over text
						//printf("TAG: <%s> %s \n", nonalarm_childnode->name, (char *)xmlNodeGetContent(nonalarm_childnode));           // TAG
						strncpy(arrayOfNonAlarm[i].Tag, xmlNodeGetContent(nonalarm_childnode), 254);  // extract the value from node : <Tag>
						nonalarm_childnode = nonalarm_childnode->next;

						nonalarm_childnode = nonalarm_childnode->next; // jump over text
						//printf("NAME: <%s> %s \n", nonalarm_childnode->name, (char *)xmlNodeGetContent(nonalarm_childnode));          // NAME
						strncpy(arrayOfNonAlarm[i].Name, (char*) xmlNodeGetContent(nonalarm_childnode), 254); // extract the value from node : <Name>
						nonalarm_childnode = nonalarm_childnode->next;

						nonalarm_childnode = nonalarm_childnode->next; // jump over text
						//printf("PROBABILITY: <%s> %f \n", nonalarm_childnode->name, (UA_Float)atof(xmlNodeGetContent(nonalarm_childnode))); 
						arrayOfNonAlarm[i].Probability =(float) atof(xmlNodeGetContent(nonalarm_childnode)); 
						nonalarm_childnode = nonalarm_childnode->next;

						nonalarm_childnode = nonalarm_childnode->next; // jump over text
						//printf("CASnumber: <%s> %s \n", nonalarm_childnode->name, (char *)xmlNodeGetContent(nonalarm_childnode));             // CASnumber
						strncpy(arrayOfNonAlarm[i].CASnumber, (char*) xmlNodeGetContent(nonalarm_childnode), 254);            // extract the value from node : <CASnumber>
						nonalarm_childnode = nonalarm_childnode->next;

						nonalarm_childnode = nonalarm_childnode->next; // jump over text
						//printf("CONCENTRATION: <%s> %d \n", nonalarm_childnode->name, (int)atoi(xmlNodeGetContent(nonalarm_childnode)));              // Concentration
						arrayOfNonAlarm[i].Concentration = (int)atoi(xmlNodeGetContent(nonalarm_childnode));
						//printf("=======================================\n");

						if ((i+1) < NoOfNonAlarmsNode)
						{
							//printf("check the position of nonalarm_childnode : %s %s \n", nonalarm_childnode->name, (char *)xmlNodeGetContent(nonalarm_childnode));
							nonalarm_childnode = nonalarm_childnode->next; // jump over </Concentration>
							nonalarm_childnode = nonalarm_childnode->next; // jump over </NonAlarm>

							// repeat the cycle for the next <NonAlarm> segment
							nonalarm_node = nonalarm_node->next;          // jump over text
							nonalarm_node = nonalarm_node->next;          // advance pointer to next node : <NonAlarm>
							//printf("check the position of nonalarm_node : %s %s \n", nonalarm_node->name, (char *)xmlNodeGetContent(nonalarm_node)); // correct : <NonAlarm>
						}
						else
							break; // exit FOR loop
					}
					//printf("NonAlarms node found in extract_element_names()\n");
					//printf("----No of non alarms discovered : <Data> -> <NonAlarms>%d<NonAlarms>---- : %d\n", NoOfNonAlarmsNode, NoOfNonAlarmsNode);
				}
				else printf("Did not enter IF loop (nonAlarms) \n");
			}
			ExtractXMLElementNames(curr_node->children);
		}
	}

    //printf("============================================================\n");
    //printf("Leaving ExtractXMLElementNames() \n");
    //printf("============================================================\n");
} // End extract_element_names()
