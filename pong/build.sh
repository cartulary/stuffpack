#/usr/bin/env sh
make $@ 2>&1|grep -v "/usr/"|grep -v "contrib/"