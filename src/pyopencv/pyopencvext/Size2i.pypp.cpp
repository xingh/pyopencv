// This file has been generated by Py++.

#include "boost/python.hpp"
#include "__ctypes_integration.pypp.hpp"
#include "opencv_headers.hpp"
#include "ndarray.hpp"
#include "opencv_converters.hpp"
#include "Size2i.pypp.hpp"

namespace bp = boost::python;

void register_Size2i_class(){

    { //::cv::Size_< int >
        typedef bp::class_< cv::Size_< int > > Size2i_exposer_t;
        Size2i_exposer_t Size2i_exposer = Size2i_exposer_t( "Size2i", bp::init< >() );
        bp::scope Size2i_scope( Size2i_exposer );
        Size2i_exposer.add_property( "this", pyplus_conv::make_addressof_inst_getter< cv::Size_< int > >() );
        Size2i_exposer.def( bp::init< int, int >(( bp::arg("_width"), bp::arg("_height") )) );
        Size2i_exposer.def( bp::init< cv::Size_< int > const & >(( bp::arg("sz") )) );
        Size2i_exposer.def( bp::init< cv::Point_< int > const & >(( bp::arg("pt") )) );
        bp::implicitly_convertible< cv::Point_< int > const &, cv::Size_< int > >();
        { //::cv::Size_< int >::area
        
            typedef cv::Size_< int > exported_class_t;
            typedef int ( exported_class_t::*area_function_type )(  ) const;
            
            Size2i_exposer.def( 
                "area"
                , area_function_type( &::cv::Size_< int >::area ) );
        
        }
        { //::cv::Size_< int >::operator=
        
            typedef cv::Size_< int > exported_class_t;
            typedef ::cv::Size_< int > & ( exported_class_t::*assign_function_type )( ::cv::Size_< int > const & ) ;
            
            Size2i_exposer.def( 
                "assign"
                , assign_function_type( &::cv::Size_< int >::operator= )
                , ( bp::arg("sz") )
                , bp::return_self< >()
                , "\nWrapped function:"
    "\n    operator=" );
        
        }
        Size2i_exposer.def_readwrite( "height", &cv::Size_< int >::height );
        Size2i_exposer.def_readwrite( "width", &cv::Size_< int >::width );
        Size2i_exposer.def("from_ndarray", &sdcpp::from_ndarray< cv::Size_<int> >, (bp::arg("inst_ndarray")) );
        Size2i_exposer.staticmethod("from_ndarray");
        Size2i_exposer.add_property("ndarray", &sdcpp::as_ndarray< cv::Size_<int> >);
        Size2i_exposer.def("__iadd__", &__iadd__<cv::Size2i, cv::Size2i>, bp::return_self<>() );
        Size2i_exposer.def("__isub__", &__isub__<cv::Size2i, cv::Size2i>, bp::return_self<>() );
        Size2i_exposer.def("__add__", &__add__<cv::Size2i, cv::Size2i> );
        Size2i_exposer.def("__sub__", &__sub__<cv::Size2i, cv::Size2i> );
        Size2i_exposer.def("__eq__", &__eq__<cv::Size2i, cv::Size2i> );
        Size2i_exposer.def("__ne__", &__ne__<cv::Size2i, cv::Size2i> );
        Size2i_exposer.def("__mul__", &__mul__<cv::Size2i, int> );
    }

}
