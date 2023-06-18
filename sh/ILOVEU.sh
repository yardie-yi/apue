#!/bin/bash

read -p "你是谁呀：" name
if [ "$name" = "HJW" ] || [ "$name" = "胡靖雯" ];then
	echo "原来是宝宝呀！超爱你哦，看我给你画个心心~~~~~"
else
	echo "不认识！！！再见！"
	exit
fi

t=0.5
for ((x=0; x<=4; x++)); do
    var1="     "
    var2="#####"
    for((y=0; y<=x; y++)); do
        var1="${var1:1}"
    done
    for((y=0; y<=x; y++)); do
        var2="${var2}##"
    done
    echo -e "\033[31m$var1$var2$var1$var1$var2\033[0m"
    sleep $t
done
echo -e "\033[31m######## YWM LOVE HJW ########\033[0m"
sleep $t
echo -e "\033[31m##############################\033[0m"
sleep $t
for((x=0; x<=13; x++)); do
    var1=""
    var2="##############################"
    for((y=0; y<=x; y++)); do
        var2="${var2:2}"
    done
    for((y=0; y<=x; y++)); do
        var1="${var1} "
    done
    if [ $((x % 2)) -ne 0 ];then
        echo -e "\033[31m$var1$var2\033[0m"
        sleep $t
    fi
done
