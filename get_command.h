#include "command.h"

class GetCommand : public Command {
public:
    GetCommand(const std::string& key,
            std::string& value, CommandCallback callback) :
        Command(CommandType::GET, key, value, callback) {}

    const std::string&& get_command_str() override {
        return "GET %s";
    }

    void parse_reply(const redisReply* reply) override;
};