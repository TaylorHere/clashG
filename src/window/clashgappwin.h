//
// Created by taylor on 22-11-22.
//

#ifndef CLASHG_CLASHGAPPWIN_H
#define CLASHG_CLASHGAPPWIN_H


#include <gtk/gtk.h>
#include "../app/clashgapp.h"


#define CLASHG_APP_WINDOW_TYPE (clashg_app_window_get_type ())

G_DECLARE_FINAL_TYPE (ClashGAPPWindow, clashg_app_window, CLASHG, APP_WINDOW, GtkApplicationWindow)


ClashGAPPWindow* clashg_app_window_new(ClashGAPP* app);

void clashg_app_window_open(ClashGAPPWindow* win,
                            GFile* file);

#endif //CLASHG_CLASHGAPPWIN_H
