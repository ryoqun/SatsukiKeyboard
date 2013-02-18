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

private:
  static const UInt32 PRESS_DOWN = 1;
  static const UInt32 PRESS_UP = 0;
  static const UInt32 kHIDUsage_KeyboardHenkan = 138;
  static const UInt32 kHIDUsage_KeyboardMuhenkan = 139;
  bool spaceMode, spaceModeUsed;
  bool shiftMode;
  bool tenkeyMode, tenkeyModeUsed;
  bool controlMode, controlModeUsed;
  bool shiftPressed;

  AbsoluteTime currentTimeStamp;
  UInt32 currentUsagePage;

  bool isPressedDown(UInt32 value);
  bool isPressedUp(UInt32 value);

  void dispatchPressDown(UInt32 usage);
  void dispatchPressUp(UInt32 usage);

  void dispatchShiftDown();
  void dispatchShiftUp();

  void dispatch(UInt32 usage,
                UInt32 value,
                IOOptionBits options=0);

  void handleKeyboardMode(UInt32 usage,
                          UInt32 value,
                          IOOptionBits options);

  bool translateSpaceMode(UInt32 original_usage,
                          UInt32 &usage,
                          bool &shift_modifier);
  bool translateTenkeyMode(UInt32 original_usage,
                           UInt32 &usage);

  void resetMode();
  void resetSpaceMode();
  void resetShiftMode();
  void resetTenkeyMode();
};
