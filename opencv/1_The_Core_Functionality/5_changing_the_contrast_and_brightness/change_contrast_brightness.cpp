#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include <iostream>
#include <opencv2/core/saturate.hpp>

using std::cin;
using std::cout;
using std::endl;
using namespace cv;

int main(int argc, char **argv) {
  CommandLineParser parser(argc, argv, "{@input | lena.jpg | input image}");
  Mat image = imread(parser.get<String>("@input"));
  if (image.empty()) {
    cout << "Could not open or find the image!\n" << endl;
    cout << "Usage: " << argv[0] << " <Input image>" << endl;
    return -1;
  }

  Mat new_image = Mat::zeros(image.size(), image.type());
  Mat new_image_gamma = Mat::zeros(image.size(), image.type());

  cout << " Basic Linear Transforms " << endl;
  cout << "-------------------------" << endl;

  // alpha-beta correction
  double alpha = 1.0;
  int beta = 0;
  cout << "* Enter the alpha value [1.0-3.0]: "; cin >> alpha;
  cout << "* Enter the beta value [0-100]: "; cin >> beta;

  for (int y = 0; y < image.rows; y++) {
    for (int x = 0; x < image.cols; x++) {
      for (int c = 0; c < image.channels(); c++) {
        new_image.at<Vec3b>(y, x)[c] =
        saturate_cast<uchar>(alpha * image.at<Vec3b>(y, x)[c] + beta);
      }
    }
  }
  // can instead use image.convertTo(new_image, -1, alpha, beta);

  // gamma correction
  double gamma = 1.0;
  cout << "* Enter the beta value [0.04-25.0]: "; cin >> gamma;

  Mat lookUpTable(1, 256, CV_8U);
  uchar* p = lookUpTable.ptr();
  for(int i =0; i < 256; i++)
    p[i] = saturate_cast<uchar>(pow(i/255.0, gamma) * 255.0);
  LUT(image, lookUpTable, new_image_gamma);

  imshow("Original Image", image);
  imshow("New Image (alpha-beta)", new_image);
  imshow("New Image (gamma)", new_image_gamma);

  waitKey(0);
  return 0;
}
