/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
/*
 * include/linux/random.h
 *
 * Include file for the random number generator.
 */

#ifndef _LINUX_RANDOM_H
#define _LINUX_RANDOM_H

#include <linux/types.h>
#include <linux/ioctl.h>
#include <linux/irqnr.h>

/* ioctl()'s for the random number generator */

/* Get the entropy count. */
#define RNDGETENTCNT	_IOR( 'R', 0x00, int )

/* Add to (or subtract from) the entropy count.  (Superuser only.) */
#define RNDADDTOENTCNT	_IOW( 'R', 0x01, int )

/* Get the contents of the entropy pool.  (Superuser only.) (Removed in 2.6.9-rc2.) */
#define RNDGETPOOL	_IOR( 'R', 0x02, int [2] )

/* 
 * Write bytes into the entropy pool and add to the entropy count.
 * (Superuser only.)
 */
#define RNDADDENTROPY	_IOW( 'R', 0x03, int [2] )

/* Clear entropy count to 0.  (Superuser only.) */
#define RNDZAPENTCNT	_IO( 'R', 0x04 )

/* Clear the entropy pool and associated counters.  (Superuser only.) */
#define RNDCLEARPOOL	_IO( 'R', 0x06 )

/* Reseed CRNG.  (Superuser only.) */
#define RNDRESEEDCRNG	_IO( 'R', 0x07 )

struct rand_pool_info {
	int	entropy_count;
	int	buf_size;
	__u32	buf[];
};

/*
 * Flags for getrandom(2)
 *
 * GRND_NONBLOCK	Don't block and return EAGAIN instead
 * GRND_RANDOM		No effect
 * GRND_INSECURE	Return non-cryptographic random bytes
 */
#define GRND_NONBLOCK	0x0001
#define GRND_RANDOM	0x0002
#define GRND_INSECURE	0x0004

/**
 * struct vgetrandom_opaque_params - arguments for allocating memory for vgetrandom
 *
 * @size_per_opaque_state:	Size of each state that is to be passed to vgetrandom().
 * @mmap_prot:			Value of the prot argument in mmap(2).
 * @mmap_flags:			Value of the flags argument in mmap(2).
 * @reserved:			Reserved for future use.
 */
struct vgetrandom_opaque_params {
	__u32 size_of_opaque_state;
	__u32 mmap_prot;
	__u32 mmap_flags;
	__u32 reserved[13];
};

#endif /* _LINUX_RANDOM_H */