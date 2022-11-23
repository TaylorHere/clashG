//
// Created by taylor on 22-11-23.
//

#include "toggle-group.h"

struct _ClashgToggleGroup {
    GtkBox parent;
    GtkButton *global;
    GtkButton *rule;
    GtkButton *direct;

};

G_DEFINE_TYPE (ClashgToggleGroup, clashg_toggle_group, GTK_TYPE_BOX)

static void
clashg_toggle_group_init(ClashgToggleGroup *self) {
    gtk_widget_init_template(GTK_WIDGET (self));

}

static void
clashg_toggle_group_dispose(GObject *object) {
    ClashgToggleGroup *page;

    page = CLASHG_TOGGLE_GROUP(object);

    G_OBJECT_CLASS (clashg_toggle_group_parent_class)->dispose(object);
}

static void
clashg_toggle_group_class_init(ClashgToggleGroupClass *class) {
    G_OBJECT_CLASS (class)->dispose = clashg_toggle_group_dispose;

    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS (class),
                                                "/org/nogfw/clashgapp/resources/ui/toggle-group.xml");
    gtk_widget_class_bind_template_child(GTK_WIDGET_CLASS(class), ClashgToggleGroup, global);
    gtk_widget_class_bind_template_child(GTK_WIDGET_CLASS(class), ClashgToggleGroup, rule);
    gtk_widget_class_bind_template_child(GTK_WIDGET_CLASS(class), ClashgToggleGroup, direct);

}

GtkWidget *
clashg_toggle_group_new() {
    return g_object_new(CLASHG_TYPE_TOGGLE_GROUP,  NULL);
}
