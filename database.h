#ifndef __DATABASE_H__
#define __DATABASE_H__

#pragma once
#include <unordered_map>
#include <string>
#include <shared_mutex>

class Database
{
private:
    std::unordered_map<std::string, std::string> store_;

    std::shared_mutex rw_mutex_;

public:
    Database();
    std::string Get(const std::string &key);
    bool Set(const std::string &key, const std::string &value);
    bool Delete(const std::string &key);
};

#endif // __DATABASE_H__