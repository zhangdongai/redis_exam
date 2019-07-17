#include "set_command.h"

void SetCommand::parse_reply(const redisReply* reply) override {
    if (reply->type == REDIS_REPLY_STATUS) {
        std::cout << "execute SET command success, str = " << reply->str << std::endl;
    }
}