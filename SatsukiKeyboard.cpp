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
