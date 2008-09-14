/*
 * Copyright (C) 2007-2008 B.A.T.M.A.N. contributors:
 * Marek Lindner, Simon Wunderlich
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of version 2 of the GNU General Public
 * License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA
 *
 *
 * This file contains macros for maintaining compatibility with older versions
 * of the Linux kernel.
 */

#include <linux/version.h>	/* LINUX_VERSION_CODE */

#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 22)

#define skb_set_network_header(_skb, _offset) \
	do { (_skb)->nh.raw = (_skb)->data + (_offset); } while (0)

#define skb_reset_mac_header(_skb) \
	do { (_skb)->mac.raw = (_skb)->data; } while (0)

#define list_first_entry(ptr, type, member) \
	list_entry((ptr)->next, type, member)

#endif /* LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 22) */


#if LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 26)

#define device_create_drvdata(_cls, _parent, _devt, _device, _fmt) \
	class_device_create(_cls, _parent, _devt, _device, _fmt)

#define device_destroy(_cls, _device) \
	class_device_destroy(_cls, _device)

#endif /* LINUX_VERSION_CODE < KERNEL_VERSION(2, 6, 26) */