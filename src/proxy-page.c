//
// Created by taylor on 22-11-23.
//

#include "proxy-page.h"

struct _ClashgProxyPage {
    GtkBox parent;

};

G_DEFINE_TYPE (ClashgProxyPage, clashg_proxy_page, GTK_TYPE_BOX)

static void
clashg_proxy_page_init(ClashgProxyPage *self) {
    gtk_widget_init_template(GTK_WIDGET (self));

}

static void
clashg_proxy_page_dispose(GObject *object) {
    ClashgProxyPage *page;

    page = CLASHG_PROXY_PAGE(object);

    G_OBJECT_CLASS (clashg_proxy_page_parent_class)->dispose(object);
}

static void
clashg_proxy_page_class_init(ClashgProxyPageClass *class) {
    G_OBJECT_CLASS (class)->dispose = clashg_proxy_page_dispose;

    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS (class),
                                                "/org/nogfw/clashgapp/resources/ui/proxy-page.xml");
}

GtkWidget *
clashg_proxy_page_new() {
    return g_object_new(CLASHG_TYPE_PROXY_PAGE,  NULL);
}
