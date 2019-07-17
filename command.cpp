#include "command.h"

Command::Command(CommandType type, const std::string& key,
                 std::string& value, CommandCallback callback) :
    command_type_(type),
    key_(key),
    value_(value),
    callback_(callback) {}
