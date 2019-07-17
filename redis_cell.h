#pragma once

#include <memory>

#include "hiredis/hiredis.h"

#include "command.h"

enum class CellState {
    INVALID = -1,
    READY = 0,
    RUNNING = 1,
};

class RedisCell {
public:
    using CommandPtr = std::shared_ptr<Command>;
    ~RedisCell();
    void init();
    void loop();

    CellState get_state() const {
        return state_;
    }
private:
    bool connect_redis();
    bool execute_command(const CommandPtr& command);
    redisContext* context_ = nullptr;
    CellState state_ = CellState::INVALID;
};