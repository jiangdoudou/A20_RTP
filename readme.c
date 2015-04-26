/*
* authro by jiangdou  QQ:344283973
* E-mail:jiangdouu88@126.com
* time at 2015-04-27
* sun4i-ts.c  为驱动文件，直接替换/drivers/input/touchscreen/sun4i-ts.c

*/

//how  get code? plase to 
git clone https://github.com/jiangdoudou/A20_RTP

一下编译在A20上编译的，

cd tslib


$ ./autogen.sh
$ ./configure --prefix=/usr
$ make     //此处错误，，export LC_ALL=en_US.UTF-8//export LANGUAGE=en_US:en
$ export LC_ALL=en_US.UTF-8//
$ export LANGUAGE=en_US:en

$ make install


/* manually add sunxi-ts to /etc/modules */
$ vi /etc/profile

export TSLIB_TSEVENTTYPE=raw
export TSLIB_CONSOLEDEVICE=none
export TSLIB_FBDEVICE=/dev/fb0
export TSLIB_TSDEVICE=/dev/input/event3 /* manually replace # by input number discovered by dmesg command */
export TSLIB_CALIBFILE=/usr/etc/pointercal  //次文件是ts_calibrate  校准后的文件，
export TSLIB_CONFFILE=/usr/etc/ts.conf
export TSLIB_PLUGINDIR=/usr/lib/ts

$ vi /usr/etc/ts.conf  //修改

# module_raw input //去掉#  


/* manually uncomment "module_raw_input" line from /usr/etc/ts.conf */

$ ts_calibrate  //校准用的

$ ts_test

$ cd xf86-input-tslib

./configure --prefix=/usr
make
make install



//配置X11

add this in the X- configuration:

Section “InputDevice”
Identifier “Sun4iTouchscreen”
Option “Device” “/dev/input/event3”
Driver “tslib”
Option “ScreenNumber” “0”
Option “Rotate” “NONE”
Option “Width” “800”
Option “Height” “480”
Option “SendCoreEvents” “yes”

EndSection

