#include "app/clashgapp.h"


int
main(int argc, char* argv[]) {
    return g_application_run(G_APPLICATION (clashg_app_new()), argc, argv);
}