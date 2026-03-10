#include "preprocessing.h"

cv::Mat convertToGray(const cv::Mat& image) {

    cv::Mat gray;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    return gray;
}

cv::Mat applyGaussianBlur(const cv::Mat& image) {

    cv::Mat blurred;
    cv::GaussianBlur(image, blurred, cv::Size(5,5), 0);
    return blurred;
}

// NEW FUNCTION
cv::Mat enhanceContrast(const cv::Mat& image) {

    cv::Mat enhanced;

    cv::equalizeHist(image, enhanced);

    return enhanced;
}