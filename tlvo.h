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

#define TLVO_HLEN 4
struct tlv_object_hdr {

        __u8 type;
        __u8 reserved;
	__be16 length;
};


//#ifdef MPLS_HEADER_IS_L3
/*static inline struct pw_codeword_hdr *pwcd_hdr(const struct sk_buff *skb)
{
    return (struct pw_codeword_hdr *)skb_network_header(skb);
}
*/
//#else
//#define mpls_hdr rpl_mpls_hdr

static inline struct tlv_object_hdr *tlvo_hdr(const struct sk_buff *skb)
{
	return (struct tlv_object_hdr *) (skb_mac_header(skb) + skb->mac_len);
}
