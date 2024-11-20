/*
 * Copyright (c) 2022, Xilinx Inc. and Contributors. All rights reserved.
 * Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All Rights Reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file	generic/xlnx_common/zynqmp_aarch64/sys.h
 * @brief	generic zynqmp_aarch64 system primitives for libmetal.
 */

#ifndef __METAL_GENERIC_SYS__H__
#error "Include metal/sys.h instead of metal/generic/@PROJECT_MACHINE@/sys.h"
#endif

#include <metal/system/@PROJECT_SYSTEM@/xlnx_common/sys.h>
#include "xscugic.h"

#ifndef __METAL_GENERIC_ZYNQMP_XLNX_COMMON_AARCH64_SYS__H__
#define __METAL_GENERIC_ZYNQMP_XLNX_COMMON_AARCH64_SYS__H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef METAL_INTERNAL

#define XLNX_MAXIRQS XSCUGIC_MAX_NUM_INTR_INPUTS

static inline void sys_irq_enable(unsigned int vector)
{
	XScuGic_EnableIntr(XPAR_SCUGIC_0_DIST_BASEADDR, vector);
}

static inline void sys_irq_disable(unsigned int vector)
{
	XScuGic_DisableIntr(XPAR_SCUGIC_0_DIST_BASEADDR, vector);
}

#endif /* METAL_INTERNAL */

#ifdef __cplusplus
}
#endif

#endif /* __METAL_GENERIC_ZYNQMP_XLNX_COMMON_AARCH64_SYS__H__ */
