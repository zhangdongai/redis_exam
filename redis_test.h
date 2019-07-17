#pragma once
#include <stdlib.h>

bool g_stop = false;
void redis_test() {
    while (!g_stop) {
        std::thread::id thread_id = std::this_thread::get_id();
        std::string id_str;
        std::ostringstream os;
        os << thread_id;
        os >> id_str;
    }
}