#include "laplace_blending.h"
#include "linear_blending.h"
#include "opencv2/imgproc.hpp"

cv::Mat laplaceBlending(const cv::Mat& img_1, const cv::Mat& img_2, const cv::Mat& weights)
{
  // Construct a gaussian pyramid of the weight image.
  // TODO 4.1: Finish constructGaussianPyramid().
  std::vector<cv::Mat> weights_pyr = constructGaussianPyramid(weights);

  // Construct a laplacian pyramid of each of the images.
  // TODO 4.2: Finish constructLaplacianPyramid().
  std::vector<cv::Mat> img_1_pyr = constructLaplacianPyramid(img_1);
  std::vector<cv::Mat> img_2_pyr = constructLaplacianPyramid(img_2);

  // Blend the laplacian pyramids according to the corresponding weight pyramid.
  std::vector<cv::Mat> blend_pyr(img_1_pyr.size());
  for (size_t i = 0; i < img_1_pyr.size(); ++i)
  {
    // TODO 4.3: Blend the images using linearBlending() on each pyramid level.
  }

  // TODO 4.4: Collapse the blended laplacian pyramid.
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
    // TODO 4.1.a: Add the next level in the pyramid.
    // Hint cv::pyrDown(...)

    break; // TODO 4.1.b: Remove this break! (Why did I have to add this now?)
  }

  return pyr;
}

std::vector<cv::Mat> constructLaplacianPyramid(const cv::Mat& img)
{
  // TODO 4.2.a: Use constructGaussianPyramid() to construct a laplacian pyramid.
  // Hint: cv::pyrUp(...)
  std::vector<cv::Mat> pyr;
  return pyr;
}

cv::Mat collapsePyramid(const std::vector<cv::Mat>& pyr)
{
  // TODO 4.4.a: Collapse the pyramid.
  return cv::Mat();
}
