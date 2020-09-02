#ifndef __REALSENSE__
#define __REALSENSE__

#include <librealsense2/rs.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;

class RealSense
{
private:
    // RealSense
    rs2::pipeline pipeline;
    rs2::pipeline_profile pipeline_profile;
    rs2::frameset aligned_frameset;

    // Color Buffer
    rs2::frame color_frame;
    
    uint32_t color_width = 640;
    uint32_t color_height = 480;
    uint32_t color_fps = 30;

    // Depth Buffer
    rs2::frame depth_frame;
    uint32_t depth_width = 640;
    uint32_t depth_height = 480;
    uint32_t depth_fps = 30;

public:

	cv::Mat depth_mat;
	cv::Mat color_mat;
public:
	// Constructor
	RealSense();

	// Destructor
	~RealSense();

	// Initialize
	void initialize();

	// Finalize
	void finalize();

	// Update Data
	void update();

	// Update Color
	cv::Mat GetColor();

	// Update Depth
	cv::Mat GetDepth();


};

extern int Point_Loc[2];//µã»÷µÄ×ø±ê
extern void on_mouse(int EVENT, int x, int y, int flags, void* userdata);


#endif

