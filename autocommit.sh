#!/bin/sh
curtime=$(date "+%Y-%m-%d,%H:%M:%S")
git add .
git commit -m $curtime
git push origin master
