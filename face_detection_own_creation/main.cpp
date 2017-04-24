#include <iostream>
#include <opencv2/opencv.hpp>
#include <omp.h>

#define FACE_CASCADE "/usr/share/opencv/haarcascades/haarcascade_frontalface_alt.xml"
#define WINDOW_NAME "Face_detecter"

using namespace std;
using namespace cv;

void detectAndDisplay( Mat frame );

CascadeClassifier face_cascade;

int main(int argc, char const *argv[])
{

	VideoCapture capture;
	Mat frame;

	// Loading face cascade
	if( !face_cascade.load(FACE_CASCADE) ){
		cout << "problema ao ler cascade" << endl;
		return -1;
	}

	capture.open(0);
	if(!capture.isOpened()){
		cout << "problema ao ligar câmera" << endl;
		return -1;
	}

	while( capture.read(frame) ){

		if(frame.empty()){
			cout << "Sem frame capturado" << endl;
			break;
		}

		// aplicando o cassifier na imagem recebida
		detectAndDisplay( frame );

		char c = (char) waitKey(10);
		if( c == 27 ) // ESC
			break;
	}


	
	return 0;
}

void detectAndDisplay( Mat frame ){

	std::vector<Rect> faces;

	Mat frame_gray;

	cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
	equalizeHist( frame_gray, frame_gray );

	face_cascade.detectMultiScale( 	frame_gray,
									faces,
									1.1,
									2,
									0 | CASCADE_SCALE_IMAGE,
									Size(30,30)
		);

	#pragma omp parallel for schedule(dynamic,1) num_threads(4)
	for( size_t i = 0; i < faces.size(); i++ ){
		cout << "NUmero de threads: " << omp_get_num_threads() << endl;
		Point center(	faces[i].x + faces[i].width/2,
						faces[i].y + faces[i].height/2
			);
		ellipse(	frame,
					center,
					Size( faces[i].width/2, faces[i].height/2 ),
					0,
					0,
					360,
					Scalar( 255, 0, 255 ),
					4,
					8,
					0
		 );

	}

	imshow( WINDOW_NAME, frame );

}