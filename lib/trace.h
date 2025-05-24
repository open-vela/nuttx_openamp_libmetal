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

/** trace message handler type. */
typedef void (*metal_trace_handler)(const char *name,
				    const char *format, ...);

/** trace message handler type. */
typedef void (*metal_trace_binary_handler)(const char *name,
					   const void *buf,
					   size_t len);

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
 * @brief	Set libmetal trace binary handler.
 * @param[in]	handler	trace binary message handler.
 * @return	0 on success, or -errno on failure.
 */
void metal_set_trace_binary_handler(metal_trace_binary_handler handler);

/**
 * @brief	Get the current libmetal trace binary handler.
 * @return	Current trace binary handler.
 */
metal_trace_binary_handler metal_get_trace_binary_handler(void);

/**
 * @brief	Emit a trace message if the trace name permits.
 *
 * @param[in]	name	ept name for filter.
 * @param[in]	fmt	Format string.
 * @param[in]	...	Variable number of arguments.
 */
#define metal_trace(name, fmt, ...) ({					\
	if (_metal.common.trace_handler) 				\
		_metal.common.trace_handler(name, fmt, ## __VA_ARGS__);	\
})

/** \defgroup trace binary Interfaces
 *  @{
 */

/**
 * @brief      Record binary information
 *
 * @param[in]	name	ept name for filter
 * @param[in]	buf	buf for recording information
 * @param[in]	len	len for recording information
 */
#define metal_trace_binary(name, buf, len) ({				\
	if (_metal.common.trace_binary_handler)				\
		_metal.common.trace_binary_handler(name, buf, len);	\
})

/** @} */

#ifdef __cplusplus
}
#endif

#include <metal/system/@PROJECT_SYSTEM@/trace.h>

#endif /* __METAL_TRACE__H__ */
