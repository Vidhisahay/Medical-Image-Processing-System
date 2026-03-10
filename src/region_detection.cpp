#include "region_detection.h"

cv::Mat detectRegions(const cv::Mat& image, const cv::Mat& edges) {

    std::vector<std::vector<cv::Point>> contours;

    cv::findContours(edges, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    cv::Mat result = image.clone();

    for (const auto& contour : contours) {

        double area = cv::contourArea(contour);

        // Ignore very small regions
        if (area > 500) {

            cv::Rect box = cv::boundingRect(contour);

            cv::rectangle(result, box, cv::Scalar(0,255,0), 2);
        }
    }

    return result;
}