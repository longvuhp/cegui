// This file has been generated by Py++.

#include "boost/python.hpp"
#include "python_CEGUI.h"
#include "Rectf.pypp.hpp"

namespace bp = boost::python;

void register_Rectf_class(){

    { //::CEGUI::Rect< float >
        typedef bp::class_< CEGUI::Rect< float > > Rectf_exposer_t;
        Rectf_exposer_t Rectf_exposer = Rectf_exposer_t( "Rectf", bp::init< >() );
        bp::scope Rectf_scope( Rectf_exposer );
        Rectf_exposer.def( bp::init< float const &, float const &, float const &, float const & >(( bp::arg("left"), bp::arg("top"), bp::arg("right"), bp::arg("bottom") )) );
        Rectf_exposer.def( bp::init< CEGUI::Vector2< float > const &, CEGUI::Vector2< float > const & >(( bp::arg("min"), bp::arg("max") )) );
        Rectf_exposer.def( bp::init< CEGUI::Vector2< float > const &, CEGUI::Size< float > const & >(( bp::arg("pos"), bp::arg("size") )) );
        Rectf_exposer.def( bp::init< CEGUI::Rect< float > const & >(( bp::arg("r") )) );
        { //::CEGUI::Rect< float >::bottom
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef void ( exported_class_t::*bottom_function_type )( float const & ) ;
            
            Rectf_exposer.def( 
                "bottom"
                , bottom_function_type( &::CEGUI::Rect< float >::bottom )
                , ( bp::arg("v") ) );
        
        }
        { //::CEGUI::Rect< float >::bottom
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef float const & ( exported_class_t::*bottom_function_type )(  ) const;
            
            Rectf_exposer.def( 
                "bottom"
                , bottom_function_type( &::CEGUI::Rect< float >::bottom )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::CEGUI::Rect< float >::constrainSize
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef void ( exported_class_t::*constrainSize_function_type )( ::CEGUI::Size< float > const &,::CEGUI::Size< float > const & ) ;
            
            Rectf_exposer.def( 
                "constrainSize"
                , constrainSize_function_type( &::CEGUI::Rect< float >::constrainSize )
                , ( bp::arg("max_sz"), bp::arg("min_sz") )
                , "*!\n\
               \n\
                  check the size of the Rect object and if it is bigger than  max_sz or smaller than  min_sz,\
                  resize it so it isn't.\n\
            \n\
               @param max_sz\n\
                  Size object that describes the maximum dimensions that this Rect should be limited to.\n\
            \n\
               @param min_sz\n\
                  Size object that describes the minimum dimensions that this Rect should be limited to.\n\
            \n\
               @return\n\
                  'this' Rect object after the constrain operation\n\
               *\n" );
        
        }
        { //::CEGUI::Rect< float >::constrainSizeMax
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef void ( exported_class_t::*constrainSizeMax_function_type )( ::CEGUI::Size< float > const & ) ;
            
            Rectf_exposer.def( 
                "constrainSizeMax"
                , constrainSizeMax_function_type( &::CEGUI::Rect< float >::constrainSizeMax )
                , ( bp::arg("size") )
                , "*!\n\
               \n\
                  check the size of the Rect object and if it is bigger than  sz, resize it so it isn't.\n\
            \n\
               @param sz\n\
                  Size object that describes the maximum dimensions that this Rect should be limited to.\n\
            \n\
               @return\n\
                  'this' Rect object after the constrain operation\n\
               *\n" );
        
        }
        { //::CEGUI::Rect< float >::constrainSizeMin
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef void ( exported_class_t::*constrainSizeMin_function_type )( ::CEGUI::Size< float > const & ) ;
            
            Rectf_exposer.def( 
                "constrainSizeMin"
                , constrainSizeMin_function_type( &::CEGUI::Rect< float >::constrainSizeMin )
                , ( bp::arg("size") )
                , "*!\n\
               \n\
                  check the size of the Rect object and if it is smaller than  sz, resize it so it isn't.\n\
            \n\
               @param sz\n\
                  Size object that describes the minimum dimensions that this Rect should be limited to.\n\
            \n\
               @return\n\
                  'this' Rect object after the constrain operation\n\
               *\n" );
        
        }
        { //::CEGUI::Rect< float >::getHeight
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef float ( exported_class_t::*getHeight_function_type )(  ) const;
            
            Rectf_exposer.def( 
                "getHeight"
                , getHeight_function_type( &::CEGUI::Rect< float >::getHeight )
                , "*!\n\
            \n\
               return height of Rect area\n\
            *\n" );
        
        }
        { //::CEGUI::Rect< float >::getIntersection
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef ::CEGUI::Rect< float > ( exported_class_t::*getIntersection_function_type )( ::CEGUI::Rect< float > const & ) const;
            
            Rectf_exposer.def( 
                "getIntersection"
                , getIntersection_function_type( &::CEGUI::Rect< float >::getIntersection )
                , ( bp::arg("rect") )
                , "*!\n\
               \n\
                  return a Rect that is the intersection of 'this' Rect with the Rect 'rect'\n\
            \n\
               \note\n\
                  It can be assumed that if d_left == d_right, or d_top == d_bottom, or getWidth() == 0, or\
                  getHeight() == 0, then\n\
                  'this' rect was totally outside 'rect'.\n\
               *\n" );
        
        }
        { //::CEGUI::Rect< float >::getPosition
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef ::CEGUI::Vector2< float > const & ( exported_class_t::*getPosition_function_type )(  ) const;
            
            Rectf_exposer.def( 
                "getPosition"
                , getPosition_function_type( &::CEGUI::Rect< float >::getPosition )
                , bp::return_value_policy< bp::copy_const_reference >()
                , "*!\n\
            \n\
               Return top-left position of Rect as a Vector2<T>\n\
            *\n" );
        
        }
        { //::CEGUI::Rect< float >::getSize
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef ::CEGUI::Size< float > ( exported_class_t::*getSize_function_type )(  ) const;
            
            Rectf_exposer.def( 
                "getSize"
                , getSize_function_type( &::CEGUI::Rect< float >::getSize )
                , "*!\n\
            \n\
               return the size of the Rect area\n\
            *\n" );
        
        }
        { //::CEGUI::Rect< float >::getWidth
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef float ( exported_class_t::*getWidth_function_type )(  ) const;
            
            Rectf_exposer.def( 
                "getWidth"
                , getWidth_function_type( &::CEGUI::Rect< float >::getWidth )
                , "*!\n\
            \n\
               return width of Rect area\n\
            *\n" );
        
        }
        { //::CEGUI::Rect< float >::isPointInRect
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef bool ( exported_class_t::*isPointInRect_function_type )( ::CEGUI::Vector2< float > const & ) const;
            
            Rectf_exposer.def( 
                "isPointInRect"
                , isPointInRect_function_type( &::CEGUI::Rect< float >::isPointInRect )
                , ( bp::arg("v") )
                , "*!\n\
               \n\
                  Return true if the given Vector2 falls within this Rect\n\
            \n\
               @param pt\n\
                  Vector2 object describing the position to test.\n\
            \n\
               @return\n\
                  true if position  pt is within this Rect's area, else false\n\
               *\n" );
        
        }
        { //::CEGUI::Rect< float >::left
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef void ( exported_class_t::*left_function_type )( float const & ) ;
            
            Rectf_exposer.def( 
                "left"
                , left_function_type( &::CEGUI::Rect< float >::left )
                , ( bp::arg("v") ) );
        
        }
        { //::CEGUI::Rect< float >::left
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef float const & ( exported_class_t::*left_function_type )(  ) const;
            
            Rectf_exposer.def( 
                "left"
                , left_function_type( &::CEGUI::Rect< float >::left )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::CEGUI::Rect< float >::offset
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef void ( exported_class_t::*offset_function_type )( ::CEGUI::Vector2< float > const & ) ;
            
            Rectf_exposer.def( 
                "offset"
                , offset_function_type( &::CEGUI::Rect< float >::offset )
                , ( bp::arg("v") )
                , "*!\n\
               \n\
                  Applies an offset the Rect object\n\
            \n\
               @param pt\n\
                  Vector2 object containing the offsets to be applied to the Rect.\n\
            \n\
               @return\n\
                  this Rect after the offset is performed\n\
               *\n" );
        
        }
        Rectf_exposer.def( bp::self != bp::self );
        Rectf_exposer.def( bp::self * bp::other< float >() );
        Rectf_exposer.def( bp::self *= bp::other< float >() );
        Rectf_exposer.def( bp::self + bp::self );
        { //::CEGUI::Rect< float >::operator=
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef ::CEGUI::Rect< float > & ( exported_class_t::*assign_function_type )( ::CEGUI::Rect< float > const & ) ;
            
            Rectf_exposer.def( 
                "assign"
                , assign_function_type( &::CEGUI::Rect< float >::operator= )
                , ( bp::arg("rhs") )
                , bp::return_self< >() );
        
        }
        Rectf_exposer.def( bp::self == bp::self );
        { //::CEGUI::Rect< float >::right
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef void ( exported_class_t::*right_function_type )( float const & ) ;
            
            Rectf_exposer.def( 
                "right"
                , right_function_type( &::CEGUI::Rect< float >::right )
                , ( bp::arg("v") ) );
        
        }
        { //::CEGUI::Rect< float >::right
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef float const & ( exported_class_t::*right_function_type )(  ) const;
            
            Rectf_exposer.def( 
                "right"
                , right_function_type( &::CEGUI::Rect< float >::right )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::CEGUI::Rect< float >::setHeight
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef void ( exported_class_t::*setHeight_function_type )( float const & ) ;
            
            Rectf_exposer.def( 
                "setHeight"
                , setHeight_function_type( &::CEGUI::Rect< float >::setHeight )
                , ( bp::arg("h") ) );
        
        }
        { //::CEGUI::Rect< float >::setPosition
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef void ( exported_class_t::*setPosition_function_type )( ::CEGUI::Vector2< float > const & ) ;
            
            Rectf_exposer.def( 
                "setPosition"
                , setPosition_function_type( &::CEGUI::Rect< float >::setPosition )
                , ( bp::arg("min") )
                , "*!\n\
            \n\
               set the position of the Rect (leaves size in tact)\n\
            *\n" );
        
        }
        { //::CEGUI::Rect< float >::setSize
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef void ( exported_class_t::*setSize_function_type )( ::CEGUI::Size< float > const & ) ;
            
            Rectf_exposer.def( 
                "setSize"
                , setSize_function_type( &::CEGUI::Rect< float >::setSize )
                , ( bp::arg("size") ) );
        
        }
        { //::CEGUI::Rect< float >::setWidth
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef void ( exported_class_t::*setWidth_function_type )( float const & ) ;
            
            Rectf_exposer.def( 
                "setWidth"
                , setWidth_function_type( &::CEGUI::Rect< float >::setWidth )
                , ( bp::arg("w") ) );
        
        }
        { //::CEGUI::Rect< float >::top
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef void ( exported_class_t::*top_function_type )( float const & ) ;
            
            Rectf_exposer.def( 
                "top"
                , top_function_type( &::CEGUI::Rect< float >::top )
                , ( bp::arg("v") ) );
        
        }
        { //::CEGUI::Rect< float >::top
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef float const & ( exported_class_t::*top_function_type )(  ) const;
            
            Rectf_exposer.def( 
                "top"
                , top_function_type( &::CEGUI::Rect< float >::top )
                , bp::return_value_policy< bp::copy_const_reference >() );
        
        }
        { //::CEGUI::Rect< float >::zero
        
            typedef CEGUI::Rect< float > exported_class_t;
            typedef ::CEGUI::Rect< float > ( *zero_function_type )(  );
            
            Rectf_exposer.def( 
                "zero"
                , zero_function_type( &::CEGUI::Rect< float >::zero )
                , "!  finger saving alias for zero sized, zero positioned rect\n" );
        
        }
        Rectf_exposer.def_readwrite( "d_max", &CEGUI::Rect< float >::d_max, "*************************************************************************\n\
            Data Fields\n\
        *************************************************************************\n" );
        Rectf_exposer.def_readwrite( "d_min", &CEGUI::Rect< float >::d_min, "*************************************************************************\n\
            Data Fields\n\
        *************************************************************************\n" );
        Rectf_exposer.staticmethod( "zero" );
    }

}
