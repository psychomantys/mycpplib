## Additional flags to pass to aclocal when it is invoked automatically at
## make time. The ${ACLOCAL_FLAGS} variable is picked up from the environment
## to provide a way for the user to supply additional arguments.
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS}

AUTOMAKE_OPTIONS=subdir-objects -Wall -Werror

## Define a libtool archive target "libmycpplib-@PACKAGE_VERSION_API@.la", with
## @PACKAGE_VERSION_API@ substituted into the generated Makefile at configure
## time.
## The libtool archive file (.la) will be installed into the directory named
## by the predefined variable $(bindir), along with the actual shared library
## file (.so).
lib_LTLIBRARIES = libmycpplib-@PACKAGE_VERSION_MAJOR@.la

## Define the source file list for the "@PACKAGE_NAME@-@PACKAGE_VERSION_API@"
## target.  Note that @PACKAGE_VERSION_API@ is not interpreted by Automake and
## will therefore be treated as if it were literally part of the target name,
## and the variable name derived from that.
## Note that it is not necessary to list header files
## which are already listed elsewhere in a _HEADERS variable assignment.
mycpplib_@PACKAGE_VERSION_API@_SOURCES = libmycpplib-@PACKAGE_VERSION_MAJOR@.la
mycpplib_@PACKAGE_VERSION_API@_LDADD = libmycpplib-@PACKAGE_VERSION_MAJOR@.la

## Define the source file list for the "libmycpplib-@PACKAGE_VERSION_API@.la"
## target.  Note that @PACKAGE_VERSION_API@ is not interpreted by Automake and
## will therefore be treated as if it were literally part of the target name,
## and the variable name derived from that.
## The file extension .cc is recognized by Automake, and makes it produce
## rules which invoke the C++ compiler to produce a libtool object file (.lo)
## from each source file.  Note that it is not necessary to list header files
## which are already listed elsewhere in a _HEADERS variable assignment.
libmycpplib_@PACKAGE_VERSION_MAJOR@_la_SOURCES = mycpplib.cc \
	http/reply.cpp app.cc \
	transmission/boost_server/server.cc \
	transmission/boost_server/connection.cc \
	transmission/fastcgi_server/server.cc \
	transmission/fastcgi_server/connection.cc \
	transmission/fastcgi_server/input_http.cc \
	http/entity_config.cc \
	transmission/fastcgi_server/my_fcgi.cc

## Instruct libtool to include ABI version information in the generated shared
## library file (.so).  The library ABI version is defined in configure.ac, so
## that all version information is kept in one place.
libmycpplib_@PACKAGE_VERSION_MAJOR@_la_LDFLAGS = -version-info $(PACKAGE_VERSION_SO)

## Define the list of public header files and their install location.  The
## nobase_ prefix instructs Automake to not strip the directory part from each
## filename, in order to avoid the need to define separate file lists for each
## installation directory.  This only works if the directory hierarchy in the
## source tree matches the hierarchy at the install location, however.
mycpplib_includedir = $(includedir)/$(PACKAGE_NAME)-$(PACKAGE_VERSION_MAJOR) $(includedir)/$(PACKAGE_NAME)
nobase_mycpplib_include_HEADERS = config.hpp mycpplib.hpp http/reply.hpp app.hpp \
				transmission.hpp http/header.hpp \
				transmission/boost_server/server.hpp \
				transmission/boost_server/connection.hpp \
				transmission/fastcgi_server/server.hpp \
				transmission/fastcgi_server/connection.hpp \
				transmission/fastcgi_server/input_http.hpp \
				transmission/fastcgi_server/my_fcgi.hpp \
				http/entity_config.hpp

