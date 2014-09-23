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
  shiftPressed = false;
  resetSpaceMode();
  resetShiftMode();
  resetTenkeyMode();
  commandMode = commandModeUsed = false;
}

void SatsukiKeyboard::resetSpaceMode()
{
  spaceMode = spaceModeUsed = false;
}

void SatsukiKeyboard::resetShiftMode()
{
  shiftMode = false;
}

void SatsukiKeyboard::resetTenkeyMode()
{
  tenkeyMode = tenkeyModeUsed = false;
}

bool SatsukiKeyboard::isPressedDown(UInt32 value)
{
  return value == PRESS_DOWN;
}

bool SatsukiKeyboard::isPressedUp(UInt32 value)
{
  return value == PRESS_UP;
}

void SatsukiKeyboard::dispatchPressDown(UInt32 usage)
{
  dispatch(usage, PRESS_DOWN);
}

void SatsukiKeyboard::dispatchPressUp(UInt32 usage)
{
  dispatch(usage, PRESS_UP);
}

void SatsukiKeyboard::dispatchShiftDown()
{
  dispatchPressDown(kHIDUsage_KeyboardLeftShift);
  shiftPressed = true;
}

void SatsukiKeyboard::dispatchShiftUp()
{
  dispatchPressUp(kHIDUsage_KeyboardLeftShift);
  shiftPressed = false;
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
        dispatchShiftDown();
      }
      
      if (controlMode) {
        dispatchPressDown(kHIDUsage_KeyboardRightControl);
      }
    }
    
    dispatch(translatedUsage, key_event.value, key_event.options);
    
    if(isPressedUp(key_event.value)) {
      if (shiftModifier or shiftMode) {
        dispatchShiftUp();
      }

      if (controlMode) {
        dispatchPressUp(kHIDUsage_KeyboardRightControl);
      }
    }
}

void SatsukiKeyboard::space_mode(char flag){
    printf("SMC space mode: %d!!!\n", (int)flag);
    spaceMode = flag;
}

void SatsukiKeyboard::tenkey_mode(char flag){
    printf("SMC tenkey mode: %d!!!\n", (int)flag);
    tenkeyMode = flag;
}

void SatsukiKeyboard::shift_mode(char flag){
    printf("SMC shift mode: %d!!!\n", (int)flag);
    shiftMode = flag;
}

void SatsukiKeyboard::control_mode(char flag){
    printf("SMC control mode: %d!!!\n", (int)flag);
    controlMode = flag;
}

void SatsukiKeyboard::handleKeyboardMode(UInt32 usage,
                                         UInt32 value,
                                         IOOptionBits options)
{
  bool ignore = false;

  KeyEvent ke = {
      usage,
      value,
      options,
      usage == kHIDUsage_KeyboardSpacebar,
      0, //usage == kHIDUsage_KeyboardSlash,
      usage == kHIDUsage_KeyboardZ,
      usage == kHIDUsage_KeyboardMuhenkan,
      usage == kHIDUsage_KeyboardHenkan,
  };

  //printf("Key event: %u %u %u\n",
    //     (unsigned int) usage,
      //   (unsigned int)value,
        // (unsigned int)options);

    printf("before stack size: %ld\n", mSatsukiContext._stack_curr - mSatsukiContext._stack_start);
    if(isPressedDown(value)) {
        satsukiContext_keydown(&mSatsukiContext, ke);
    } else if (isPressedUp(value)){
        satsukiContext_keyup(&mSatsukiContext, ke);
    }
    printf("after stack size: %ld\n", mSatsukiContext._stack_curr - mSatsukiContext._stack_start);
    return;
    
  if (usage == kHIDUsage_KeyboardSpacebar) {
    if (isPressedDown(value)) {
        if(commandMode) {
            commandModeUsed = true;
        }
      ignore = true;
      spaceMode = true;
    } else if (isPressedUp(value)) {
      if (spaceModeUsed) {
        ignore = true;
        if (shiftPressed && !shiftMode) {
          dispatchShiftUp();
        }
      } else {
          dispatchPressDown(kHIDUsage_KeyboardSpacebar);
      }
      resetSpaceMode();
    } else {
      printf("unrecognized key event value: %u\n", (unsigned int)value);
    }
  } else if (usage == kHIDUsage_KeyboardHenkan) {
    ignore = true;

    if (isPressedDown(value) and !shiftPressed) {
      shiftMode = true;
      dispatchShiftDown();
    } else if (isPressedUp(value) and shiftPressed) {
      shiftMode = false;
      dispatchShiftUp();
    }
  } else if (usage == kHIDUsage_KeyboardMuhenkan) {
    ignore = true;

    if (isPressedDown(value)) {
      tenkeyMode = true;
    } else {
      resetTenkeyMode();
    }
  } else if (usage == kHIDUsage_KeyboardSlash) {
      if (isPressedDown(value)) {
          ignore = true;
          controlMode = true;
          dispatchPressDown(kHIDUsage_KeyboardRightControl);
      } else if (isPressedUp(value)) {
          dispatchPressUp(kHIDUsage_KeyboardRightControl);
          if (controlModeUsed) {
              ignore = true;
              controlModeUsed = false;
          } else {
              dispatchPressDown(kHIDUsage_KeyboardSlash);
          }
          controlMode = false;
      } else {
          printf("unrecognized key event value: %u\n", (unsigned int)value);
      }
  } else if (usage == kHIDUsage_KeyboardZ) {
      if (isPressedDown(value)) {
          ignore = true;
          controlMode = true;
          dispatchPressDown(kHIDUsage_KeyboardRightControl);
      } else if (isPressedUp(value)) {
          dispatchPressUp(kHIDUsage_KeyboardRightControl);
          if (controlModeUsed) {
              ignore = true;
              controlModeUsed = false;
          } else {
              dispatchPressDown(kHIDUsage_KeyboardZ);
          }
          controlMode = false;
      } else {
          printf("unrecognized key event value: %u\n", (unsigned int)value);
      }
  } else if (usage == kHIDUsage_KeyboardPeriod) {
    if (isPressedDown(value)) {
        ignore = true;
        commandMode = true;
        dispatchPressDown(kHIDUsage_KeyboardRightGUI);
    } else if (isPressedUp(value)) {
        dispatchPressUp(kHIDUsage_KeyboardRightGUI);
        if (commandModeUsed) {
            ignore = true;
            commandModeUsed = false;
        } else {
            dispatchPressDown(kHIDUsage_KeyboardPeriod);
        }
        commandMode = false;
    } else {
        printf("unrecognized key event value: %u\n", (unsigned int)value);
    }
}

  if (ignore) {
    return;
  }

  UInt32 originalUsage = usage;
  bool shiftModifier = false;

  if (spaceMode) {
    if (isPressedDown(value)) {
      spaceModeUsed = true;
    }

    if (spaceModeUsed and translateSpaceMode(originalUsage, usage, shiftModifier)) {
      if (shiftModifier and isPressedDown(value) and !shiftPressed) {
        dispatchShiftDown();
      } else if (!shiftModifier and isPressedDown(value) and shiftPressed) {
        dispatchShiftUp();
      }
    }
  }

  if (tenkeyMode) {
    if (isPressedDown(value)) {
      tenkeyModeUsed = true;
    }
    if (tenkeyModeUsed) {
      translateTenkeyMode(originalUsage, usage);
    }
  }

    if (controlMode) {
        if (isPressedDown(value)) {
            controlModeUsed = true;
        }
    }
    
    if(commandMode) {
        if(isPressedDown(value)) {
            commandModeUsed = true;
        }
    }

  dispatch(usage, value, options);

  if (shiftModifier and shiftPressed and isPressedUp(value) and !shiftMode) {
    dispatchShiftUp();
  } else if (!shiftModifier and !shiftPressed and isPressedUp(value) and shiftMode) {
    dispatchShiftDown();
  }
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
