#include <boost/python/detail/prefix.hpp>
#include <boost/python/extract.hpp>
#include <boost/python/default_call_policies.hpp>
#include <boost/python/object.hpp>

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

#include "opencv_extra.hpp"
#include "ndarray.hpp"


// ================================================================================================

void CV_CDECL sdTrackbarCallback2(int pos, void* userdata)
{
    bp::object items(bp::handle<>(bp::borrowed((PyObject *)userdata)));
    if(bp::object(items[0]).ptr() != Py_None) // invoke if not None
        (items[0])(pos, bp::object(items[1])); // need a copy of items[1] to make it safe with threading
}


void CV_CDECL sdMouseCallback(int event, int x, int y, int flags, void* param)
{
    bp::object items(bp::handle<>(bp::borrowed((PyObject *)param)));
    if(bp::object(items[0]).ptr() != Py_None) // invoke if not None
        (items[0])(event, x, y, flags, bp::object(items[1])); // need a copy of items[1] to make it safe with threading
}

float CV_CDECL sdDistanceFunction( const float* a, const float*b, void* user_param )
{
    bp::object items(bp::handle<>(bp::borrowed((PyObject *)user_param)));
    // pass 'a' and 'b' by address instead of by pointer
    return bp::extract < float >((items[0])((int)a, (int)b, bp::object(items[1]))); // need a copy of items[1] to make it safe with threading
}

// ================================================================================================

template void convert_Mat( const cv::Mat &in_arr, char *&out_arr );
template void convert_Mat( const cv::Mat &in_arr, unsigned char *&out_arr );
template void convert_Mat( const cv::Mat &in_arr, short *&out_arr );
template void convert_Mat( const cv::Mat &in_arr, unsigned short *&out_arr );
template void convert_Mat( const cv::Mat &in_arr, long *&out_arr );
template void convert_Mat( const cv::Mat &in_arr, unsigned long *&out_arr );
template void convert_Mat( const cv::Mat &in_arr, int *&out_arr );
template void convert_Mat( const cv::Mat &in_arr, unsigned int *&out_arr );
template void convert_Mat( const cv::Mat &in_arr, float *&out_arr );
template void convert_Mat( const cv::Mat &in_arr, double *&out_arr );

// ================================================================================================

// convert_seq1d_to_Mat: convert a Python 1D sequence of objects of type cv::Point2? into a cv::Mat
template<typename Point2Type, typename ElementType, int MatType>
void convert_seq1d_of_Point2_to_Mat( const bp::object &in_arr, cv::Mat &out_arr )
{
    int len = bp::len(in_arr);
    out_arr.create(1, len, MatType);
    ElementType *data = (ElementType *)out_arr.data;
    for(int i = 0; i < len; ++i, data += 2)
    {
        const Point2Type &x = bp::extract<const Point2Type &>(in_arr[i]);
        data[0] = x.x;
        data[1] = x.y;
    }
}

// convert_seq1d_to_Mat: convert a Python 1D sequence of objects of type cv::Point3? into a cv::Mat
template<typename Point3Type, typename ElementType, int MatType>
void convert_seq1d_of_Point3_to_Mat( const bp::object &in_arr, cv::Mat &out_arr )
{
    int len = bp::len(in_arr);
    out_arr.create(1, len, MatType);
    ElementType *data = (ElementType *)out_arr.data;
    for(int i = 0; i < len; ++i, data += 3)
    {
        const Point3Type &x = bp::extract<const Point3Type &>(in_arr[i]);
        data[0] = x.x;
        data[1] = x.y;
        data[2] = x.z;
    }
}


// convert a Python sequence into a cv::Mat
template<> void convert_Mat<bp::object>( const bp::object &in_arr, cv::Mat &out_arr )
{
    char s[300];
    if(PyObject_HasAttrString(in_arr.ptr(), "__len__")) // Python 1D sequence
    {
        if(!bp::len(in_arr)) { out_arr = cv::Mat(); return; }
        if(bp::extract<const cv::Point2i &>(in_arr[0]).check())
            { convert_seq1d_of_Point2_to_Mat<cv::Point2i, int, CV_32SC2>(in_arr, out_arr); return; }
        if(bp::extract<const cv::Point2f &>(in_arr[0]).check())
            { convert_seq1d_of_Point2_to_Mat<cv::Point2f, float, CV_32FC2>(in_arr, out_arr); return; }
        if(bp::extract<const cv::Point2d &>(in_arr[0]).check())
            { convert_seq1d_of_Point2_to_Mat<cv::Point2d, double, CV_64FC2>(in_arr, out_arr); return; }
        if(bp::extract<const cv::Point3i &>(in_arr[0]).check())
            { convert_seq1d_of_Point3_to_Mat<cv::Point3i, int, CV_32SC3>(in_arr, out_arr); return; }
        if(bp::extract<const cv::Point3f &>(in_arr[0]).check())
            { convert_seq1d_of_Point3_to_Mat<cv::Point3f, float, CV_32FC3>(in_arr, out_arr); return; }
        if(bp::extract<const cv::Point3d &>(in_arr[0]).check())
            { convert_seq1d_of_Point3_to_Mat<cv::Point3d, double, CV_64FC3>(in_arr, out_arr); return; }
        if(PyObject_HasAttrString(bp::object(in_arr[0]).ptr(), "__len__")) // Python 2D sequence
        {
            sprintf( s, "Converting a Python 2D sequence into a cv::Mat in function convert_Mat<bp::object>() is not yet implemented." );
            PyErr_SetString(PyExc_NotImplementedError, s);
            throw bp::error_already_set(); 
        }

        sprintf( s, "Unknown element type while converting a Python sequence into a cv::Mat in function convert_Mat<bp::object>()." );
        PyErr_SetString(PyExc_NotImplementedError, s);
        throw bp::error_already_set(); 
    }

    sprintf( s, "Unknown object type while converting a Python object into a cv::Mat in function convert_Mat<bp::object>()." );
    PyErr_SetString(PyExc_NotImplementedError, s);
    throw bp::error_already_set(); 
}


// ================================================================================================

// workaround for getting a CvMat pointer
CvMat * get_CvMat_ptr(cv::Mat &mat)
{
    static int cnt = 0;
    static CvMat arr[1024];
    CvMat *result = &(arr[cnt] = mat);
    cnt = (cnt+1) & 1023;
    return result;
}


// workaround for getting an IplImage pointer
IplImage * get_IplImage_ptr(cv::Mat &mat)
{
    static int cnt = 0;
    static IplImage arr[1024];
    IplImage *result = &(arr[cnt] = mat);
    cnt = (cnt+1) & 1023;
    return result;
}


// ================================================================================================

// convert_vector_to_seq

#define CONVERT_VECTOR_TO_NDARRAY(VectType) \
CONVERT_VECTOR_TO_SEQ(VectType) \
{ \
    bp::ndarray out_arr; \
    bp::vector_to_ndarray(in_arr, out_arr); \
    return bp::sequence(out_arr); \
}

// basic
CONVERT_VECTOR_TO_NDARRAY(char);
CONVERT_VECTOR_TO_NDARRAY(unsigned char);
CONVERT_VECTOR_TO_NDARRAY(short);
CONVERT_VECTOR_TO_NDARRAY(unsigned short);
CONVERT_VECTOR_TO_NDARRAY(long);
CONVERT_VECTOR_TO_NDARRAY(unsigned long);
CONVERT_VECTOR_TO_NDARRAY(int);
CONVERT_VECTOR_TO_NDARRAY(unsigned int);
CONVERT_VECTOR_TO_NDARRAY(float);
CONVERT_VECTOR_TO_NDARRAY(double);

// Vec-like
CONVERT_VECTOR_TO_NDARRAY(cv::Vec2b);
CONVERT_VECTOR_TO_NDARRAY(cv::Vec3b);
CONVERT_VECTOR_TO_NDARRAY(cv::Vec4b);
CONVERT_VECTOR_TO_NDARRAY(cv::Vec2s);
CONVERT_VECTOR_TO_NDARRAY(cv::Vec3s);
CONVERT_VECTOR_TO_NDARRAY(cv::Vec4s);
CONVERT_VECTOR_TO_NDARRAY(cv::Vec2w);
CONVERT_VECTOR_TO_NDARRAY(cv::Vec3w);
CONVERT_VECTOR_TO_NDARRAY(cv::Vec4w);
CONVERT_VECTOR_TO_NDARRAY(cv::Vec2i);
CONVERT_VECTOR_TO_NDARRAY(cv::Vec3i);
CONVERT_VECTOR_TO_NDARRAY(cv::Vec4i);
CONVERT_VECTOR_TO_NDARRAY(cv::Vec2f);
CONVERT_VECTOR_TO_NDARRAY(cv::Vec3f);
CONVERT_VECTOR_TO_NDARRAY(cv::Vec4f);
CONVERT_VECTOR_TO_NDARRAY(cv::Vec6f);
CONVERT_VECTOR_TO_NDARRAY(cv::Vec2d);
CONVERT_VECTOR_TO_NDARRAY(cv::Vec3d);
CONVERT_VECTOR_TO_NDARRAY(cv::Vec4d);
CONVERT_VECTOR_TO_NDARRAY(cv::Vec6d);

// Point-like
CONVERT_VECTOR_TO_NDARRAY(cv::Point2i);
CONVERT_VECTOR_TO_NDARRAY(cv::Point2f);
CONVERT_VECTOR_TO_NDARRAY(cv::Point2d);
CONVERT_VECTOR_TO_NDARRAY(cv::Point3i);
CONVERT_VECTOR_TO_NDARRAY(cv::Point3f);
CONVERT_VECTOR_TO_NDARRAY(cv::Point3d);

// Rect-like
CONVERT_VECTOR_TO_NDARRAY(cv::Rect);
CONVERT_VECTOR_TO_NDARRAY(cv::Rectd);
CONVERT_VECTOR_TO_NDARRAY(cv::Rectf);
CONVERT_VECTOR_TO_NDARRAY(cv::RotatedRect);

// Scalar
CONVERT_VECTOR_TO_NDARRAY(cv::Scalar);

// Range
CONVERT_VECTOR_TO_NDARRAY(cv::Range);



// ================================================================================================

bp::sequence mixChannels(const bp::sequence &src, bp::sequence &dst, const bp::ndarray &fromTo)
{
    char s[200];
    
    const int *shape = fromTo.shape();
    
    if(fromTo.ndim() != 2 || fromTo.dtype() != bp::dtypeof<long>() || shape[1] != 2 || !fromTo.iscontiguous())
    {
        sprintf(s, "Wrong type! 'fromTo' is not a N-row 2-column int32 C-contiguous ndarray. ");
        PyErr_SetString(PyExc_TypeError, s);
        throw bp::error_already_set();
    }
    
    bp::extract<const cv::Mat &> mat(src[0]);
    if(mat.check())
    {
        std::vector<cv::Mat> src2, dst2;
        convert_seq_to_vector(src, src2);
        convert_seq_to_vector(dst, dst2);
        cv::mixChannels(&src2[0], bp::len(src), &dst2[0], bp::len(dst), (const int *)fromTo.data(), shape[0]);
        return convert_vector_to_seq(dst2);
    }

    bp::extract<const cv::MatND &> matnd(src[0]);
    if(matnd.check())
    {
        std::vector<cv::MatND> src3, dst3;
        convert_seq_to_vector(src, src3);
        convert_seq_to_vector(dst, dst3);
        cv::mixChannels(&src3[0], bp::len(src), &dst3[0], bp::len(dst), (const int *)fromTo.data(), shape[0]);
        return convert_vector_to_seq(dst3);
    }

    sprintf(s, "Cannot determine whether the 1st item of 'src' is Mat or MatND.");
    PyErr_SetString(PyExc_TypeError, s);
    throw bp::error_already_set();
    
    return bp::sequence();
}

bp::tuple minMaxLoc(const bp::object& a, const bp::object& mask)
{
    double minVal, maxVal;
    int minIdx[CV_MAX_DIM], maxIdx[CV_MAX_DIM];
    int i, n;
    cv::Point minLoc, maxLoc;
    
    bp::tuple result;
    
    bp::extract<const cv::Mat &> mat(a);
    bp::extract<const cv::MatND &> matnd(a);
    bp::extract<const cv::SparseMat &> smat(a);
    if(mat.check())
    {    
        cv::minMaxLoc(mat(), &minVal, &maxVal, &minLoc, &maxLoc, bp::extract<const cv::Mat &>(mask));
        result = bp::make_tuple(bp::object(minVal), bp::object(maxVal), bp::object(minLoc), bp::object(maxLoc));
    }
    else if(matnd.check())
    {
        const cv::MatND &m = matnd();
        cv::minMaxLoc(m, &minVal, &maxVal, minIdx, maxIdx, bp::extract<const cv::MatND &>(mask));
        n = m.dims;
        bp::list l1, l2;
        for(i = 0; i < n; ++i)
        {
            l1.append(bp::object(minIdx[i]));
            l2.append(bp::object(maxIdx[i]));
        }
        result = bp::make_tuple(bp::object(minVal), bp::object(maxVal), bp::tuple(l1), bp::tuple(l2));
    }
    else if(smat.check())
    {
        const cv::SparseMat &m2 = smat();
        cv::minMaxLoc(m2, &minVal, &maxVal, minIdx, maxIdx);
        n = m2.dims();
        bp::list l1, l2;
        for(i = 0; i < n; ++i)
        {
            l1.append(bp::object(minIdx[i]));
            l2.append(bp::object(maxIdx[i]));
        }
        result = bp::make_tuple(bp::object(minVal), bp::object(maxVal), bp::tuple(l1), bp::tuple(l2));
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "Cannot determine whether 'a' is Mat, MatND, or SparseMat.");
        throw bp::error_already_set();
    }
    return result;
}


// ================================================================================================
