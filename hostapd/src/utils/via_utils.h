#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 1239
#define MAX_BUF_SIZE 1024

int sockfd4ReportStaInfo;
struct sockaddr_in udpAddr;

/*
typedef enum{
	STA_CONNECTED,		
	STA_DISCONNECTED,	
	STA_DEAUTH_ENFORCE,
	STA_RETRY_LIMIT,	
	STA_NUMBER_LIMIT,	
}STA_STATUS;

typedef struct{
	//char MACAddr[19];
	unsigned char MACAddr[6];
	char ssid[32];
	char mode[13];
	unsigned char channel;
	int frequency;
	STA_STATUS status;
}CWStationInformation;
*/
