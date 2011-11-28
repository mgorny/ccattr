#include <stdio.h>
#include <stdarg.h>

#include "../ccattr.h"

#ifndef _CCATTR_HAVE_FORMAT
#	warning "SKIPTEST"
#endif

static int foo(const char *fstr, ...) CCATTR_PRINTF(1, 2);

static int foo(const char *fstr, ...) {
	va_list ap;

	va_start(ap, fstr);
	vprintf(fstr, ap);
	va_end(ap);

	return 0;
}

int main(void) {
	foo("%s\n", 11);

	return 0;
}
