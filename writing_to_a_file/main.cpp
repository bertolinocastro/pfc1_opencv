#include "main.hpp"

//#define FOTO "/home/mamboy/Downloads/stormtrooper.jpg"
#define WINDOW "My Window"
#define FILE "/home/mamboy/Downloads/teste.jpg"

using namespace std; // Namespace of Standard CPP libs
using namespace cv;	 // Namespace of OpenCV

int main(int argc, char const *argv[])
{
	Mat img(650, 600, CV_16UC3, Scalar(0,50000,50000));

	if(img.empty()){
		cout << "Falha ao criar imagem\n";
		return -1;
	}

	vector<int> compression_params;

	compression_params.push_back( CV_IMWRITE_JPEG_QUALITY );

	compression_params.push_back( 98 );

	bool suc = imwrite( FILE, img, compression_params );

	if(!suc) {
		cout << "Falha ao escrever imagem \n";
		// return -1;
	}



	namedWindow(WINDOW, CV_WINDOW_AUTOSIZE);
	imshow(WINDOW, img);

	waitKey(0);

	destroyWindow(WINDOW);
	return 0;
}