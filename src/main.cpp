#include <opencv2/opencv.hpp>
#include <iostream>

#include "preprocessing.h"
#include "edge_detection.h"
#include "region_detection.h"

int main() {

    std::string imagePath = "images/xray.jpg";

    cv::Mat image = cv::imread(imagePath);

    if (image.empty()) {
        std::cout << "Error loading image\n";
        return -1;
    }

    std::cout << "Image loaded successfully\n";

    // Preprocessing
    cv::Mat gray = convertToGray(image);
    cv::Mat blurred = applyGaussianBlur(gray);

    // Edge detection
    cv::Mat edges = detectEdges(blurred);

    // Region detection
    cv::Mat result = detectRegions(image, edges);

    cv::imwrite("results/final_detection_modular.png", result);

    std::cout << "Region detection complete\n";

    return 0;
}