#include "redis_manager.h"

RedisManager::RedisManager() {
    redis_cells_.resize(10);
    init();
}

void RedisManager::init() {
    for (auto& e : redis_cells_) {
        e.init();
    }

    pool_ = std::make_shared<ThreadPool>(4);
}

void RedisManager::main_loop() {
    update_cells();
}

void RedisManager::update_cells() {
    for (auto& e : redis_cells_) {
        if (e.get_state() == CellState::READY) {
            pool_->Enqueue(&RedisCell::loop, &e);
        }
    }
}