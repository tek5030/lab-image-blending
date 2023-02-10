#pragma once

#include "opencv2/core.hpp"

/// \brief Runs the lab.
void runImageBlendingLab();

/// \brief Shows an image in a window with the corresponding title.
/// \param title Window title (and name).
/// \param img The image to show.
void showResult(const std::string& title, const cv::Mat& img);
