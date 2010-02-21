// This file has been generated by Py++.

#include "boost/python.hpp"
#include "__call_policies.pypp.hpp"
#include "opencv_extra.hpp"
#include "__ctypes_integration.pypp.hpp"
#include "opencv_headers.hpp"
#include "opencv_extra.hpp"
#include "IntegralHistogram.pypp.hpp"

namespace bp = boost::python;

static boost::python::object calcHist_7e977de6e27427b53a27b192cb2b370c( ::sdopencv::IntegralHistogram & inst, ::cv::Rect rect ){
    bp::sequence out_hist2;
    std::vector<int, std::allocator<int> > out_hist3;
    inst.calcHist(rect, out_hist3);
    out_hist2 = convert_vector_to_seq(out_hist3);
    return bp::object( out_hist2 );
}

static boost::shared_ptr<sdopencv::IntegralHistogram> IntegralHistogram__init1__(int histSize, bp::sequence const &ranges, bool uniform)
{
    std::vector<float> ranges2; convert_seq_to_vector(ranges, ranges2);
    return boost::shared_ptr<sdopencv::IntegralHistogram>(new sdopencv::IntegralHistogram(histSize, ranges2, uniform));
}

void register_IntegralHistogram_class(){

    bp::class_< sdopencv::IntegralHistogram >( "IntegralHistogram", bp::no_init )    
        .add_property( "this", pyplus_conv::make_addressof_inst_getter< sdopencv::IntegralHistogram >() )    
        .def( 
            "calcHist"
            , (boost::python::object (*)( ::sdopencv::IntegralHistogram &,::cv::Rect ))( &calcHist_7e977de6e27427b53a27b192cb2b370c )
            , ( bp::arg("inst"), bp::arg("rect") ) )    
        .def( 
            "get_index"
            , (int ( ::sdopencv::IntegralHistogram::* )( float ) )( &::sdopencv::IntegralHistogram::get_index )
            , ( bp::arg("value") ) )    
        .def( 
            "__call__"
            , (void ( ::sdopencv::IntegralHistogram::* )( ::cv::Mat const & ) )( &::sdopencv::IntegralHistogram::operator() )
            , ( bp::arg("image") ) )    
        .def("__init__", bp::make_constructor(&IntegralHistogram__init1__, bp::default_call_policies(), ( bp::arg("histSize"), bp::arg("ranges"), bp::arg("uniform")=bp::object(true) )));

}