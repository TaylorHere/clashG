//
// Created by taylor on 22-11-22.
//

#ifndef CLASHG_WINDOW_H
#define CLASHG_WINDOW_H


#include <gtk/gtk.h>
#include "app.h"

#define CLASHG_APP_WINDOW_TYPE (clashg_app_window_get_type ())

G_DECLARE_FINAL_TYPE (ClashGAppWindow, clashg_app_window, CLASHG, APP_WINDOW, AdwApplicationWindow)


ClashGAppWindow *clashg_app_window_new(ClashGAPP *app);

void clashg_app_window_open(ClashGAppWindow *win,
                            GFile *file);


#endif //CLASHG_WINDOW_H
