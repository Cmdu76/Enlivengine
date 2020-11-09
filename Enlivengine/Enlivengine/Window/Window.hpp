#pragma once

#include <Enlivengine/Config.hpp>

#ifdef ENLIVE_MODULE_WINDOW

#include <SDL.h>

#include <Enlivengine/Platform/PrimitiveTypes.hpp>
#include <Enlivengine/Utils/Signal.hpp>

namespace en
{

class Window
{
public:
    Window();
    ~Window();

    bool Create(const char* name, U32 width, U32 height, U32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	void Destroy();
	bool IsValid() const;

    void Close();
	void ResetShouldClose();
	bool ShouldClose() const;
    enSignal(OnShouldClose, const Window*);

    void SetVisible(bool visible);
    bool IsVisible() const;

    void Minimize();
    void Maximize();
    bool IsMinimized() const;
    bool IsMaximized() const;

    void SetSize(U32 width, U32 height);
    U32 GetWidth() const;
	U32 GetHeight() const;
    void GetSize(U32& width, U32& height) const;
    enSignal(OnResized, const Window*, U32, U32);

    void SetTitle(const char* title);
    const char* GetTitle() const;

    U32 GetID() const;
    U32 GetFlags() const;

private:
    friend class BgfxWrapper;
    friend class Mouse;
    friend class EventSystem;

    SDL_Window* mWindow;
    bool mShouldClose;

    static constexpr U32 kMaxWindows = 10;
    static U32 sWindowCount;
    static Window* sWindows[kMaxWindows];
    static void RegisterWindow(Window* window);
    static void UnregisterWindow(Window* window);
    static Window* GetWindowFromSDLWindow(SDL_Window* sdlWindow);
    static Window* GetWindowFromSDLWindowID(U32 sldWindowID);
};

} // namespace en

#endif // ENLIVE_MODULE_WINDOW