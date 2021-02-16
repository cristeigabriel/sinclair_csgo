#include "../../game.h"

#include "../../../cstrike/cstrike.h"

//  this is disgusting...
int __cdecl game::hooking::functions::prototypes::vsnprintf::hooked(char* dest, int text_len, const char* fmt, ...) {
    int v4; //  ecx

    va_list args;
    va_start(args, fmt);
    if (_ReturnAddress() == pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_NET_GRAPH_TEXT_MAIN_MENU_RET_ADDR] ||
        _ReturnAddress() == pe::util::prototypes::static_addresses[pe::util::StaticAddresses::ADDRESS_NET_GRAPH_TEXT_GAME_RET_ADDR]) {
        //  This isn't safe, but according to caps should never be an issue unless you get a trillion ping
        char buf[256] = "[sinclair] ";
        strcat_s(buf, fmt);
        v4 = _vsnprintf(dest, text_len, buf, args);
    }
    else {
        v4 = _vsnprintf(dest, text_len, fmt, args);
    }
    va_end(args);

    if ((v4 < 0) || (text_len > 0 && v4 >= text_len)) {
        v4 = text_len - 1;
        dest[text_len - 1] = '\0';
    }

    return v4;
}