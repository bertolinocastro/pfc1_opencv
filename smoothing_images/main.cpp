#include "main.hpp"

#define FOTO "/home/mamboy/Downloads/stormtrooper.jpg"
#define WINDOW "My Window"
// #define FILE "/home/mamboy/Downloads/testevideo.avi"

using namespace std; // Namespace of Standard CPP libs
using namespace cv;	 // Namespace of OpenCV

int main( int argc, char** argv )
{
 //create 2 empty windows
 namedWindow( "Original Image" , CV_WINDOW_AUTOSIZE );
 namedWindow( "Smoothed Image" , CV_WINDOW_AUTOSIZE );

 // Load an image from file
 Mat src = imread( FOTO, 1 );

 //show the loaded image
 imshow( "Original Image", src );

 Mat dst;
 char zBuffer[35];

 for ( int i = 1; i < 31; i = i + 2 )
 { 
      //copy the text to the "zBuffer"
      sprintf(zBuffer, "Kernel Size : %d x %d", i, i);

      //smooth the image in the "src" and save it to "dst"
      blur( src, dst, Size( i, i ) );

      //put the text in the "zBuffer" to the "dst" image
      putText( dst, zBuffer, Point( src.cols/4, src.rows/8), CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255) );

      //show the blurred image with the text
      imshow( "Smoothed Image", dst );

      //wait for 2 seconds
      int c = waitKey(2000);

      //if the "esc" key is pressed during the wait, return
      if (c == 27)
      {
           return 0;
      }
 }

 //make the "dst" image, black
 dst = Mat::zeros( src.size(), src.type() );

 //copy the text to the "zBuffer"
 sprintf(zBuffer, "Press Any Key to Exit");

 //put the text in the "zBuffer" to the "dst" image
 putText( dst, zBuffer, Point( src.cols/4,  src.rows / 2), CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255) );

 //show the black image with the text
 imshow( "Smoothed Image", dst );
 
 //wait for a key press infinitely
 waitKey(0);
     
 return 0;

}