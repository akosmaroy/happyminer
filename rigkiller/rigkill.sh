#!/bin/bash

DEVICE=/dev/ttyUSB0

stty -F $DEVICE 0:0:8bd:0:3:1c:7f:15:4:0:0:0:11:13:1a:0:12:f:17:16:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0

echo "$@" > $DEVICE

