#!/bin/sh
curtime=$(date "+%Y-%m-%d,%H:%M:%S")
git add ~/Document/Cpp/xtayex-CompetitivePrograming/
git commit -m $curtime
git push origin master
