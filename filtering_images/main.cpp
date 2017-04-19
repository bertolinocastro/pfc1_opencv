#include "main.hpp"

//#define FOTO "/home/mamboy/Downloads/stormtrooper.jpg"
#define WINDOW "My Window"
#define WINDOW2 "My Window2"
#define FILE "/home/mamboy/Downloads/stormtrooper.jpg"

using namespace std; // Namespace of Standard CPP libs
using namespace cv;	 // Namespace of OpenCV

int main(int argc, char const *argv[])
{
	IplImage *img = cvLoadImage(FILE);
	
	cvNamedWindow(WINDOW);
	cvShowImage(WINDOW, img);

	cvNot(img,img);
	cvNamedWindow(WINDOW2);
	cvShowImage(WINDOW2,img);

	cvWaitKey(0);

	cvDestroyWindow(WINDOW);
	cvDestroyWindow(WINDOW2);

	cvReleaseImage(&img);

	return 0;
}