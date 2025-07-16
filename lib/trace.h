/*
 * Copyright (c) 2016, Xilinx Inc. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file	trace.h
 * @brief	trace operation primitives for libmetal.
 */

#ifndef __METAL_TRACE__H__
#define __METAL_TRACE__H__

#ifdef __cplusplus
extern "C" {
#endif

/** trace message and binary handler type. */
typedef void (*metal_trace_handler)(const char *name,
				    const void *buf,
				    size_t len,
				    const char *format, ...);

/**
 * @brief	Set libmetal trace handler.
 * @param[in]	handler	trace message handler.
 * @return	0 on success, or -errno on failure.
 */
void metal_set_trace_handler(metal_trace_handler handler);

/**
 * @brief	Get the current libmetal trace handler.
 * @return	Current trace handler.
 */
metal_trace_handler metal_get_trace_handler(void);

/**
 * @brief	Emit a trace and binary message if the trace name permits.
 *
 * @param[in]	name	ept name for filter.
 * @param[in]	buf	buf for recording information
 * @param[in]	len	len for recording information
 * @param[in]	fmt	Format string.
 * @param[in]	...	Variable number of arguments.
 */
#define metal_trace(name, buf, len, fmt, ...) ({					\
	if (_metal.common.trace_handler)						\
		_metal.common.trace_handler(name, buf, len, fmt, ## __VA_ARGS__);	\
})

/** @} */

#ifdef __cplusplus
}
#endif

#include <metal/system/@PROJECT_SYSTEM@/trace.h>

#endif /* __METAL_TRACE__H__ */
