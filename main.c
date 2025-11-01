#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int widths;
    int heights;
    int channels;
    unsigned char* data;
} Image;

void initImage(Image* image)
{
    image->data = stbi_load("image.jpg", &image->widths, &image->heights, &image->channels, 3);
    if (!image->data)
    {
        printf("Cant init image\n");
    }
}
// index = (y * width + x) * 3 (RGB)
int posConvertor(int x,int y,int width)
{
	return y * width + x;
}

char asciiConvertor(float brightness)
{
	char chars[] = "@%#*+=-:. ";
	int index = (int)((brightness * (sizeof(chars)-2)) / 255); 
	char pixelChar = chars[index];
	return pixelChar;
}

// brightness = 0.299 * R + 0.587 * G + 0.114 * B;
float rgbToBrightness(Image* image,int pixel_address) // Use posConvertor function on x,y before put it in pixel_address
{
	unsigned char r = image->data[pixel_address*3 + 0];
	unsigned char g = image->data[pixel_address*3 + 1];
	unsigned char b = image->data[pixel_address*3 + 2];

	return (float)(0.299f * r + 0.587f * g + 0.114f * b);
}

void freeImage(Image* image)
{
    stbi_image_free(image->data);
    free(image);
}

int main()
{
    Image* img = malloc(sizeof(Image)); //this was named i
    initImage(img);	

    // printf("Image loaded: %dx%d, %d channels\n", i->widths, i->heights, i->channels);
    // printf("First pixel's brightness:%f\n",rgbToBrightness(i,posConvertor(0,0,i->widths)));
    // printf("First letter:%c\n",asciiConvertor(rgbToBrightness(i,posConvertor(0,0,i->widths))));
    
    FILE *output;
    output = fopen("output.txt","w");
    
    for(int i = 0;i < img->heights;i++)
    {
    	for(int j = 0;j < img->widths;j++)
	{
		char s[2] = {asciiConvertor(rgbToBrightness(img,posConvertor(j,i,img->widths))), '\0'};
		const char* str = s;
		fprintf(output,"%s",str);
	}
	fprintf(output,"\n");
    }

    fclose(output);

    freeImage(img);
    return 0;
}

