#include "main.hpp"

//#define FOTO "/home/mamboy/Downloads/stormtrooper.jpg"
#define WINDOW "My Window"
#define FILE "/home/mamboy/Downloads/testevideo.avi"

using namespace std; // Namespace of Standard CPP libs
using namespace cv;	 // Namespace of OpenCV

int main(int argc, char const *argv[])
{

	VideoCapture cap(0);

	if(!cap.isOpened()){
		cout << "Falha ao abrir device\n";
		return -1;
	}

	namedWindow(WINDOW, CV_WINDOW_AUTOSIZE);
	
	double width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	double height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

	cout << "Resolução: "<<width<<"X"<<height<<endl;

	Size frameSize(static_cast<int>(width),static_cast<int>(height) );

	VideoWriter ovw(FILE, CV_FOURCC('P','I','M','1'), 20, frameSize, true);

	if(!ovw.isOpened()){
		cout << "Falha ao abrir escritor\n";
		return -1;
	}

	while(1){
		Mat frame;

		bool bsuc = cap.read(frame);

		if(!bsuc){
			cout<<"Falha ao ler do device"<<endl;
			break;
		}

		ovw.write(frame);

		imshow(WINDOW,frame);

		if(char(waitKey(10))==27){
			cout<<"Esc pressed!"<<endl;
			break;
		}


	}

	return 0;
}