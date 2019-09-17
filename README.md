# Reading BMP's individual color components to a structure
BMP has origin of image at botom left So, for further 2D signal processing application the read image values were set such that the origin is set at top left.
This is a part of laboratory excersise for Multimedia Signal Processing course at EET UNSW Sydney.

Image is flipped horizontally here to highlight the change of origin. A library provided by Prof. David Taubman for reading 8 bit and 24 bit bmp files "io_bmp" is used for reading and displaying the bmp file.
