//
// Created by taylor on 22-11-22.
//

#include <gtk/gtk.h>

#include "app.h"
#include "window.h"
#include "rule-page.h"

struct _ClashGAppWindow {
    AdwApplicationWindow parent;
    GSettings *settings;

    AdwViewStack *stack;
    GtkWidget *gears;

    ClashgRulePage *rulePage;
};

G_DEFINE_TYPE(ClashGAppWindow, clashg_app_window, ADW_TYPE_APPLICATION_WINDOW);

static void
clashg_app_window_init(ClashGAppWindow *win) {
    gtk_widget_init_template(GTK_WIDGET (win));
    GtkBuilder *builder;
    GMenuModel *menu;

    win->settings = g_settings_new("org.nogfw.clashgapp");


    builder = gtk_builder_new_from_resource("/org/nogfw/clashgapp/resources/ui/gears-menu.xml");
    menu = G_MENU_MODEL (gtk_builder_get_object(builder, "menu"));
    gtk_menu_button_set_menu_model(GTK_MENU_BUTTON (win->gears), menu);
    g_object_unref(builder);

}

static void
clashg_app_window_class_init(ClashGAppWindowClass *class) {

    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS (class),
                                                "/org/nogfw/clashgapp/resources/ui/window.xml");
    gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS(class), ClashGAppWindow, stack);
    gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS(class), ClashGAppWindow, gears);
    gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS(class), ClashGAppWindow, rulePage);

}

ClashGAppWindow *
clashg_app_window_new(ClashGAPP *app) {
    return g_object_new(CLASHG_APP_WINDOW_TYPE, "application", app, NULL);
}

void
clashg_app_window_open(ClashGAppWindow *win, GFile *file) {}
