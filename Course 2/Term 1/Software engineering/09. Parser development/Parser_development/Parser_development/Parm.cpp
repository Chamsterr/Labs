#include "Parm.h"
#include "Error.h"
#include "pch.h"

namespace Parm {
	PARM getparm(int argc, _TCHAR* argv[]) {
		PARM parm;
		if(argc > 2){
			for(int i = 1; i < argc; i++){
				if (wcslen(argv[i]) > PARAM_MAX_SIZE)
					throw ERROR_THROW(104);
				if (wcsstr(argv[i], PARAM_IN))
					wcscpy_s(parm.in, &(argv[i])[4]);
				else if (wcsstr(argv[i], PARAM_OUT))
					wcscpy_s(parm.out, &(argv[i])[5]);
				else if (wcsstr(argv[i], PARAM_LOG))
					wcscpy_s(parm.log, &(argv[i])[5]);
			}
		}
		else if (argc == 2 && wcsstr(argv[1], PARAM_IN)){
			if (wcslen(argv[1]) > PARAM_MAX_SIZE)
				throw ERROR_THROW(104);
			wcscpy_s(parm.in, &(argv[1])[4]);

			wcscpy_s(parm.out, &(argv[1])[4]);
			wcsncat_s(parm.out, PARAM_OUT_DEFAULT_EXT, 4);

			wcscpy_s(parm.log, &(argv[1])[4]);
			wcsncat_s(parm.log, PARAM_LOG_DEFAULT_EXT, 4);
		}
		else
			throw ERROR_THROW(100);

		return parm;
	}
}
