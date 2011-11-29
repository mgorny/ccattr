#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>
#include <setjmp.h>

#include "ccattr.h"

static const char *foo(const char *fstr) CCATTR_FORMAT_ARG(1) CCATTR_MALLOC;
static void fooexit(void) CCATTR_NORETURN;
static void foomp(void) CCATTR_RETURNS_TWICE;
static const char *foosprintf(int bufx, int bufy, const char *fstr, ...)
		CCATTR_PRINTF(3, 4) CCATTR_ALLOC_SIZE2(1,2);
static int foolist(const char *a, ...) CCATTR_SENTINEL CCATTR_WARN_UNUSED_RESULT;

static int sum(int a, int b) CCATTR_CONST CCATTR_UNUSED CCATTR_DEPRECATED;
static int sumgl(int a) CCATTR_PURE CCATTR_USED CCATTR_DEPRECATED_WITH_MESSAGE("testz");

static const char *foo(const char *fstr) {
	return strdup(fstr);
}

static void fooexit(void) {
	exit(0);
	assert(!"NOT REACHED");
}

static jmp_buf jb;

static void foomp(void) {
	setjmp(jb);
}

static const char *foosprintf(int bufx, int bufy, const char *fstr, ...) {
	va_list ap;
	char *buf = calloc(bufx, bufy);
	assert(buf);

	va_start(ap, fstr);
	vsprintf(buf, fstr, ap);
	va_end(ap);

	return buf;
}

static int foolist(const char *a, ...) {
	va_list ap;
	const char *b;
	int n = 1;

	printf("%s:\n", a);
	va_start(ap, a);
	while ((b = va_arg(ap, const char*)))
		printf("%d. %s\n", n++, b);
	va_end(ap);

	return n;
}

static int sum(int a, int b) {
	return a+b;
}

static int reg = 0;

static int sumgl(int a) {
	reg += a;
	return reg;
}

int main(void) {
	foomp();
	printf(foo("%d\n"), 11);
	foosprintf(34, 7, "%s %d\n", "foo", 12);
	printf("%d\n", foolist("literki", "ab", "bc", "cd", NULL));

	fooexit();
	return 1;
}
