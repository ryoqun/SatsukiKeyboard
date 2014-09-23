//
//  engine.cpp
//  SatsukiKeyboard
//
//  Created by ryo-onodera on 9/22/14.
//
//

extern "C" {
  #include "engine.h"
}

#include "SatsukiKeyboard.h"
#include <IOKit/hid/IOHIDUsageTables.h>


void Turnstile_buffer(Context* ctxt, KeyEvent key_event) {
};

void Turnstile_flush(Context* ctxt) {
};

void Turnstile_emit(Context* ctxt, KeyEvent key_event) {
    SatsukiKeyboard *keyboard = reinterpret_cast<SatsukiKeyboard*>(ctxt);
    keyboard->emit(key_event);
};

void Turnstile_pop_state(Context* ctxt) {
};

void Turnstile_emit_z(Context* ctxt) {
};

void Turnstile_emit_space(Context* ctxt) {
    SatsukiKeyboard *keyboard = reinterpret_cast<SatsukiKeyboard*>(ctxt);
    printf("eimit space!!\n");
    keyboard->dispatchPressDown(kHIDUsage_KeyboardSpacebar);
    keyboard->dispatchPressUp(kHIDUsage_KeyboardSpacebar);
};

void Turnstile_emit_slash(Context* ctxt) {
};

void Turnstile_space_mode(Context* ctxt, char flag) {
    SatsukiKeyboard *keyboard = reinterpret_cast<SatsukiKeyboard*>(ctxt);
    keyboard->space_mode(flag);
};

void Turnstile_control_mode(Context* ctxt, char flag) {
};

void Turnstile_shift_mode(Context* ctxt, char flag) {
};

void Turnstile_tenkey_mode(Context* ctxt, char flag) {
    SatsukiKeyboard *keyboard = reinterpret_cast<SatsukiKeyboard*>(ctxt);
    keyboard->tenkey_mode(flag);
};
