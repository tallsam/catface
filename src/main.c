#include <pebble.h>

static Window *s_main_window;
static BitmapLayer *s_cat_layer;
static GBitmap *s_cat_bitmap;

static void main_window_load(Window *window) {
  s_cat_bitmap = gbitmap_create_with_resource(RESOURCE_ID_IMAGE_CAT);
  s_cat_layer = bitmap_layer_create(GRect(0,0,144,138));
  bitmap_layer_set_bitmap(s_cat_layer, s_cat_bitmap);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(s_cat_layer));
}

static void main_window_unload(Window *window) {
  gbitmap_destroy(s_cat_bitmap);
  bitmap_layer_destroy(s_cat_layer);
}
  
static void init() {
  s_main_window = window_create();
  
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });
  
  window_stack_push(s_main_window, true);
} 
                             
static void deinit() {
  window_destroy(s_main_window);
}
  
int main(void) {
 init();
 app_event_loop();
 deinit();
}
  