#------------------------------------------------- 
DESTDIR = $${BIN_PATH}/ 
linux-g++: QMAKE_LFLAGS += -Wl,--rpath=\\\$\$ORIGIN/../../lib.$${OS_SUFFIX}/ 

CONFIG(debug, debug|release) { 
    TARGET=$${TARGET}-$${VERSION}.$${BUILD_FLAG} 
} else { 
    TARGET=$${TARGET} 
} 
 
TRANSLATIONS = $${TARGET}_ru.ts \  
$${TARGET}_en.ts \  
$${TARGET}_kk.ts  
  
