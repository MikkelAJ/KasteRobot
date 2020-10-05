#ifndef APP_H
#define APP_H
#pragma once

#include "includeheader.h"

// NOTE: cMain and xBaslerCam should be encapsulated by cLinker and xLinker
#include "gui/cmain.h"
#include "logic/xbaslercam.h"

class app : public wxApp
{
public:
    app();
    ~app();

public:
    virtual bool OnInit();

private:
    cMain* mFrame = nullptr;
    
    // Treat this thread as the main program loop for now ..
    std::thread* thread = nullptr;
    void threadFunc();
    bool mJoinThread = false;
};

#endif // APP_H
