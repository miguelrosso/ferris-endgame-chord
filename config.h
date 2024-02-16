#pragma once

#undef  TAPPING_TERM
#define TAPPING_TERM 200

#undef  QUICK_TAP_TERM
#define QUICK_TAP_TERM 100

#ifdef __AVR__
#define SPLIT_USB_DETECT
#endif
