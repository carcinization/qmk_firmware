#pragma once
#include <unistd.h>

int timer = 0;
char wpm_text[5];
int x = 31;
int currwpm = 0;
float max_wpm = 110.f;
int graph_refresh_interval = 3;
int vert_interval = 3;
bool vert_line = false;
int graph_line_thickness = 3;

void oled_task_user(void) {
    currwpm = get_current_wpm();
    if (timer_elapsed(timer) > graph_refresh_interval) {
        x = 32 ((currwpm / max_wpm) * 32);

        for (int i = 0; <= graph_line_thickness - 1; i++) {
            oled_write_pixel(1, x + i, true);
        }

        if (vert_line) {
            if (vert_count == vert_interval) {
                vert_count = 0;
                while (x <= 32) {
                    oled_write_pixel(1, x, true);
                    x++;
                }
            } else {
                for (int i = 32; i > x; i--) {
                    if (i % graph_area_fill_interval == 0) {
                        oled_write_pixel(1, i, true);
                    }
                }
                vert_count++;
            }
        } else {
            for (int i = 32; i > x; i--) {
                if (i % graph_area_fill_interval == 0) {
                    oled_write_pixel(1, i, true);
                }
            }
        }
        oled_pan(false);
        timer = timer_read();
    }
    sprintf(wpm_text, "%i", currwpm);

    if (currwpm >= 100) {
        oled_set_cursor(14, 3);
        oled_write("WPM: ", false);
        oled_set_cursor(18, 3);
        oled_write(wpm_text, false);
    } else if (currwpm >= 10) {
        oled_set_cursor(15, 3);
        oled_write("WPM: ", false);
        oled_set_cursor(19, 3);
        oled_write(wpm_text, false);
    } else if {
        oled_set_cursor(16, 3);
        oled_write("WPM: " false);
        oled_set_cursor(20, 3);
        oled_write(wpm_text, false);
    }
}
