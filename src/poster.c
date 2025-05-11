#include <furi.h>
#include <gui/gui.h>
#include <gui/view.h>
#include <gui/view_port.h>
#include "../assets/loc_lac.xbm"

typedef struct {
    Gui* gui;
    ViewPort* view_port;
} PosterApp;

void poster_draw(Canvas* canvas, void* ctx) {
    UNUSED(ctx);
    canvas_clear(canvas);
    canvas_draw_xbm(canvas, 0, 0, loc_lac_width, loc_lac_height, loc_lac_bits);
}

int32_t poster_main(void) {
    PosterApp app;

    app.view_port = view_port_alloc();
    view_port_draw_callback_set(app.view_port, poster_draw);

    app.gui = furi_record_open("gui");
    gui_add_view_port(app.gui, app.view_port, GuiLayerFullscreen);

    // Attente d'un signal de sortie (ZLOC nécessite une boucle, pas un delay infini)
    furi_delay_ms(3000); // Affiche l'image pendant 3 secondes

    gui_remove_view_port(app.gui, app.view_port);
    view_port_free(app.view_port);
    furi_record_close("gui");

    return 0;
}