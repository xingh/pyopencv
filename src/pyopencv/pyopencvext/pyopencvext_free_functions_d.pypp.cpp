// This file has been generated by Py++.

#include "boost/python.hpp"
#include "opencv_headers.hpp"
#include "pyopencvext_free_functions_d.pypp.hpp"

namespace bp = boost::python;

void register_free_functions_d(){

    { //::cvDetectedBlob
    
        typedef ::CvDetectedBlob ( *detectedBlob_function_type )( float,float,float,float,int,float );
        
        bp::def( 
            "detectedBlob"
            , detectedBlob_function_type( &::cvDetectedBlob )
            , ( bp::arg("x"), bp::arg("y"), bp::arg("w"), bp::arg("h"), bp::arg("ID")=(int)(0), bp::arg("response")=0.0f )
            , "\nWrapped function:"
    "\n    cvDetectedBlob" );
    
    }

    { //::cv::dct
    
        typedef void ( *dct_function_type )( ::cv::Mat const &,::cv::Mat &,int );
        
        bp::def( 
            "dct"
            , dct_function_type( &::cv::dct )
            , ( bp::arg("src"), bp::arg("dst"), bp::arg("flags")=(int)(0) )
            , "\nPerforms a forward or inverse discrete cosine transform of 1D or 2D "
    "\narray."
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/cpp/operations_on_arrays.html#cv-dct" );
    
    }

    { //::cv::decomposeProjectionMatrix
    
        typedef void ( *decomposeProjectionMatrix_function_type )( ::cv::Mat const &,::cv::Mat &,::cv::Mat &,::cv::Mat &,::cv::Mat &,::cv::Mat &,::cv::Mat &,::cv::Vec3d & );
        
        bp::def( 
            "decomposeProjectionMatrix"
            , decomposeProjectionMatrix_function_type( &::cv::decomposeProjectionMatrix )
            , ( bp::arg("projMatrix"), bp::arg("cameraMatrix"), bp::arg("rotMatrix"), bp::arg("transVect"), bp::arg("rotMatrixX"), bp::arg("rotMatrixY"), bp::arg("rotMatrixZ"), bp::arg("eulerAngles") ) );
    
    }

    { //::cv::decomposeProjectionMatrix
    
        typedef void ( *decomposeProjectionMatrix_function_type )( ::cv::Mat const &,::cv::Mat &,::cv::Mat &,::cv::Mat & );
        
        bp::def( 
            "decomposeProjectionMatrix"
            , decomposeProjectionMatrix_function_type( &::cv::decomposeProjectionMatrix )
            , ( bp::arg("projMatrix"), bp::arg("cameraMatrix"), bp::arg("rotMatrix"), bp::arg("transVect") ) );
    
    }

    { //::cv::determinant
    
        typedef double ( *determinant_function_type )( ::cv::Mat const & );
        
        bp::def( 
            "determinant"
            , determinant_function_type( &::cv::determinant )
            , ( bp::arg("m") )
            , "\nReturns determinant of a square floating-point matrix."
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/cpp/operations_on_arrays.html#cv-determinant" );
    
    }

    { //::cv::dft
    
        typedef void ( *dft_function_type )( ::cv::Mat const &,::cv::Mat &,int,int );
        
        bp::def( 
            "dft"
            , dft_function_type( &::cv::dft )
            , ( bp::arg("src"), bp::arg("dst"), bp::arg("flags")=(int)(0), bp::arg("nonzeroRows")=(int)(0) )
            , "\nPerforms a forward or inverse Discrete Fourier transform of 1D or 2D "
    "\nfloating-point array."
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/cpp/operations_on_arrays.html#cv-dft" );
    
    }

    { //::cv::dilate
    
        typedef void ( *dilate_function_type )( ::cv::Mat const &,::cv::Mat &,::cv::Mat const &,::cv::Point,int,int,::cv::Scalar const & );
        
        bp::def( 
            "dilate"
            , dilate_function_type( &::cv::dilate )
            , ( bp::arg("src"), bp::arg("dst"), bp::arg("kernel"), bp::arg("anchor")=cv::Point_<int>(-0x000000001, -0x000000001), bp::arg("iterations")=(int)(1), bp::arg("borderType")=int(::cv::BORDER_CONSTANT), bp::arg("borderValue")=cv::morphologyDefaultBorderValue( ) ) );
    
    }

    { //::cv::distanceTransform
    
        typedef void ( *distanceTransform_function_type )( ::cv::Mat const &,::cv::Mat &,int,int );
        
        bp::def( 
            "distanceTransform"
            , distanceTransform_function_type( &::cv::distanceTransform )
            , ( bp::arg("src"), bp::arg("dst"), bp::arg("distanceType"), bp::arg("maskSize") ) );
    
    }

    { //::cv::distanceTransform
    
        typedef void ( *distanceTransform_function_type )( ::cv::Mat const &,::cv::Mat &,::cv::Mat &,int,int );
        
        bp::def( 
            "distanceTransform"
            , distanceTransform_function_type( &::cv::distanceTransform )
            , ( bp::arg("src"), bp::arg("dst"), bp::arg("labels"), bp::arg("distanceType"), bp::arg("maskSize") ) );
    
    }

    { //::cv::divide
    
        typedef void ( *divide_function_type )( double,::cv::MatND const &,::cv::MatND & );
        
        bp::def( 
            "divide"
            , divide_function_type( &::cv::divide )
            , ( bp::arg("scale"), bp::arg("b"), bp::arg("c") )
            , "\nPerforms per-element division of two arrays or a scalar by an array."
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/cpp/operations_on_arrays.html#cv-divide" );
    
    }

    { //::cv::divide
    
        typedef void ( *divide_function_type )( ::cv::MatND const &,::cv::MatND const &,::cv::MatND &,double );
        
        bp::def( 
            "divide"
            , divide_function_type( &::cv::divide )
            , ( bp::arg("a"), bp::arg("b"), bp::arg("c"), bp::arg("scale")=1 )
            , "\nPerforms per-element division of two arrays or a scalar by an array."
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/cpp/operations_on_arrays.html#cv-divide" );
    
    }

    { //::cv::divide
    
        typedef void ( *divide_function_type )( double,::cv::Mat const &,::cv::Mat & );
        
        bp::def( 
            "divide"
            , divide_function_type( &::cv::divide )
            , ( bp::arg("scale"), bp::arg("b"), bp::arg("c") )
            , "\nPerforms per-element division of two arrays or a scalar by an array."
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/cpp/operations_on_arrays.html#cv-divide" );
    
    }

    { //::cv::divide
    
        typedef void ( *divide_function_type )( ::cv::Mat const &,::cv::Mat const &,::cv::Mat &,double );
        
        bp::def( 
            "divide"
            , divide_function_type( &::cv::divide )
            , ( bp::arg("a"), bp::arg("b"), bp::arg("c"), bp::arg("scale")=1 )
            , "\nPerforms per-element division of two arrays or a scalar by an array."
    "\nReference:"
    "\n    http://opencv.willowgarage.com/documentation/cpp/operations_on_arrays.html#cv-divide" );
    
    }

    { //::cv::drawChessboardCorners
    
        typedef void ( *drawChessboardCorners_function_type )( ::cv::Mat &,::cv::Size,::cv::Mat const &,bool );
        
        bp::def( 
            "drawChessboardCorners"
            , drawChessboardCorners_function_type( &::cv::drawChessboardCorners )
            , ( bp::arg("image"), bp::arg("patternSize"), bp::arg("corners"), bp::arg("patternWasFound") ) );
    
    }

    { //::cv::drawContours
    
        typedef void ( *drawContours_function_type )( ::cv::Mat &,::std::vector< std::vector< cv::Point_<int> > > const &,int,::cv::Scalar const &,int,int,::std::vector< cv::Vec<int, 4> > const &,int,::cv::Point );
        
        bp::def( 
            "drawContours"
            , drawContours_function_type( &::cv::drawContours )
            , ( bp::arg("image"), bp::arg("contours"), bp::arg("contourIdx"), bp::arg("color"), bp::arg("thickness")=(int)(1), bp::arg("lineType")=(int)(8), bp::arg("hierarchy")=std::vector<cv::Vec4i>(), bp::arg("maxLevel")=(int)(2147483647), bp::arg("offset")=cv::Point_<int>() ) );
    
    }

}
