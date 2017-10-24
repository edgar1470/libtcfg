/*
 *      Copyright (c) 2016 edgar1470@gmail.com
 */
#ifndef _TCFG_H_
#define _TCFG_H_

#ifdef __cplusplus
extern "C"{
#endif


#define TCFG_CONFIG_FILE_MAX_SIZE       (32*1024)

typedef char tcfg_config_data_t;
typedef char tcfg_config_value_t;

tcfg_config_data_t *tcfg_get_section(const char *config_data, const char *section_name);
tcfg_config_data_t *tcfg_get_config_data(char *cFilename);
void tcfg_free_config_data(tcfg_config_data_t *config_data);
tcfg_config_value_t *tcfg_get_value(const char *config_data, const char *key, const char delimiter);
void tcfg_free_config_value(tcfg_config_value_t *setdata);
char * tcfg_get_lib_version(void);

#ifdef __cplusplus
}
#endif

#endif /* _TCFG_H_ */
