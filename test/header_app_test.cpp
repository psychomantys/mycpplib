#define BOOST_TEST_MODULE	Tests of header app.hpp
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include <webcpp/app.hpp>
#include <webcpp/http/entity_config.hpp>

BOOST_AUTO_TEST_CASE( ctor_and_dtor )
{
	webcpp::http::Entity_config	envs;
	webcpp::app test( "/tmp/opa.so", envs );
}

BOOST_AUTO_TEST_CASE( app_not_is_good )
{
	webcpp::http::Entity_config	envs;
	webcpp::app test( "/tmp/opa.so", envs );
	BOOST_CHECK( ! test.is_good() );
}

BOOST_AUTO_TEST_CASE( app_is_equal )
{
	webcpp::http::Entity_config	envs;
	webcpp::app test_1( "/tmp/opa.so", envs );
	webcpp::app test_2( "/tmp/opa.so", envs );

	BOOST_REQUIRE_EQUAL( test_1.is_good() , test_2.is_good() );

	BOOST_CHECK( test_1==test_2 );
}

BOOST_AUTO_TEST_CASE( app_is_not_equal )
{
	webcpp::http::Entity_config	envs;
	webcpp::app test_1( "/tmp/opa_1.so", envs );
	webcpp::app test_2( "/tmp/opa_2.so", envs );

	BOOST_CHECK( test_1!=test_2 );
}

//	const_string cs1( "test_string" );
//	BOOST_CHECK_EQUAL( cs1[(size_t)0], 't' );
//	BOOST_CHECK_EQUAL( cs1[(size_t)4], '_' );
//	BOOST_CHECK_EQUAL( cs1[cs1.length()-1], 'g' );
//	BOOST_CHECK_EQUAL( cs1[(size_t)0], cs1.at( 0 ) );
//	BOOST_CHECK_EQUAL( cs1[(size_t)2], cs1.at( 5 ) );
//	BOOST_CHECK_EQUAL( cs1.at( cs1.length() - 1 ), 'g' );

//	BOOST_CHECK_THROW( cs1.at( cs1.length() ), std::out_of_range );

