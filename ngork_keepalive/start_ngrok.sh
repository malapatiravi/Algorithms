#!/bin/bash
cd /home/pi

declare -a output_ps_list

output_ps_list=()
echo "Hello"

for i in $(ps aux | awk '{print $11}' | grep /home/pi/ngrok); do
    echo $i;
    output_ps_list+=($i)
    # echo $i
done
echo ${#output_ps_list[@]};

if [ ${#output_ps_list[@]} -lt 1 ]; then
    echo "The session does not exist";
    python3 /home/pi/keep_alive.py
else
    echo "The session already exist no action taken"
fi





