#include <stdlib.h>
#include <stdarg.h>

#include "../ccattr.h"

#ifndef _CCATTR_HAVE_SENTINEL
#	warning "SKIPTEST"
#endif

static int foo(int a, ...) CCATTR_SENTINEL;

static int foo(int a, ...) {
	va_list ap;

	va_start(ap, a);
	while (va_arg(ap, const char*));
	va_end(ap);

	return a;
}

int main(void) {
	foo(12, "ab", "bc", "cd");

	return 0;
}
