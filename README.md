# QMiniPCIDevice

## Description
This is a parent class for [QMiniNVMeDevice](https://github.com/aekhv/mininvme) and [QMiniAHCIDevice](https://github.com/aekhv/miniahci) subclasses.

## Features
- Available devices enumeration;
- Driver version;
- PCI device location (domain, bus, slot, function);
- PCI device hardware ID (vendor, device, class, revision);
- PCI device link speed;
- Hot-plug methods: device remove and PCI bus rescan;

See MiniPCITestApp for more details.

![](/img/screenshot.png)

## PCIe Hot-Plug important notes for modern PC mainboards
To make PCIe Hot-Plug work some conditions must be fulfilled:
1. Use Linux kernel version 6.x.
2. You have to use system chipset that supports PCIe Hot-Plug capability. Type in terminal `sudo lspci -vv | grep HotPlug`. If you see `HotPlug+` in output it means some of the PCIe slots are support Hot-Plug. Of course you have to use these slots only.
3. At the boot time any NVMe device must be attached already, in any words a BIOS must to initialize PCIe bridge and attached NVMe device. You can use any working NVMe device as a kind of dummy. As soon as operating system is loaded you can remove dummy device and then attach faulty device to begin data recovery.

