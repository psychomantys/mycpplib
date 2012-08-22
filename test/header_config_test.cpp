#define BOOST_TEST_MODULE	Tests of header config.hpp
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include <webcpp/config.hpp>

BOOST_AUTO_TEST_CASE( version_macros )
{
	#if	defined(WEBCPP_VERSION)
	BOOST_MESSAGE( "WEBCPP_VERSION defined." );
	#else
	BOOST_FAIL( "WEBCPP_VERSION not defined." );
	#endif

	#if	defined(WEBCPP_VERSION_API)
	BOOST_MESSAGE( "WEBCPP_VERSION_API defined." );
	#else
	BOOST_FAIL( "WEBCPP_VERSION_API not defined." );
	#endif

	#if	defined(WEBCPP_VERSION_SO)
	BOOST_MESSAGE( "WEBCPP_VERSION_SO defined." );
	#else
	BOOST_FAIL( "WEBCPP_VERSION_SO not defined." );
	#endif

	#if	defined(WEBCPP_VERSION_MAJOR)
	BOOST_MESSAGE( "WEBCPP_VERSION_MAJOR defined." );
	#else
	BOOST_FAIL( "WEBCPP_VERSION_MAJOR not defined." );
	#endif

	#if	defined(WEBCPP_VERSION_MINOR)
	BOOST_MESSAGE( "WEBCPP_VERSION_MINOR defined." );
	#else
	BOOST_FAIL( "WEBCPP_VERSION_MINOR not defined." );
	#endif

	#if	defined(WEBCPP_VERSION_MINOR_FIX)
	BOOST_MESSAGE( "WEBCPP_VERSION_MINOR_FIX defined." );
	#else
	BOOST_FAIL( "WEBCPP_VERSION_MINOR_FIX not defined." );
	#endif
}

BOOST_AUTO_TEST_CASE( header_guard_macro )
{
	#if	defined(WEBCPP_CONFIG_HPP)
	BOOST_MESSAGE( "WEBCPP_CONFIG_HPP defined." );
	#else
	BOOST_FAIL( "WEBCPP_CONFIG_HPP not defined." );
	#endif
}

BOOST_AUTO_TEST_CASE( webcpp_information_macros )
{
	#if	defined(WEBCPP_NAME)
	BOOST_MESSAGE( "WEBCPP_NAME defined." );
	#else
	BOOST_FAIL( "WEBCPP_NAME not defined." );
	#endif

	#if	defined(WEBCPP_SHORT_DESCRIPTION)
	BOOST_MESSAGE( "WEBCPP_SHORT_DESCRIPTION defined." );
	#else
	BOOST_FAIL( "WEBCPP_SHORT_DESCRIPTION not defined." );
	#endif

	#if	defined(WEBCPP_URL)
	BOOST_MESSAGE( "WEBCPP_URL defined." );
	#else
	BOOST_FAIL( "WEBCPP_URL not defined." );
	#endif
}

BOOST_AUTO_TEST_CASE( webcpp_default_information_macros )
{
	#if	defined(WEBCPP_SERVER_SIGNATURE)
	BOOST_MESSAGE( "WEBCPP_SERVER_SIGNATURE defined." );
	#else
	BOOST_FAIL( "WEBCPP_SERVER_SIGNATURE not defined." );
	#endif

	#if	defined(WEBCPP_SERVER_SOFTWARE)
	BOOST_MESSAGE( "WEBCPP_SERVER_SOFTWARE defined." );
	#else
	BOOST_FAIL( "WEBCPP_SERVER_SOFTWARE not defined." );
	#endif

	#if	defined(WEBCPP_SERVER_ADMIN)
	BOOST_MESSAGE( "WEBCPP_SERVER_ADMIN defined." );
	#else
	BOOST_FAIL( "WEBCPP_SERVER_ADMIN not defined." );
	#endif

	#if	defined(WEBCPP_GATEWAY_INTERFACE)
	BOOST_MESSAGE( "WEBCPP_GATEWAY_INTERFACE defined." );
	#else
	BOOST_FAIL( "WEBCPP_GATEWAY_INTERFACE not defined." );
	#endif

	#if	defined(WEBCPP_APP_FUNCTION_NAME)
	BOOST_MESSAGE( "WEBCPP_APP_FUNCTION_NAME defined." );
	#else
	BOOST_FAIL( "WEBCPP_APP_FUNCTION_NAME not defined." );
	#endif

	#if	defined(WEBCPP_APP_FUNCTION_NAME_INIT)
	BOOST_MESSAGE( "WEBCPP_APP_FUNCTION_NAME_INIT defined." );
	#else
	BOOST_FAIL( "WEBCPP_APP_FUNCTION_NAME_INIT not defined." );
	#endif

	#if	defined(WEBCPP_APP_FUNCTION_NAME_END)
	BOOST_MESSAGE( "WEBCPP_APP_FUNCTION_NAME_END defined." );
	#else
	BOOST_FAIL( "WEBCPP_APP_FUNCTION_NAME_END not defined." );
	#endif
}

BOOST_AUTO_TEST_CASE( transmission_layer_is_choosen )
{
	#if	defined(TRANSMISSION_USE)
	BOOST_MESSAGE( "TRANSMISSION_USE defined." );
	#else
	BOOST_FAIL( "TRANSMISSION_USE not defined." );
	#endif
}

BOOST_AUTO_TEST_CASE( default_install_dirs )
{
	#if	defined(WEBCPP_PREFIX)
	BOOST_MESSAGE( "WEBCPP_PREFIX defined." );
	#else
	BOOST_FAIL( "WEBCPP_PREFIX not defined." );
	#endif

	#if	defined(WEBCPP_EXEC_PREFIX)
	BOOST_MESSAGE( "WEBCPP_EXEC_PREFIX defined." );
	#else
	BOOST_FAIL( "WEBCPP_EXEC_PREFIX not defined." );
	#endif

	#if	defined(WEBCPP_EPREFIX)
	BOOST_MESSAGE( "WEBCPP_EPREFIX defined." );
	#else
	BOOST_FAIL( "WEBCPP_EPREFIX not defined." );
	#endif

	#if	defined(WEBCPP_LIBDIR)
	BOOST_MESSAGE( "WEBCPP_LIBDIR defined." );
	#else
	BOOST_FAIL( "WEBCPP_LIBDIR not defined." );
	#endif

	#if	defined(WEBCPP_INCLUDEDIR)
	BOOST_MESSAGE( "WEBCPP_INCLUDEDIR defined." );
	#else
	BOOST_FAIL( "WEBCPP_INCLUDEDIR not defined." );
	#endif
}

