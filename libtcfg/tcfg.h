#ifndef _TCFG_H_
#define _TCFG_H_

#ifdef __cplusplus
extern "C"{
#endif


#define TCFG_CONFIG_FILE_MAX_SIZE	(32*1024)

#define TCFG_NO_ERROR  0
#define TCFG_ERROR     1

typedef char tcfg_config_data_t;
typedef char tcfg_config_value_t;

tcfg_config_data_t *tcfg_get_config_data(char *cFilename);
void tcfg_free_config_data(tcfg_config_data_t *config_data);
tcfg_config_value_t *tcfg_get_value(const char *config_data, const char *key, const char delimiter);
void tcfg_free_config_value(tcfg_config_value_t *setdata);

#ifdef __cplusplus
}
#endif

#endif /* _TCFG_H_ */
