#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat image = imread("C:/Users/srini/Pictures/dog.png",-1);
	if (image.empty()) {
		cout<<"Could not open or find the image:"<<endl;
		return -1;
	}
	Mat resizedImage;
	resize(image, resizedImage, Size(500, 500), INTER_LINEAR);
	//imshow("Resized_image", resizedImage);
	
	Mat original_Resized = resizedImage.clone();
	Point pt1(20, 30);
	Point pt2(300, 300);
	line(resizedImage, pt1, pt2, Scalar(0, 255, 0), 1);
	
	Point2f center((resizedImage.cols - 1) / 2, (resizedImage.rows - 1) / 2);
	circle(resizedImage, center, 50, Scalar(20, 10, 137), -1);
	Point2f Center((resizedImage.cols - 1) / 2, 100);
	ellipse(resizedImage, Center, Size(200, 50), 0.0, 0.0, 360.0, Scalar(0, 255, 0), 10);
	imshow("Annoted Image", resizedImage);
	waitKey(0);
	destroyAllWindows();
	return 0;

}