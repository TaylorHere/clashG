//
// Created by taylor on 22-11-22.
//
#include <gtk/gtk.h>

#include "app.h"
#include "window.h"
#include "prefs.h"

struct _ClashGAPP {
    AdwApplication parent;
};

G_DEFINE_TYPE(ClashGAPP, clashg_app, ADW_TYPE_APPLICATION);

static void
preferences_activated(GSimpleAction *action,
                      GVariant *parameter,
                      gpointer app) {
    ClashGAppPrefs *prefs;
    GtkWindow *win;

    win = gtk_application_get_active_window(GTK_APPLICATION (app));
    prefs = clashg_app_prefs_new(CLASHG_APP_WINDOW(win));
    gtk_window_present(GTK_WINDOW (prefs));

}

static void
quit_activated(GSimpleAction *action,
               GVariant *parameter,
               gpointer app) {
    g_application_quit(G_APPLICATION (app));
}

static GActionEntry app_entries[] =
        {
                {"preferences", preferences_activated, NULL, NULL, NULL},
                {"quit",        quit_activated,        NULL, NULL, NULL}
        };

static void
clashg_app_startup(GApplication *app) {
    GtkBuilder *builder;
    GMenuModel *app_menu;
    const char *quit_accels[2] = {"<Ctrl>Q", NULL};

    G_APPLICATION_CLASS (clashg_app_parent_class)->startup(app);

    g_action_map_add_action_entries(G_ACTION_MAP (app),
                                    app_entries, G_N_ELEMENTS (app_entries),
                                    app);
    gtk_application_set_accels_for_action(GTK_APPLICATION (app),
                                          "app.quit",
                                          quit_accels);
}


static void
clashg_app_activate(GApplication *app) {
    ClashGAppWindow *win;

    win = clashg_app_window_new(CLASHG_APP(app));
    gtk_window_present(GTK_WINDOW (win));
}

static void
clashg_app_open(GApplication *app,
                GFile **files,
                int n_files,
                const char *hint) {
    GList *windows;
    ClashGAppWindow *win;
    int i;

    windows = gtk_application_get_windows(GTK_APPLICATION (app));
    if (windows)
        win = CLASHG_APP_WINDOW(windows->data);
    else
        win = clashg_app_window_new(CLASHG_APP(app));

    for (i = 0; i < n_files; i++)
        clashg_app_window_open(win, files[i]);

    gtk_window_present(GTK_WINDOW (win));
}

static void
clashg_app_class_init(ClashGAPPClass *class) {
    G_APPLICATION_CLASS (class)->activate = clashg_app_activate;
    G_APPLICATION_CLASS (class)->open = clashg_app_open;
    G_APPLICATION_CLASS (class)->startup = clashg_app_startup;
}

ClashGAPP *
clashg_app_new(void) {
    return g_object_new(CLASHG_APP_TYPE,
                        "application-id", "org.nogfw.clashgapp",
                        "flags", G_APPLICATION_HANDLES_OPEN,
                        NULL);
}

static void
clashg_app_init(ClashGAPP *app) {
}