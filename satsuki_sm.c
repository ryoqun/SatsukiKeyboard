/*
 * ex: set ro:
 * DO NOT EDIT.
 * generated by smc (http://smc.sourceforge.net/)
 * from file : satsuki.sm
 */

#include "engine.h"
#include "satsuki_sm.h"

#define getOwner(fsm) \
(fsm)->_owner

#define POPULATE_STATE(state) \
state##_Entry, \
state##_Exit, \
state##_keydown, \
state##_keyup, \
state##_Default

#define ENTRY_STATE(state) \
if ((state)->Entry != NULL) { \
(state)->Entry(fsm); \
}

#define EXIT_STATE(state) \
if ((state)->Exit != NULL) { \
(state)->Exit(fsm); \
}

static void TurnstileState_keydown(struct satsukiContext *fsm, KeyEvent event)
{
    getState(fsm)->Default(fsm);
}

static void TurnstileState_keyup(struct satsukiContext *fsm, KeyEvent event)
{
    getState(fsm)->Default(fsm);
}

static void TurnstileState_Default(struct satsukiContext *fsm)
{
    State_Default(fsm);
}

#define MainMap_Normal_keydown TurnstileState_keydown
#define MainMap_Normal_keyup TurnstileState_keyup
#define MainMap_Normal_Default TurnstileState_Default
#define MainMap_Normal_Entry NULL
#define MainMap_Normal_Exit NULL
#define MainMap_Shift_keydown TurnstileState_keydown
#define MainMap_Shift_keyup TurnstileState_keyup
#define MainMap_Shift_Default TurnstileState_Default
#define MainMap_Shift_Entry NULL
#define MainMap_Shift_Exit NULL
#define MainMap_Tenkey_keydown TurnstileState_keydown
#define MainMap_Tenkey_keyup TurnstileState_keyup
#define MainMap_Tenkey_Default TurnstileState_Default
#define MainMap_Tenkey_Entry NULL
#define MainMap_Tenkey_Exit NULL
#define MainMap_PreSpace_keydown TurnstileState_keydown
#define MainMap_PreSpace_keyup TurnstileState_keyup
#define MainMap_PreSpace_Default TurnstileState_Default
#define MainMap_PreSpace_Entry NULL
#define MainMap_PreSpace_Exit NULL
#define MainMap_Space_keydown TurnstileState_keydown
#define MainMap_Space_keyup TurnstileState_keyup
#define MainMap_Space_Default TurnstileState_Default
#define MainMap_Space_Entry NULL
#define MainMap_Space_Exit NULL
#define MainMap_PreZKeyControl_keydown TurnstileState_keydown
#define MainMap_PreZKeyControl_keyup TurnstileState_keyup
#define MainMap_PreZKeyControl_Default TurnstileState_Default
#define MainMap_PreZKeyControl_Entry NULL
#define MainMap_PreZKeyControl_Exit NULL
#define MainMap_PreSlashControl_keydown TurnstileState_keydown
#define MainMap_PreSlashControl_keyup TurnstileState_keyup
#define MainMap_PreSlashControl_Default TurnstileState_Default
#define MainMap_PreSlashControl_Entry NULL
#define MainMap_PreSlashControl_Exit NULL
#define MainMap_SemiZKeyControl_keydown TurnstileState_keydown
#define MainMap_SemiZKeyControl_keyup TurnstileState_keyup
#define MainMap_SemiZKeyControl_Default TurnstileState_Default
#define MainMap_SemiZKeyControl_Entry NULL
#define MainMap_SemiZKeyControl_Exit NULL
#define MainMap_SemiSlashControl_keydown TurnstileState_keydown
#define MainMap_SemiSlashControl_keyup TurnstileState_keyup
#define MainMap_SemiSlashControl_Default TurnstileState_Default
#define MainMap_SemiSlashControl_Entry NULL
#define MainMap_SemiSlashControl_Exit NULL
#define MainMap_ZKeyControl_keydown TurnstileState_keydown
#define MainMap_ZKeyControl_keyup TurnstileState_keyup
#define MainMap_ZKeyControl_Default TurnstileState_Default
#define MainMap_ZKeyControl_Entry NULL
#define MainMap_ZKeyControl_Exit NULL
#define MainMap_SlashControl_keydown TurnstileState_keydown
#define MainMap_SlashControl_keyup TurnstileState_keyup
#define MainMap_SlashControl_Default TurnstileState_Default
#define MainMap_SlashControl_Entry NULL
#define MainMap_SlashControl_Exit NULL
#define MainMap_DefaultState_keydown TurnstileState_keydown
#define MainMap_DefaultState_keyup TurnstileState_keyup

#undef MainMap_Normal_keydown
static void MainMap_Normal_keydown(struct satsukiContext *fsm, KeyEvent event)
{
    struct Turnstile* ctxt = getOwner(fsm);
    
    if ( event.is_space ) {
        /* No actions. */
        pushState(fsm, &MainMap_PreSpace);
        ENTRY_STATE(getState(fsm));
    }
    else if ( event.is_slash ) {
        /* No actions. */
        pushState(fsm, &MainMap_PreSlashControl);
        ENTRY_STATE(getState(fsm));
    }
    else if ( event.is_z ) {
        /* No actions. */
        pushState(fsm, &MainMap_PreZKeyControl);
        ENTRY_STATE(getState(fsm));
    }
    else if ( event.is_shift ) {
        /* No actions. */
        pushState(fsm, &MainMap_Shift);
        ENTRY_STATE(getState(fsm));
    }
    else if ( event.is_tenkey ) {
        /* No actions. */
        pushState(fsm, &MainMap_Tenkey);
        ENTRY_STATE(getState(fsm));
    }
    else {
        const struct TurnstileState* EndStateName = getState(fsm);
        
        clearState(fsm);
        Turnstile_emit(ctxt, event);
        setState(fsm, EndStateName);
    }
}

const struct TurnstileState MainMap_Normal = { POPULATE_STATE(MainMap_Normal), 0 };

#undef MainMap_Shift_Entry
void MainMap_Shift_Entry(struct satsukiContext *fsm)
{
    struct Turnstile *ctxt = getOwner(fsm);
    
    Turnstile_shift_mode(ctxt, True);
}

#undef MainMap_Shift_Exit
void MainMap_Shift_Exit(struct satsukiContext *fsm)
{
    struct Turnstile *ctxt = getOwner(fsm);
    
    Turnstile_shift_mode(ctxt, False);
}

#undef MainMap_Shift_keydown
static void MainMap_Shift_keydown(struct satsukiContext *fsm, KeyEvent event)
{
    struct Turnstile* ctxt = getOwner(fsm);
    const struct TurnstileState* EndStateName = getState(fsm);
    
    clearState(fsm);
    Turnstile_emit(ctxt, event);
    setState(fsm, EndStateName);
}

#undef MainMap_Shift_keyup
static void MainMap_Shift_keyup(struct satsukiContext *fsm, KeyEvent event)
{
    struct Turnstile* ctxt = getOwner(fsm);
    
    if ( event.is_shift ) {
        EXIT_STATE(getState(fsm));
        /* No actions. */
        popState(fsm);
    }
    else {
        const struct TurnstileState* EndStateName = getState(fsm);
        
        clearState(fsm);
        Turnstile_emit(ctxt, event);
        setState(fsm, EndStateName);
    }
}

const struct TurnstileState MainMap_Shift = { POPULATE_STATE(MainMap_Shift), 1 };

#undef MainMap_Tenkey_Entry
void MainMap_Tenkey_Entry(struct satsukiContext *fsm)
{
    struct Turnstile *ctxt = getOwner(fsm);
    
    Turnstile_tenkey_mode(ctxt, True);
}

#undef MainMap_Tenkey_Exit
void MainMap_Tenkey_Exit(struct satsukiContext *fsm)
{
    struct Turnstile *ctxt = getOwner(fsm);
    
    Turnstile_tenkey_mode(ctxt, False);
}

#undef MainMap_Tenkey_keydown
static void MainMap_Tenkey_keydown(struct satsukiContext *fsm, KeyEvent event)
{
    struct Turnstile* ctxt = getOwner(fsm);
    const struct TurnstileState* EndStateName = getState(fsm);
    
    clearState(fsm);
    Turnstile_emit(ctxt, event);
    setState(fsm, EndStateName);
}

#undef MainMap_Tenkey_keyup
static void MainMap_Tenkey_keyup(struct satsukiContext *fsm, KeyEvent event)
{
    struct Turnstile* ctxt = getOwner(fsm);
    
    if ( event.is_tenkey ) {
        EXIT_STATE(getState(fsm));
        /* No actions. */
        popState(fsm);
    }
    else {
        const struct TurnstileState* EndStateName = getState(fsm);
        
        clearState(fsm);
        Turnstile_emit(ctxt, event);
        setState(fsm, EndStateName);
    }
}

const struct TurnstileState MainMap_Tenkey = { POPULATE_STATE(MainMap_Tenkey), 2 };

#undef MainMap_PreSpace_keydown
static void MainMap_PreSpace_keydown(struct satsukiContext *fsm, KeyEvent event)
{
    struct Turnstile* ctxt = getOwner(fsm);
    
    if ( event.is_slash ) {
        EXIT_STATE(getState(fsm));
        /* No actions. */
        setState(fsm, &MainMap_Space);
        ENTRY_STATE(getState(fsm));
        pushState(fsm, &MainMap_PreSlashControl);
        ENTRY_STATE(getState(fsm));
    }
    else if ( event.is_z ) {
        EXIT_STATE(getState(fsm));
        /* No actions. */
        setState(fsm, &MainMap_Space);
        ENTRY_STATE(getState(fsm));
        pushState(fsm, &MainMap_PreZKeyControl);
        ENTRY_STATE(getState(fsm));
    }
    else if ( event.is_space ) {
        EXIT_STATE(getState(fsm));
        /* No actions. */
        setState(fsm, &MainMap_Space);
        ENTRY_STATE(getState(fsm));
    }
    else {
        EXIT_STATE(getState(fsm));
        clearState(fsm);
        Turnstile_space_mode(ctxt, True);
        Turnstile_emit(ctxt, event);
        setState(fsm, &MainMap_Space);
        ENTRY_STATE(getState(fsm));
    }
}

#undef MainMap_PreSpace_keyup
static void MainMap_PreSpace_keyup(struct satsukiContext *fsm, KeyEvent event)
{
    struct Turnstile* ctxt = getOwner(fsm);
    
    if ( event.is_space ) {
        EXIT_STATE(getState(fsm));
        clearState(fsm);
        Turnstile_emit_space(ctxt);
        popState(fsm);
    }
    else {
        MainMap_DefaultState_keyup(fsm, event);
    }
}

const struct TurnstileState MainMap_PreSpace = { POPULATE_STATE(MainMap_PreSpace), 3 };

#undef MainMap_Space_Entry
void MainMap_Space_Entry(struct satsukiContext *fsm)
{
    struct Turnstile *ctxt = getOwner(fsm);
    
    Turnstile_space_mode(ctxt, True);
}

#undef MainMap_Space_Exit
void MainMap_Space_Exit(struct satsukiContext *fsm)
{
    struct Turnstile *ctxt = getOwner(fsm);
    
    Turnstile_space_mode(ctxt, False);
}

#undef MainMap_Space_keydown
static void MainMap_Space_keydown(struct satsukiContext *fsm, KeyEvent event)
{
    struct Turnstile* ctxt = getOwner(fsm);
    
    if ( event.is_slash ) {
        /* No actions. */
        pushState(fsm, &MainMap_PreSlashControl);
        ENTRY_STATE(getState(fsm));
    }
    else if ( event.is_z ) {
        /* No actions. */
        pushState(fsm, &MainMap_PreZKeyControl);
        ENTRY_STATE(getState(fsm));
    }
    else if ( event.is_space ) {
        /* No actions. */
    }
    else {
        const struct TurnstileState* EndStateName = getState(fsm);
        
        clearState(fsm);
        Turnstile_emit(ctxt, event);
        setState(fsm, EndStateName);
    }
}

#undef MainMap_Space_keyup
static void MainMap_Space_keyup(struct satsukiContext *fsm, KeyEvent event)
{
    struct Turnstile* ctxt = getOwner(fsm);
    
    if ( event.is_space ) {
        EXIT_STATE(getState(fsm));
        /* No actions. */
        popState(fsm);
    }
    else {
        const struct TurnstileState* EndStateName = getState(fsm);
        
        clearState(fsm);
        Turnstile_emit(ctxt, event);
        setState(fsm, EndStateName);
    }
}

const struct TurnstileState MainMap_Space = { POPULATE_STATE(MainMap_Space), 4 };

#undef MainMap_PreZKeyControl_keydown
static void MainMap_PreZKeyControl_keydown(struct satsukiContext *fsm, KeyEvent event)
{
    struct Turnstile* ctxt = getOwner(fsm);
    
    if ( event.is_z ) {
        EXIT_STATE(getState(fsm));
        /* No actions. */
        setState(fsm, &MainMap_ZKeyControl);
        ENTRY_STATE(getState(fsm));
    }
    else if ( event.is_space ) {
        EXIT_STATE(getState(fsm));
        /* No actions. */
        setState(fsm, &MainMap_ZKeyControl);
        ENTRY_STATE(getState(fsm));
        pushState(fsm, &MainMap_PreSpace);
        ENTRY_STATE(getState(fsm));
    }
    else {
        EXIT_STATE(getState(fsm));
        clearState(fsm);
        Turnstile_buffer(ctxt, event);
        setState(fsm, &MainMap_SemiZKeyControl);
        ENTRY_STATE(getState(fsm));
    }
}

#undef MainMap_PreZKeyControl_keyup
static void MainMap_PreZKeyControl_keyup(struct satsukiContext *fsm, KeyEvent event)
{
    struct Turnstile* ctxt = getOwner(fsm);
    
    if ( event.is_z ) {
        EXIT_STATE(getState(fsm));
        clearState(fsm);
        Turnstile_emit_z(ctxt);
        popState(fsm);
    }
    else {
        MainMap_DefaultState_keyup(fsm, event);
    }
}

const struct TurnstileState MainMap_PreZKeyControl = { POPULATE_STATE(MainMap_PreZKeyControl), 5 };

#undef MainMap_PreSlashControl_keydown
static void MainMap_PreSlashControl_keydown(struct satsukiContext *fsm, KeyEvent event)
{
    struct Turnstile* ctxt = getOwner(fsm);
    
    if ( event.is_slash ) {
        EXIT_STATE(getState(fsm));
        /* No actions. */
        setState(fsm, &MainMap_SlashControl);
        ENTRY_STATE(getState(fsm));
    }
    else if ( event.is_space ) {
        EXIT_STATE(getState(fsm));
        /* No actions. */
        setState(fsm, &MainMap_SlashControl);
        ENTRY_STATE(getState(fsm));
        pushState(fsm, &MainMap_PreSpace);
        ENTRY_STATE(getState(fsm));
    }
    else {
        EXIT_STATE(getState(fsm));
        clearState(fsm);
        Turnstile_buffer(ctxt, event);
        setState(fsm, &MainMap_SemiSlashControl);
        ENTRY_STATE(getState(fsm));
    }
}

#undef MainMap_PreSlashControl_keyup
static void MainMap_PreSlashControl_keyup(struct satsukiContext *fsm, KeyEvent event)
{
    struct Turnstile* ctxt = getOwner(fsm);
    
    if ( event.is_slash ) {
        EXIT_STATE(getState(fsm));
        clearState(fsm);
        Turnstile_emit_slash(ctxt);
        popState(fsm);
    }
    else {
        MainMap_DefaultState_keyup(fsm, event);
    }
}

const struct TurnstileState MainMap_PreSlashControl = { POPULATE_STATE(MainMap_PreSlashControl), 6 };

#undef MainMap_SemiZKeyControl_keydown
static void MainMap_SemiZKeyControl_keydown(struct satsukiContext *fsm, KeyEvent event)
{
    struct Turnstile* ctxt = getOwner(fsm);
    
    EXIT_STATE(getState(fsm));
    clearState(fsm);
    Turnstile_control_mode(ctxt, True);
    Turnstile_flush(ctxt);
    Turnstile_emit(ctxt, event);
    setState(fsm, &MainMap_ZKeyControl);
    ENTRY_STATE(getState(fsm));
}

#undef MainMap_SemiZKeyControl_keyup
static void MainMap_SemiZKeyControl_keyup(struct satsukiContext *fsm, KeyEvent event)
{
    struct Turnstile* ctxt = getOwner(fsm);
    
    if ( event.is_z ) {
        EXIT_STATE(getState(fsm));
        clearState(fsm);
        Turnstile_emit_z(ctxt);
        Turnstile_flush(ctxt);
        Turnstile_emit(ctxt, event);
        popState(fsm);
    }
    else {
        EXIT_STATE(getState(fsm));
        clearState(fsm);
        Turnstile_control_mode(ctxt, True);
        Turnstile_flush(ctxt);
        Turnstile_emit(ctxt, event);
        setState(fsm, &MainMap_ZKeyControl);
        ENTRY_STATE(getState(fsm));
    }
}

const struct TurnstileState MainMap_SemiZKeyControl = { POPULATE_STATE(MainMap_SemiZKeyControl), 7 };

#undef MainMap_SemiSlashControl_keydown
static void MainMap_SemiSlashControl_keydown(struct satsukiContext *fsm, KeyEvent event)
{
    struct Turnstile* ctxt = getOwner(fsm);
    
    EXIT_STATE(getState(fsm));
    clearState(fsm);
    Turnstile_control_mode(ctxt, True);
    Turnstile_flush(ctxt);
    Turnstile_emit(ctxt, event);
    setState(fsm, &MainMap_SlashControl);
    ENTRY_STATE(getState(fsm));
}

#undef MainMap_SemiSlashControl_keyup
static void MainMap_SemiSlashControl_keyup(struct satsukiContext *fsm, KeyEvent event)
{
    struct Turnstile* ctxt = getOwner(fsm);
    
    if ( event.is_slash ) {
        EXIT_STATE(getState(fsm));
        clearState(fsm);
        Turnstile_emit_slash(ctxt);
        Turnstile_flush(ctxt);
        Turnstile_emit(ctxt, event);
        popState(fsm);
    }
    else {
        EXIT_STATE(getState(fsm));
        clearState(fsm);
        Turnstile_control_mode(ctxt, True);
        Turnstile_flush(ctxt);
        Turnstile_emit(ctxt, event);
        setState(fsm, &MainMap_SlashControl);
        ENTRY_STATE(getState(fsm));
    }
}

const struct TurnstileState MainMap_SemiSlashControl = { POPULATE_STATE(MainMap_SemiSlashControl), 8 };

#undef MainMap_ZKeyControl_Entry
void MainMap_ZKeyControl_Entry(struct satsukiContext *fsm)
{
    struct Turnstile *ctxt = getOwner(fsm);
    
    Turnstile_control_mode(ctxt, True);
}

#undef MainMap_ZKeyControl_Exit
void MainMap_ZKeyControl_Exit(struct satsukiContext *fsm)
{
    struct Turnstile *ctxt = getOwner(fsm);
    
    Turnstile_control_mode(ctxt, False);
}

#undef MainMap_ZKeyControl_keydown
static void MainMap_ZKeyControl_keydown(struct satsukiContext *fsm, KeyEvent event)
{
    struct Turnstile* ctxt = getOwner(fsm);
    
    if ( event.is_z ) {
        /* No actions. */
    }
    else {
        const struct TurnstileState* EndStateName = getState(fsm);
        
        clearState(fsm);
        Turnstile_emit(ctxt, event);
        setState(fsm, EndStateName);
    }
}

#undef MainMap_ZKeyControl_keyup
static void MainMap_ZKeyControl_keyup(struct satsukiContext *fsm, KeyEvent event)
{
    struct Turnstile* ctxt = getOwner(fsm);
    
    if ( event.is_z ) {
        EXIT_STATE(getState(fsm));
        /* No actions. */
        popState(fsm);
    }
    else {
        const struct TurnstileState* EndStateName = getState(fsm);
        
        clearState(fsm);
        Turnstile_emit(ctxt, event);
        setState(fsm, EndStateName);
    }
}

const struct TurnstileState MainMap_ZKeyControl = { POPULATE_STATE(MainMap_ZKeyControl), 9 };

#undef MainMap_SlashControl_Entry
void MainMap_SlashControl_Entry(struct satsukiContext *fsm)
{
    struct Turnstile *ctxt = getOwner(fsm);
    
    Turnstile_control_mode(ctxt, True);
}

#undef MainMap_SlashControl_Exit
void MainMap_SlashControl_Exit(struct satsukiContext *fsm)
{
    struct Turnstile *ctxt = getOwner(fsm);
    
    Turnstile_control_mode(ctxt, False);
}

#undef MainMap_SlashControl_keydown
static void MainMap_SlashControl_keydown(struct satsukiContext *fsm, KeyEvent event)
{
    struct Turnstile* ctxt = getOwner(fsm);
    
    if ( event.is_slash ) {
        /* No actions. */
    }
    else {
        const struct TurnstileState* EndStateName = getState(fsm);
        
        clearState(fsm);
        Turnstile_emit(ctxt, event);
        setState(fsm, EndStateName);
    }
}

#undef MainMap_SlashControl_keyup
static void MainMap_SlashControl_keyup(struct satsukiContext *fsm, KeyEvent event)
{
    struct Turnstile* ctxt = getOwner(fsm);
    
    if ( event.is_slash ) {
        EXIT_STATE(getState(fsm));
        /* No actions. */
        popState(fsm);
    }
    else {
        const struct TurnstileState* EndStateName = getState(fsm);
        
        clearState(fsm);
        Turnstile_emit(ctxt, event);
        setState(fsm, EndStateName);
    }
}

const struct TurnstileState MainMap_SlashControl = { POPULATE_STATE(MainMap_SlashControl), 10 };

#ifdef NO_SATSUKI_SM_MACRO
void satsukiContext_Init(struct satsukiContext* fsm, struct Turnstile* owner)
{
    FSM_INIT(fsm, &MainMap_Normal);
    fsm->_owner = owner;
}

void satsukiContext_EnterStartState(struct satsukiContext* fsm)
{
    ENTRY_STATE(getState(fsm));
}

void satsukiContext_keydown(struct satsukiContext* fsm, KeyEvent event)
{
    const struct TurnstileState* state = getState(fsm);
    
    setTransition(fsm, "keydown");
    state->keydown(fsm, event);
    setTransition(fsm, NULL);
}

void satsukiContext_keyup(struct satsukiContext* fsm, KeyEvent event)
{
    const struct TurnstileState* state = getState(fsm);
    
    setTransition(fsm, "keyup");
    state->keyup(fsm, event);
    setTransition(fsm, NULL);
}
#endif

/*
 * Local variables:
 *  buffer-read-only: t
 * End:
 */