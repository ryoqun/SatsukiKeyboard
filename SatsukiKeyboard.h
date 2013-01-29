#include <IOKit/hidevent/IOHIDEventDriver.h>

class SatsukiKeyboard : public IOHIDEventDriver
{
  OSDeclareDefaultStructors(SatsukiKeyboard)

public:
  virtual bool start(IOService *provider);
  virtual void stop(IOService *provider);

  // We intercept keyboard events and handle special ones by overriding this virtual member function.
  virtual void dispatchKeyboardEvent(AbsoluteTime timeStamp,
                                     UInt32 usagePage,
                                     UInt32 usage,
                                     UInt32 value,
                                     IOOptionBits options=0);
};
