#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	Mat image = imread("C:/Users/srini/Pictures/dog.png",IMREAD_COLOR);
	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		return -1;
	}
	//cout << "The size of the image is : "<<image.size << endl;

	Mat crooped_image=image(Range(0,1000),Range(1000,1700));
	Mat resized_image;
	resize(crooped_image, resized_image,Size(500,500),INTER_LINEAR);
	//imshow("Cropped Image", resized_image);
	Mat traced_image = image.clone();
	Mat Rsized_traced_image;
	resize(traced_image, Rsized_traced_image, Size(500, 500), INTER_LINEAR);
	Point pt1(180,10);
	Point pt2(350,450);
	rectangle(Rsized_traced_image, pt1, pt2, Scalar(0, 0, 0), 1);
	//imshow("Traced Image", Rsized_traced_image);
	//imshow("Original Image", image);

	//"----------------------------------------"
			//To create Patches
	//-------------------------------------------
	int imgwidth = resized_image.cols;
	cout << "The imgwidth is :" << imgwidth << endl;
	int w = imgwidth / 4;
	int imgheight = resized_image.rows;
	int h = (imgheight / 4);
	cout << w << endl;
	for (int i = 0; i<imgwidth; i = i + w) {
		//cout << i << endl;
		Mat patch1 = resized_image(Range(0, 500), Range(i, i + w));
		imwrite("C:/Users/srini/Pictures/Patch_" + to_string(i) + ".png", patch1);

	}
	for (int j = 0; j < imgheight; j = j + h) {
		//cout << i << endl;
		Mat patch2 = resized_image(Range(j, j+h), Range(0, imgheight));
		imwrite("C:/Users/srini/Pictures/Patch_" + to_string(j) +" v"+".png", patch2);

	}
	for (int j = 0; j < imgheight; j = j + h) {
		//cout << i << endl;
		for (int i = 0; i < imgwidth; i = i + w) {
			Mat patch12 = resized_image(Range(j, j + h), Range(i,i+w));
			imwrite("C:/Users/srini/Pictures/Patch_" + to_string(i)+to_string(j) + "_vh" + ".png", patch12);
		}
	}

	/*Point2f center(...) : This declares a variable named center of the type Point2f, which is an OpenCV data structure designed 
	to store a 2D point using floating - point coordinates(f)
	*/


	Point2f Center((resized_image.cols -1)/ 2.0f, (resized_image.rows -1)/ 2.0f);
	cout << "Center Point is : " << Center << endl;
	// cout << Center.x << endl;  Accessing x coordinate of Center point

	Mat Rotation_Matrix = getRotationMatrix2D(Center,90,1);
	Mat Rotated_image;
	warpAffine(resized_image, Rotated_image, Rotation_Matrix, Size(500,500));
	imshow("Rotated Image", Rotated_image);
	waitKey(0);
	imwrite("C:/Users/srini/Pictures/Rotated_image.png", Rotated_image);

	float tx = 300;
	float ty = 100;
	float  warp_values[] = {1,0,tx,0,1,ty};
	Mat Translation_Matrix = Mat(2, 3, CV_32F, warp_values);
	Mat Translated_image;
	warpAffine(resized_image, Translated_image, Translation_Matrix, Size(1200, 700));
	imshow("Translated Image", Translated_image);
	waitKey(0);
	destroyAllWindows();
	return 0;
}