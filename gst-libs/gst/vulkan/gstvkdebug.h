/*
 * GStreamer
 * Copyright (C) 2019 Matthew Waters <matthew@centricular.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __GST_VULKAN_DEBUG_H__
#define __GST_VULKAN_DEBUG_H__

#include <gst/gst.h>
#include <vulkan/vulkan.h>
#include <gst/vulkan/vulkan-prelude.h>

G_BEGIN_DECLS

#define GST_VULKAN_EXTENT3D_FORMAT G_GUINT32_FORMAT ", %" G_GUINT32_FORMAT ", %" G_GUINT32_FORMAT
#define GST_VULKAN_EXTENT3D_ARGS(var) (var).width, (var).height, (var).depth

G_END_DECLS

#endif /* __GST_VULKAN_DEBUG_H__ */