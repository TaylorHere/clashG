//
// Created by taylor on 22-11-22.
//

#include <gtk/gtk.h>

#include "clashgapp.h"
#include "clashgappwin.h"

struct _ClashGAPPWindow {
    GtkApplicationWindow parent;
    GSettings *settings;

    GtkWidget* stack;
    GtkWidget* gears;
};

G_DEFINE_TYPE(ClashGAPPWindow, clashg_app_window, GTK_TYPE_APPLICATION_WINDOW);

static void
clashg_app_window_init(ClashGAPPWindow* win) {
    gtk_widget_init_template(GTK_WIDGET (win));
    GtkBuilder* builder;
    GMenuModel* menu;

    gtk_widget_init_template(GTK_WIDGET (win));
      win->settings = g_settings_new ("org.nogfw.clashgapp");

      g_settings_bind (win->settings, "transition",
                       win->stack, "transition-type",
                       G_SETTINGS_BIND_DEFAULT);
    builder = gtk_builder_new_from_resource("/org/nogfw/clashgapp/resources/ui/gears-menu.xml");
    menu = G_MENU_MODEL (gtk_builder_get_object(builder, "menu"));
    gtk_menu_button_set_menu_model(GTK_MENU_BUTTON (win->gears), menu);
    g_object_unref(builder);

}

static void
clashg_app_window_class_init(ClashGAPPWindowClass* class) {
    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS (class),
                                                "/org/nogfw/clashgapp/resources/ui/window.xml");
    gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS(class), ClashGAPPWindow, stack);
    gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS(class), ClashGAPPWindow, gears);
}

ClashGAPPWindow*
clashg_app_window_new(ClashGAPP* app) {
    return g_object_new(CLASHG_APP_WINDOW_TYPE, "application", app, NULL);
}

void
clashg_app_window_open(ClashGAPPWindow* win,
                       GFile* file) {
    char* basename;
    GtkWidget* scrolled, * view;
    char* contents;
    gsize length;

    basename = g_file_get_basename(file);

    scrolled = gtk_scrolled_window_new();
    gtk_widget_set_hexpand(scrolled, TRUE);
    gtk_widget_set_vexpand(scrolled, TRUE);
    view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW (view), FALSE);
    gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW (view), FALSE);
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW (scrolled), view);
    gtk_stack_add_titled(GTK_STACK (win->stack), scrolled, basename, basename);

    if (g_file_load_contents(file, NULL, &contents, &length, NULL, NULL)) {
        GtkTextBuffer* buffer;

        buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW (view));
        gtk_text_buffer_set_text(buffer, contents, length);
        g_free(contents);
    }

    g_free(basename);
}
