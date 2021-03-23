#include <iostream>
#include <chrono>

using namespace std;

#include <opencv2/core/core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv\cv.hpp>

int main(int argc, char **argv) {
  // 读取argv[1]指定的图像
  cv::Mat image;
  image = cv::imread(argv[1]); //cv::imread函数读取指定路径下的图像

}
