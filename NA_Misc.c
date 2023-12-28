#include "open62541.h"
#include <stdio.h>
#include <string.h>
#include <libxml2/libxml/parser.h>
#include <libxml2/libxml/tree.h>
#include <libxml2/libxml/xmlreader.h>

xmlNodePtr srSeekChildNodeNamed(xmlNode* p, char* name, int len);
UA_ByteString loadFile(const char *const path);

xmlNodePtr srSeekChildNodeNamed(xmlNode* p, char* name, int len)
{
	xmlNodePtr curr_node;

	if (p == NULL || name == NULL)
		return NULL;
	for (curr_node = p; curr_node; curr_node = curr_node->next)
	{
		printf("In for loop : curr_node content : %s\n", (char*)xmlNodeGetContent(curr_node));

		printf("In the loop : (Len=%d) Comparing <curr_node->name> with <name> | %s : %s \n", len, curr_node->name, name);
		if (strncmp(curr_node->name, name, len) == 0)	// look for xmlNode with tag = <name>
		{
			// found seatch string <name>
			printf("----------------Found In srSeekChildNodeNamed() [line 195] : searching for %s, found %s; returning the xmlNodePtr\n", name, curr_node->name);
			return curr_node;
		}
	}
}

// sample found in /open62541/examples/common.h
// parses the certificate file - used in NA_mainOPCUAClient.c
UA_ByteString loadFile(const char *const path)
{
    UA_ByteString fileContents = UA_STRING_NULL;

    /* Open the file */
    FILE *fp = fopen(path, "rb");
    if(!fp) {
        errno = 0; /* We read errno also from the tcp layer... */
        return fileContents;
    }

    /* Get the file length, allocate the data and read */
    fseek(fp, 0, SEEK_END);
    fileContents.length = (size_t)ftell(fp);
    fileContents.data = (UA_Byte *)UA_malloc(fileContents.length * sizeof(UA_Byte));
    if(fileContents.data) {
        fseek(fp, 0, SEEK_SET);
        size_t read = fread(fileContents.data, sizeof(UA_Byte), fileContents.length, fp);
        if(read != fileContents.length)
            UA_ByteString_clear(&fileContents);
    } else {
        fileContents.length = 0;
    }
    fclose(fp);

    return fileContents;
}


/*
UA_ByteString loadFile(char* filename)
{
	int filesize = 0;
	UA_Byte* filecontent;
	FILE* fp;

	fp = fopen(filename, "r");
	fseek(fp, 0L, SEEK_END);
	filesize = ftell(fp) + 1;
	rewind(fp);

	filecontent = (UA_Byte*)calloc(filesize, sizeof(char));
	fread(filecontent, sizeof(char), filesize, fp);

	UA_ByteString output;
	output.length = filesize;
	output.data = filecontent;

	return output;

}
*/
