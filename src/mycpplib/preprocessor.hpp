



/* #####   HEADER FILE INCLUDES   ################################################### */
/* #####   EXPORTED MACROS   ######################################################## */

#define declare(type, var_name) \
	private:\
		type _##name; \
	public: \
		void name(const type& var){\
			_##name = var;\
		}\
\
		const type& name(){\
			return _##name; \
		}

/* #####   EXPORTED TYPE DEFINITIONS   ############################################## */
/* #####   EXPORTED DATA TYPES   #################################################### */
/* #####   EXPORTED CLASS DEFINITIONS   ############################################# */
/* #####   EXPORTED VARIABLES   ##################################################### */
/* #####   EXPORTED FUNCTION DECLARATIONS   ######################################### */

