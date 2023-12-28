#include <stdio.h>
#include <modbus/modbus.h>
#include <errno.h>

int initialiseModbusConnection(modbus_t *ctx, char* ipaddress);
int readModbusData(modbus_t *ctx, uint16_t *);
void closeModbusConnection(modbus_t *ctx);


int initialiseModbusConnection(modbus_t *ctx, char* ipaddress)
{
  int errno;
  ctx = modbus_new_tcp(ipaddress, MODBUS_TCP_DEFAULT_PORT);
  if (ctx == NULL)
  {
	fprintf(stderr, "Unable to allocate libmodbus context : %s\n");
  	return -1;
  }
  if (modbus_connect(ctx)==-1)
  {
	fprintf(stderr, "SV_Modbus.c :: Connection failed: %s\n", modbus_strerror(errno));
	modbus_free(ctx);
	return -1;
  }
  else
  {
	printf("initialiseModbusConnection() :: success \n");
	return 0;
  }
}

int readModbusData(modbus_t *mb, uint16_t *tab_reg)
{
  //uint16_t tab_reg[32];

  /* Read 5 registers from the address 0 */
  if (mb)
  {
  	modbus_read_registers(mb, 0, 5, tab_reg);
	return 0;
  }
  else return -1;
}

void closeModbusConnection(modbus_t *mb)
{

  if (mb != NULL)
  {
  	modbus_close(mb);
  	modbus_free(mb);
  }
}
