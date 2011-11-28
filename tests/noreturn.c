#include "../ccattr.h"

#ifndef _CCATTR_HAVE_NORETURN
#	warning "SKIPTEST"
#endif

static int foo(void) CCATTR_NORETURN;

/* Here we assume that a compiler will warn when func marked 'noreturn' does
 * actually try to return something. */
static int foo(void) {
	return 11;
}

int main(void) {
	foo();

	return 0;
}
