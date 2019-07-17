#include <iostream>
#include <vector>
#include <memory>

#include "redis_manager.h"


int main(int argc, char** argv) {
    RedisManager::instance()->main_loop();
/*    redisContext* context = redisConnect("127.0.0.1", 6379);
    if (context->err) {
        redisFree(context);
        std::cout << "connect failed!" << std::endl;
        return 0;
    }
    std::cout << "connect success!" << std::endl;

    int key = 1234;
    const char* value = "who is your daddy";
    redisReply* reply = static_cast<redisReply*>(redisCommand(context, "SET %d %s", key, value));
    if (reply == nullptr) {
        std::cout << "execute SET command failed" << std::endl;
        redisFree(context);
        return 0;
    }

    if (reply->type == REDIS_REPLY_STATUS) {
        std::cout << "execute SET command success, str = " << reply->str << std::endl;
    }
    freeReplyObject(reply);

    reply = static_cast<redisReply*>(redisCommand(context, "GET %d", key));
    if (reply == nullptr) {
        std::cout << "execute GET command failed" << std::endl;
        redisFree(context);
        return 0;
    }
    if (reply->type != REDIS_REPLY_STRING) {
        std::cout << "execute GET command failed, no string" << std::endl;
        redisFree(context);
        return 0;
    }
    std::cout << "execute GET command success! value = " << reply->str << std::endl;
    freeReplyObject(reply);

    redisFree(context);
*/
    getchar();
    return 0;
}