#include "main.hpp"

//#define FOTO "/home/mamboy/Downloads/stormtrooper.jpg"
#define WINDOW "My Window"


using namespace std; // Namespace of Standard CPP libs
using namespace cv;	 // Namespace of OpenCV

int main(int argc, char const *argv[])
{
	Mat img( 500, 1000,CV_8UC3, Scalar(0,0,100) );
	if(img.empty()){
		return -1;
	}


	namedWindow( WINDOW, CV_WINDOW_AUTOSIZE );
	imshow( WINDOW, img );

	waitKey(0);
	destroyWindow(WINDOW);

	return 0;
}