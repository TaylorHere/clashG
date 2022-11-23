//
// Created by taylor on 22-11-23.
//

#ifndef CLASHG_SELECTORS_GROUP_H
#define CLASHG_SELECTORS_GROUP_H

#include <gtk/gtk.h>
#include "window.h"

G_BEGIN_DECLS

#define CLASHG_TYPE_SELECTORS_GROUP (clashg_selectors_group_get_type ())

G_DECLARE_FINAL_TYPE (ClashgSelectorsGroup, clashg_selectors_group, CLASHG, SELECTORS_GROUP, AdwPreferencesGroup)

GtkWidget *clashg_selectors_group_new();

#endif //CLASHG_SELECTORS_GROUP_H
