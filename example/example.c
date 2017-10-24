/*
 *      Copyright (c) 2016 edgar1470@gmail.com
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "tcfg.h"

#define DEFAULT_CFG_FILE "example.conf"

#define KEY_NAME_DELIMITER_CHAR         '='
#define KEY_NAME_SECTION_GROUP_1        "group1"
#define KEY_NAME_SECTION_GROUP_2        "group2"
#define KEY_NAME_KEY1                   "key1"
#define KEY_NAME_KEY2                   "key2"
#define KEY_NAME_KEY3                   "key3"

int main(int argc, char *argv[])
{
        tcfg_config_data_t *config_data;
        tcfg_config_data_t *config_data_section;
        tcfg_config_value_t  *cfg_value1;
        tcfg_config_value_t  *cfg_value2;
        tcfg_config_value_t  *cfg_value3;
        int   cValue2;
        float cValue3;

        printf("libtcfg version: %s\n", tcfg_get_lib_version());

        if (argc == 2) {
                config_data = tcfg_get_config_data(argv[1]);
        } else {
                config_data = tcfg_get_config_data(DEFAULT_CFG_FILE);
        }
        if(config_data == NULL) {
                printf("failed to get config data\n");
                return -1;
        }

        /* parse group1 configure */
        config_data_section = tcfg_get_section(config_data, KEY_NAME_SECTION_GROUP_1);
        if (config_data_section == NULL) {
                printf("can't find the section [%s]\n", KEY_NAME_SECTION_GROUP_1);
                return -1;
        }
        cfg_value1 = tcfg_get_value(config_data_section, KEY_NAME_KEY1, KEY_NAME_DELIMITER_CHAR);
        if(cfg_value1 == NULL) {
                printf("failed to get the key value [%s]\n", KEY_NAME_KEY1);
                return -1;
        }

        cfg_value2 = tcfg_get_value(config_data_section, KEY_NAME_KEY2, KEY_NAME_DELIMITER_CHAR);
        if(cfg_value2 == NULL) {
                printf("failed to get the key value [%s]\n", KEY_NAME_KEY2);
                return -1;
        }

        cfg_value3 = tcfg_get_value(config_data_section, KEY_NAME_KEY3, KEY_NAME_DELIMITER_CHAR);
        if(cfg_value3 == NULL) {
                printf("failed to get the key value [%s]\n", KEY_NAME_KEY3);
                return -1;
        }

        cValue2 = atoi(cfg_value2);
        cValue3 = atof(cfg_value3);
        printf("%s:\n"
                        "\tcfg_value1\t->\t%s\t# value type is char\n"
                        "\tcfg_value2\t->\t%d\t# value type is integer\n"
                        "\tcfg_value3\t->\t%f\t# valu etype is float\n",
                        KEY_NAME_SECTION_GROUP_1,
                        cfg_value1,
                        cValue2,
                        cValue3
              );

        tcfg_free_config_value( cfg_value1 );
        tcfg_free_config_value( cfg_value2 );
        tcfg_free_config_value( cfg_value3 );

        /* parse group2 configure */
        config_data_section = tcfg_get_section(config_data, KEY_NAME_SECTION_GROUP_2);
        if (config_data_section == NULL) {
                printf("can't find the section [%s]\n", KEY_NAME_SECTION_GROUP_1);
                return -1;
        }
        cfg_value1 = tcfg_get_value(config_data_section, KEY_NAME_KEY1, KEY_NAME_DELIMITER_CHAR);
        if(cfg_value1 == NULL) {
                printf("failed to get the key value [%s]\n", KEY_NAME_KEY1);
                return -1;
        }

        cfg_value2 = tcfg_get_value(config_data_section, KEY_NAME_KEY2, KEY_NAME_DELIMITER_CHAR);
        if(cfg_value2 == NULL) {
                printf("failed to get the key value [%s]\n", KEY_NAME_KEY2);
                return -1;
        }

        cfg_value3 = tcfg_get_value(config_data_section, KEY_NAME_KEY3, KEY_NAME_DELIMITER_CHAR);
        if(cfg_value3 == NULL) {
                printf("failed to get the key value [%s]\n", KEY_NAME_KEY3);
                return -1;
        }

        cValue2 = atoi(cfg_value2);
        cValue3 = atof(cfg_value3);
        printf("%s:\n"
                        "\tcfg_value1\t->\t%s\t# value type is char\n"
                        "\tcfg_value2\t->\t%d\t# value type is integer\n"
                        "\tcfg_value3\t->\t%f\t# valu etype is float\n",
                        KEY_NAME_SECTION_GROUP_2,
                        cfg_value1,
                        cValue2,
                        cValue3
              );

        tcfg_free_config_value( cfg_value1 );
        tcfg_free_config_value( cfg_value2 );
        tcfg_free_config_value( cfg_value3 );

        tcfg_free_config_data( config_data );

        return 0;
}
