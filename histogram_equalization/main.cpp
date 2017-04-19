#include "main.hpp"

#define FOTO "/home/mamboy/Downloads/stormtrooper.jpg"
#define WINDOW "My Window"

using namespace std; // Namespace of Standard CPP libs
using namespace cv;	 // Namespace of OpenCV

int main( int argc, const char** argv )
{
     Mat img = imread(FOTO, CV_LOAD_IMAGE_COLOR); //open and read the image

     if (img.empty())
     {
          cout << "Image cannot be loaded..!!" << endl;
          return -1;
     }

     cvtColor(img, img, CV_BGR2GRAY); //change the color image to grayscale image

     Mat img_hist_equalized;
     equalizeHist(img, img_hist_equalized); //equalize the histogram

     //create windows
     namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
     namedWindow("Histogram Equalized", CV_WINDOW_AUTOSIZE);

     //show the image
     imshow("Original Image", img);
     imshow("Histogram Equalized", img_hist_equalized);

     waitKey(0); //wait for key press

     destroyAllWindows(); //destroy all open windows

     return 0;
}