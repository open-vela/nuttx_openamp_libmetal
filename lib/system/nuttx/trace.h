/*
 * Copyright (c) 2018, Pinecone Inc. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file	nuttx/trace.h
 * @brief	nuttx libmetal trace definitions.
 */

#ifndef __METAL_TRACE__H__
#error "Include metal/trace.h instead of metal/nuttx/trace.h"
#endif

#ifndef __METAL_NUTTX_TRACE__H__
#define __METAL_NUTTX_TRACE__H__

#include <nuttx/rpmsg/rpmsg_note.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline void metal_nuttx_trace_binary_handler(const char *name,
						    const void *buf, size_t len)
{
	rpmsg_note_binary(name, buf, len);
}

static inline void metal_nuttx_trace_handler(const char *name,
					     const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	rpmsg_note_vprintf(name, true, format, ap);
	va_end(ap);
}

#ifdef __cplusplus
}
#endif

#endif /* __METAL_NUTTX_TRACE__H__ */
