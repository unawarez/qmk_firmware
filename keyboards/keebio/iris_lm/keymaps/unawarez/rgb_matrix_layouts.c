#include "rgb_matrix_layouts.h"
#include "quantum/action_layer.h"

extern const rgb_matrix_layouts_data_t    rgblayouts[];
extern const uint8_t                      n_rgblayouts;
extern const rgb_matrix_layouts_palette_t rgblayouts_palette;

static bool LAYOUTS(effect_params_t *params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t layer = 0;
    for (uint8_t checklayer = 1; checklayer < n_rgblayouts; checklayer++) {
        if (layer_state_is(checklayer)) {
            layer = checklayer;
        }
    }
    const uint8_t *layout = rgblayouts[layer];
    for (uint8_t i = led_min; i < led_max; i++) {
        const rgb_t *color = rgblayouts_palette + layout[i];
        rgb_matrix_set_color(i, color->r, color->g, color->b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}
