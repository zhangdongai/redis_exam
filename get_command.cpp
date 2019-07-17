#include "get_command.h"

void GetCommand::parse_reply(const redisReply* reply) override {
    if (reply->type == REDIS_REPLY_STRING) {
        if (command->callback()) {
            command->callback()(reply->str);
        }
    }
    else if (reply->type == REDIS_REPLY_NIL) {
        // todo
    }
}