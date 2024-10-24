#pragma once
#include <cstdint>

namespace engine::core
{
    struct window_size
    {
        static constexpr int32_t default_width  { 1024 };
        static constexpr int32_t default_height {  768 };

        int32_t width  { default_width  };
        int32_t height { default_height };
    };
}
