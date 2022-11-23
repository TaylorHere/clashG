//
// Created by taylor on 22-11-23.
//

#ifndef CLASHG_TOGGLE_GROUP_H
#define CLASHG_TOGGLE_GROUP_H

#include <gtk/gtk.h>
#include "window.h"

G_BEGIN_DECLS

#define CLASHG_TYPE_TOGGLE_GROUP (clashg_toggle_group_get_type ())

G_DECLARE_FINAL_TYPE (ClashgToggleGroup, clashg_toggle_group, CLASHG, TOGGLE_GROUP, GtkBox)

GtkWidget *clashg_toggle_group_new();

G_END_DECLS
#endif //CLASHG_TOGGLE_GROUP_H
