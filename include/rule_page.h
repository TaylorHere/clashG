//
// Created by taylor on 22-11-22.
//

#ifndef CLASHG_RULE_PAGE_H
#define CLASHG_RULE_PAGE_H

#include <gtk/gtk.h>
#include "window.h"

G_BEGIN_DECLS

#define CLASHG_TYPE_RULE_PAGE (clashg_rule_page_get_type ())

G_DECLARE_FINAL_TYPE (ClashgRulePage, clashg_rule_page, CLASHG, RULE_PAGE, GtkBox)

GtkWidget *clashg_rule_page_new(ClashGAppWindow *win);

G_END_DECLS

#endif //CLASHG_RULE_PAGE_H
