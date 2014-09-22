sudo cp -R /Users/ryo-onodera/Library/Developer/Xcode/DerivedData/SatsukiKeyboard-dlwupfdjqpqeebeuoxglrevxugfn/Build/Products/Debug/SatsukiKeyboard.kext /tmp
sudo kextutil -t /tmp/SatsukiKeyboard.kext/
sudo kextunload /tmp/SatsukiKeyboard.kext/
sudo kextload /tmp/SatsukiKeyboard.kext/
#sudo -k
