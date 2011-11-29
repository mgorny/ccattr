ACLOCAL_AMFLAGS = -I m4
DISTCHECK_CONFIGURE_FLAGS = --enable-gtk-doc

SUBDIRS = doc

TESTS_ENVIRONMENT = $(top_srcdir)/tests/run-test $(CC) $(CFLAGS) \
	-I$(top_srcdir)/src -Wall

TESTS = $(top_srcdir)/tests/malloc.c \
	$(top_srcdir)/tests/warn-unused-result.c \
	$(top_srcdir)/tests/noreturn.c \
	$(top_srcdir)/tests/sentinel.c \
	$(top_srcdir)/tests/printf.c \
	$(top_srcdir)/tests/format-arg.c \
	$(top_srcdir)/tests/deprecated.c \
	$(top_srcdir)/tests/deprecated-with-message.c \
	$(top_srcdir)/tests/all-ok.c
XFAIL_TESTS = $(top_srcdir)/tests/all-ok.c

EXTRA_DIST = tests/run-test

include_HEADERS = src/ccattr.h
