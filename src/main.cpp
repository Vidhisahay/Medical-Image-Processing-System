#include <opencv2/opencv.hpp>
#include <iostream>

int main() {

    std::string imagePath = "images/xray.jpg";

    cv::Mat image = cv::imread(imagePath);

    if (image.empty()) {
        std::cout << "Error: Could not load image\n";
        return -1;
    }

    std::cout << "Image loaded successfully\n";

    // Convert to grayscale
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

    // Gaussian blur
    cv::Mat blurredImage;
    cv::GaussianBlur(grayImage, blurredImage, cv::Size(5,5), 0);

    // Edge detection
    cv::Mat edges;
    cv::Canny(blurredImage, edges, 50, 150);

    // Find contours
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(edges, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    cv::Mat result = image.clone();

    int detectedRegions = 0;

    for (const auto& contour : contours) {

        double area = cv::contourArea(contour);

        // Ignore tiny contours
        if (area > 500) {

            cv::Rect box = cv::boundingRect(contour);

            cv::rectangle(result, box, cv::Scalar(0,255,0), 2);

            detectedRegions++;
        }
    }

    std::cout << "Significant regions detected: " << detectedRegions << std::endl;

    cv::imwrite("results/detected_regions.png", result);

    std::cout << "Result saved\n";

    return 0;
}