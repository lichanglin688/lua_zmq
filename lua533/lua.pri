# TOLUAPP宏定义
DEFINES +=  TOLUAPP_DLL

LUA_DIR = $$PWD

# 头文件路径
INCLUDEPATH += \
    $$LUA_DIR/include \


# MSVC版本, vs2015对应14.0，vs2019对应16.0，区分处理库的引用
MSVC_VER = $$(VisualStudioVersion)  #
equals(MSVC_VER, 16.0) {
    LIBS += \
        $$LUA_DIR/lib/vs2019/toluapp.lib \
        $$LUA_DIR/lib/vs2019/lua.lib

    DEPENDS += \
        $$LUA_DIR/bin/vs2019/lua.dll \
        $$LUA_DIR/bin/vs2019/toluapp.dll
} else {
    LIBS += \
        $$LUA_DIR/lib/vs2015/toluapp.lib \
        $$LUA_DIR/lib/vs2015/lua.lib

    DEPENDS += \
        $$LUA_DIR/bin/vs2015/lua.dll \
        $$LUA_DIR/bin/vs2015/toluapp.dll
}

