#include <Application.h>

int main(int count, char **argv) {
    Application app(count, argv);
    return app.run();
}
