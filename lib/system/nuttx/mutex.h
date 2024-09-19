/*
 * Copyright (c) 2018, Pinecone Inc. and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * @file	nuttx/mutex.h
 * @brief	NuttX mutex primitives for libmetal.
 */

#ifndef __METAL_MUTEX__H__
#error "Include metal/mutex.h instead of metal/nuttx/mutex.h"
#endif

#ifndef __METAL_NUTTX_MUTEX__H__
#define __METAL_NUTTX_MUTEX__H__

#include <metal/utilities.h>
#include <nuttx/spinlock.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct metal_mutex {
	rspinlock_t lock;
	irqstate_t flags;
} metal_mutex_t;

/*
 * METAL_MUTEX_INIT - used for initializing an mutex element in a static struct
 * or global
 */
#define METAL_MUTEX_INIT(m) {.lock.val = 0, .flags = 0}
/*
 * METAL_MUTEX_DEFINE - used for defining and initializing a global or
 * static singleton mutex
 */
#define METAL_MUTEX_DEFINE(m) metal_mutex_t m = METAL_MUTEX_INIT(m)

static inline void __metal_mutex_init(metal_mutex_t *mutex)
{
	rspin_lock_init(&mutex->lock);
}

static inline void __metal_mutex_deinit(metal_mutex_t *mutex)
{
	metal_unused(mutex);
}

static inline int __metal_mutex_try_acquire(metal_mutex_t *mutex)
{
	irqstate_t flags;
	int ret;

	ret= rspin_trylock_irqsave_nopreempt(&mutex->lock, flags);
	if (ret && !rspin_lock_is_recursive(&mutex->lock))
		mutex->flags = flags;

	return ret;
}

static inline void __metal_mutex_acquire(metal_mutex_t *mutex)
{
	irqstate_t flags;

	flags = rspin_lock_irqsave_nopreempt(&mutex->lock);
	if (!rspin_lock_is_recursive(&mutex->lock))
		mutex->flags = flags;
}

static inline void __metal_mutex_release(metal_mutex_t *mutex)
{
	rspin_unlock_irqrestore_nopreempt(&mutex->lock, mutex->flags);
}

static inline int __metal_mutex_is_acquired(metal_mutex_t *mutex)
{
	return rspin_lock_is_locked(&mutex->lock);
}

#ifdef __cplusplus
}
#endif

#endif /* __METAL_NUTTX_MUTEX__H__ */
