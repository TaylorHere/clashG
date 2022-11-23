//
// Created by taylor on 22-11-23.
//

#ifndef CLASHG_URL_TEST_GROUP_H
#define CLASHG_URL_TEST_GROUP_H

#include <gtk/gtk.h>
#include "window.h"

G_BEGIN_DECLS

#define CLASHG_TYPE_URL_TEST_GROUP (clashg_url_test_group_get_type ())

G_DECLARE_FINAL_TYPE (ClashgURLTestGroup, clashg_url_test_group, CLASHG, URL_TEST_GROUP, AdwPreferencesGroup)

GtkWidget *clashg_url_test_group_new();

#endif //CLASHG_URL_TEST_GROUP_H
