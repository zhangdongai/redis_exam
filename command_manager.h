#include <memory>
#include <vector>

#include "command.h"
#include "singleton.h"
#include "unbounded_queue.h"

class CommandManager {
public:
    using CommandPtr = std::shared_ptr<Command>;

    void push(const CommandPtr& command);
    CommandPtr pop();
private:
    UnboundedQueue<CommandPtr> commands_;
    SINGLETION_DECLARE(CommandManager);
};