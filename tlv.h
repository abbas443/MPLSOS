/*
 * Copyright (c) 2014 Nicira, Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of version 2 of the GNU General Public
 * License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 */

//Associated Channel Header

#include <linux/if_ether.h>
#include <linux/netdevice.h>

#define TLV_HLEN 16
struct mpls_tlv_hdr {
        __u8    type;
        __u8    reserved;
        __be16  length;
 

#if defined(__LITTLE_ENDIAN_BITFIELD)
	__be32	d:1,
		rsvd:3,
                retrn:4,
                path_id:24; 
#elif defined (__BIG_ENDIAN_BITFIELD)
        __be32  d:1,
                rsvd:3,
                retrn:4,
                path_id:24;
#else
#error	"Please fix <asm/byteorder.h>"
#endif
	__be32	lsp_id;
	__u8	algo;
	__u8	group;
	__be16	dh_value;



};


static inline struct mpls_tlv_hdr *tlv_hdr(const struct sk_buff *skb)
{
	return (struct mpls_tlv_hdr *) (skb_mac_header(skb) + skb->mac_len);
}
