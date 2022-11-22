//
// Created by taylor on 22-11-22.
//

#ifndef CLASHG_CLASHGAPPPREFS_H
#define CLASHG_CLASHGAPPPREFS_H
#ifndef __EXAMPLEAPPPREFS_H
#define __EXAMPLEAPPPREFS_H

#include <gtk/gtk.h>
#include "clashgappwin.h"


#define CLASHG_APP_PREFS_TYPE (clashg_app_prefs_get_type ())
G_DECLARE_FINAL_TYPE (ClashGAppPrefs, clashg_app_prefs, CLASHG, APP_PREFS, GtkDialog)


ClashGAppPrefs        *clashg_app_prefs_new          (ClashGAPPWindow *win);


#endif /* __EXAMPLEAPPPREFS_H */

#endif //CLASHG_CLASHGAPPPREFS_H
