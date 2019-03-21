#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace cv;
using namespace std;

/**  @function main */
int main( int argc, char** argv )
{
  Mat frame;
  Mat frame_l, frame_r;
  int y;
  int flag = 0;
  unsigned char *ptr_frame_org, *ptr_frame;
  unsigned char *ptr_frame_l_org, *ptr_frame_l;
  unsigned char *ptr_frame_r_org, *ptr_frame_r;

  VideoCapture cap(0);
  if(!cap.isOpened())
  {
      return -1;
  }


  // Display Image
  namedWindow( "Left Image", CV_WINDOW_AUTOSIZE );
  namedWindow( "Right Image", CV_WINDOW_AUTOSIZE );


  for(;;)
  {

    cap >> frame; // Obtenir une image de la camera
    if (flag == 0)
    {
      ptr_frame_org = frame.ptr<uchar>(0);
      frame_l.create(frame.rows, (frame.cols)/2, CV_8UC3 );
      frame_r.create(frame.rows, (frame.cols)/2, CV_8UC3 );
      ptr_frame_l_org = frame_l.ptr<uchar>(0);
      ptr_frame_r_org = frame_r.ptr<uchar>(0);
      flag = 1;

    }
    // Copie of Images
    ptr_frame = ptr_frame_org;
    ptr_frame_l = ptr_frame_l_org;
    ptr_frame_r = ptr_frame_r_org;

    for (y = 0; y < frame.rows; y++)
    {
        memcpy(ptr_frame_l, ptr_frame, (3 * frame.cols)/2 );
        ptr_frame += (3 * frame.cols)/2;
        ptr_frame_l += (3 * frame.cols)/2;

        memcpy(ptr_frame_r, ptr_frame, (3 * frame.cols)/2 );
        ptr_frame += (3 * frame.cols)/2;
        ptr_frame_r += (3 * frame.cols)/2;

    }

    imshow( "Left Image", frame_l);
    imshow( "Right Image", frame_r);
    if(waitKey(1) >= 0) break;
    }


  /// Wait until user exits the program
  waitKey(0);

  return 0;
}
