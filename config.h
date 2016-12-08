#ifndef CONFIG_PHONGNH_H_
#define CONFIG_PHONGNH_H_

#include "../../config.h"

#undef  MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 10

#undef  MOUSEKEY_MAX_SPEED
// #define MOUSEKEY_MAX_SPEED 4
#define MOUSEKEY_MAX_SPEED 3

#undef  MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 0

#undef  MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 0

#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_TIMEOUT 3000

// Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap
#undef LOCKING_SUPPORT_ENABLE

// Locking resynchronize hack
#undef LOCKING_RESYNC_ENABLE

#undef  LEADER_TIMEOUT
#define LEADER_TIMEOUT 1000

#endif /* CONFIG_PHONGNH_H_ */
