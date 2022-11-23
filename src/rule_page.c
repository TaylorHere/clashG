//
// Created by taylor on 22-11-22.
//

#include "rule_page.h"

struct _ClashgRulePage {
    GtkBox parent;

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
}

GtkWidget *
clashg_rule_page_new(ClashGAppWindow *win) {
    return g_object_new(CLASHG_TYPE_RULE_PAGE,  NULL);
}
