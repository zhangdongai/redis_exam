#include "command_manager.h"

CommandManager::CommandManager() {}

void CommandManager::push(const CommandPtr& command) {
    commands_.Enqueue(command);
}

CommandPtr CommandManager::pop() {
    CommandPtr command;
    if (!commands_.Dequeue(&command)) {
        return nullptr;
    }
    return command;
}