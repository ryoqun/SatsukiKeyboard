#include <IOKit/hidevent/IOHIDEventDriver.h>

class SatsukiKeyboard : public IOHIDEventDriver
{
  OSDeclareDefaultStructors(SatsukiKeyboard)

public:
  virtual bool start(IOService *provider);
  virtual void stop(IOService *provider);
};
