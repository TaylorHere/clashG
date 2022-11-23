//
// Created by taylor on 22-11-23.
//

#include "selectors-group.h"

struct _ClashgSelectorsGroup {
    AdwPreferencesGroup parent;

};

G_DEFINE_TYPE (ClashgSelectorsGroup, clashg_selectors_group, ADW_TYPE_PREFERENCES_GROUP)

static void
clashg_selectors_group_init(ClashgSelectorsGroup *self) {
    gtk_widget_init_template(GTK_WIDGET (self));

}

static void
clashg_selectors_group_dispose(GObject *object) {
    ClashgSelectorsGroup *page;

    page = CLASHG_SELECTORS_GROUP(object);

    G_OBJECT_CLASS (clashg_selectors_group_parent_class)->dispose(object);
}

static void
clashg_selectors_group_class_init(ClashgSelectorsGroupClass *class) {
    G_OBJECT_CLASS (class)->dispose = clashg_selectors_group_dispose;

    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS (class),
                                                "/org/nogfw/clashgapp/resources/ui/selectors-group.xml");
}

GtkWidget *
clashg_selectors_group_new() {
    return g_object_new(CLASHG_TYPE_SELECTORS_GROUP,  NULL);
}
