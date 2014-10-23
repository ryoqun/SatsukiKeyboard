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

extern "C" {
#include "statemap.h"
}

void Turnstile_buffer(Context* ctxt, KeyEvent key_event) {
    SatsukiKeyboard *keyboard = reinterpret_cast<SatsukiKeyboard*>(ctxt);
    keyboard->buffer(key_event);
};

void Turnstile_flush(Context* ctxt) {
    SatsukiKeyboard *keyboard = reinterpret_cast<SatsukiKeyboard*>(ctxt);
    keyboard->flush();
};

void Turnstile_emit(Context* ctxt, KeyEvent key_event) {
    SatsukiKeyboard *keyboard = reinterpret_cast<SatsukiKeyboard*>(ctxt);
    keyboard->emit(key_event);
};

void Turnstile_pop_state(Context* ctxt) {
    SatsukiKeyboard *keyboard = reinterpret_cast<SatsukiKeyboard*>(ctxt);
    printf("pop state!!!!!!!!!\n");
    popState(&(keyboard->mSatsukiContext));
    if ((keyboard->mSatsukiContext._state)->Exit != NULL) {
        (keyboard->mSatsukiContext._state)->Exit(&keyboard->mSatsukiContext);
    }
};

void Turnstile_emit_z(Context* ctxt) {
    SatsukiKeyboard *keyboard = reinterpret_cast<SatsukiKeyboard*>(ctxt);
    keyboard->emitPressDown(kHIDUsage_KeyboardZ);
    keyboard->emitPressUp(kHIDUsage_KeyboardZ);
};

void Turnstile_emit_space(Context* ctxt) {
    SatsukiKeyboard *keyboard = reinterpret_cast<SatsukiKeyboard*>(ctxt);
    keyboard->emitPressDown(kHIDUsage_KeyboardSpacebar);
    keyboard->emitPressUp(kHIDUsage_KeyboardSpacebar);
};

void Turnstile_emit_slash(Context* ctxt) {
    SatsukiKeyboard *keyboard = reinterpret_cast<SatsukiKeyboard*>(ctxt);
    keyboard->emitPressDown(kHIDUsage_KeyboardSlash);
    keyboard->emitPressUp(kHIDUsage_KeyboardSlash);
};

void Turnstile_emit_period(Context* ctxt) {
    SatsukiKeyboard *keyboard = reinterpret_cast<SatsukiKeyboard*>(ctxt);
    keyboard->emitPressDown(kHIDUsage_KeyboardPeriod);
    keyboard->emitPressUp(kHIDUsage_KeyboardPeriod);
};

void Turnstile_space_mode(Context* ctxt, char flag) {
    SatsukiKeyboard *keyboard = reinterpret_cast<SatsukiKeyboard*>(ctxt);
    keyboard->space_mode(flag);
};

void Turnstile_control_mode(Context* ctxt, char flag) {
    SatsukiKeyboard *keyboard = reinterpret_cast<SatsukiKeyboard*>(ctxt);
    keyboard->control_mode(flag);
};

void Turnstile_shift_mode(Context* ctxt, char flag) {
    SatsukiKeyboard *keyboard = reinterpret_cast<SatsukiKeyboard*>(ctxt);
    keyboard->shift_mode(flag);
};

void Turnstile_tenkey_mode(Context* ctxt, char flag) {
    SatsukiKeyboard *keyboard = reinterpret_cast<SatsukiKeyboard*>(ctxt);
    keyboard->tenkey_mode(flag);
};

void Turnstile_meta_mode(Context* ctxt, char flag) {
    SatsukiKeyboard *keyboard = reinterpret_cast<SatsukiKeyboard*>(ctxt);
    keyboard->meta_mode(flag);
};
