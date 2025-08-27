#pragma once
#include "quantum/rgb_matrix/rgb_matrix.h"

typedef rgb_t   rgb_matrix_layouts_palette_t[];
typedef uint8_t rgb_matrix_layouts_data_t[RGB_MATRIX_LED_COUNT];

#ifndef RGB_MATRIX_LAYOUTS_SWIZZLE
// Unfortunatley this has to be manually written for each board layout based on
// the `g_led_config` in .build/.../default_keyboard.c.
// The SWIZZLE param names' numbers are the LED strip indexes.
// clang-format off
#        define RGB_MATRIX_LAYOUTS_SWIZZLE( \
/* underglow in LAYOUT() order: */ \
            L01, L04, L07, L41, L38, L35, \
            L27, L24, L31, L65, L58, L61, \
/* both splits in LAYOUT() order: */ \
            L00, L02, L03, L05, L06, L08, \
            L42, L40, L39, L37, L36, L34, \
            \
            L14, L13, L12, L11, L10, L09, \
            L43, L44, L45, L46, L47, L48, \
            \
            L15, L16, L17, L18, L19, L20, \
            L54, L53, L52, L51, L50, L49, \
            \
            L28, L26, L25, L23, L22, L21, L29, \
            L67, L55, L56, L57, L59, L60, L62, \
            \
            L33, L32, L30, \
            L66, L64, L63) \
\
            L00, L01, L02, L03,   L04, L05, L06, L07, \
            L08, L09, L10, L11,   L12, L13, L14, L15, \
            L16, L17, L18, L19,   L20, L21, L22, L23, \
            L24, L25, L26, L27,   L28, L29, L30, L31, \
            L32, L33, L34, L35,   L36, L37, L38, L39, \
            L40, L41, L42, L43,   L44, L45, L46, L47, \
            L48, L49, L50, L51,   L52, L53, L54, L55, \
            L56, L57, L58, L59,   L60, L61, L62, L63, \
            L64, L65, L66, L67
// clang-format on
#endif

#define RGBLAYOUT(...) {RGB_MATRIX_LAYOUTS_SWIZZLE(__VA_ARGS__)}
