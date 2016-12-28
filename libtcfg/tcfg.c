#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>

#include "tcfg.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define TCFG_DEBUG
#ifdef TCFG_DEBUG
#define log_error(fmt, args...) printf(ANSI_COLOR_RED"[%s,%d] "fmt ANSI_COLOR_RESET, __FUNCTION__, __LINE__, ##args)
#else
#define log_error(fmt, args...)
#endif

tcfg_config_value_t *tcfg_get_value(const char *config_data, const char *key, const char delimiter)
{
	char *keyValue = NULL;
	int setLen = 0;
	int valLen = 0;
	char *pstr = NULL;

	assert(config_data != NULL);
	assert(key != NULL);

	pstr = strstr(config_data, key);
	if (pstr == NULL) {
		log_error("can't find the key %s\n", key);
		return NULL;
	}
	setLen = strlen(key);
	pstr += setLen;
	if((pstr[0] != '=') && (pstr[0] != ' ')) {
		log_error("config format error\n");
		return NULL;
	}
	setLen = 0;
	while(pstr[valLen] != '\r' && pstr[valLen] != '\n')
	{
		if(pstr[valLen] == delimiter)
		{
			setLen = 1;
			break;
		}
		valLen++;
	}
	if(setLen < 1) {
		log_error("delimiter not found\n");
		return NULL;
	}
	pstr = strchr(pstr, delimiter);
	pstr++;
	valLen = 0;
	while(pstr[valLen] != '\r' && pstr[valLen] != '\n') {
		if(pstr[valLen] == '#') break;

		if(pstr[valLen] == ' ' && valLen == 0) {
			pstr++;
			continue;
		}
		valLen++;
		/* if(pstr[valLen] == ' ' || pstr[valLen] == '#') { */
		if(pstr[valLen] == '#') {
			break;
		}
	}

	if(valLen < 1) {
		log_error("no value found\n");
		return NULL;
	}

	keyValue = malloc ( valLen + 1);
	if(keyValue == NULL) {
		log_error("memory failed\n");
		return NULL;
	}

	memcpy(keyValue, pstr, valLen);
	keyValue[valLen] = 0;

	return keyValue;
}

void tcfg_free_config_value(tcfg_config_value_t *keyValue)
{
	if(keyValue) free(keyValue);
}

tcfg_config_data_t *tcfg_get_config_data(char *filename)
{
	tcfg_config_data_t *config_data;
	FILE *stream;
	long int filesize;
	int ret = 0;

	assert(filename != NULL);

	stream = fopen(filename, "rb");
	if(stream== NULL) {
		log_error("open %s failed\n", filename);
		return NULL;
	}

	ret = fseek(stream, 0, SEEK_END);
	if (ret != 0) {
		log_error("seek failed\n");
		fclose(stream);
		return NULL;
	}

	filesize = ftell(stream);
	if(filesize < 0) {
		log_error("ftell failed\n");
		fclose(stream);
		return NULL;
	}

	if (filesize > TCFG_CONFIG_FILE_MAX_SIZE) {
		log_error("config file is > %d\n", TCFG_CONFIG_FILE_MAX_SIZE);
		fclose(stream);
		return NULL;
	}
	rewind(stream);

	config_data = malloc((size_t)filesize * sizeof(char) + 1);
	if(config_data == NULL) {
		log_error("memory failed\n");
		fclose(stream);
		return NULL;
	}

	fread(config_data, (size_t)filesize, sizeof(char), stream);
	ret = ferror(stream);
	if(ret != 0) {
		log_error("read file failed\n");
		free(config_data);
		fclose(stream);
		return NULL;
	}
	config_data[filesize] = '\0';
	fclose(stream);

	return config_data;
}

void tcfg_free_config_data(tcfg_config_data_t *config_data)
{
	if(config_data) free(config_data);
}
