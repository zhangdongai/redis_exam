#include <memory>
#include <vector>

#include "redis_cell.h"
#include "singleton.h"
#include "thread_pool.h"

class RedisManager {
public:
    ~RedisManager() {
        pool_.reset();
    }
    void main_loop();
private:
    void init();
    void update_cells();
    std::vector<RedisCell> redis_cells_;
    std::shared_ptr<ThreadPool> pool_;

    SINGLETION_DECLARE(RedisManager);
};