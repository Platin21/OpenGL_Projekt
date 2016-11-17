TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
    shader.hpp \
    ptl/pb_file.hpp \
    ptl/pb_opengl.hpp \
    ptl/pb_types.hpp \
    ptl/pb_window.hpp \
    ptl/pb_angle.hpp \
    ptl/pb_stream.hpp

SOURCES += \
    main.cpp \
    shader.cpp \
    ptl/pb_file.cpp \
    ptl/pb_opengl.cpp \
    ptl/pb_types.cpp \
    ptl/pb_window.cpp \
    ptl/pb_angle.cpp \
    ptl/pb_stream.cpp

LIBS += \
-L$$PWD/LIB -lglew32 -lglfw3dll \
-lopengl32 \
-lglu32 \
-lgdi32 \
-lkernel32 \
-luser32 \

INCLUDEPATH = $$PWD/INCLUDE/

OTHER_FILES = fshader.frag \
              vshader.vert

DISTFILES += \
    build/fshader.frag \
    build/vshader.vert

