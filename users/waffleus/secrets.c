#include "pru.h"
#if (__has_include("secrets.h") && !defined(NO_SECRETS))
#include "secrets.h"
#else
static const char * const secret[] = {
  "test1",
  "test2",
  "test3",
  "test4",
  "test5"
};
#endif

bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SECRET1 ... SECRET5:
            if (!record->event.pressed) {
            clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
            send_string_with_delay(secrets[keycode - SECRET1], MACRO_TIMER);
        }
        return false;
        break;
    }
    return true;
}
