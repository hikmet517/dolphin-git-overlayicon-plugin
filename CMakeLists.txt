cmake_minimum_required(VERSION 3.16.0)

project(dolphin-git-overlayicon-plugin)

set(QT_MIN_VERSION "6.7.0")
set(KF_MIN_VERSION "6.0.0")


# ECM setup
find_package(ECM ${KF_MIN_VERSION} CONFIG REQUIRED)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(FeatureSummary)

find_package(Qt6 ${QT_MIN_VERSION} REQUIRED COMPONENTS
    Core
)

find_package(KF6 ${KF_MIN_VERSION} REQUIRED COMPONENTS
    KIO
)

set(DOLPHIN_GIT_OVERLAYICON_PLUGIN_SOURCES
    "dolphin-git-overlayicon-plugin.cpp"
    "dolphin-git-overlayicon-plugin.hpp"
)

set(DOLPHIN_GIT_OVERLAYICON_PLUGIN dolphin-git-overlayicon-plugin)
kcoreaddons_add_plugin(${DOLPHIN_GIT_OVERLAYICON_PLUGIN}
    SOURCES ${DOLPHIN_GIT_OVERLAYICON_PLUGIN_SOURCES}
    INSTALL_NAMESPACE "kf6/overlayicon"
)

target_link_libraries(${DOLPHIN_GIT_OVERLAYICON_PLUGIN}
    KF6::KIOCore
    KF6::KIOWidgets
)

install(
    FILES "resources/git-overlay.svg"
    DESTINATION ${KDE_INSTALL_FULL_ICONDIR}/hicolor/scalable/emblems
)

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)
