/*
 * Copyright (c) 2015, Xilinx Inc. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdarg.h>
#include <stdio.h>

#include <metal/trace.h>
#include <metal/sys.h>

void metal_set_trace_handler(metal_trace_handler handler)
{
	_metal.common.trace_handler = handler;
}

metal_trace_handler metal_get_trace_handler(void)
{
	return _metal.common.trace_handler;
}

void metal_set_trace_binary_handler(metal_trace_binary_handler handler)
{
	_metal.common.trace_binary_handler = handler;
}

metal_trace_binary_handler metal_get_trace_binary_handler(void)
{
	return _metal.common.trace_binary_handler;
}
