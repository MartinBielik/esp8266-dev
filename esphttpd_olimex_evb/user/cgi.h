#ifndef CGI_H
#define CGI_H

#include "httpd.h"

int cgiRelay(HttpdConnData *connData);
void tplRelay(HttpdConnData *connData, char *token, void **arg);

#endif