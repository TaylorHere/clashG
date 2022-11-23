//
// Created by taylor on 22-11-22.
//

#include "rule-page.h"

struct _ClashgRulePage {
    GtkBox parent;

    GtkButton button;
};

G_DEFINE_TYPE (ClashgRulePage, clashg_rule_page, GTK_TYPE_BOX)

static void
clashg_rule_page_init(ClashgRulePage *self) {
    gtk_widget_init_template(GTK_WIDGET (self));

}

static void
clashg_rule_page_dispose(GObject *object) {
    ClashgRulePage *page;

    page = CLASHG_RULE_PAGE(object);

    G_OBJECT_CLASS (clashg_rule_page_parent_class)->dispose(object);
}

static void
clashg_rule_page_class_init(ClashgRulePageClass *class) {
    G_OBJECT_CLASS (class)->dispose = clashg_rule_page_dispose;

    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS (class),
                                                "/org/nogfw/clashgapp/resources/ui/rule-page.xml");
    gtk_widget_class_bind_template_child(GTK_WIDGET_CLASS(class), ClashgRulePage, button);
}

GtkWidget *
clashg_rule_page_new() {
    return g_object_new(CLASHG_TYPE_RULE_PAGE,  NULL);
}
