#include <IOKit/IOLib.h>
#include <IOKit/hid/IOHIDUsageTables.h>

#include "SatsukiKeyboard.h"

#define super IOHIDEventDriver

OSDefineMetaClassAndStructors(SatsukiKeyboard, IOHIDEventDriver)

bool SatsukiKeyboard::start(IOService *provider)
{
  printf("SatsukiKeyboard start\n");
  return super::start(provider);
}

void SatsukiKeyboard::stop(IOService *provider)
{
  printf("SatsukiKeyboard stop\n");
  return super::stop(provider);
}

void SatsukiKeyboard::dispatchKeyboardEvent(AbsoluteTime timeStamp,
                                            UInt32 usagePage,
                                            UInt32 usage,
                                            UInt32 value,
                                            IOOptionBits options)
{
  printf("Keyboard Event\n");
  super::dispatchKeyboardEvent(timeStamp,
                               usagePage,
                               usage,
                               value,
                               options);
}
