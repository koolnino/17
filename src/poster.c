#include <gui/gui.h>
#include <gui/view.h>
#include <furi.h>
#include <furi_hal.h>
#include "../assets/loc_lac.xbm"

void poster_draw(Canvas* canvas, void* ctx) {
    UNUSED(ctx);
    canvas_clear(canvas);
    canvas_draw_xbm(canvas, 0, 0, loc_lac_width, loc_lac_height, loc_lac_bits);
}

int32_t poster_main(void) {
    ViewPort* viewport = view_port_alloc();
    view_port_draw_callback_set(viewport, poster_draw);
    Gui* gui = furi_record_open("gui");
    gui_add_view_port(gui, viewport, GuiLayerFullscreen);
    furi_delay(FuriWaitForever);
    gui_remove_view_port(gui, viewport);
    view_port_free(viewport);
    furi_record_close("gui");
    return 0;
}