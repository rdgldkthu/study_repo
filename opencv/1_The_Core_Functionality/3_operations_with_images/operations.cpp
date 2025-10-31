#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

int main(int, char **) {
  string filename = "";
  // Input/Output
  {
    Mat img = imread(filename);
    CV_UNUSED(img);
  }
  {
    Mat img = imread(filename, IMREAD_GRAYSCALE);
    CV_UNUSED(img);
  }
  {
    Mat img(4, 4, CV_8U);
    imwrite(filename, img);
  }
  // Accessing pixel intensity values
  {
    Mat img(4, 4, CV_8U);
    int y = 0, x = 0;
    {
      Scalar intensity = img.at<uchar>(y, x);
      CV_UNUSED(intensity);
    }
    {
      Scalar intensity = img.at<uchar>(Point(x, y));
      CV_UNUSED(intensity);
    }
    {
      Vec3b intensity = img.at<Vec3b>(y, x);
      uchar blue = intensity.val[0];
      uchar green = intensity.val[1];
      uchar red = intensity.val[2];
      CV_UNUSED(blue);
      CV_UNUSED(green);
      CV_UNUSED(red);
    }
    {
      Vec3f intensity = img.at<Vec3f>(y, x);
      float blue = intensity.val[0];
      float green = intensity.val[1];
      float red = intensity.val[2];
      CV_UNUSED(blue);
      CV_UNUSED(green);
      CV_UNUSED(red);
    }
    {
      img.at<uchar>(y, x) = 128;
    }
    {
      int i = 0;
      vector<Point2f> points;
      //... fill the array
      Mat pointsMat = Mat(points);

      Point2f point = pointsMat.at<Point2f>(i, 0);
      CV_UNUSED(point);
    }
  }
  // Memory management and reference counting
  {
    vector<Point3f> points;
    // .. fill the array
    Mat pointsMat = Mat(points).reshape(1);
    CV_UNUSED(pointsMat);
  }
  {
    Mat img = imread("image.jpg");
    Mat img1 = img.clone();
    CV_UNUSED(img1);
  }
  {
    Mat img = imread("image.jpg");
    Mat sobelx;
    Sobel(img, sobelx, CV_32F, 1, 0);
  }
  // Primitive operations
  {
    Mat img;
    { img = Scalar(0); }
    {
      Rect r(10, 10, 100, 100);
      Mat smallImg = img(r);
      CV_UNUSED(smallImg);
    }
  }
  {
    Mat img = imread("image.jpg"); // loading a 8UC3 image
    Mat grey;
    cvtColor(img, grey, COLOR_BGR2GRAY);
  }
  {
    Mat dst, src;
    src.convertTo(dst, CV_32F);
  }
  // Visualizing images
  {
    Mat img = imread("image.jpg");
    namedWindow("image", WINDOW_AUTOSIZE);
    imshow("image", img);
    waitKey();
  }
  {
    Mat img = imread("image.jpg");
    Mat grey;
    cvtColor(img, grey, COLOR_BGR2GRAY);
    Mat sobelx;
    Sobel(grey, sobelx, CV_32F, 1, 0);
    double minVal, maxVal;
    minMaxLoc(sobelx, &minVal, &maxVal); // find minimum and maximum intensities
    Mat draw;
    sobelx.convertTo(draw, CV_8U, 255.0 / (maxVal - minVal),
                     -minVal * 255.0 / (maxVal - minVal));
    namedWindow("image", WINDOW_AUTOSIZE);
    imshow("image", draw);
    waitKey();
  }

  return 0;
}
