#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

static void __attribute__ ((constructor)) strip_env(void);
extern char **environ;

static void strip_env()
{
	char *c;
	int i = 0;
	for (i=0; environ[i] != NULL;i++ ) {
		c = strstr(environ[i],"=() {");
		if (c != NULL) {
			*(c+2) = '\0';
		}
	}
}
