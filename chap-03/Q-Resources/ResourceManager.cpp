#include "ResourceManager.h"

size_t ResourceManager::create(const std::string& content) {
    _resources.emplace_back(std::make_unique<Resource>(content));
    return _resources.size();
}

void ResourceManager::destroy(size_t index) {
    auto tmp = std::move(_resources.at(index));
}

size_t ResourceManager::acquire(std::unique_ptr<Resource> resource) {
    _resources.emplace_back(std::move(resource));
    return _resources.size();
}

std::unique_ptr<Resource> ResourceManager::yield(size_t index) {
    return std::move(_resources.at(index));
}

Resource& ResourceManager::get(size_t index) const {
    Resource& ref = *_resources.at(index);
    return ref;
}