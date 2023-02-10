/**
 * 
 * 
 *   @author Sean Hobeck
 * 
 *    @date 02/10/2023
 * 
 * 
 **/
#pragma once

/// @subsection psp2 include
#include <psp2/appmgr.h>
#include <psp2/apputil.h>
#include <psp2/atrac.h>
#include <psp2/audiodec.h>
#include <psp2/audioenc.h>
#include <psp2/audioin.h>
#include <psp2/audioout.h>
#include <psp2/avconfig.h>
#include <psp2/avplayer.h>
#include <psp2/bgapputil.h>
#include <psp2/camera.h>
#include <psp2/common_dialog.h>
#include <psp2/compat.h>
#include <psp2/ctrl.h>
#include <psp2/display.h>
#include <psp2/dmac5.h>
#include <psp2/fiber.h>
#include <psp2/fios2kernel.h>
#include <psp2/fios2kernel02.h>
#include <psp2/gps.h>
#include <psp2/gxm.h>
#include <psp2/gxt.h>
#include <psp2/hid.h>
#include <psp2/ime_dialog.h>
#include <psp2/incoming_dialog.h>
#include <psp2/jpeg.h>
#include <psp2/jpegarm.h>
#include <psp2/jpegenc.h>
#include <psp2/jpegencarm.h>
#include <psp2/json.h>
#include <psp2/libdbg.h>
#include <psp2/libime.h>
#include <psp2/libssl.h>
#include <psp2/location.h>
#include <psp2/message_dialog.h>
#include <psp2/motion.h>
#include <psp2/motion_dev.h>
#include <psp2/mtpif.h>
#include <psp2/musicexport.h>
#include <psp2/netcheck_dialog.h>
#include <psp2/ngs_internal.h>
#include <psp2/notificationutil.h>
#include <psp2/npdrm.h>
#include <psp2/npdrmpackage.h>
#include <psp2/paf.h>
#include <psp2/pamgr.h>
#include <psp2/pgf.h>
#include <psp2/photoexport.h>
#include <psp2/power.h>
#include <psp2/promoterutil.h>
#include <psp2/pspnet_adhoc.h>
#include <psp2/pspnet_adhocctl.h>
#include <psp2/pss.h>
#include <psp2/pvf.h>
#include <psp2/razor_capture.h>
#include <psp2/razor_hud.h>
#include <psp2/registrymgr.h>
#include <psp2/rtc.h>
#include <psp2/sblacmgr.h>
#include <psp2/screenshot.h>
#include <psp2/shacccg.h>
#include <psp2/sharedfb.h>
#include <psp2/shellutil.h>
#include <psp2/shutter_sound.h>
#include <psp2/sqlite.h>
#include <psp2/sysmodule.h>
#include <psp2/system_param.h>
#include <psp2/touch.h>
#include <psp2/triggerutil.h>
#include <psp2/types.h>
#include <psp2/udcd.h>
#include <psp2/update.h>
#include <psp2/usbd.h>
#include <psp2/usbserial.h>
#include <psp2/usbserv.h>
#include <psp2/usbstorvstor.h>
#include <psp2/videodec.h>
#include <psp2/videoexport.h>
#include <psp2/vshbridge.h>

/// @subsection kernel
#include <psp2/kernel/clib.h>
#include <psp2/kernel/cpu.h>
#include <psp2/kernel/dmac.h>
#include <psp2/kernel/error.h>
#include <psp2/kernel/modulemgr.h>
#include <psp2/kernel/openpsid.h>
#include <psp2/kernel/processmgr.h>
#include <psp2/kernel/rng.h>
#include <psp2/kernel/sysmem.h>
#include <psp2/kernel/threadmgr.h>

/// @subsection deci4p
#include <psp2/deci4p/user.h>

/// @subsection io
#include <psp2/io/devctl.h>
#include <psp2/io/dirent.h>
#include <psp2/io/fcntl.h>
#include <psp2/io/stat.h>

/// @subsection net
#include <psp2/net/http.h>
#include <psp2/net/net.h>
#include <psp2/net/netctl.h>
#include <psp2/net/net_syscalls.h>

/// @subsection paf
#include <psp2/paf/misc.h>
#include <psp2/paf/stdc.h>

/// @section c++ features

#include <bits/stdc++.h>