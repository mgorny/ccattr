#include "ccattr.h"

#ifndef _CCATTR_HAVE_DEPRECATED
#	warning "SKIPTEST"
#endif

static int foo(void) CCATTR_DEPRECATED_WITH_MESSAGE("bar baz?");

static int foo(void) {
	return 11;
}

int main(void) {
	foo();

	return 0;
}
