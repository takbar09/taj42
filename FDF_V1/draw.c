/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: takbar <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/06 11:15:50 by takbar        #+#    #+#                 */
/*   Updated: 2023/08/06 18:58:16 by takbar        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
#include "fdf.h"
#include <math.h>
#include <stdlib.h>>

void drawLine(int x0, int y0, int x1, int y1, t_data *data) 
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1; // Increment direction for X
    int sy = (y0 < y1) ? 1 : -1; // Increment direction for Y
    int err = dx - dy;

    while ((x0 - x1) || (y0 - y1))
   	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, 0xffffff)

        // Draw pixel at (x0, y0) or do whatever you need with the X and Y values here
        // For example: printf("x: %d, y: %d\n", x0, y0);

        if (x0 == x1 && y0 == y1) {
            break; // Exit the loop when the endpoint is reached
        }

        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x0 += sx; // Increment X
        }

        if (e2 < dx) {
            err += dx;
            y0 += sy; // Increment Y
        }
    }
}*/

#include "MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "MLX42/include/MLX42/MLX42_Int.h"
#include "fdf.h"

// BUG: Linux may experience a red hue instead due to endiannes
void mlx_draw_pixel(uint8_t* pixel, uint32_t color)
{
    *(pixel++) = (uint8_t)(color >> 24);
    *(pixel++) = (uint8_t)(color >> 16);
    *(pixel++) = (uint8_t)(color >> 8);
    *(pixel++) = (uint8_t)(color & 0xFF);
}

//= Public =//

void mlx_put_pixel(mlx_image_t* image, uint32_t x, uint32_t y, uint32_t color)
{
    MLX_NONNULL(image);
    MLX_ASSERT(x < image->width, "Pixel is out of bounds");
    MLX_ASSERT(y < image->height, "Pixel is out of bounds");

    uint8_t* pixelstart = &image->pixels[(y * image->width + x) * BPP];
    mlx_draw_pixel(pixelstart, color);
}

void drawLine(int x0, int y0, int x1, int y1, t_data *data) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1; // Increment direction for X
    int sy = (y0 < y1) ? 1 : -1; // Increment direction for Y
    int err = dx - dy;

    while (1) {
        // Draw pixel at (x0, y0) or do whatever you need with the X and Y values here
        printf("x: %d, y: %d\n", x0, y0);
		mlx_put_pixel(data->mlx_ptr, data->win_ptr, x0, y0, 0xffffff);

        if (x0 == x1 && y0 == y1) {
            break; // Exit the loop when the endpoint is reached
        }

        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x0 += sx; // Increment X
        }

        if (e2 < dx) {
            err += dx;
            y0 += sy; // Increment Y
        }
    }
}

int main() {
    //int x0 = 1, y0 = 1; // Starting point
    //int x1 = 8, y1 = 5; // Ending point
    t_data *data;
    drawLine(1, 1, 8, 5, data);

    return 0;
}
