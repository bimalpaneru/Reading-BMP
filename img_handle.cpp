#include"img_handle.h"



int flip_data(io_byte* data, io_byte* inverted_data, int height, int planes, int width) {

	int inverted_data_line = 0;
	
	for (int old_data_line = height; old_data_line > 0; old_data_line--) {

		for (int line_scanner = 0; line_scanner < width * planes; line_scanner++) {

			inverted_data[inverted_data_line * width * planes + line_scanner] = data[old_data_line * width * planes - width * planes + line_scanner];
		}
		inverted_data_line++;

	}

	return 0;
}




int read_bmp(bmp_in* bmp_img, io_image* image_buf) {

	int width  = bmp_img->cols;
	int height = bmp_img->rows;
	int planes = bmp_img->num_components;
	image_buf->num_components = bmp_img->num_components;
	image_buf->comps = new io_comp[planes];
	
	int n;
	
	io_byte* dp, * data = new io_byte[width * height * planes];
	
	for (dp = data, n = height; n > 0; n--, dp += width * planes) {
		
		bmp_in__get_line(bmp_img, dp);
			
	}

	io_byte* inverted_data = new io_byte[width * height * planes];
	flip_data(data, inverted_data, height, planes, width);
	
	
	
	for (int c = 0; c < planes; c++) {

		io_comp* comp = image_buf->comps + c;
		comp->width = width;
		comp->height = height;
		comp->buf = new int[comp->width * comp->height];

		
		for (int i = 0; i < comp->width * comp->height; i++) {
			
			comp->buf[i] = inverted_data[i * planes + c];
			
		}


	}
	return 0;
}


int write_bmp( io_image *image_buf, bmp_out *out_bmp ) {

	int width = image_buf->comps->width;
	int height = image_buf->comps->height;
	int planes = image_buf->num_components;
	int n = 0;

	io_byte* invt_data = new io_byte[width * height * planes];
	io_byte* dp,* invt_data_invt = new io_byte[width * height * planes];

	
	for (int c = 0; c < image_buf->num_components; c++) {
		io_comp* comp = image_buf->comps + c;

		for (int i = 0; i < comp->height * comp->width; i++) {
			
			invt_data[i * image_buf->num_components + c] = comp->buf[i];

		}
			   
	}

	flip_data(invt_data, invt_data_invt, height, planes, width);
	
	for (dp = invt_data_invt, n = height; n > 0; n--, dp += width * planes) {

		bmp_out__put_line(out_bmp, dp);
	}
		
	return 0;
}