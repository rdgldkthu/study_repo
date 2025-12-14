#include <chrono>
#include <iostream>

using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char **argv) {
  // Read image from argv[1]
  cv::Mat image;
  image = cv::imread(argv[1]);

  if (image.data == nullptr) {
    cerr << "File:" << argv[1] << " does not exist." << endl;
    return 0;
  }

  // Print some basic information
  cout << "Image Width:" << image.cols << ", Height:" << image.rows
       << ", Channels:" << image.channels() << endl;
  cv::imshow("image", image);
  cv::waitKey(0);

  // Check image type
  if (image.type() != CV_8UC1 && image.type() != CV_8UC3) {
    cout << "Incorrect image type." << endl;
    return 0;
  }

  // Iterate though pixels
  chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
  for (size_t y = 0; y < image.rows; y++) {
    unsigned char *row_ptr = image.ptr<unsigned char>(y);
    for (size_t x = 0; x < image.cols; x++) {
      unsigned char *data_ptr = &row_ptr[x * image.channels()];
      // Visit the pixel in each channel
      for (int c = 0; c != image.channels(); c++) {
        unsigned char data = data_ptr[c];
      }
    }
  }
  chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
  chrono::duration<double> time_used =
      chrono::duration_cast<chrono::duration<double>>(t2 - t1);
  cout << "Time used：" << time_used.count() << " seconds." << endl;

  // Assignment operator will not copy the image data but only the reference
  cv::Mat image_another = image;
  // Modifying image_another will also affect image
  image_another(cv::Rect(0, 0, 100, 100)).setTo(0);
  cv::imshow("image", image);
  cv::waitKey(0);

  // Use cv::Mat::clone to actually clone the data
  cv::Mat image_clone = image.clone();
  image_clone(cv::Rect(0, 0, 100, 100)).setTo(255);
  cv::imshow("image", image);
  cv::imshow("image_clone", image_clone);
  cv::waitKey(0);

  cv::destroyAllWindows();
  return 0;
}
