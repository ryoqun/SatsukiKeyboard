//
//  engine.h
//  SatsukiKeyboard
//
//  Created by ryo-onodera on 9/22/14.
//
//

#include <IOKit/IOLib.h>

#ifndef SatsukiKeyboard_engine_h
#define SatsukiKeyboard_engine_h

typedef struct {
    UInt32 usage, value;
    IOOptionBits options;
    char is_space, is_slash, is_z, is_tenkey, is_shift;
} KeyEvent;

#define KEY_SPACE 0
#define KEY_SLASH 1
#define KEY_Z 2
#define KEY_SHIFT 3
#define KEY_TENKEY 4
#define True 1
#define False 0

typedef struct Turnstile Context;

void Turnstile_buffer(Context* ctxt, KeyEvent keyevent);
void Turnstile_flush(Context* ctxt);
void Turnstile_emit(Context* ctxt, KeyEvent keyevent);
void Turnstile_emit_z(Context* ctxt);
void Turnstile_emit_space(Context* ctxt);
void Turnstile_emit_slash(Context* ctxt);
void Turnstile_space_mode(Context* ctxt, char flag);
void Turnstile_control_mode(Context* ctxt, char flag);
void Turnstile_shift_mode(Context* ctxt, char flag);
void Turnstile_tenkey_mode(Context* ctxt, char flag);


#endif
