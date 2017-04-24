#include <cstdio>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <opencv2/opencv.hpp>

using namespace cv;

string const window_name = "Take a pic";

char const diretorio[] = "imagens_camera/";

void imprimeFoto(Mat image, std::vector<int> &parameters);

int main(int argc, char const *argv[])
{
	
	VideoCapture camera(0);
	unsigned int conta_nome=0;

	if(!camera.isOpened()){
		printf("Failed to open device\n");
		return -1;
	}

	namedWindow(window_name);

	Mat frame;

	std::vector<int> parameters;

	parameters.push_back( CV_IMWRITE_JPEG_QUALITY );
	parameters.push_back( 100 );

	while(1){
		camera >> frame;

		if(frame.empty()){
			printf("Whitout more frames in Device\n");
			return -1;
		}

		imshow(window_name, frame);

		char btn = (char) waitKey(10); 

		if( 27 == btn ){
			printf("Esc pressionado\n");
			break;
		}
		if( ' ' == btn ){
			char file_name[50];
			sprintf( file_name, "%s%u.jpeg", diretorio, conta_nome );
			printf("%s\n",file_name );

			if( access( diretorio, F_OK ) ){
				printf("Diretorio nao existe\n");
				mkdir( diretorio, 0764 );
			}

			while( !access( file_name, F_OK ) ){
				printf("Arquivo já existe\n");
				sprintf( file_name, "%s%u.jpeg", diretorio, ++conta_nome );
			}

			imwrite( file_name, frame, parameters);
		}

	}


	destroyWindow(window_name);

	return 0;
}



