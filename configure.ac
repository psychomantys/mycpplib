
# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.60])
AC_INIT(webcpp, 01.00, psycho at lccv.ufal.br)

AC_CONFIG_MACRO_DIR([build-aux/m4])
AC_CONFIG_AUX_DIR([build-aux])

LT_INIT([dlopen])

# find the libltdl sources in the libltdl sub-directory
LT_CONFIG_LTDL_DIR([build-aux/libltdl])

LTDL_INIT([recursive])

# Include DOLT, libtool faster compiler for something plataforms.
m4_include([build-aux/m4/dolt.m4])

# Inicialize DOLT
DOLT

AM_INIT_AUTOMAKE([1.11 subdir-objects parallel-tests color-tests silent-rules -Wall -Werror])

# Silent Build, sample:
#   CXX    ../webcpp/main.o
AM_SILENT_RULES([yes])


# Information about projet to build packages and the programs.
AC_SUBST([PACKAGE_NAME], ["mycpplib"] )
AC_SUBST([PACKAGE_DESCRIPTION_SHORT], ["My Lib. to C++ aplications"] )
AC_SUBST([PACKAGE_DESCRIPTION_LONG], ["My Lib. to C++ aplications"] )
AC_SUBST([PACKAGE_URL], ["https://psychomantys.wordpress.com"] )

AC_SUBST([PACKAGE_AUTHOR], ["Psycho Mantys"] )
AC_SUBST([PACKAGE_AUTHOR_EMAIL], ["Psycho dot Mantys (.at), gmail dot com"] )

AC_SUBST([PACKAGE_REQUIRED_BUILD], ["boost_thread-dev"] )
AC_SUBST([PACKAGE_REQUIRED_RUNTIME], ["boost_thread"] )

AC_SUBST([PACKAGE_VERSION_MAJOR], [0])
AC_SUBST([PACKAGE_VERSION_MINOR], [1])
AC_SUBST([PACKAGE_VERSION_MINOR_FIX], [0])

AC_SUBST([PACKAGE_VERSION_SO], [${PACKAGE_VERSION_MAJOR}:${PACKAGE_VERSION_MINOR}:${PACKAGE_VERSION_MINOR_FIX}])
AC_SUBST([PACKAGE_VERSION_API], [${PACKAGE_VERSION_MAJOR}.${PACKAGE_VERSION_MINOR}])


# Checks for programs.
AC_PROG_CXX
AC_PROG_CPP
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([unistd.h])

AC_CHECK_HEADER([ltdl.h],
		[AC_CHECK_LIB([ltdl],[lt_dladvise_init],
			[LIBLTDL=-lltdl],
			[LIBLTDL=])
		],[
			LIBLTDL=
		])


# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([getcwd mkdir socket])



# Set --with-transmission-use argument.
# This argument by default is set for boost.
AC_MSG_CHECKING([Checking options for transmission layer])
TRANSMISSION_USE='boost'
AC_ARG_WITH(transmission-use,
	[AS_HELP_STRING([--with-transmission-use=option],
	[Define who is de layer of transmission used for the server. Actual option are: boost or fastcgi.])],
	[
		TRANSMISSION_USE="${withval}"
	]
)
AC_MSG_RESULT([${TRANSMISSION_USE}])
case "${TRANSMISSION_USE}" in
	boost)
		AC_CHECK_LIB([boost_thread],[pthread_sigmask])
		AC_CHECK_LIB([boost_filesystem],[readlink])
	;;
	fastcgi)
		AC_CHECK_LIB([fcgi++],[FCGX_GetChar])
		AC_CHECK_LIB([boost_thread],[pthread_sigmask])
	;;
	*)
		AC_MSG_ERROR(Bad value ${TRANSMISSION_USE} for --transmission-use)
	;;
esac
AC_SUBST([TRANSMISSION_USE])





# Set --enable-debug flag.
# If not debug, silent make will be unset.
AC_MSG_CHECKING([Enable debug])
AC_ARG_ENABLE(
	[debug],
	AS_HELP_STRING([--enable-debug],[Turn on debugging]),
	[
	case "${enableval}" in
		yes) debug=true;;
		no)  debug=false ;;
		*)
			AC_MSG_RESULT([${enableval}])
			AC_MSG_ERROR([Bad value ${enableval} for --enable-debug])
		;;
	esac
	],
	[debug=false]
)
AM_CONDITIONAL([DEBUG], [test x$debug = xtrue])
AM_COND_IF([DEBUG],
	[
	CPPFLAGS="$CPPFLAGS -g -O0 -DDEBUG"
	CFLAGS="$CFLAGS -g -O0 -DDEBUG"
	LDFLAGS="$LDFLAGS -g -O0 -DDEBUG"

	# Disable silent Build, sample:
	#   CXX    ../webcpp/main.o
	AM_SILENT_RULES([no])
	AC_MSG_RESULT([enable])
],[
	CPPFLAGS="$CPPFLAGS -DNDEBUG"
	CFLAGS="$CFLAGS -DNDEBUG"
	LDFLAGS="$LDFLAGS -DNDEBUG"

	AC_MSG_RESULT([not enable flags])
])



dnl ---------------------------------------------------------------------------
dnl Turn on (almost) all warnings when using gcc
dnl ---------------------------------------------------------------------------
if test "x$GCC" = "xyes"; then
	CPPFLAGS="$CPPFLAGS -Wall"
	## CFLAGS="$CFLAGS --std=c99 -Wall -Wextra -Werror -pedantic"
	CFLAGS="$CFLAGS -Wall"
	## CFLAGS="$CFLAGS -Wno-pointer-sign -Wno-unused -Wno-sign-compare"
	#CFLAGS="$CFLAGS -Wmissing-declarations -Wmissing-prototypes"
	LDFLAGS="$LDFLAGS -Wall"
	AC_SUBST([NO_UNUSED_CFLAGS], [-Wno-unused])
fi

# Workaroud to show some vars.
abs_builddir=`pwd`
abs_top_builddir=`pwd`
cd $srcdir

abs_srcdir=`pwd`
abs_top_srcdir=`pwd`
cd $abs_builddir

# Check and expand install path vars.
if test "x${prefix}" = "xNONE"; then
	prefix="${ac_default_prefix}"
fi
if test "x${exec_prefix}" = "xNONE"; then
	exec_prefix="${prefix}"
fi
AC_DEFINE_UNQUOTED([PREFIX], "$(eval echo ${prefix})", [Install prefix directory.])
AC_DEFINE_UNQUOTED([EXEC_PREFIX], ["$(eval echo $exec_prefix)"], [Exec-prefix directory.])
AC_DEFINE_UNQUOTED([LIBDIR], ["$(eval eval echo $libdir)"], [Library directory.] )
AC_SUBST( libdir, ["$(eval eval echo $libdir)"])
AC_SUBST( includedir, ["$(eval eval echo $includedir)"])
AS_IF([ test "x$pkgsrvdir" = "x" -o "x$pkgsrvdir" = "xNONE" -o "x$pkgsrvdir" = "xnone" ],[
	AC_SUBST( pkgsrvdir, ["$(eval eval echo $localstatedir)/${PACKAGE_NAME}-${PACKAGE_VERSION_MAJOR}"])
])



# Add required deps for linker
# Add required deps for compiler
# Add source code include dir for make. The builddir is add here for de case
# of build in another dir, because the *.in files is generate in the builddir.
CPPFLAGS="$CPPFLAGS -I${abs_top_srcdir}/src"
CFLAGS="$CFLAGS -I${abs_top_srcdir}/src"

CPPFLAGS="$CPPFLAGS -I${abs_top_builddir}/src"
CFLAGS="$CFLAGS -I${abs_top_builddir}/src"

# Override the template file name of the generated .pc file, so that there
# is no need to rename the template file when the API version changes.
AC_CONFIG_FILES([
	Makefile src/mycpplib/Makefile test/Makefile
	src/mycpplib/config.hpp
	mycpplib-${PACKAGE_VERSION_MAJOR}.pc:mycpplib.pc.in
	packages/debian/control
	mycpplib.spec
	])

AC_OUTPUT

