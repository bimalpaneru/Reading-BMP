#pragma once
#ifndef IMG_HANDLE_H
#define IMG_HANDLE_H

#include <stdio.h>
#include <io_bmp.h>

struct io_comp {
	int width, height, stride;
	int* buf, *handle;
};


struct io_image {
	int num_components;
	io_comp* comps;
};


int flip_data(io_byte* data, io_byte* inverted_data, int height, int planes, int width);

int read_bmp(bmp_in* bmp_img, io_image* image_buf);

int write_bmp(io_image* image_buf, bmp_out* out_bmp);

#endif
