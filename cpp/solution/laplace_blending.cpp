#include "laplace_blending.h"
#include "linear_blending.h"
#include "opencv2/imgproc.hpp"

cv::Mat laplaceBlending(const cv::Mat& img_1, const cv::Mat& img_2, const cv::Mat& weights)
{
  // Construct a gaussian pyramid of the weight image.
  std::vector<cv::Mat> weights_pyr = constructGaussianPyramid(weights);

  // Construct a laplacian pyramid of each of the images.
  std::vector<cv::Mat> img_1_pyr = constructLaplacianPyramid(img_1);
  std::vector<cv::Mat> img_2_pyr = constructLaplacianPyramid(img_2);

  // Blend the laplacian pyramids according to the corresponding weight pyramid.
  std::vector<cv::Mat> blend_pyr(img_1_pyr.size());
  for (size_t i = 0; i < img_1_pyr.size(); ++i)
  {
    blend_pyr[i] = linearBlending(img_1_pyr[i], img_2_pyr[i], weights_pyr[i]);
  }

  return collapsePyramid(blend_pyr);
}

std::vector<cv::Mat> constructGaussianPyramid(const cv::Mat& img)
{
  // Construct the pyramid starting with the original image.
  std::vector<cv::Mat> pyr;
  pyr.push_back(img.clone());

  // Add new downscaled images to the pyramid
  // until image width is <= 16 pixels
  while(pyr.back().cols > 16)
  {
    // Hint cv::pyrDown(...)
    cv::Mat next_level;
    cv::pyrDown(pyr.back(), next_level);
    pyr.push_back(next_level);
  }

  return pyr;
}

std::vector<cv::Mat> constructLaplacianPyramid(const cv::Mat& img)
{
  // Hint: cv::pyrUp(...)
  std::vector<cv::Mat> pyr = constructGaussianPyramid(img);

  for (size_t i = 0; i < pyr.size() - 1; ++i)
  {
    cv::Mat rescaled_level;
    cv::pyrUp(pyr[i + 1], rescaled_level, pyr[i].size());
    pyr[i] -= rescaled_level;
  }

  return pyr;
}

cv::Mat collapsePyramid(const std::vector<cv::Mat>& pyr)
{
  for (int i = static_cast<int>(pyr.size()) - 2; i >= 0; --i)
  {
    cv::Mat rescaled_level;
    cv::pyrUp(pyr[i + 1], rescaled_level, pyr[i].size());
    pyr[i] += rescaled_level;
  }

  return pyr[0];
}
