// This file has been generated by Py++.

#include "boost/python.hpp"
#include "__ctypes_integration.pypp.hpp"
#include "opencv_headers.hpp"
#include "ndarray.hpp"
#include "Vec3b.pypp.hpp"

namespace bp = boost::python;

void register_Vec3b_class(){

    { //::cv::Vec< unsigned char, 3 >
        typedef bp::class_< cv::Vec< unsigned char, 3 > > Vec3b_exposer_t;
        Vec3b_exposer_t Vec3b_exposer = Vec3b_exposer_t( "Vec3b", bp::init< >() );
        bp::scope Vec3b_scope( Vec3b_exposer );
        Vec3b_exposer.add_property( "this", pyplus_conv::make_addressof_inst_getter< cv::Vec< unsigned char, 3 > >() );
        bp::scope().attr("depth") = (int)cv::Vec<unsigned char, 3>::depth;
        bp::scope().attr("channels") = (int)cv::Vec<unsigned char, 3>::channels;
        bp::scope().attr("type") = (int)cv::Vec<unsigned char, 3>::type;
        Vec3b_exposer.def( bp::init< unsigned char >(( bp::arg("v0") )) );
        bp::implicitly_convertible< unsigned char, cv::Vec< unsigned char, 3 > >();
        Vec3b_exposer.def( bp::init< unsigned char, unsigned char >(( bp::arg("v0"), bp::arg("v1") )) );
        Vec3b_exposer.def( bp::init< unsigned char, unsigned char, unsigned char >(( bp::arg("v0"), bp::arg("v1"), bp::arg("v2") )) );
        Vec3b_exposer.def( bp::init< unsigned char, unsigned char, unsigned char, unsigned char >(( bp::arg("v0"), bp::arg("v1"), bp::arg("v2"), bp::arg("v3") )) );
        Vec3b_exposer.def( bp::init< unsigned char, unsigned char, unsigned char, unsigned char, unsigned char >(( bp::arg("v0"), bp::arg("v1"), bp::arg("v2"), bp::arg("v3"), bp::arg("v4") )) );
        Vec3b_exposer.def( bp::init< unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char >(( bp::arg("v0"), bp::arg("v1"), bp::arg("v2"), bp::arg("v3"), bp::arg("v4"), bp::arg("v5") )) );
        Vec3b_exposer.def( bp::init< unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char >(( bp::arg("v0"), bp::arg("v1"), bp::arg("v2"), bp::arg("v3"), bp::arg("v4"), bp::arg("v5"), bp::arg("v6") )) );
        Vec3b_exposer.def( bp::init< unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char >(( bp::arg("v0"), bp::arg("v1"), bp::arg("v2"), bp::arg("v3"), bp::arg("v4"), bp::arg("v5"), bp::arg("v6"), bp::arg("v7") )) );
        Vec3b_exposer.def( bp::init< unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char >(( bp::arg("v0"), bp::arg("v1"), bp::arg("v2"), bp::arg("v3"), bp::arg("v4"), bp::arg("v5"), bp::arg("v6"), bp::arg("v7"), bp::arg("v8") )) );
        Vec3b_exposer.def( bp::init< unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char >(( bp::arg("v0"), bp::arg("v1"), bp::arg("v2"), bp::arg("v3"), bp::arg("v4"), bp::arg("v5"), bp::arg("v6"), bp::arg("v7"), bp::arg("v8"), bp::arg("v9") )) );
        Vec3b_exposer.def( bp::init< cv::Vec< unsigned char, 3 > const & >(( bp::arg("v") )) );
        { //::cv::Vec< unsigned char, 3 >::all
        
            typedef cv::Vec< unsigned char, 3 > exported_class_t;
            typedef ::cv::Vec< unsigned char, 3 > ( *all_function_type )( unsigned char );
            
            Vec3b_exposer.def( 
                "all"
                , all_function_type( &::cv::Vec< unsigned char, 3 >::all )
                , ( bp::arg("alpha") ) );
        
        }
        { //::cv::Vec< unsigned char, 3 >::cross
        
            typedef cv::Vec< unsigned char, 3 > exported_class_t;
            typedef ::cv::Vec< unsigned char, 3 > ( exported_class_t::*cross_function_type )( ::cv::Vec< unsigned char, 3 > const & ) const;
            
            Vec3b_exposer.def( 
                "cross"
                , cross_function_type( &::cv::Vec< unsigned char, 3 >::cross )
                , ( bp::arg("v") ) );
        
        }
        { //::cv::Vec< unsigned char, 3 >::ddot
        
            typedef cv::Vec< unsigned char, 3 > exported_class_t;
            typedef double ( exported_class_t::*ddot_function_type )( ::cv::Vec< unsigned char, 3 > const & ) const;
            
            Vec3b_exposer.def( 
                "ddot"
                , ddot_function_type( &::cv::Vec< unsigned char, 3 >::ddot )
                , ( bp::arg("v") ) );
        
        }
        { //::cv::Vec< unsigned char, 3 >::dot
        
            typedef cv::Vec< unsigned char, 3 > exported_class_t;
            typedef unsigned char ( exported_class_t::*dot_function_type )( ::cv::Vec< unsigned char, 3 > const & ) const;
            
            Vec3b_exposer.def( 
                "dot"
                , dot_function_type( &::cv::Vec< unsigned char, 3 >::dot )
                , ( bp::arg("v") ) );
        
        }
        { //::cv::Vec< unsigned char, 3 >::operator[]
        
            typedef cv::Vec< unsigned char, 3 > exported_class_t;
            typedef unsigned char ( exported_class_t::*__getitem___function_type )( int ) const;
            
            Vec3b_exposer.def( 
                "__getitem__"
                , __getitem___function_type( &::cv::Vec< unsigned char, 3 >::operator[] )
                , ( bp::arg("i") ) );
        
        }
        { //::cv::Vec< unsigned char, 3 >::operator[]
        
            typedef cv::Vec< unsigned char, 3 > exported_class_t;
            typedef unsigned char & ( exported_class_t::*__getitem___function_type )( int ) ;
            
            Vec3b_exposer.def( 
                "__getitem__"
                , __getitem___function_type( &::cv::Vec< unsigned char, 3 >::operator[] )
                , ( bp::arg("i") )
                , bp::return_value_policy< bp::copy_non_const_reference >() );
        
        }
        Vec3b_exposer.staticmethod( "all" );
        Vec3b_exposer.def("from_ndarray", &bp::from_ndarray< cv::Vec3b >, (bp::arg("arr")) );
        Vec3b_exposer.staticmethod("from_ndarray");
        Vec3b_exposer.add_property("ndarray", &bp::as_ndarray< cv::Vec3b >);
    }

}
