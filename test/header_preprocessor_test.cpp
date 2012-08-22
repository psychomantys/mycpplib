#define BOOST_TEST_MODULE	Tests interface of header mycpplib/preprocessor.hpp
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include <mycpplib/preprocessor.hpp>


class Foo{
	declare_gs(char,data);
};

BOOST_AUTO_TEST_CASE( get_and_set )
{
	Foo x;
	x.data('S');
	BOOST_CHECK( x.data() == 'S' );
}

