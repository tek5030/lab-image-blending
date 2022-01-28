#pragma once

#include "opencv2/core.hpp"

/// \brief Blends two images according to scale.
/// \param img_1 A three channel image with data type CV_32F.
/// \param img_2 A three channel image with data type CV_32F.
/// \param weights A three channel image with data type CV_32F, containing the weights in the range [0,1].
/// \return The resulting blended image.
cv::Mat laplaceBlending(const cv::Mat& img_1, const cv::Mat& img_2, const cv::Mat& weights);

/// \brief Constructs a gaussian pyramid.
/// \param img The original image.
/// \return The pyramid represented as a std::vector with images, starting at the original scale.
std::vector<cv::Mat> constructGaussianPyramid(const cv::Mat& img);

/// \brief Constructs a laplacian pyramid.
/// \param img The original image.
/// \return The pyramid represented as a std::vector with images, starting at the original scale.
std::vector<cv::Mat> constructLaplacianPyramid(const cv::Mat& img);

/// \brief Collapses a laplacian pyramid into a image.
/// \param pyr A laplacian pyramid.
/// \return The resulting image.
cv::Mat collapsePyramid(const std::vector<cv::Mat>& pyr);
