/* Portable wrappers around CC extended attributes
 * (c) 2011 Michał Górny
 * 2-clause BSD-licensed
 */

#pragma once
#ifndef _CCATTR_H
#define _CCATTR_H

/**
 * SECTION: ccattr
 * @short_description: macros to use CC attributes portably
 * @include: ccattr.h
 *
 * ccattr is a simple header file which directly checks for various extended CC
 * attributes and exports them via macros in a portable manner.
 *
 * Right now, ccattr supports GCC & clang compilers.
 */

#ifdef __has_attribute /* clang */
#	if __has_attribute(constant) /* XXX: we can't use const... */
#		define _CCATTR_HAVE_CONST
#	endif
#	if __has_attribute(noreturn)
#		define _CCATTR_HAVE_NORETURN
#	endif
#	if __has_attribute(returns_twice)
#		define _CCATTR_HAVE_RETURNS_TWICE
#	endif
#	if __has_attribute(unused)
#		define _CCATTR_HAVE_UNUSED
#	endif
#	if __has_attribute(used)
#		define _CCATTR_HAVE_USED
#	endif
#	if __has_attribute(pure)
#		define _CCATTR_HAVE_PURE
#	endif
#	if __has_attribute(malloc)
#		define _CCATTR_HAVE_MALLOC
#	endif
#	if __has_attribute(warn_unused_result)
#		define _CCATTR_HAVE_WARN_UNUSED_RESULT
#	endif
#	if __has_attribute(sentinel)
#		define _CCATTR_HAVE_SENTINEL
#	endif
#else /* !__has_attribute -- gcc */
#	if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 5)
#		define _CCATTR_HAVE_CONST
#		define _CCATTR_HAVE_NORETURN
#		define _CCATTR_HAVE_RETURNS_TWICE /* XXX: check version */
#		define _CCATTR_HAVE_UNUSED
#		define _CCATTR_HAVE_USED
#	endif
#	if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 96)
#		define _CCATTR_HAVE_PURE
#		define _CCATTR_HAVE_MALLOC
#	endif
#	if __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#		define _CCATTR_HAVE_WARN_UNUSED_RESULT
#	endif
#	if __GNUC__ >= 4
#		define _CCATTR_HAVE_SENTINEL
#	endif
#endif /* __has_attribute */

/**
 * CCATTR_CONST
 *
 * Declare a function as `const'. This means that the function does not examine
 * any values except its parameters and has no effects except its return value.
 *
 * Const function must not access memory referenced by its arguments as well.
 * It must not call non-const functions (including malloc()).
 */
#ifdef _CCATTR_HAVE_CONST
#	define CCATTR_CONST __attribute__((const))
#else
#	define CCATTR_CONST
#endif

/**
 * CCATTR_PURE
 *
 * Declare a function as `pure'. This means that the function does not examine
 * any values except its parameters and global variables, and has no effects
 * except its return value.
 */
#ifdef _CCATTR_HAVE_PURE
#	define CCATTR_PURE __attribute__((pure))
#else
#	define CCATTR_PURE
#endif

/**
 * CCATTR_MALLOC
 *
 * Declare a function as `malloc'. This means that the function always returns
 * a pointer to memory which is guaranteed not to alias (IOW, a newly-allocated
 * memory) or %NULL.
 */
#ifdef _CCATTR_HAVE_MALLOC
#	define CCATTR_MALLOC __attribute__((malloc))
#else
#	define CCATTR_MALLOC
#endif

/**
 * CCATTR_WARN_UNUSED_RESULT
 *
 * Declare a function as `warn_unused_result'. This means that the compiler will
 * warn whenever the function result is not used.
 */
#ifdef _CCATTR_HAVE_WARN_UNUSED_RESULT
#	define CCATTR_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
#	define CCATTR_WARN_UNUSED_RESULT
#endif

/**
 * CCATTR_NORETURN
 *
 * Declare a function as `return'. This means that the function does not ever
 * return (e.g. uses exit(), exec*() or a similar function).
 */
#ifdef _CCATTR_HAVE_NORETURN
#	define CCATTR_NORETURN __attribute__((noreturn))
#else
#	define CCATTR_NORETURN
#endif

/**
 * CCATTR_RETURNS_TWICE
 *
 * Declare a function as `returns_twice'. This means that the function may
 * return more than once, e.g. setjmp(), fork().
 */
#ifdef _CCATTR_HAVE_RETURNS_TWICE
#	define CCATTR_RETURNS_TWICE __attribute__((returns_twice))
#else
#	define CCATTR_RETURNS_TWICE
#endif

/**
 * CCATTR_UNUSED
 *
 * Declare a function as `unused'. This means that the function may not be used
 * at all and compiler should not warn about it.
 */
#ifdef _CCATTR_HAVE_UNUSED
#	define CCATTR_UNUSED __attribute__((unused))
#else
#	define CCATTR_UNUSED
#endif

/**
 * CCATTR_USED
 *
 * Declare a function as `used'. This means that the function code must be
 * generated even if it appears to be unused.
 */
#ifdef _CCATTR_HAVE_USED
#	define CCATTR_USED __attribute__((used))
#else
#	define CCATTR_USED
#endif

/**
 * CCATTR_SENTINEL
 *
 * Declare a variadic function as `sentinel'. This means that the variadic
 * argument list must be terminated with an explicit %NULL.
 */
#ifdef _CCATTR_HAVE_SENTINEL
#	define CCATTR_SENTINEL __attribute__((sentinel))
#else
#	define CCATTR_SENTINEL
#endif

#endif /*_CCATTR_H*/
