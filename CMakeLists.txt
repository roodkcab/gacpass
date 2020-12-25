cmake_minimum_required(VERSION 3.16)
project(GacPass)

set(CMAKE_CXX_STANDARD 20)

include_directories("Lib")
include_directories("Lib/GacUI")
include_directories("Lib/iGac")
include_directories("UI/Source")

include_directories(${DEPENDENCIES_INCLUDE_DIRS})
link_directories(${DEPENDENCIES_LIBRARY_DIRS})

set(OS_LIBRARIES "pthread")
find_library(COREFOUNDATION_LIBRARIES CoreFoundation)
find_library(QUARTZ_LIBRARIES Quartz)
find_library(COREGRAPHICS_LIBRARIES CoreGraphics)
find_library(COCOA_LIBRARIES Cocoa)
set(OS_LIBRARIES ${COREFOUNDATION_LIBRARIES} ${QUARTZ_LIBRARIES} ${COREGRAPHICS_LIBRARIES} ${COCOA_LIBRARIES} ${OS_LIBRARIES})

include(FetchContent)
FetchContent_Declare(SqliteOrm
		GIT_REPOSITORY https://github.com/fnc12/sqlite_orm
		GIT_TAG        origin/dev
		)
FetchContent_MakeAvailable(SqliteOrm)
find_package(sqlite3 CONFIG REQUIRED)
set(THIRD_LIBRARIES sqlite_orm::sqlite_orm sqlite3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-missing-declarations")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

add_compile_definitions(VCZH_DEBUG_NO_REFLECTION)

set(GACUI_COMMON_FILES
	"Lib/GacUI/GacUI.cpp"
	"Lib/GacUI/Vlpp.cpp"
	"Lib/GacUI/VlppOS.cpp"
	"Lib/GacUI/VlppRegex.cpp"
	"Lib/GacUI/VlppParser.cpp"
	"Lib/GacUI/VlppReflection.cpp"
	"Lib/GacUI/VlppWorkflowLibrary.cpp"
	"Lib/GacUI/Skins/DarkSkin/DarkSkin.cpp"
)

set(GACOSX_FILES
	"Lib/iGac/GraphicsElement/CoreGraphics/GuiGraphicsCoreGraphics.mm"
	"Lib/iGac/GraphicsElement/CoreGraphics/GuiGraphicsCoreGraphicsRenderers.mm"
	"Lib/iGac/GraphicsElement/CoreGraphics/GuiGraphicsLayoutProviderCoreText.mm"
	"Lib/iGac/NativeWindow/OSX/CocoaBaseView.mm"
	"Lib/iGac/NativeWindow/OSX/CocoaHelper.mm"
	"Lib/iGac/NativeWindow/OSX/CocoaIntrospection.mm"
	"Lib/iGac/NativeWindow/OSX/CocoaNativeController.mm"
	"Lib/iGac/NativeWindow/OSX/CocoaWindow.mm"
	"Lib/iGac/NativeWindow/OSX/CoreGraphics/CoreGraphicsApp.mm"
	"Lib/iGac/NativeWindow/OSX/ServicesImpl/CocoaAsyncService.mm"
	"Lib/iGac/NativeWindow/OSX/ServicesImpl/CocoaCallbackService.mm"
	"Lib/iGac/NativeWindow/OSX/ServicesImpl/CocoaClipboardService.mm"
	"Lib/iGac/NativeWindow/OSX/ServicesImpl/CocoaDialogService.mm"
	"Lib/iGac/NativeWindow/OSX/ServicesImpl/CocoaImageService.mm"
	"Lib/iGac/NativeWindow/OSX/ServicesImpl/CocoaInputService.mm"
	"Lib/iGac/NativeWindow/OSX/ServicesImpl/CocoaResourceService.mm"
	"Lib/iGac/NativeWindow/OSX/ServicesImpl/CocoaScreenService.mm"
)

add_library(GacUI STATIC ${GACUI_COMMON_FILES})
add_library(GacOSX STATIC ${GACOSX_FILES})

set(DEPENDENCIES_LIBRARIES ${DEPENDENCIES_LIBRARIES} ${OS_LIBRARIES} ${THIRD_LIBRARIES})
set(GACUI_LIBRARIES "GacUI" "GacOSX")

set(GACOSX_SHARED_FILES
	"Lib/iGac/shared/osx_shared.mm"
	"Lib/iGac/shared/UnixFileSystemInfo.cpp"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "bin/")

set(PLIST_TEMPLATE "${CMAKE_CURRENT_SOURCE_DIR}/Info.plist.in")

add_custom_target(
    CopyResources
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/CopyResources.py
)

#
set(SHARED_RESOURCES "MVVM.bin")
SET_SOURCE_FILES_PROPERTIES(${SHARED_RESOURCES} PROPERTIES MACOSX_PACKAGE_LOCATION Resources)

set(APP_NAME "GacPass")
set(SOURCE_FILES
	"Main.cpp"
	"MacMain.cpp"
	"ViewModel/Code.cpp"
	"ViewModel/Key.cpp"
	"ViewModel/RegisterViewModel.cpp"
	"ViewModel/LoginViewModel.cpp"
	"ViewModel/CodeBookViewModel.cpp"
	"Lib/sqlite_orm/WString.cpp"
	"Lib/util.cpp"
	"UI/Source/GacPassPartialClasses.cpp"
	"UI/Source/CodeBookWindow.cpp"
)
set(MACOSX_BUNDLE_GUI_IDENTIFIER "com.darkfall.iGac.${APP_NAME}")
add_executable(${APP_NAME} MACOSX_BUNDLE ${SOURCE_FILES} ${GACOSX_SHARED_FILES} ${SHARED_RESOURCES})
target_link_libraries(${APP_NAME} ${GACUI_LIBRARIES} ${DEPENDENCIES_LIBRARIES})
set_target_properties( ${APP_NAME} PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${PLIST_TEMPLATE} MACOSX_BUNDLE_GUI_IDENTIFIER ${MACOSX_BUNDLE_GUI_IDENTIFIER} )
add_dependencies(${APP_NAME} CopyResources)
