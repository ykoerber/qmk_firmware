// the crkbd and aurora corne keymaps are one and the same. this used to be a
// symlink, but the macOS file sharing used for docker builds refuses to read
// symlinks whose target climbs upward with "..", so a real file #includes the
// shared source instead.
#include "../../../../../crkbd/keymaps/ykoerber/keymap.c"
