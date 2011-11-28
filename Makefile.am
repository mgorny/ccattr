ACLOCAL_AMFLAGS = -I m4
DISTCHECK_CONFIGURE_FLAGS = --enable-gtk-doc

SUBDIRS = doc

TESTS_ENVIRONMENT = $(top_srcdir)/tests/run-test $(CC) $(CFLAGS) -Wall

TESTS = tests/malloc.c tests/warn-unused-result.c tests/noreturn.c \
	tests/sentinel.c tests/printf.c tests/format-arg.c

include_HEADERS = ccattr.h
