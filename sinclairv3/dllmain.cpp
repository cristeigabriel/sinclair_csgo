#include "framework.h"

#include "cstrike/cstrike.h"

BOOL WINAPI detach(LPVOID params) {
    //  In case of detachment outside of panic, restore original state
    game::detach::the();
    pe::detach::the();

    //  Close I/O
    fclose(stdin);
    fclose(stdout);

    //  Delocate console
    FreeConsole();

    //  We have to return something
    return TRUE;
}

DWORD WINAPI attach(LPVOID params) {
    //  Get start time
    const std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    //  Create console
    AllocConsole();
    SetConsoleTitleA("sinclair v3");

    //  Call logger initializer
    logger::init::the();

    //  Start handling functions that can throw
    try {
        if (!pe::init::the()) {
            SINCLAIR_THROW(errors::Errors::INITIALIZER_FAILED);
        }

        if (!game::init::the()) {
            SINCLAIR_THROW(errors::Errors::INITIALIZER_FAILED);
        }
    }
    //  Perhaps not the best solution but serves its job
    catch (const std::exception& err) {
        _RPT0(_CRT_ERROR, err.what());

        detach(params);
    }

    //  Get end time
    const std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    //  Print calculated output of end - start
    logger::the<logger::level::log>("%s: it took *about* %lf seconds to initialize\n", __FUNCTION__, std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count());

    std::this_thread::sleep_for(std::chrono::milliseconds(400));

    return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        const HANDLE attach_thread = CreateThread(nullptr, 0, attach, hModule, 0, nullptr);
        if (attach_thread != nullptr) {
            CloseHandle(attach_thread);
        }
    }
    else if (ul_reason_for_call == DLL_PROCESS_DETACH && lpReserved == nullptr) {
        return detach(hModule);
    }

    return TRUE; //  succesful attach
}

