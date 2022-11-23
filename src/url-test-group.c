//
// Created by taylor on 22-11-23.
//

#include "url-test-group.h"

struct _ClashgURLTestGroup {
    AdwPreferencesGroup parent;

};

G_DEFINE_TYPE (ClashgURLTestGroup, clashg_url_test_group, ADW_TYPE_PREFERENCES_GROUP)

static void
clashg_url_test_group_init(ClashgURLTestGroup *self) {
    gtk_widget_init_template(GTK_WIDGET (self));

}

static void
clashg_url_test_group_dispose(GObject *object) {
    ClashgURLTestGroup *page;

    page = CLASHG_URL_TEST_GROUP(object);

    G_OBJECT_CLASS (clashg_url_test_group_parent_class)->dispose(object);
}

static void
clashg_url_test_group_class_init(ClashgURLTestGroupClass *class) {
    G_OBJECT_CLASS (class)->dispose = clashg_url_test_group_dispose;

    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS (class),
                                                "/org/nogfw/clashgapp/resources/ui/url-test-group.xml");
}

GtkWidget *
clashg_url_test_group_new() {
    return g_object_new(CLASHG_TYPE_URL_TEST_GROUP,  NULL);
}
