#pragma once
#include <memory>
#include <string>
#include <vector>

struct Resource
{
    Resource(const std::string& content)
        : _content { content } {}

    std::string _content;
};

// Index objects of type Resource and handle their lifespans.
class ResourceManager
{
public:
    // Create a new resource.
    // Return the index where the resource was created.
    size_t create(const std::string& content);

    // Destroy the resource at the given index.
    // The other elements keep the same index, we do not reorganize the array.
    void destroy(size_t index);

    // Take the ownership of an existing resource.
    // Return the index where the resource was placed.
    size_t acquire(std::unique_ptr<Resource> resource);

    // Transfer the resource at the given index to the caller.
    std::unique_ptr<Resource> yield(size_t index);

    // Provide access to the resource at the given index.
    Resource& get(size_t index) const;

private:
    std::vector<std::unique_ptr<Resource>> _resources;
};
