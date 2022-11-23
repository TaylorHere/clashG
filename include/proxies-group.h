//
// Created by taylor on 22-11-23.
//

#ifndef CLASHG_PROXIES_GROUP_H
#define CLASHG_PROXIES_GROUP_H

#include <gtk/gtk.h>
#include "window.h"

G_BEGIN_DECLS

#define CLASHG_TYPE_PROXIES_GROUP (clashg_proxies_group_get_type ())

G_DECLARE_FINAL_TYPE (ClashgProxiesGroup, clashg_proxies_group, CLASHG, PROXIES_GROUP, AdwPreferencesGroup)

GtkWidget *clashg_proxies_group_new();

#endif //CLASHG_PROXIES_GROUP_H
