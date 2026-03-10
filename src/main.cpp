#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem>

#include "preprocessing.h"
#include "edge_detection.h"
#include "region_detection.h"

namespace fs = std::filesystem;

int main() {

    std::string inputFolder = "images";

    for (const auto& entry : fs::directory_iterator(inputFolder)) {

        std::string imagePath = entry.path().string();

        std::cout << "Processing: " << imagePath << std::endl;

        cv::Mat image = cv::imread(imagePath);

        if (image.empty()) {
            std::cout << "Skipping invalid image\n";
            continue;
        }

        // Preprocessing
        cv::Mat gray = convertToGray(image);
        cv::Mat blurred = applyGaussianBlur(gray);

        // Edge detection
        cv::Mat edges = detectEdges(blurred);

        // Region detection
        cv::Mat result = detectRegions(image, edges);

        std::string outputPath =
            "results/processed_" + entry.path().filename().string();

        cv::imwrite(outputPath, result);

        std::cout << "Saved: " << outputPath << std::endl;
    }

    std::cout << "Batch processing complete\n";

    return 0;
}