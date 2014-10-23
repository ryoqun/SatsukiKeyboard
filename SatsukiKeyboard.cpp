#include <IOKit/IOLib.h>
#include <IOKit/hid/IOHIDUsageTables.h>

#include "SatsukiKeyboard.h"


#define super IOHIDEventDriver

OSDefineMetaClassAndStructors(SatsukiKeyboard, IOHIDEventDriver)

bool SatsukiKeyboard::start(IOService *provider)
{
  printf("SatsukiKeyboard start\n");
  printf("SMC\n");
  resetMode();
  satsukiContext_Init(&mSatsukiContext, (struct Turnstile*)this, (const struct TurnstileState**)mStack);
  satsukiContext_EnterStartState(&mSatsukiContext);
  return super::start(provider);
}

void SatsukiKeyboard::stop(IOService *provider)
{
  printf("SatsukiKeyboard stop\n");
  resetMode();
  return super::stop(provider);
}

void SatsukiKeyboard::resetMode()
{
  resetSpaceMode();
  resetShiftMode();
  resetTenkeyMode();
  commandMode = false;
}

void SatsukiKeyboard::resetSpaceMode()
{
  spaceMode = false;
}

void SatsukiKeyboard::resetShiftMode()
{
  shiftMode = false;
}

void SatsukiKeyboard::resetTenkeyMode()
{
  tenkeyMode = false;
}

bool SatsukiKeyboard::isPressedDown(UInt32 value)
{
  return value == PRESS_DOWN;
}

bool SatsukiKeyboard::isPressedUp(UInt32 value)
{
  return value == PRESS_UP;
}

void SatsukiKeyboard::emitPressDown(UInt32 usage)
{
  KeyEvent ke = {
    usage,
    PRESS_DOWN,
    0,
    usage == kHIDUsage_KeyboardSpacebar,
    usage == kHIDUsage_KeyboardSlash,
    usage == kHIDUsage_KeyboardZ,
    usage == kHIDUsage_KeyboardMuhenkan,
    usage == kHIDUsage_KeyboardHenkan,
    usage == kHIDUsage_KeyboardPeriod,
  };
  emit(ke);
}

void SatsukiKeyboard::emitPressUp(UInt32 usage)
{
  KeyEvent ke = {
    usage,
    PRESS_UP,
    0,
    usage == kHIDUsage_KeyboardSpacebar,
    usage == kHIDUsage_KeyboardSlash,
    usage == kHIDUsage_KeyboardZ,
    usage == kHIDUsage_KeyboardMuhenkan,
    usage == kHIDUsage_KeyboardHenkan,
    usage == kHIDUsage_KeyboardPeriod,
  };
  emit(ke);
}

void SatsukiKeyboard::dispatchPressDown(UInt32 usage)
{
  dispatch(usage, PRESS_DOWN);
}

void SatsukiKeyboard::dispatchPressUp(UInt32 usage)
{
  dispatch(usage, PRESS_UP);
}

void SatsukiKeyboard::dispatch(UInt32 usage, UInt32 value, IOOptionBits options)
{
  super::dispatchKeyboardEvent(currentTimeStamp, currentUsagePage, usage, value, options);
}

bool SatsukiKeyboard::translateTenkeyMode(UInt32 originalUsage,
                                          UInt32 &outUsage)
{
  bool translated = true;
  UInt32 usage;

  switch (originalUsage) {
    case kHIDUsage_KeyboardQ:
      usage = kHIDUsage_Keyboard1;
      break;
    case kHIDUsage_KeyboardW:
      usage = kHIDUsage_Keyboard2;
      break;
    case kHIDUsage_KeyboardE:
      usage = kHIDUsage_Keyboard3;
      break;
    case kHIDUsage_KeyboardR:
      usage = kHIDUsage_Keyboard4;
      break;
    case kHIDUsage_KeyboardT:
      usage = kHIDUsage_Keyboard5;
      break;
    case kHIDUsage_KeyboardY:
      usage = kHIDUsage_Keyboard6;
      break;
    case kHIDUsage_KeyboardU:
      usage = kHIDUsage_Keyboard7;
      break;
    case kHIDUsage_KeyboardI:
      usage = kHIDUsage_Keyboard8;
      break;
    case kHIDUsage_KeyboardO:
      usage = kHIDUsage_Keyboard9;
      break;
    case kHIDUsage_KeyboardP:
      usage = kHIDUsage_Keyboard0;
      break;

    case kHIDUsage_KeyboardA:
      usage = kHIDUsage_KeyboardTab;
      break;
    case kHIDUsage_KeyboardS:
      usage = kHIDUsage_KeyboardDeleteForward;
      break;
    case kHIDUsage_KeyboardD:
      usage = kHIDUsage_KeyboardDeleteOrBackspace;
      break;
    case kHIDUsage_KeyboardF:
      usage = kHIDUsage_KeyboardEscape;
      break;

    case kHIDUsage_KeyboardH:
      usage = kHIDUsage_KeyboardLeftArrow;
      break;
    case kHIDUsage_KeyboardJ:
      usage = kHIDUsage_KeyboardDownArrow;
      break;
    case kHIDUsage_KeyboardK:
      usage = kHIDUsage_KeyboardUpArrow;
      break;
    case kHIDUsage_KeyboardL:
      usage = kHIDUsage_KeyboardRightArrow;
      break;
    case kHIDUsage_KeyboardSemicolon:
      usage = kHIDUsage_KeyboardReturnOrEnter;
      break;
    default:
      translated = false;
      break;
  }

  if (translated) {
    outUsage = usage;
  }

  return translated;
}

bool SatsukiKeyboard::translateSpaceMode(UInt32 originalUsage,
                                         UInt32 &outUsage,
                                         bool &outShiftModifier)
{
  bool translated = true;
  UInt32 usage;
  bool shiftModifier;

  switch (originalUsage) {
    case kHIDUsage_KeyboardQ:
      usage = kHIDUsage_Keyboard1;
      shiftModifier = true;
      break;
    case kHIDUsage_KeyboardW:
      usage = kHIDUsage_Keyboard2;
      shiftModifier = true;
      break;
    case kHIDUsage_KeyboardE:
      usage = kHIDUsage_Keyboard3;
      shiftModifier = true;
      break;
    case kHIDUsage_KeyboardR:
      usage = kHIDUsage_Keyboard4;
      shiftModifier = true;
      break;
    case kHIDUsage_KeyboardT:
      usage = kHIDUsage_Keyboard5;
      shiftModifier = true;
      break;
    case kHIDUsage_KeyboardY:
      usage = kHIDUsage_Keyboard6;
      shiftModifier = true;
      break;
    case kHIDUsage_KeyboardU:
      usage = kHIDUsage_Keyboard7;
      shiftModifier = true;
      break;
    case kHIDUsage_KeyboardI:
      usage = kHIDUsage_Keyboard8;
      shiftModifier = true;
      break;
    case kHIDUsage_KeyboardO:
      usage = kHIDUsage_Keyboard9;
      shiftModifier = true;
      break;
    case kHIDUsage_KeyboardP:
      usage = kHIDUsage_Keyboard0;
      shiftModifier = true;
      break;

    case kHIDUsage_KeyboardA:
      usage = kHIDUsage_KeyboardHyphen;
      shiftModifier = true;
      break;
    case kHIDUsage_KeyboardS:
      usage = kHIDUsage_KeyboardHyphen;
      shiftModifier = false;
      break;
    case kHIDUsage_KeyboardD:
      usage = kHIDUsage_KeyboardOpenBracket;
      shiftModifier = false;
      break;
    case kHIDUsage_KeyboardF:
      usage = kHIDUsage_KeyboardCloseBracket;
      shiftModifier = false;
      break;
    case kHIDUsage_KeyboardG:
      usage = kHIDUsage_KeyboardQuote;
      shiftModifier = false;
      break;
    case kHIDUsage_KeyboardH:
      usage = kHIDUsage_KeyboardQuote;
      shiftModifier = true;
      break;
    case kHIDUsage_KeyboardJ:
      usage = kHIDUsage_KeyboardOpenBracket;
      shiftModifier = true;
      break;
    case kHIDUsage_KeyboardK:
      usage = kHIDUsage_KeyboardCloseBracket;
      shiftModifier = true;
      break;
    case kHIDUsage_KeyboardL:
      usage = kHIDUsage_KeyboardGraveAccentAndTilde;
      shiftModifier = true;
      break;
    case kHIDUsage_KeyboardSemicolon:
      usage = kHIDUsage_KeyboardSemicolon;
      shiftModifier = true;
      break;

    case kHIDUsage_KeyboardX:
      usage = kHIDUsage_KeyboardGraveAccentAndTilde;
      shiftModifier = false;
      break;
    case kHIDUsage_KeyboardC:
      usage = kHIDUsage_KeyboardBackslash;
      shiftModifier = false;
      break;
    case kHIDUsage_KeyboardV:
      usage = kHIDUsage_KeyboardEqualSign;
      shiftModifier = false;
      break;
    case kHIDUsage_KeyboardB:
      usage = kHIDUsage_KeyboardBackslash;
      shiftModifier = true;
      break;
    case kHIDUsage_KeyboardN:
      usage = kHIDUsage_KeyboardEqualSign;
      shiftModifier = true;
      break;
    case kHIDUsage_KeyboardM:
      usage = kHIDUsage_KeyboardSpacebar;
      shiftModifier = true;
      break;
    case kHIDUsage_KeyboardComma:
      usage = kHIDUsage_KeyboardComma;
      shiftModifier = true;
      break;
    case kHIDUsage_KeyboardPeriod:
      usage = kHIDUsage_KeyboardPeriod;
      shiftModifier = true;
      break;
    case kHIDUsage_KeyboardSlash:
      usage = kHIDUsage_KeyboardSlash;
      shiftModifier = true;
      break;
    default:
      translated = false;
      break;
  }

  if (translated) {
    outUsage = usage;
    outShiftModifier = shiftModifier;
  }

  return translated;
}

void SatsukiKeyboard::buffer(KeyEvent key_event) {
  bufferedKeyEvent = key_event;
}

void SatsukiKeyboard::flush() {
  emit(bufferedKeyEvent);
}

void SatsukiKeyboard::emit(KeyEvent key_event) {
    printf("Satsuki emit Key event: %u %u %u (space: %d control: %d tenkey: %d shift: %d)\n",
           (unsigned int)key_event.usage,
           (unsigned int)key_event.value,
           (unsigned int)key_event.options,
           (int)spaceMode,
           (int)controlMode,
           (int)tenkeyMode,
           (int)shiftMode);

    UInt32 translatedUsage, originalUsage;
    translatedUsage = originalUsage = key_event.usage;
    bool shiftModifier = false;
  
    if (spaceMode) {
        translateSpaceMode(originalUsage, translatedUsage, shiftModifier);
    }
    
    if (tenkeyMode) {
        translateTenkeyMode(originalUsage, translatedUsage);
    }

    if (isPressedDown(key_event.value)) {
      if (shiftModifier or shiftMode) {
        dispatchPressDown(kHIDUsage_KeyboardLeftShift);
      }
      
      if (controlMode) {
        dispatchPressDown(kHIDUsage_KeyboardRightControl);
      }

      if (commandMode) {
        dispatchPressDown(kHIDUsage_KeyboardRightGUI);
      }
    }
    
    dispatch(translatedUsage, key_event.value, key_event.options);
    
    if(isPressedUp(key_event.value)) {
      if (shiftModifier or shiftMode) {
        dispatchPressUp(kHIDUsage_KeyboardLeftShift);
      }

      if (controlMode) {
        dispatchPressUp(kHIDUsage_KeyboardRightControl);
      }
      if (commandMode) {
        dispatchPressUp(kHIDUsage_KeyboardRightGUI);
      }
    }
}

void SatsukiKeyboard::space_mode(char flag){
  printf("SMC space mode: %d!!!\n", (int)flag);
  spaceMode = flag;
  if(!flag) {
    dispatchPressUp(kHIDUsage_KeyboardLeftShift);
  }
}

void SatsukiKeyboard::tenkey_mode(char flag){
  printf("SMC tenkey mode: %d!!!\n", (int)flag);
  tenkeyMode = flag;
}

void SatsukiKeyboard::shift_mode(char flag){
  printf("SMC shift mode: %d!!!\n", (int)flag);
  shiftMode = flag;
  if(!flag) {
    dispatchPressUp(kHIDUsage_KeyboardLeftShift);
  }
}

void SatsukiKeyboard::control_mode(char flag){
  printf("SMC control mode: %d!!!\n", (int)flag);
  controlMode = flag;
  if(!flag) {
    dispatchPressUp(kHIDUsage_KeyboardRightControl);
  }
}

void SatsukiKeyboard::meta_mode(char flag){
  printf("SMC meta mode: %d!!!\n", (int)flag);
  commandMode = flag;
  if(!flag) {
    dispatchPressUp(kHIDUsage_KeyboardRightGUI);
  }
}

void SatsukiKeyboard::handleKeyboardMode(UInt32 usage,
                                         UInt32 value,
                                         IOOptionBits options)
{
  KeyEvent ke = {
      usage,
      value,
      options,
      usage == kHIDUsage_KeyboardSpacebar,
      usage == kHIDUsage_KeyboardSlash,
      usage == kHIDUsage_KeyboardZ,
      ((usage == kHIDUsage_KeyboardMuhenkan) or (usage == kHIDUsage_KeyboardLeftGUI)),
      ((usage == kHIDUsage_KeyboardHenkan) or (usage == kHIDUsage_KeyboardRightGUI)),
      usage == kHIDUsage_KeyboardPeriod,
  };

  //printf("Key event: %u %u %u\n",
    //     (unsigned int) usage,
      //   (unsigned int)value,
        // (unsigned int)options);

    //printf("before stack size: %ld\n", mSatsukiContext._stack_curr - mSatsukiContext._stack_start);
    if(isPressedDown(value)) {
        satsukiContext_keydown(&mSatsukiContext, ke);
    } else if (isPressedUp(value)){
        satsukiContext_keyup(&mSatsukiContext, ke);
    }
    //printf("after stack size: %ld\n", mSatsukiContext._stack_curr - mSatsukiContext._stack_start);
}

void SatsukiKeyboard::dispatchKeyboardEvent(AbsoluteTime timeStamp,
                                            UInt32 usagePage,
                                            UInt32 usage,
                                            UInt32 value,
                                            IOOptionBits options)
{
  if (usagePage != kHIDPage_KeyboardOrKeypad) {
    super::dispatchKeyboardEvent(timeStamp,
                                 usagePage,
                                 usage,
                                 value,
                                 options);
    return;
  }

  currentTimeStamp = timeStamp;
  currentUsagePage = usagePage;
  handleKeyboardMode(usage, value, options);
}
