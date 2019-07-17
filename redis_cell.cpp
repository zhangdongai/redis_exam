#include "redis_cell.h"

#include <iostream>

#include "command_manager.h"

RedisCell::~RedisCell() {
    redisFree(context_);
}

void RedisCell::init() {
    connect_redis();
    state_ = CellState::READY;
}

bool RedisCell::connect_redis() {
    context_ = redisConnect("127.0.0.1", 6379);
    if (context_->err) {
        redisFree(context_);
        std::cout << "connect failed!" << std::endl;
        return false;
    }
    std::cout << "connect success!" << std::endl;
    return true;
}

void RedisCell::loop() {
    state_ = CellState::RUNNING;

    CommandPtr command = CommandManager::instance()->pop();
    if (command) {
        execute_command(command);
    }

    state_ = CellState::READY;
}

bool RedisCell::execute_command(const CommandPtr& command) {
    std::string command_str = command->get_command_str;
    redisReply* reply = static_cast<redisReply*>(redisCommand(
        context_, command_str.c_str(),
        command->key().c_str(), command->value().c_str()));
    if (reply == nullptr) {
        std::cout << "execute SET command failed" << std::endl;
        return false;
    }

    command->parse_reply(reply);
    
    freeReplyObject(reply);
    return true;
}