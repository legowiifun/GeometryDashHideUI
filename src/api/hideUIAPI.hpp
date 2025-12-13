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

class HIDE_UI_API_DLL hideUIAPI {
    public:
        static void toggleUI();
        static void turnOffUI();
        static void turnOnUI();
};