//
// Created by taylor on 22-11-22.
//
#include <gtk/gtk.h>

#include "clashgapp.h"
#include "../window/clashgappwin.h"

struct _ClashGAPP {
    AdwApplication parent;
};

G_DEFINE_TYPE(ClashGAPP, clashg_app, ADW_TYPE_APPLICATION);

static void
clashg_app_init(ClashGAPP* app) {
}

static void
clashg_app_activate(GApplication* app) {
    ClashGAPPWindow* win;

    win = clashg_app_window_new(CLASHG_APP(app));
    gtk_window_present(GTK_WINDOW (win));
}

static void
clashg_app_open(GApplication* app,
                GFile** files,
                int n_files,
                const char* hint) {
    GList* windows;
    ClashGAPPWindow* win;
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
clashg_app_class_init(ClashGAPPClass* class) {
    G_APPLICATION_CLASS (class)->activate = clashg_app_activate;
    G_APPLICATION_CLASS (class)->open = clashg_app_open;
}

ClashGAPP*
clashg_app_new(void) {
    return g_object_new(CLASHG_APP_TYPE,
                        "application-id", "org.gtk.exampleapp",
                        "flags", G_APPLICATION_HANDLES_OPEN,
                        NULL);
}
