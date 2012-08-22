#define BOOST_TEST_MODULE	Tests interface of header webcpp/http/content_config.hpp
#define BOOST_TEST_DYN_LINK

#include <boost/test/unit_test.hpp>

#include <webcpp/http/entity_config.hpp>

namespace wh=webcpp::http ;
using std::string ;

#define SIMPLE_GET_AND_SET_TEST( set_and_get_name, content ) \
	wh::Entity_config test; \
	std::string content_string( #content ); \
	test.set_and_get_name(content_string); \
	BOOST_REQUIRE_EQUAL( test.set_and_get_name() , content_string );

BOOST_AUTO_TEST_CASE( ctor_and_dtor )
{
	wh::Entity_config test;
}

BOOST_AUTO_TEST_CASE( set_and_get_server_name )
{
	SIMPLE_GET_AND_SET_TEST( server_name, "192.168.2.50" );
}

BOOST_AUTO_TEST_CASE( set_and_get_server_addr )
{
	SIMPLE_GET_AND_SET_TEST( server_addr, "192.168.2.50");
}

BOOST_AUTO_TEST_CASE( set_and_get_server_port )
{
	wh::Entity_config test;
	string content("80");

	test.server_port(content);
	BOOST_REQUIRE_EQUAL( test.server_port() , content );

	test.server_port(80);
	BOOST_REQUIRE_EQUAL( test.server_port() , content );
}

BOOST_AUTO_TEST_CASE( set_and_get_server_signature )
{
	SIMPLE_GET_AND_SET_TEST( server_signature, "Apache/2.24" );
}


BOOST_AUTO_TEST_CASE( set_and_get_server_software )
{
	SIMPLE_GET_AND_SET_TEST( server_software, "Apache/2.2.16 (Unix) DAV/2 PHP/5.2.14" );
}

BOOST_AUTO_TEST_CASE( set_and_get_server_protocol )
{
	SIMPLE_GET_AND_SET_TEST( server_protocol, "HTTP/1.1" );
}

BOOST_AUTO_TEST_CASE( set_and_get_server_admin )
{
	SIMPLE_GET_AND_SET_TEST( server_admin, "root@localhost" );
}

BOOST_AUTO_TEST_CASE( set_and_get_path )
{
	SIMPLE_GET_AND_SET_TEST( path, "/bin:/sbin" );
}

BOOST_AUTO_TEST_CASE( set_and_get_remote_addr )
{
	SIMPLE_GET_AND_SET_TEST( remote_addr, "8.8.8.8" );
}

BOOST_AUTO_TEST_CASE( set_and_get_remote_port )
{
	SIMPLE_GET_AND_SET_TEST( remote_port, "41912" );
}

BOOST_AUTO_TEST_CASE( set_and_get_document_root )
{
	SIMPLE_GET_AND_SET_TEST( document_root, "/var/lib/webcpp" );
}

BOOST_AUTO_TEST_CASE( set_and_get_request_method )
{
	SIMPLE_GET_AND_SET_TEST( request_method, "GET" );
}

BOOST_AUTO_TEST_CASE( set_and_get_request_uri )
{
	SIMPLE_GET_AND_SET_TEST( request_uri, "/cgi-bin/teste3.fcgi/asdasdasdasdasdasd" );
}

BOOST_AUTO_TEST_CASE( set_and_get_query_string )
{
	SIMPLE_GET_AND_SET_TEST( query_string, "algo&a=oooo&b=asdsad+asdas" );
}

BOOST_AUTO_TEST_CASE( set_and_get_script_filename )
{
	SIMPLE_GET_AND_SET_TEST( script_filename, "/srv/httpd/htdocs/psycho/cgi-bin/teste3.fcgi" );
}

BOOST_AUTO_TEST_CASE( set_and_get_script_name )
{
	SIMPLE_GET_AND_SET_TEST( script_name, "/cgi-bin/teste3.fcgi" );
}

BOOST_AUTO_TEST_CASE( set_and_get_path_info )
{
	SIMPLE_GET_AND_SET_TEST( path_info, "/asdasdasdasdasdasd" );
}

BOOST_AUTO_TEST_CASE( set_and_get_path_translated )
{
	SIMPLE_GET_AND_SET_TEST( path_translated, "/srv/httpd/htdocs/asdasdasdasdasdasd" );
}

BOOST_AUTO_TEST_CASE( set_and_get_gateway_interface )
{
	SIMPLE_GET_AND_SET_TEST( gateway_interface, "CGI/1.1" );
}

BOOST_AUTO_TEST_CASE( test_head_map )
{
	wh::Entity_config test;
	test.head["host"]="192.168.2.50";
	test.head["user-agent"]="Firefox";
	test.head["accept"]="text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8";
	test.head["accept-language"]="en-us,en;q=0.8,pt-br;q=0.5,pt;q=0.3";
	test.head["accept-encoding"]="gzip,deflate";
	test.head["accept-charset"]="ISO-8859-1,utf-8;q=0.7,*;q=0.7";
	test.head["keep-alive"]="115";
	test.head["connection"]="keep-alive";
	test.head["cookie"]="oi 3333\\%&*; OI2=oi 3333\\%&*; OI2=oi 3333\\%&*; PHPSESSID=e5iv968deev8oo3nr3ion42hl7";
}

BOOST_AUTO_TEST_CASE( test_copy_info_to_another_entity_config )
{
	wh::Entity_config test_1, test_2;

	test_1.server_name("192.168.2.50");
	test_1.server_addr("192.168.2.50");
	test_1.server_signature("Apache/2.24");
	test_1.server_software("Apache/2.2.16 (Unix) DAV/2 PHP/5.2.14");
	test_1.server_protocol("HTTP/1.1");
	test_1.server_admin("root@localhost");
	test_1.path("/bin:/sbin");
	test_1.document_root("/var/lib/webcpp");
	test_1.gateway_interface("CGI/1.1");

	test_1.remote_addr("8.8.8.8");
	test_1.remote_port("41912");
	test_1.request_method("GET");
	test_1.request_uri("/cgi-bin/teste3.fcgi/asdasdasdasdasdasd");
	test_1.query_string("algo&a=oooo&b=asdsad+asdas");
	test_1.script_filename("/srv/httpd/htdocs/psycho/cgi-bin/teste3.fcgi");
	test_1.script_name("/cgi-bin/teste3.fcgi");
	test_1.path_info("/asdasdasdasdasdasd");
	test_1.path_translated("/srv/httpd/htdocs/asdasdasdasdasdasd");

	test_1.head["host"]="192.168.2.50";
	test_1.head["user-agent"]="Firefox";
	test_1.head["accept"]="text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8";
	test_1.head["accept-language"]="en-us,en;q=0.8,pt-br;q=0.5,pt;q=0.3";
	test_1.head["accept-encoding"]="gzip,deflate";
	test_1.head["accept-charset"]="ISO-8859-1,utf-8;q=0.7,*;q=0.7";
	test_1.head["keep-alive"]="115";
	test_1.head["connection"]="keep-alive";
	test_1.head["cookie"]="oi 3333\\%&*; OI2=oi 3333\\%&*; OI2=oi 3333\\%&*; PHPSESSID=e5iv968deev8oo3nr3ion42hl7";

	test_2.copy_header(test_1);
//	BOOST_REQUIRE_EQUAL( test_1.head , test_2.head );
	BOOST_CHECK( test_1.head == test_2.head );
//	BOOST_CHECK( test_1 != test_2 );

	test_2.copy_server_info(test_1);
	BOOST_REQUIRE_EQUAL( test_1.server_name(), test_2.server_name() );
	BOOST_REQUIRE_EQUAL( test_1.server_addr(), test_2.server_addr() );
	BOOST_REQUIRE_EQUAL( test_1.server_signature(), test_2.server_signature() );
	BOOST_REQUIRE_EQUAL( test_1.server_software(), test_2.server_software() );
	BOOST_REQUIRE_EQUAL( test_1.server_protocol(), test_2.server_protocol() );
	BOOST_REQUIRE_EQUAL( test_1.server_admin(), test_2.server_admin() );
	BOOST_REQUIRE_EQUAL( test_1.server_path(), test_2.server_path() );
	BOOST_REQUIRE_EQUAL( test_1.document_root(), test_2.document_root() );
	BOOST_REQUIRE_EQUAL( test_1.gateway_interface(), test_2.gateway_interface() );
//	BOOST_CHECK( test_1 != test_2 );

	test_2.copy_entity_info(test_1);
//	BOOST_CHECK( test_1 == test_2 );
}

