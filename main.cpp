#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
#include <fstream>

int main() {
    cv::Mat img = cv::imread("logo.png");
    cv::namedWindow("source", cv::WINDOW_AUTOSIZE);
    cv::imshow("source",img); //Source

    cv::Mat gimg;
    cv::namedWindow("gray", cv::WINDOW_AUTOSIZE);
    cv::cvtColor(img,gimg,cv::COLOR_BGR2GRAY);
    cv::imshow("gray",gimg); //Gray

    cv::Mat rgimg;
    cv::namedWindow("resize", cv::WINDOW_AUTOSIZE);
    cv::resize(gimg,rgimg,cv::Size(gimg.rows / 16,gimg.cols / 16));
    cv::imshow("resize",rgimg); //Resize & Gray

    std::vector<std::string> key{"M","A","/"}; //Composition
    std::string result = "";
    float unit = (256.0 + 1) / 2;

    int row = rgimg.rows; //Row
    int col = rgimg.cols; //Column

    for (int x = 0; x < row; ++x) {
        for (int y = 0; y < col; ++y) {
            result += key[int(rgimg.at<uchar>(x,y) / unit)];
        }
        result += "\n";
    }

    //std::cout << result << std::endl;

    std::ofstream file;
    file.open("out.txt"); //Output file in [project]/cmake-build-release/out.txt
    if(file.is_open()) file << result;
    file.close();

    cv::waitKey(0);
    return 0;
}