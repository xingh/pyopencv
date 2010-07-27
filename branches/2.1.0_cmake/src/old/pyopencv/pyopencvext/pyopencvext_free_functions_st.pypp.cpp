// This file has been generated by Py++.

#include "boost/python.hpp"
#include "opencv_headers.hpp"
#include "pyopencvext_free_functions_st.pypp.hpp"

namespace bp = boost::python;

void register_free_functions_st(){

    { //::cvStartReadChainPoints
    
        typedef void ( *startReadChainPoints_function_type )( ::CvChain *,::CvChainPtReader * );
        
        bp::def( 
            "startReadChainPoints"
            , startReadChainPoints_function_type( &::cvStartReadChainPoints )
            , ( bp::arg("chain"), bp::arg("reader") )
            , "\nWrapped function:"
    "\n    cvStartReadChainPoints" );
    
    }

    { //::cvStartWindowThread
    
        typedef int ( *startWindowThread_function_type )(  );
        
        bp::def( 
            "startWindowThread"
            , startWindowThread_function_type( &::cvStartWindowThread )
            , "\nWrapped function:"
    "\n    cvStartWindowThread" );
    
    }

    { //::cv::stereoCalibrate
    
        typedef double ( *stereoCalibrate_function_type )( ::std::vector< std::vector< cv::Point3_<float> > > const &,::std::vector< std::vector< cv::Point_<float> > > const &,::std::vector< std::vector< cv::Point_<float> > > const &,::cv::Mat &,::cv::Mat &,::cv::Mat &,::cv::Mat &,::cv::Size,::cv::Mat &,::cv::Mat &,::cv::Mat &,::cv::Mat &,::cv::TermCriteria,int );
        
        bp::def( 
            "stereoCalibrate"
            , stereoCalibrate_function_type( &::cv::stereoCalibrate )
            , ( bp::arg("objectPoints"), bp::arg("imagePoints1"), bp::arg("imagePoints2"), bp::arg("cameraMatrix1"), bp::arg("distCoeffs1"), bp::arg("cameraMatrix2"), bp::arg("distCoeffs2"), bp::arg("imageSize"), bp::arg("R"), bp::arg("T"), bp::arg("E"), bp::arg("F"), bp::arg("criteria")=cv::TermCriteria(3, 30, 9.99999999999999954748111825886258685613938723691e-7), bp::arg("flags")=int(::cv::CALIB_FIX_INTRINSIC) ) );
    
    }

    { //::cv::stereoRectify
    
        typedef void ( *stereoRectify_function_type )( ::cv::Mat const &,::cv::Mat const &,::cv::Mat const &,::cv::Mat const &,::cv::Size,::cv::Mat const &,::cv::Mat const &,::cv::Mat &,::cv::Mat &,::cv::Mat &,::cv::Mat &,::cv::Mat &,int );
        
        bp::def( 
            "stereoRectify"
            , stereoRectify_function_type( &::cv::stereoRectify )
            , ( bp::arg("cameraMatrix1"), bp::arg("distCoeffs1"), bp::arg("cameraMatrix2"), bp::arg("distCoeffs2"), bp::arg("imageSize"), bp::arg("R"), bp::arg("T"), bp::arg("R1"), bp::arg("R2"), bp::arg("P1"), bp::arg("P2"), bp::arg("Q"), bp::arg("flags")=int(::cv::CALIB_ZERO_DISPARITY) ) );
    
    }

    { //::cv::stereoRectifyUncalibrated
    
        typedef bool ( *stereoRectifyUncalibrated_function_type )( ::cv::Mat const &,::cv::Mat const &,::cv::Mat const &,::cv::Size,::cv::Mat &,::cv::Mat &,double );
        
        bp::def( 
            "stereoRectifyUncalibrated"
            , stereoRectifyUncalibrated_function_type( &::cv::stereoRectifyUncalibrated )
            , ( bp::arg("points1"), bp::arg("points2"), bp::arg("F"), bp::arg("imgSize"), bp::arg("H1"), bp::arg("H2"), bp::arg("threshold")=5 ) );
    
    }

}