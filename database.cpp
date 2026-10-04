
#include "database.h"
#include <mutex>

Database::Database()
{
}

std::string Database::Get(const std::string &key)
{
    std::shared_lock lock(rw_mutex_);

    auto it = store_.find(key);

    if (it != store_.end())
    {
        return it->second;
    }

    return "(nil)";
}

bool Database::Set(const std::string &key, const std::string &value)
{
    std::unique_lock lock(rw_mutex_);

    Database::store_[key] = value;

    return true;
}

bool Database::Delete(const std::string &key)
{
    std::unique_lock lock(rw_mutex_);

    return store_.erase(key) > 0;
}
