//
// Created by taylor on 22-11-23.
//

#ifndef CLASHG_PROXY_PAGE_H
#define CLASHG_PROXY_PAGE_H

#include <gtk/gtk.h>
#include "window.h"

G_BEGIN_DECLS

#define CLASHG_TYPE_PROXY_PAGE (clashg_proxy_page_get_type ())

G_DECLARE_FINAL_TYPE (ClashgProxyPage, clashg_proxy_page, CLASHG, PROXY_PAGE, GtkBox)

GtkWidget *clashg_proxy_page_new();

G_END_DECLS

#endif //CLASHG_PROXY_PAGE_H
