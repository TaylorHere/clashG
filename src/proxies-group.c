//
// Created by taylor on 22-11-23.
//

#include "proxies-group.h"

struct _ClashgProxiesGroup {
    AdwPreferencesGroup parent;
    GtkButton *test;
};

G_DEFINE_TYPE (ClashgProxiesGroup, clashg_proxies_group, ADW_TYPE_PREFERENCES_GROUP)

static void
clashg_proxies_group_init(ClashgProxiesGroup *self) {
    gtk_widget_init_template(GTK_WIDGET (self));

}

static void
clashg_proxies_group_dispose(GObject *object) {
    ClashgProxiesGroup *page;

    page = CLASHG_PROXIES_GROUP(object);

    G_OBJECT_CLASS (clashg_proxies_group_parent_class)->dispose(object);
}

static void
clashg_proxies_group_class_init(ClashgProxiesGroupClass *class) {
    G_OBJECT_CLASS (class)->dispose = clashg_proxies_group_dispose;

    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS (class),
                                                "/org/nogfw/clashgapp/resources/ui/proxies-group.xml");
    gtk_widget_class_bind_template_child(GTK_WIDGET_CLASS(class), ClashgProxiesGroup, test);
}

GtkWidget *
clashg_proxies_group_new() {
    return g_object_new(CLASHG_TYPE_PROXIES_GROUP,  NULL);
}
