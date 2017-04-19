#include "main.hpp"

//#define FOTO "/home/mamboy/Downloads/stormtrooper.jpg"
#define WINDOW "My Window"
#define FILE "/home/mamboy/Downloads/rallye.mp4"

using namespace std; // Namespace of Standard CPP libs
using namespace cv;	 // Namespace of OpenCV

int main(int argc, char const *argv[])
{
	VideoCapture cap( 0 );

	if(!cap.isOpened()) return -1;

	double dwidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	double dheight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

	cout<<"Fame size: "<<dwidth<<"x"<<dheight<<endl;

	namedWindow(WINDOW, CV_WINDOW_AUTOSIZE);

	while(1){
		Mat frame;

		bool bSuccess = cap.read(frame);

		if(!bSuccess){
			cout << "Can't read frame from file" << endl;
			break;
		}

		imshow(WINDOW, frame);

		// cout << "Key presed: " << char(waitKey(30)) << endl;

		if(char(waitKey(30)) == char(27)){
			cout << "ESC pressed!" << endl;
			break;
		}

	}

	destroyWindow(WINDOW);
	return 0;
}