#pragma once

#include <functional>
#include <string>

enum class CommandType {
    SET = 0,
    GET = 1,
};

class redisReply;
class Command {
public:
    using CommandCallback = std::function<void(const std::string&)>;
    Command(CommandType type, const std::string& key,
            std::string& value, CommandCallback callback);

    CommandType command_type() const {return command_type_;}
    std::string key() const {return key_;}
    std::string value() const {return value_;}
    CommandCallback callback() const {return callback_;}

    virtual const std::string&& get_command_str() = 0;
    virtual void parse_reply(const redisReply* reply) = 0;

private:
    CommandType command_type_;
    std::string key_;
    std::string value_;
    CommandCallback callback_;
};