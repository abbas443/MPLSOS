#!/bin/bash
sudo rmmod openvswitch
sudo /usr/local/share/openvswitch/scripts/ovs-ctl stop
sudo make -C ovs
sudo make install -C ovs
sudo make modules_install -C ovs
sudo modprobe openvswitch
sudo /usr/local/share/openvswitch/scripts/ovs-ctl start
