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

#define GAP_HLEN 16
struct gap_msg_hdr {

#if defined(__LITTLE_ENDIAN_BITFIELD)
        __be32  version:4,
                reserved:12,
                message_length:16;
#elif defined (__BIG_ENDIAN_BITFIELD)
        __be32  version:4,
                reserved:12,
                message_length:16;
#else
#error  "Please fix <asm/byteorder.h>"
#endif

        __be32  message_id:32;
        __be64  timestamp:64;

};


static inline struct gap_msg_hdr *gap_hdr(const struct sk_buff *skb)
{
        return (struct gap_msg_hdr *) (skb_mac_header(skb) + skb->mac_len);
}

