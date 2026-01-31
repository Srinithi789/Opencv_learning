#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    Mat img =imread("C:/Users/srini/Pictures/orange/iris-scatterplot.png", 1);
    Mat dog = imread("C:/Users/srini/Pictures/dog.png",IMREAD_GRAYSCALE);
    //imshow("IrisData Scatter plot", img);
	//imshow("Dog Image", dog);
    //imwrite("dog_grayscale.jpg", dog);

    //waitKey(0);
	//destroyAllWindows();
    

	//OPencv Resizing Image

    Mat resizedimg,resizedimg_area,resizedimg_nearest;
    cout << "orginal size" << endl;
    cout << "----------------------------" << endl;
	cout << "Original Dog Image Size: " << dog.size() << endl;
	cout << "Height of Dog originaal image: " << dog.rows << endl;
    cout << "width of Dog originaal image: " << dog.cols << endl;

    cout << "After Resizing" << endl;
    cout << "----------------------------" << endl;
    resize(dog, resizedimg, Size(500, 500),INTER_LINEAR);
	imshow("Resized Dog Image Linear Interpol", resizedimg);
    cout<<"Resized Dog Image Size: " << resizedimg.size() << endl;
    cout << "Height of Dog resized image: " << resizedimg.rows << endl;
	cout << "width of Dog resized image: " << resizedimg.cols << endl;

	double fx = 1.5;
	double fy = 1.5;

	double scale_up = 1.2;
	double scale_down = 0.5;
    resize(dog, resizedimg, Size(), fx, fy, INTER_LINEAR);
	imshow("Resized Dog Image with fx and fy", resizedimg);
	waitKey(0);
	destroyAllWindows();
    return 0;
}
