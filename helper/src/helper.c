#include <stdio.h>
#include <fcntl.h>/*fopen()*/
#include <signal.h>/*signal()*/
#include <unistd.h>/*pause()*/
#include <syslog.h>

#define REPEAT_FOREVER while(1)
#define HELPER_PID_FILE "/var/run/helper_pid"

static void signal_handler(int dunno)
{
	switch(dunno){
	case SIGUSR1:
		syslog(LOG_DEBUG,
			"helper(pid:%u) signal(usr1) caught\n",getpid());
		sleep(10);
		system("uci commit");
		system("wifi up");
		break;
	default:
		syslog(LOG_DEBUG,
			"helper(pid:%u) has caught a unknown signal:%d\n",getpid(),dunno);
		break;
	}
	return;
}

int main(int argc,char *argv[])
{
	daemon(1,1);
	/* record its pid to /var/run/helper_pid */
	FILE *fp = NULL;
	while(!fp)
		fp = fopen(HELPER_PID_FILE,"w+");
	
	syslog(LOG_DEBUG, "helper(pid:%u) is ready\n",getpid());

	if(fp){
		fprintf(fp,"%u",getpid());
		fclose(fp);
	}
	
	signal(SIGUSR1,signal_handler);
	signal(SIGUSR2,signal_handler);
	
	/* enter mainloop */
	REPEAT_FOREVER{
		pause();
		continue;//nothing to do,but wait for a signal
	}
	
	return 0;
}
