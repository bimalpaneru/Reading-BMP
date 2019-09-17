#include "io_bmp.h"
#include "img_handle.h"
#include<iostream>

using namespace std;

int  main(int argc, char* argv[])
{

	bmp_in in;
	bmp_out out;
	io_image image_buf;
	   	 
	bmp_in__open(&in, argv[1]); // opens bmp file and fills up in

	int width = in.cols;
	int height = in.rows;
	int planes = in.num_components;
		
	
	read_bmp(&in, &image_buf); //read bmp and fills up the image buffer with individual components
	bmp_in__close(&in);

	bmp_out__open(&out, argv[2], width, height, planes);
	write_bmp(&image_buf, &out); //writes back image buffer to output bmp file
	
	bmp_out__close(&out);
	return 0;

}


