/*
 * Copyright (c) 2018, Pinecone Inc. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file	nuttx/log.h
 * @brief	NuttX libmetal log handler definition.
 */

#ifndef __METAL_METAL_LOG__H__
#error "Include metal/log.h instead of metal/nuttx/log.h"
#endif

#ifndef __METAL_NUTTX_LOG__H__
#define __METAL_NUTTX_LOG__H__

#include <stdarg.h>
#include <syslog.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline void metal_nuttx_log_handler(enum metal_log_level level,
					   const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	vsyslog(level, format, ap);
	va_end(ap);
}

#ifdef __cplusplus
}
#endif

#endif /* __METAL_NUTTX_LOG__H__ */
