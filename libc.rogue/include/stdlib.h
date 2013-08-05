/*	$OpenBSD: stdlib.h,v 1.51 2012/12/03 20:08:33 millert Exp $	*/
/*	$NetBSD: stdlib.h,v 1.25 1995/12/27 21:19:08 jtc Exp $	*/

/*-
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)stdlib.h	5.13 (Berkeley) 6/4/91
 */

#ifndef _STDLIB_H_
#define _STDLIB_H_

#include <sys/cdefs.h>
#include <machine/_types.h>
#if __BSD_VISIBLE	/* for quad_t, etc. (XXX - use protected types) */
#include <sys/types.h>
#endif

#ifndef	_SIZE_T_DEFINED_
#define	_SIZE_T_DEFINED_
typedef	__size_t	size_t;
#endif

/* in C++, wchar_t is a built-in type */
#if !defined(_WCHAR_T_DEFINED_) && !defined(__cplusplus)
#define _WCHAR_T_DEFINED_
typedef	__wchar_t	wchar_t;
#endif

typedef struct {
	int quot;		/* quotient */
	int rem;		/* remainder */
} div_t;

typedef struct {
	long quot;		/* quotient */
	long rem;		/* remainder */
} ldiv_t;

#if __ISO_C_VISIBLE >= 1999
typedef struct {
	long long quot;		/* quotient */
	long long rem;		/* remainder */
} lldiv_t;
#endif

#if __BSD_VISIBLE
typedef struct {
	quad_t quot;		/* quotient */
	quad_t rem;		/* remainder */
} qdiv_t;
#endif


#ifndef	NULL
#ifdef 	__GNUG__
#define NULL	__null
#elif defined(__cplusplus)
#define	NULL	0L
#else
#define	NULL	((void *)0)
#endif
#endif

#define	EXIT_FAILURE	1
#define	EXIT_SUCCESS	0

#define	RAND_MAX	0x7fffffff

extern size_t	__mb_cur_max;
#define	MB_CUR_MAX	__mb_cur_max

#include <sys/cdefs.h>

/*
 * Some header files may define an abs macro.
 * If defined, undef it to prevent a syntax error and issue a warning.
 */
#ifdef abs
#undef abs
#warning abs macro collides with abs() prototype, undefining
#endif

__BEGIN_DECLS
void	*calloc(size_t, size_t);
void	 free(void *);
void	*malloc(size_t);

#endif /* _STDLIB_H_ */
