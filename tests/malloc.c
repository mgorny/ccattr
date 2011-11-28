#include "ccattr.h"

#ifndef _CCATTR_HAVE_MALLOC
#	warning "SKIPTEST"
#endif

/* We're hoping here compiler gets 'malloc' correctly if it complains about
 * invalid return type. */
static int foo(void) CCATTR_MALLOC;

static int foo(void) {
	return 0;
}

int main(void) {
	foo();

	return 0;
}
