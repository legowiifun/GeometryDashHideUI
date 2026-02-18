#pragma once
#ifdef GEODE_IS_WINDOWS
    #ifdef LEGOWIIFUN_HIDE_UI_API_EXPORTING
        #define HIDE_UI_API_DLL __declspec(dllexport)
    #else
        #define HIDE_UI_API_DLL __declspec(dllimport)
    #endif
#else
    #define HIDE_UI_API_DLL __attribute__((visibility("default")))
#endif

#ifdef MY_MOD_ID
    #undef MY_MOD_ID
#endif
#define MY_MOD_ID "legowiifun.hide_ui"

#include <Geode/Geode.hpp>
#include <Geode/loader/Event.hpp>
#include <Geode/loader/Dispatch.hpp>

class HIDE_UI_API_DLL hideUIAPI {
    public:
        static void toggleUI();
        static void turnOffUI();
        static void turnOnUI();
};
namespace hide_ui_events {
    inline geode::Result<void> addUIElementEvent(std::string nodeID, std::string location) GEODE_EVENT_EXPORT(&addUIElementEvent, (nodeID, location));
}