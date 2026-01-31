#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat EdgeDetection(Mat resizedimage)
{
	Mat vertical_scan,horizontal_scan;
	Mat filterkernal2 = (Mat_<double>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
	Mat filterkernal3 = (Mat_<double>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);
	filter2D(resizedimage, vertical_scan, -1, filterkernal2);
	filter2D(vertical_scan,horizontal_scan, -1, filterkernal3);
	return horizontal_scan;
}

int main()
{
	Mat image = imread("C:/Users/srini/Pictures/dog.png", IMREAD_GRAYSCALE);
	Mat image2 = imread("C:/Users/srini/Pictures/shapes.webp", IMREAD_COLOR);
	if (image.empty())
	{
		cout << "Could not open or find the image!" << endl;
		return -1;
	}
	Mat resizedimage;
	resize(image, resizedimage, Size(500, 500), INTER_LINEAR);
	Mat filterkernal = (Mat_<float>(3, 3) << 0, 0, 0, 0, 1, 0, 0, 0, 0); //IDENTITY KERNAL
	Mat Output;
	filter2D(resizedimage, Output, -1, filterkernal);
	imshow("filter Image", Output);
	waitKey(0);

	Mat filterkernal2 = (Mat_<double>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 2);
	Mat Output2;
	filter2D(resizedimage, Output2, -1, filterkernal2);
	imshow("filter Image 2", Output2);
	Mat filterkernal3 = (Mat_<double>(3, 3) << 1, 2, 1, 0, 0, 0, -1, -2, -1);
	Mat Output3;
	filter2D(Output2, Output3, -1, filterkernal3);
	imshow("filter Image 3", Output3);

	Mat edgeimage = EdgeDetection(image2);
	imshow("Edge Detected Image", edgeimage);


	waitKey(0);

	destroyAllWindows();


	return 0;
}