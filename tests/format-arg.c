#include <stdio.h>

#include "ccattr.h"

#ifndef _CCATTR_HAVE_FORMAT
#	warning "SKIPTEST"
#endif

static const char *foo(const char *fstr) CCATTR_FORMAT_ARG(1);

static const char *foo(const char *fstr) {
	return fstr;
}

int main(void) {
	printf(foo("%s\n"), 11);

	return 0;
}
