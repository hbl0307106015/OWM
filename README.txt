hostapd dev from hostapd-20121209 in OpenWrt

20121201
	added new function:
	reporting station information to AC via udp socket.
20121228
	added new function:
	add auto channel support
	
	in the meanwhile:
	helper app should start up while system is booted.
	/lib/wifi/mac80211.sh should be modified.

	add a repo at github.
	tfa-hostapd ( tymon flaming adventure hostapd )










Note:

helper		:modified at package/helper
mac80211.sh	:modified at package/mac80211/files/lib/wifi/mac80211.sh 
		 and it will be seen at /lib/wifi/ in OpenWrt file system.