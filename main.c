#include <stdio.h>
#include "librequests.h"

int main() {
    HTTPResponse response = requests("GET", "http://127.0.0.1/", "");

    if (response.status_line.status_code >= 200){
        printf("%s", response.body);
    }

    HTTPResponse_drop(&response);
    return 0;
}
