//
// Created by taylor on 22-11-22.
//

#include "prefs.h"
#include <gtk/gtk.h>

#include "app.h"
#include "window.h"
#include "prefs.h"

struct _ClashGAppPrefs {
    GtkDialog parent;

    GSettings *settings;
    GtkWidget *font;
    GtkWidget *transition;
};

G_DEFINE_TYPE (ClashGAppPrefs, clashg_app_prefs, GTK_TYPE_DIALOG)

static void
clashg_app_prefs_init(ClashGAppPrefs *prefs) {
    gtk_widget_init_template(GTK_WIDGET (prefs));
    prefs->settings = g_settings_new("org.nogfw.clashgapp");

    g_settings_bind(prefs->settings, "font",
                    prefs->font, "font",
                    G_SETTINGS_BIND_DEFAULT);
    g_settings_bind(prefs->settings, "transition",
                    prefs->transition, "active-id",
                    G_SETTINGS_BIND_DEFAULT);
}

static void
clashg_app_prefs_dispose(GObject *object) {
    ClashGAppPrefs *prefs;

    prefs = CLASHG_APP_PREFS(object);

    g_clear_object (&prefs->settings);

    G_OBJECT_CLASS (clashg_app_prefs_parent_class)->dispose(object);
}

static void
clashg_app_prefs_class_init(ClashGAppPrefsClass *class) {
    G_OBJECT_CLASS (class)->dispose = clashg_app_prefs_dispose;

    gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS (class),
                                                "/org/nogfw/clashgapp/resources/ui/prefs.xml");
    gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS(class), ClashGAppPrefs, font);
    gtk_widget_class_bind_template_child (GTK_WIDGET_CLASS(class), ClashGAppPrefs, transition);
}

ClashGAppPrefs *
clashg_app_prefs_new(ClashGAppWindow *win) {
    return g_object_new(CLASHG_APP_PREFS_TYPE, "transient-for", win, "use-header-bar", TRUE, NULL);
}
