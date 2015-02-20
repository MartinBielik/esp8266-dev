/*
Some random cgi routines. Used in the LED example and the page that returns the entire
flash as a binary. Also handles the hit counter on the main page.
*/

/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Jeroen Domburg <jeroen@spritesmods.com> wrote this file. As long as you retain 
 * this notice you can do whatever you want with this stuff. If we meet some day, 
 * and you think this stuff is worth it, you can buy me a beer in return. 
 * ----------------------------------------------------------------------------
 */


#include <string.h>
#include <osapi.h>
#include "user_interface.h"
#include "mem.h"
#include "httpd.h"
#include "cgi.h"
#include "io.h"
#include <ip_addr.h>
#include "espmissingincludes.h"


static char currRelayLedState=0;

//Cgi that turns the LED on or off according to the 'led' param in the POST data
int ICACHE_FLASH_ATTR cgiRelay(HttpdConnData *connData) {
	int len;
	char buff[1024];

	
	if (connData->conn==NULL) {
		//Connection aborted. Clean up.
		return HTTPD_CGI_DONE;
	}

	len=httpdFindArg(connData->postBuff, "RelayLed", buff, sizeof(buff));
	if (len!=0) {
		currRelayLedState=atoi(buff);
		ioRelayLed(currRelayLedState);
	}

	httpdRedirect(connData, "index.tpl");
	return HTTPD_CGI_DONE;
}


void ICACHE_FLASH_ATTR tplRelay(HttpdConnData *connData, char *token, void **arg) {
	char buff[128];
	if (token==NULL) return;

	if (os_strcmp(token, "relay_state")==0) {
		os_sprintf(buff, "%d", currRelayLedState);
	}
	httpdSend(connData, buff, -1);
}


