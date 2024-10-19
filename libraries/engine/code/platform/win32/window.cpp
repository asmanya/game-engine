#include "window.hpp"
#include "window_events.hpp"

namespace engine::win32
{
    void window::create()
    {
        register_window_class();

        UINT extra = WS_EX_APPWINDOW;
        UINT style = WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_OVERLAPPEDWINDOW;


        _handle = CreateWindowEx(extra, MAKEINTATOM(_classex), _title.c_str(),
                                 style, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
                                 nullptr, nullptr, GetModuleHandle(nullptr), nullptr);
    }

    void window::destroy() const
    {
        DestroyWindow(_handle);
        unregister_window_class();
    }

    void window::display() const
    {
        ShowWindow(_handle, SW_SHOW);
    }

    void window::register_window_class()
    {
        const WNDCLASSEX classex{
            .cbSize        = sizeof(WNDCLASSEX),
            .style         = CS_VREDRAW | CS_OWNDC | CS_HREDRAW,
            .lpfnWndProc   = WindowEvents::process,
            .hInstance     = GetModuleHandle(nullptr),
            .hCursor       = LoadCursor(nullptr, IDC_ARROW),
            .lpszClassName = _title.c_str(),
        };

        _classex = RegisterClassEx(&classex);
    }

    void window::unregister_window_class() const
    {
        UnregisterClass(MAKEINTATOM(_classex), GetModuleHandle(nullptr));
    }

}