
#include <jni.h>
#include <android/log.h>

#define LOG_TAG "GTASA_SimpleMenu"

#define LOGI(...) \
    __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

#define LOGE(...) \
    __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

static bool g_initialized = false;

static void InitializeModMenu()
{
    if (g_initialized)
        return;

    LOGI("GTASA Simple Mod Menu initialized");
    g_initialized = true;
}

extern "C"
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM* vm, void* reserved)
{
    (void)vm;
    (void)reserved;

    InitializeModMenu();

    return JNI_VERSION_1_6;
}
