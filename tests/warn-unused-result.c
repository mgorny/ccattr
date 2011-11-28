#include "../ccattr.h"

#ifndef _CCATTR_HAVE_WARN_UNUSED_RESULT
#	warning "SKIPTEST"
#endif

static int foo(void) CCATTR_WARN_UNUSED_RESULT;

static int foo(void) {
	return 11;
}

int main(void) {
	foo();

	return 0;
}
