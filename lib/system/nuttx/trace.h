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

#include <metal/utilities.h>
#include <nuttx/rpmsg/rpmsg.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline void metal_nuttx_trace_handler(const char *name,
					     const void *buf, size_t len,
					     const char *format, ...)
{
#ifdef CONFIG_RPMSG_NOTE
	va_list ap;

	va_start(ap, format);
	rpmsg_note_vtrace(name, true, buf, len, format, ap);
	va_end(ap);
#else
	metal_unused(name);
	metal_unused(buf);
	metal_unused(len);
	metal_unused(format);
#endif
}

#ifdef __cplusplus
}
#endif

#endif /* __METAL_NUTTX_TRACE__H__ */
