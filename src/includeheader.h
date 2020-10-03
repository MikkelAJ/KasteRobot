#ifndef INCLUDEHEADER_H
#define INCLUDEHEADER_H

/*
 *  All libraries and definitions can be
 *  collected here for readability's sake.
 */

// Redefining logging function names
#ifndef LOG_DEFINES
#define LOG_DEFINES 1
#define logstd wxLogMessage
#define logwar wxLogWarning
#define logerr wxLogError
#endif

// Includes from standard libraries
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <iostream>

// wxWidgets includes
#include "wx/wx.h"
#include "wx/app.h"
#include "wx/frame.h"
#include "wx/menu.h"
#include "wx/sizer.h"
#include "wx/splitter.h"
#include "wx/textctrl.h"
#include "wx/notebook.h"
#include "wx/treelist.h"
#include "wx/aboutdlg.h"
#include "wx/artprov.h"

// A few sample images for wxWidgets
#ifndef wxHAS_IMAGES_IN_RESOURCES
    #include "gui/sample.xpm"
#endif

#endif // INCLUDEHEADER_H