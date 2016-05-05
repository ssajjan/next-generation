t1=$(ifconfig | grep -o qca0)
t2='qca0'

if [ "$t1" = "$t2" ]; then
  echo "eth0 up"
else
  echo "eth0 down"
fi


# cat /debug/mode0.sh-  
#!/bin/sh
let loop=1
slay hostapd
slay dhcpd
slay dhcpcd
slay wpa_supplicant
ifconfig qca1 destroy
ifconfig qca0 destroy
sleep 2
ifconfig

while true; do
echo "START**********************************************"  Loop $loop
slog2info -c
sloginfo -c > /dev/null

pidin -p io-pkt-v6-hc mem
#mount -T io-pkt -o wlan_config_path=/etc/wlan,con_mode=0 /lib/dll/devnp-qcwlan.so
mount -T io-pkt -o wlan_config_path=/etc/wlan,con_mode=0 /debug/dbg_pkg/lib/dll/devnp-qcwlan.so
sleep 4

t1=$(ifconfig | grep -o qca0)
t2='qca0'

if [ "$t1" = "$t2" ]; then
        echo "-------------Loaded PASS------------------"
else
        slog2info > /debug/slog2ino-reload.txt
        sloginfo > /debug/slogino-reload.txt
        echo "-------------FAIL to load------------------"
        exit 1
fi

ifconfig
pidin -p io-pkt-v6-hc mem
sleep 4
ifconfig qca1 destroy
sleep 4
ifconfig qca0 destroy
echo "\n-------------un-Loaded------------------"
ifconfig
let loop=loop+1
slog2info > /debug/slog2into-prev.txt
sloginfo > /debug/slogino-prev.txt
sleep 10
done
