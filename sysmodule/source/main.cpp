#include <switch.h>

#define INNER_HEAP_SIZE 0x80000

extern "C" {
    u32 __nx_applet_type = AppletType_None;
    u32 __nx_fs_num_sessions = 1;

    size_t nx_inner_heap_size = INNER_HEAP_SIZE;
    char nx_inner_heap[INNER_HEAP_SIZE];

    void __libnx_initheap(void) {
        void *addr = nx_inner_heap;
        size_t size = nx_inner_heap_size;

        extern char *fake_heap_start;
        extern char *fake_heap_end;

        fake_heap_start = (char *) addr;
        fake_heap_end = (char *) addr + size;
    }

    void __appInit(void) {
        if (R_FAILED(smInitialize())) {
            fatalThrow(MAKERESULT(Module_Libnx, LibnxError_InitFail_SM));
        }

        Result rc = setsysInitialize();
        if (R_SUCCEEDED(rc)) {
            SetSysFirmwareVersion fw;
            rc = setsysGetFirmwareVersion(&fw);
            if (R_SUCCEEDED(rc))
                hosversionSet(MAKEHOSVERSION(fw.major, fw.minor, fw.micro));
            setsysExit();
        }

        rc = fsInitialize();
        if (R_FAILED(rc)) {
            fatalThrow(MAKERESULT(Module_Libnx, LibnxError_InitFail_FS));
        }

        fsdevMountSdmc();
    }

    void __appExit(void) {
        smExit();
        fsExit();
    }

    int main() {
        while (true) {
            svcSleepThread(1'000'000'000'000);
        }
    }

}
