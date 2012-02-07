/*
 * Windows CE backend for libusb 1.0
 * Copyright (C) 2011 RealVNC Ltd.
 * Portions taken from Windows backend, which is
 * Copyright (C) 2009-2010 Pete Batard <pbatard@gmail.com>
 * With contributions from Michael Plante, Orin Eman et al.
 * Parts of this code adapted from libusb-win32-v1 by Stephan Meyer
 * Major code testing contribution by Xiaofan Chen
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "wince_usb.h"

#include <libusbi.h>

#include <stdint.h>
#include <errno.h>

// Global variables
int errno;
const uint64_t epoch_time = UINT64_C(116444736000000000);       // 1970.01.01 00:00:000 in MS Filetime


// Internal API functions
static int wince_init(struct libusb_context *ctx)
{
	return LIBUSB_ERROR_NOT_SUPPORTED;
}

static void wince_exit(void)
{

}

static int wince_get_device_list(
	struct libusb_context *ctx,
	struct discovered_devs **discdevs)
{
	return LIBUSB_ERROR_NOT_SUPPORTED;
}

static int wince_open(struct libusb_device_handle *handle)
{
	return LIBUSB_ERROR_NOT_SUPPORTED;
}

static void wince_close(struct libusb_device_handle *handle)
{

}

static int wince_get_device_descriptor(
   struct libusb_device *device,
   unsigned char *buffer, int *host_endian)
{
	return LIBUSB_ERROR_NOT_SUPPORTED;
}

static int wince_get_active_config_descriptor(
	struct libusb_device *device,
	unsigned char *buffer, size_t len, int *host_endian)
{
	return LIBUSB_ERROR_NOT_SUPPORTED;
}

static int wince_get_config_descriptor(
	struct libusb_device *device,
	uint8_t config_index,
	unsigned char *buffer, size_t len, int *host_endian)
{
	return LIBUSB_ERROR_NOT_SUPPORTED;
}

static int wince_get_configuration(
   struct libusb_device_handle *handle,
   int *config)
{
	return LIBUSB_ERROR_NOT_SUPPORTED;
}

static int wince_set_configuration(
	struct libusb_device_handle *handle,
	int config)
{
	return LIBUSB_ERROR_NOT_SUPPORTED;
}

static int wince_claim_interface(
	struct libusb_device_handle *handle,
	int interface_number)
{
	return LIBUSB_ERROR_NOT_SUPPORTED;
}

static int wince_release_interface(
	struct libusb_device_handle *handle,
	int interface_number)
{
	return LIBUSB_ERROR_NOT_SUPPORTED;
}

static int wince_set_interface_altsetting(
	struct libusb_device_handle *handle,
	int interface_number, int altsetting)
{
	return LIBUSB_ERROR_NOT_SUPPORTED;
}

static int wince_clear_halt(
	struct libusb_device_handle *handle,
	unsigned char endpoint)
{
	return LIBUSB_ERROR_NOT_SUPPORTED;
}

static int wince_reset_device(
	struct libusb_device_handle *handle)
{
	return LIBUSB_ERROR_NOT_SUPPORTED;
}

static int wince_kernel_driver_active(
	struct libusb_device_handle *handle,
	int interface_number)
{
	return LIBUSB_ERROR_NOT_SUPPORTED;
}

static int wince_detach_kernel_driver(
	struct libusb_device_handle *handle,
	int interface_number)
{
	return LIBUSB_ERROR_NOT_SUPPORTED;
}

static int wince_attach_kernel_driver(
	struct libusb_device_handle *handle,
	int interface_number)
{
	return LIBUSB_ERROR_NOT_SUPPORTED;
}

static void wince_destroy_device(
	struct libusb_device *dev)
{

}

static int wince_submit_transfer(
	struct usbi_transfer *itransfer)
{
	return LIBUSB_ERROR_NOT_SUPPORTED;
}

static int wince_cancel_transfer(
	struct usbi_transfer *itransfer)
{
	return LIBUSB_ERROR_NOT_SUPPORTED;
}

static int wince_clear_transfer_priv(
	struct usbi_transfer *itransfer)
{
	return LIBUSB_ERROR_NOT_SUPPORTED;
}

static int wince_handle_events(
	struct libusb_context *ctx,
	struct pollfd *fds, POLL_NFDS_TYPE nfds, int num_ready)
{
	return LIBUSB_ERROR_NOT_SUPPORTED;
}

static int wince_clock_gettime(
   int clkid, struct timespec *tp)
{
	return LIBUSB_ERROR_NOT_SUPPORTED;
}

const struct usbi_os_backend wince_backend = {
        "Windows CE",
        wince_init,
        wince_exit,

        wince_get_device_list,
        wince_open,
        wince_close,

        wince_get_device_descriptor,
        wince_get_active_config_descriptor,
        wince_get_config_descriptor,

        wince_get_configuration,
        wince_set_configuration,
        wince_claim_interface,
        wince_release_interface,

        wince_set_interface_altsetting,
        wince_clear_halt,
        wince_reset_device,

        wince_kernel_driver_active,
        wince_detach_kernel_driver,
        wince_attach_kernel_driver,

        wince_destroy_device,

        wince_submit_transfer,
        wince_cancel_transfer,
        wince_clear_transfer_priv,

        wince_handle_events,

        wince_clock_gettime,
#if defined(USBI_TIMERFD_AVAILABLE)
        NULL,
#endif
        sizeof(struct wince_device_priv),
        sizeof(struct wince_device_handle_priv),
        sizeof(struct wince_transfer_priv),
        0,
};