#include <SDL3/SDL_main.h>

#include "../src/core.h"
#include "../src/constants.h"
#include "../src/networking.h"
#include "../src/graphics.h"
#include "../src/logging.h"
#include "../src/mixer.h"
#include "../src/font.h"
#include "../src/print.h"


using namespace std;



int main(int argc, char *argv[]) {
    Engine engine;

    Window window("Test", {800, 600});
    Renderer renderer(window);

    Clock clock;
    Events events;

    bool rng = true;
    double dt;

    auto handler = [](SDL_Event &event) {
        switch (event.type) {
            case SDL_EVENT_WINDOW_RESIZED:
                SDL_Log("Works");
                break;
        };
        return false;
    };

    Mouse mouse;

    while (rng) {
        dt = clock.tick(60);

        rng = events.process_events({.event_handler = handler});

        renderer.clear(WHITE);
        renderer.present();
    }

    return 0;
}
