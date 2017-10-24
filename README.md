# libtcfg
a tiny configure file parse library.

+ **lightweight** :suitable for embedded system
+ **portable** :just use stand c library function

## config file example

allow same config key name in diffrent group
```
[group1]  # parser will use this to allow the same key in multi group
key1 =  hello, world! # can add comment here
key2 =  12345
key3 =  3.14

[group2]  # parser will use this to allow the same key in multi group
key1 =  group2, key1 # can add comment here
key2 =  222
key3 =  333
```

## compile

Debian(Linux debian 3.16.0-4-586 #1 Debian 3.16.43-2+deb8u2 (2017-06-26) i686 GNU/Linux):
``` bash
$git clone https://github.com/edgar1470/libtcfg.git
$cd libtcfg
$make
$cd example
$./example
```
cross compile for Hi3518/Hi3516:
``` bash
$git clone https://github.com/edgar1470/libtcfg.git
$cd libtcfg
$make CROSS=arm-hisiv300-linux-
```
