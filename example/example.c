#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "tcfg.h"

#define CFG_FILE "example.conf"

int main(int argc, char *argv[])
{
	tcfg_config_data_t *config_data;
	tcfg_config_value_t  *cfg_value1;
	tcfg_config_value_t  *cfg_value2;
	tcfg_config_value_t  *cfg_value3;

	int   cValue2;
	float cValue3;

	if (argc == 2) {
		config_data = tcfg_get_config_data(argv[1]);
	} else {
		config_data = tcfg_get_config_data(CFG_FILE);
	}
	if(config_data == NULL)
	{
		printf("failed to get config data\n");
		return -1;
	}

	cfg_value1 = tcfg_get_value(config_data, "key1", '=');
	if(cfg_value1 == NULL)
	{
		printf("failed to get key1\n");
		return -1;
	}

	cfg_value2 = tcfg_get_value(config_data, "key2", '=');
	if(cfg_value2 == NULL)
	{
		printf("failed to get key2\n");
		return -1;
	}

	cfg_value3 = tcfg_get_value(config_data, "key3", '=');
	if(cfg_value3 == NULL)
	{
		printf("failed to get key3\n");
		return -1;
	}

	tcfg_free_config_data( config_data );
	cValue2 = atoi(cfg_value2);
	cValue3 = atof(cfg_value3);
	tcfg_free_config_value( cfg_value2 );
	tcfg_free_config_value( cfg_value3 );
	printf("Results:\n"
			"\tcfg_value1\t->\t%s\t# value type is char\n"
			"\tcfg_value2\t->\t%d\t# value type is integer\n"
			"\tcfg_value3\t->\t%f\t# valu etype is float\n", 
			cfg_value1,
			cValue2,
			cValue3
	      );

	tcfg_free_config_value( cfg_value1 );

	return 0;
}
