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
#else /* !__has_attribute -- gcc */
#	if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ > 4)
#		define _CCATTR_HAVE_CONST
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

#endif /*_CCATTR_H*/
