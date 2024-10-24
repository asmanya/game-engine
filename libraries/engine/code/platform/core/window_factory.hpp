#pragma once

#include "factory.hpp"

namespace engine::core
{
    class window_factory
    {
    public:
        static std::unique_ptr<Factory> create();
    };
}