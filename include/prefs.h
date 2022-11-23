//
// Created by taylor on 22-11-22.
//

#ifndef CLASHG_PREFS_H
#define CLASHG_PREFS_H

#include <gtk/gtk.h>
#include "window.h"


#define CLASHG_APP_PREFS_TYPE (clashg_app_prefs_get_type ())

G_DECLARE_FINAL_TYPE (ClashGAppPrefs, clashg_app_prefs, CLASHG, APP_PREFS, GtkDialog)


ClashGAppPrefs *clashg_app_prefs_new(ClashGAppWindow *win);

#endif //CLASHG_PREFS_H
