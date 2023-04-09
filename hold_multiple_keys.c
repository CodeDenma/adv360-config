#include <dt-bindings/zmk/keys.h>
#include <zmk/keys.h>
#include <zmk/keymap.h>
#include <zmk/matrix.h>
#include <zmk/endpoints.h>
#include <zmk/behavior.h>

static int on_keymap_binding_triggered(struct zmk_behavior_binding *binding,
                                       struct zmk_behavior_binding_event event)
{
  zmk_keycode_state_changed_from_binding(binding, event, true);
  k_msleep(50);
  zmk_keycode_state_changed_from_binding(binding, event, false);

  return 0;
}

ZMK_BEHAVIOR_DEFINE(hold_multiple_keys, on_keymap_binding_triggered);
