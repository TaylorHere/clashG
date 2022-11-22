//
// Created by taylor on 22-11-22.
//

#ifndef CLASHG_CLASHGAPP_H
#define CLASHG_CLASHGAPP_H

#include <adwaita.h>
#include <gtk/gtk.h>

#define CLASHG_APP_TYPE (clashg_app_get_type ())
G_DECLARE_FINAL_TYPE (ClashGAPP, clashg_app, CLASHG, APP, AdwApplication)

ClashGAPP* clashg_app_new(void);

#endif //CLASHG_CLASHGAPP_H
