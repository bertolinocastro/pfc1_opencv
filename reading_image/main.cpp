#include "main.hpp"

#define FOTO "/home/mamboy/Downloads/stormtrooper.jpg"
#define WINDOW "My Window"


using namespace std; // Namespace of Standard CPP libs
using namespace cv;	 // Namespace of OpenCV

int main(int argc, char const *argv[])
{
	Mat img = imread( FOTO, CV_LOAD_IMAGE_UNCHANGED );

	if(img.empty()){
		cout << "Error: Image cannot be loaded!" << endl;
		return -1;
	}

	namedWindow( WINDOW, CV_WINDOW_AUTOSIZE );

	imshow( WINDOW, img );

	waitKey( 0 );
	destroyWindow( WINDOW );
	return 0;
}