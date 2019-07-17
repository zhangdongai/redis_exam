#include "command.h"

class SetCommand : public Command {
public:
    SetCommand(const std::string& key,
            std::string& value, CommandCallback callback) :
        Command(CommandType::SET, key, value, callback) {}

    const std::string&& get_command_str() override {
        return "SET %s %s";
    }

    void parse_reply(const redisReply* reply) override;
};