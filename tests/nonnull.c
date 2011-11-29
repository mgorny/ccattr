#include <stdlib.h>

#include "ccattr.h"

#ifndef _CCATTR_HAVE_NONNULL
#	warning "SKIPTEST"
#endif

static void foo(int *a, int *b) CCATTR_NONNULL((1,2));

static void foo(int *a, int *b) {
	*a = *b;
}

int main(void) {
	int c;

	foo(&c, NULL);

	return 0;
}
