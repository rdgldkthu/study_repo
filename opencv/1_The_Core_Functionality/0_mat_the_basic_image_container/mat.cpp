#include "opencv2/core.hpp"
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
  { // Mat
    // All of these point to the same matrix
    Mat A, C; // Creates just the header parts
    A = imread("starry_night.jpg", IMREAD_COLOR);
    Mat B(A); // Copy constructor
    C = A;    // Assignment operator

    // You can create headers which refer to only a subsection of the full data
    Mat D(A, Rect(10, 10, 100, 100));     // using a rectangle
    Mat E = A(Range::all(), Range(1, 3)); // using row and column boundaries

    // Sometimes you will want to copy the matrix itself
    Mat F = A.clone();
    Mat G;
    A.copyTo(G);
  }

  { // Creating a Mat object explicitly
    // The data type to use for storing the elements and the number of channels
    // per matrix point CV_[The number of bits per item][Signed or
    // Unsigned][Type Prefix]C[The channel number]
    Mat M(2, 2, CV_8UC3, Scalar(0, 0, 255));
    cout << "M = " << endl << " " << M << endl << endl;

    // More than to dimensions
    int sz[3] = {2, 2, 2};
    Mat L(3, sz, CV_8UC(1), Scalar::all(0));

    // You cannot initialize the matrix values with this construction. It will
    // only reallocate its matrix data memory if the new size will not fit into
    // the old one.
    M.create(4, 4, CV_8UC(2));
    cout << "M = " << endl << " " << M << endl << endl;

    // MATLAB style initializer: cv::Mat::zeros , cv::Mat::ones , cv::Mat::eye
    Mat E = Mat::eye(4, 4, CV_64F);
    cout << "E = " << endl << " " << E << endl << endl;
    Mat O = Mat::ones(2, 2, CV_32F);
    cout << "O = " << endl << " " << O << endl << endl;
    Mat Z = Mat::zeros(3, 3, CV_8UC1);
    cout << "Z = " << endl << " " << Z << endl << endl;

    // For small matrices you may use comma separated initializers or
    // initializer lists
    Mat C = (Mat_<double>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    cout << "C = " << endl << " " << C << endl << endl;
    C = (Mat_<double>({0, -1, 0, -1, 5, -1, 0, -1, 0})).reshape(3);
    cout << "C = " << endl << " " << C << endl << endl;

    // Create a new header for an existing Mat object and cv::Mat::clone or
    // cv::Mat::copyTo it
    Mat RowClone = C.row(1).clone();
    cout << "RowClone = " << endl << " " << RowClone << endl << endl;
  }

  { // Output formatting
    Mat R = Mat(3, 2, CV_8UC3);
    randu(R, Scalar::all(0), Scalar::all(255));

    // Default
    cout << "R (default) = " << endl << R << endl << endl;

    // Python
    cout << "R (python)  = " << endl
         << format(R, Formatter::FMT_PYTHON) << endl
         << endl;

    // CSV
    cout << "R (csv)     = " << endl
         << format(R, Formatter::FMT_CSV) << endl
         << endl;

    // Numpy
    cout << "R (numpy)   = " << endl
         << format(R, Formatter::FMT_NUMPY) << endl
         << endl;

    // C
    cout << "R (c)       = " << endl
         << format(R, Formatter::FMT_C) << endl
         << endl;
  }

  { // Output of other common items
    // 2D Point
    Point2f P(5, 1);
    cout << "Point (2D) = " << P << endl << endl;

    // 3D Point
    Point3f P3f(2, 6, 7);
    cout << "Point (3D) = " << P3f << endl << endl;

    // std::vector via cv::Mat
    vector<float> v;
    v.push_back((float)CV_PI);
    v.push_back(2);
    v.push_back(3.01f);
    cout << "Vector of floats via Mat = " << Mat(v) << endl << endl;

    // std::vector of points
    vector<Point2f> vPoints(20);
    for (size_t i = 0; i < vPoints.size(); ++i)
      vPoints[i] = Point2f((float)(i * 5), (float)(i % 7));
    cout << "A vector of 2D Points = " << vPoints << endl << endl;
  }
  return 0;
}