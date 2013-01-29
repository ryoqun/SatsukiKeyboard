sudo cp -R ./build/Debug/SatsukiKeyboard.kext /tmp
sudo kextutil -t /tmp/SatsukiKeyboard.kext/
sudo kextunload /tmp/SatsukiKeyboard.kext/
sudo kextload /tmp/SatsukiKeyboard.kext/
sudo -k
